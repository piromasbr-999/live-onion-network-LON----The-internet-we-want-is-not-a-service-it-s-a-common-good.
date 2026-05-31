/**
 * Live Onion Network (LON) - Daemon principal
 * 
 * Este é o ponto de partida do lond, o daemon que roda
 * em cada dispositivo LON (Raspberry Pi, PC, etc.)
 * 
 * Tecnologia brasileira - Soberania digital
 * Licença: GPL v3
 */

#include <iostream>
#include <csignal>
#include <atomic>
#include <thread>
#include <chrono>
#include "common/config.hpp"
#include "common/crypto.hpp"
#include "common/network.hpp"
#include "crypto/keys.hpp"
#include "mesh/manager.hpp"
#include "onion/circuit.hpp"
#include "onion/relay.hpp"
#include "net/tcp.hpp"

// Flag global para controle de execução
std::atomic<bool> running(true);

// Tratamento de sinais para encerramento limpo
void signal_handler(int signal) {
    std::cout << "\n[LON] Sinal " << signal << " recebido. Encerrando..." << std::endl;
    running = false;
}

int main() {
    // Configurar tratadores de sinal
    std::signal(SIGINT, signal_handler);
    std::signal(SIGTERM, signal_handler);

    // Banner
    std::cout << std::endl;
    std::cout << "╔══════════════════════════════════════════════╗" << std::endl;
    std::cout << "║                                              ║" << std::endl;
    std::cout << "║       🧅 Live Onion Network (LON)            ║" << std::endl;
    std::cout << "║       Daemon v" << lon::VERSION << "                          ║" << std::endl;
    std::cout << "║       Tecnologia brasileira                  ║" << std::endl;
    std::cout << "║       Soberania digital                      ║" << std::endl;
    std::cout << "║                                              ║" << std::endl;
    std::cout << "╚══════════════════════════════════════════════╝" << std::endl;
    std::cout << std::endl;

    // Inicializar libsodium
    if (sodium_init() < 0) {
        std::cerr << "[ERRO] Falha ao inicializar libsodium. Abortando." << std::endl;
        return 1;
    }
    std::cout << "[OK] libsodium inicializado (v" << sodium_version_string() << ")" << std::endl;

    // Inicializar par de chaves do nó
    lon::crypto::NodeKeyManager key_manager;
    if (!key_manager.init()) {
        std::cerr << "[ERRO] Falha ao inicializar chaves do nó. Abortando." << std::endl;
        return 1;
    }
    
    auto keypair = key_manager.get_keypair();
    std::cout << "[OK] Chaves carregadas. ID do nó: " << keypair.public_key_hex().substr(0, 16) << "..." << std::endl;

    // Inicializar gerenciador de malha
    lon::mesh::MeshNetwork mesh;
    if (!mesh.initialize(lon::DEFAULT_PORT)) {
        std::cerr << "[ERRO] Falha ao inicializar a malha. Abortando." << std::endl;
        return 1;
    }
    std::cout << "[OK] Malha mesh inicializada na porta " << lon::DEFAULT_PORT << std::endl;

    // Inicializar roteamento onion
    lon::onion::CircuitManager circuit_manager;
    if (!circuit_manager.init(keypair)) {
        std::cerr << "[ERRO] Falha ao inicializar roteamento onion. Abortando." << std::endl;
        return 1;
    }
    std::cout << "[OK] Roteamento onion inicializado." << std::endl;

    // Inicializar relay
    lon::onion::RelayManager relay_manager;
    relay_manager.init(keypair);
    std::cout << "[OK] Gerenciador de relay inicializado." << std::endl;

    // Inicializar servidor TCP
    lon::net::TCPServer tcp_server(lon::DEFAULT_PORT);
    if (!tcp_server.start()) {
        std::cerr << "[ERRO] Falha ao iniciar servidor TCP. Abortando." << std::endl;
        return 1;
    }
    std::cout << "[OK] Servidor TCP ouvindo na porta " << lon::DEFAULT_PORT << std::endl;

    // Iniciar descoberta automática de vizinhos
    mesh.start_discovery();

    std::cout << std::endl;
    std::cout << "[LON] ✅ Daemon iniciado com sucesso!" << std::endl;
    std::cout << "[LON] Pressione Ctrl+C para encerrar." << std::endl;
    std::cout << std::endl;

    // Loop principal
    while (running) {
        // Processar conexões recebidas
        tcp_server.process_connections();
        
        // Atualizar circuitos onion
        circuit_manager.maintain_circuits();
        
        // Processar relay
        relay_manager.process_queue();
        
        // Pequena pausa para não consumir 100% da CPU
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    // Encerramento limpo
    std::cout << std::endl;
    std::cout << "[LON] Encerrando serviços..." << std::endl;
    
    mesh.stop_discovery();
    tcp_server.stop();
    relay_manager.shutdown();
    circuit_manager.shutdown();
    mesh.shutdown();
    
    std::cout << "[LON] ✅ Daemon encerrado. Até mais!" << std::endl;
    return 0;
}