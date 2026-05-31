#pragma once
#include <sodium.h>
#include <vector>
#include <string>
#include <array>
#include <stdexcept>

namespace lon {
namespace crypto {

// Tamanhos fixos para chaves
constexpr size_t PUBLIC_KEY_SIZE = crypto_box_PUBLICKEYBYTES;    // 32 bytes
constexpr size_t SECRET_KEY_SIZE = crypto_box_SECRETKEYBYTES;    // 32 bytes
constexpr size_t NONCE_SIZE = crypto_box_NONCEBYTES;             // 24 bytes
constexpr size_t MAC_SIZE = crypto_box_MACBYTES;                 // 16 bytes

// Tipos
using PublicKey = std::array<unsigned char, PUBLIC_KEY_SIZE>;
using SecretKey = std::array<unsigned char, SECRET_KEY_SIZE>;
using Nonce = std::array<unsigned char, NONCE_SIZE>;

class KeyPair {
public:
    KeyPair();
    std::string public_key_hex() const;
    std::string public_key_bytes() const;
    
    PublicKey public_key;
    SecretKey secret_key;
};

// Funções criptográficas
std::string bytes_to_hex(const unsigned char* bytes, size_t length);
std::vector<unsigned char> hex_to_bytes(const std::string& hex);
std::vector<unsigned char> encrypt(const std::vector<unsigned char>& message,
                                    const PublicKey& receiver_public_key,
                                    const SecretKey& sender_secret_key);
std::vector<unsigned char> decrypt(const std::vector<unsigned char>& encrypted,
                                    const PublicKey& sender_public_key,
                                    const SecretKey& receiver_secret_key);
std::vector<unsigned char> generate_random_bytes(size_t size);
std::string generate_nonce_hex();

} // namespace crypto
} // namespace lon