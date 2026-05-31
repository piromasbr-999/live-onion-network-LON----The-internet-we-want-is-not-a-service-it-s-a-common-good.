#include "crypto.hpp"
#include <sstream>
#include <iomanip>
#include <cstring>

namespace lon {
namespace crypto {

KeyPair::KeyPair() {
    crypto_box_keypair(public_key.data(), secret_key.data());
}

std::string KeyPair::public_key_hex() const {
    return bytes_to_hex(public_key.data(), PUBLIC_KEY_SIZE);
}

std::string KeyPair::public_key_bytes() const {
    return std::string(reinterpret_cast<const char*>(public_key.data()), PUBLIC_KEY_SIZE);
}

std::string bytes_to_hex(const unsigned char* bytes, size_t length) {
    std::ostringstream oss;
    oss << std::hex << std::setfill('0');
    for (size_t i = 0; i < length; i++) {
        oss << std::setw(2) << static_cast<int>(bytes[i]);
    }
    return oss.str();
}

std::vector<unsigned char> hex_to_bytes(const std::string& hex) {
    std::vector<unsigned char> bytes;
    for (size_t i = 0; i < hex.length(); i += 2) {
        std::string byte_str = hex.substr(i, 2);
        unsigned char byte = static_cast<unsigned char>(std::stoul(byte_str, nullptr, 16));
        bytes.push_back(byte);
    }
    return bytes;
}

std::vector<unsigned char> encrypt(const std::vector<unsigned char>& message,
                                    const PublicKey& receiver_public_key,
                                    const SecretKey& sender_secret_key) {
    std::vector<unsigned char> encrypted(message.size() + MAC_SIZE);
    
    // Gerar nonce aleatório
    Nonce nonce;
    randombytes_buf(nonce.data(), NONCE_SIZE);
    
    // Prepend nonce ao texto cifrado
    encrypted.resize(NONCE_SIZE + message.size() + MAC_SIZE);
    std::memcpy(encrypted.data(), nonce.data(), NONCE_SIZE);
    
    if (crypto_box_easy(encrypted.data() + NONCE_SIZE, message.data(), message.size(),
                         nonce.data(), receiver_public_key.data(), sender_secret_key.data()) != 0) {
        throw std::runtime_error("Falha na criptografia");
    }
    
    return encrypted;
}

std::vector<unsigned char> decrypt(const std::vector<unsigned char>& encrypted,
                                    const PublicKey& sender_public_key,
                                    const SecretKey& receiver_secret_key) {
    if (encrypted.size() < NONCE_SIZE + MAC_SIZE) {
        throw std::runtime_error("Dados criptografados muito curtos");
    }
    
    // Extrair nonce do início
    Nonce nonce;
    std::memcpy(nonce.data(), encrypted.data(), NONCE_SIZE);
    
    size_t message_size = encrypted.size() - NONCE_SIZE - MAC_SIZE;
    std::vector<unsigned char> decrypted(message_size);
    
    if (crypto_box_open_easy(decrypted.data(), encrypted.data() + NONCE_SIZE,
                              encrypted.size() - NONCE_SIZE, nonce.data(),
                              sender_public_key.data(), receiver_secret_key.data()) != 0) {
        throw std::runtime_error("Falha na descriptografia");
    }
    
    return decrypted;
}

std::vector<unsigned char> generate_random_bytes(size_t size) {
    std::vector<unsigned char> bytes(size);
    randombytes_buf(bytes.data(), size);
    return bytes;
}

std::string generate_nonce_hex() {
    Nonce nonce;
    randombytes_buf(nonce.data(), NONCE_SIZE);
    return bytes_to_hex(nonce.data(), NONCE_SIZE);
}

} // namespace crypto
} // namespace lon