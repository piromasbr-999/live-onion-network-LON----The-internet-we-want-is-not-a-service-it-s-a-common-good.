#pragma once
#include "common/crypto.hpp"
#include <string>

namespace lon {
namespace crypto {

class NodeKeyManager {
public:
    NodeKeyManager();
    ~NodeKeyManager();
    
    bool init();
    bool generate_keys();
    bool load_keys(const std::string& path);
    bool save_keys(const std::string& path);
    
    KeyPair get_keypair() const;
    std::string get_node_id() const;

private:
    KeyPair keypair_;
    std::string keys_path_;
    
    std::string compute_node_id(const PublicKey& public_key) const;
};

} // namespace crypto
} // namespace lon