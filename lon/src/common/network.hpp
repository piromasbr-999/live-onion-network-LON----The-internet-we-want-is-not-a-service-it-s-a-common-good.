#pragma once
#include <string>
#include <vector>
#include <cstdint>
#include <chrono>

namespace lon {
namespace network {

struct Peer {
    std::string id;             // Identificador único (hash da chave pública)
    std::string public_key;     // Chave pública Ed25519
    std::string address;        // Endereço IP
    uint16_t port;              // Porta
    int hop_count;              // Distância em saltos
    std::chrono::steady_clock::time_point last_seen;
    bool is_connected;
    
    Peer() : port(0), hop_count(0), is_connected(false) {}
};

class MeshManager {
public:
    MeshManager();
    ~MeshManager();
    
    bool init(uint16_t port);
    void shutdown();
    
    std::vector<Peer> discover_peers();
    bool connect_to_peer(const Peer& peer);
    bool disconnect_from_peer(const std::string& peer_id);
    std::vector<Peer> get_connected_peers() const;
    
    void start_discovery();
    void stop_discovery();

private:
    uint16_t port_;
    std::vector<Peer> peers_;
    bool running_;
    
    void discovery_loop();
    void cleanup_stale_peers();
};

} // namespace network
} // namespace lon