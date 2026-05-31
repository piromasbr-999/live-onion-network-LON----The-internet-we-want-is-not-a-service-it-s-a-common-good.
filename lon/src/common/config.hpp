#pragma once
#include <string>
#include <cstdint>

namespace lon {
    constexpr const char* VERSION = "0.1.0";
    constexpr const char* PROJECT_NAME = "Live Onion Network";
    constexpr const char* DESCRIPTION = "Tecnologia brasileira - Soberania digital";
    
    constexpr uint16_t DEFAULT_PORT = 9051;
    constexpr const char* CONFIG_DIR = "/etc/lon";
    constexpr const char* DATA_DIR = "/var/lib/lon";
    constexpr const char* LOG_DIR = "/var/log/lon";
    
    constexpr int MAX_HOPS = 6;
    constexpr int MESH_DISCOVERY_INTERVAL = 30;  // segundos
    constexpr int CIRCUIT_TIMEOUT = 300;         // segundos
}