#include "network.hpp"
#include <iostream>
#include <thread>
#include <algorithm>
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <cstring>

namespace lon {
namespace network {

MeshManager::MeshManager() : port_(0), running_(false) {}

MeshManager::~MeshManager() {
    shutdown();
}

bool MeshManager::init(uint16_t port) {
    port_ = port;
    std::cout << "[Mesh] Inicializado na porta " << port_ << std::endl;
    return true;
}

void MeshManager::shutdown() {
    stop_discovery();
    peers_.clear();
    std::cout << "[Mesh] Encerrado." << std::endl;
}

std::vector<Peer> MeshManager::discover_peers() {
    std::vector<Peer> discovered;
    
    // Por enquanto, retorna lista vazia
    // Futuro: escanear rede local, mDNS, DHT
    
    std::cout << "[Mesh] Buscando vizinhos..." << std::endl;
    
    return discovered;
}

bool MeshManager::connect_to_peer(const Peer& peer) {
    // Verificar se já está conectado
    auto it = std::find_if(peers_.begin(), peers_.end(),
        [&peer](const Peer& p) { return p.id == peer.id; });
    
    if (it != peers_.end()) {
        std::cout << "[Mesh] Já conectado ao peer " << peer.id << std::endl;
        return false;
    }
    
    // Adicionar à lista
    Peer new_peer = peer;
    new_peer.is_connected = true;
    new_peer.last_seen = std::chrono::steady_clock::now();
    peers_.push_back(new_peer);
    
    std::cout << "[Mesh] Conectado ao peer " << peer.id << std::endl;
    return true;
}

bool MeshManager::disconnect_from_peer(const std::string& peer_id) {
    auto it = std::find_if(peers_.begin(), peers_.end(),
        [&peer_id](const Peer& p) { return p.id == peer_id; });
    
    if (it != peers_.end()) {
        peers_.erase(it);
        std::cout << "[Mesh] Desconectado do peer " << peer_id << std::endl;
        return true;
    }
    
    return false;
}

std::vector<Peer> MeshManager::get_connected_peers() const {
    std::vector<Peer> connected;
    for (const auto& peer : peers_) {
        if (peer.is_connected) {
            connected.push_back(peer);
        }
    }
    return connected;
}

void MeshManager::start_discovery() {
    running_ = true;
    std::cout << "[Mesh] Descoberta automática iniciada." << std::endl;
}

void MeshManager::stop_discovery() {
    running_ = false;
    std::cout << "[Mesh] Descoberta automática parada." << std::endl;
}

void MeshManager::discovery_loop() {
    while (running_) {
        discover_peers();
        cleanup_stale_peers();
        std::this_thread::sleep_for(std::chrono::seconds(30));
    }
}

void MeshManager::cleanup_stale_peers() {
    auto now = std::chrono::steady_clock::now();
    peers_.erase(
        std::remove_if(peers_.begin(), peers_.end(),
            [now](const Peer& p) {
                auto diff = std::chrono::duration_cast<std::chrono::seconds>(now - p.last_seen);
                return diff.count() > 300; // 5 minutos
            }),
        peers_.end()
    );
}

} // namespace network
} // namespace lon