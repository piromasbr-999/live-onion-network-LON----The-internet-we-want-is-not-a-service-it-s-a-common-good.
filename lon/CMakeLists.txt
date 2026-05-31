cmake_minimum_required(VERSION 3.16)
project(LiveOnionNetwork VERSION 0.1.0 LANGUAGES CXX)

# Padrão C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Opções de compilação
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2")

# Encontrar dependências
find_package(Boost REQUIRED COMPONENTS system)
find_package(sodium REQUIRED)

# Biblioteca comum (compartilhada entre lond e lonctl)
add_library(loncommon STATIC
    src/common/config.hpp
    src/common/crypto.hpp
    src/common/crypto.cpp
    src/common/network.hpp
    src/common/network.cpp
)

target_include_directories(loncommon PUBLIC src)
target_link_libraries(loncommon PUBLIC sodium ${Boost_LIBRARIES})

# Daemon principal (lond)
add_executable(lond
    src/lond/main.cpp
    src/lond/crypto/keys.hpp
    src/lond/crypto/keys.cpp
    src/lond/mesh/manager.hpp
    src/lond/mesh/manager.cpp
    src/lond/net/tcp.hpp
    src/lond/net/tcp.cpp
    src/lond/onion/circuit.hpp
    src/lond/onion/circuit.cpp
    src/lond/onion/relay.hpp
    src/lond/onion/relay.cpp
)

target_link_libraries(lond PRIVATE loncommon pthread)

# Ferramenta CLI (lonctl)
add_executable(lonctl
    src/lonctl/main.cpp
)

target_link_libraries(lonctl PRIVATE loncommon)