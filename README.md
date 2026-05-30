# live-onion-network-LON----The-internet-we-want-is-not-a-service-it-s-a-common-good.
live onion network LON -- The internet we want is not a service — it's a common good.

Author:piromasbr

# 🧅 Live Onion Network (LON)

> **The internet we want is not a service — it's a common good.**

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
[![Status: Active Development](https://img.shields.io/badge/status-active%20development-brightgreen)](https://github.com/liveonion/lon)
[![Open Source](https://img.shields.io/badge/open%20source-%E2%9D%A4-brightgreen)](https://opensource.org/)

---

## 🧠 What is Live Onion Network?

**Live Onion Network (LON)** transforms ordinary home routers into nodes of a decentralized mesh network. All traffic is automatically routed through multiple encrypted hops — like the Tor network — protecting both the privacy of users and the security of those who share their connection.

> You install LON on your router and on your phone. When you're near any other LON router, your traffic flows through it — and through other neighbors — before reaching the internet. No one can trace what you access, and the neighbor's IP is never exposed.

---

## 🎯 Why LON matters

| Principle | What it means |
|-----------|---------------|
| 🔒 **Privacy by default** | All traffic is onion-routed through multiple hops |
| 🛡️ **Legal safety for sharers** | Optional exit through Tor — the volunteer's IP is never the visible exit |
| 📡 **Resilience** | No single point of failure; the mesh self-heals when nodes go offline |
| 🌍 **Connectivity anywhere** | Ideal for underserved communities, rural areas, emergency situations |
| 🏠 **Digital sovereignty** | Infrastructure controlled by the community, not by corporations |
| 🧅 **Layered growth** | Each new node strengthens the network — literally growing in layers |

---

## 🏗️ Architecture

[Phone] <--WiFi--> [Router A] <--Mesh--> [Router B] <--Mesh--> [Router C (Exit via Tor)]
| | |
Private LAN Private LAN Internet
(isolated) (isolated) (via Tor exit node)


| Layer | Technology | Purpose |
|-------|------------|---------|
| **Mesh** | `batman-adv` or `802.11s` | Wireless mesh between routers |
| **Onion** | `lond` (C++ daemon) | Multi-hop encrypted tunnels, onion routing |
| **Exit** | Tor / I2P integration | Anonymous exit to the public internet |

---

## 🧰 Tech Stack

| Component | Technology |
|------------|------------|
| **Core daemon** | C++17, Boost.Asio, libsodium / Botan |
| **Firmware** | OpenWrt (custom image or `.ipk` package) |
| **Mesh protocol** | batman-adv or 802.11s |
| **Onion routing** | Custom implementation inspired by Tor and I2P; optional `i2pd` integration |
| **Cryptography** | libsodium (Curve25519, XSalsa20-Poly1305) |
| **Android app** | Kotlin/Java + C++ (NDK) for networking core |
| **iOS app** | Swift + C++ (via bridging headers) |
| **Key management** | Ed25519 keypair per node, local DHT for peer discovery |

---

## 📦 Project Structure


---

## 🚀 Quick Start

*Coming soon — prototype phase.*

### Prerequisites:
- 2+ OpenWrt-compatible routers (TP-Link Archer C6, Xiaomi Mi Router 4A, GL.iNet devices)
- OpenWrt 23.05 or later

```bash
# Placeholder — not functional yet
git clone https://github.com/liveonion/lon.git
cd lon
make TARGET=ramips/mt7621
scp bin/lond root@192.168.1.1:/usr/bin/
ssh root@192.168.1.1 "lond start"

lonctl start              # Start the LON daemon
lonctl stop               # Stop the LON daemon
lonctl status             # Show node status
lonctl mesh peers         # List mesh neighbors
lonctl onion circuit      # Show current onion circuit
lonctl keys generate      # Generate node keypair
lonctl keys show          # Show public key

🗺️ Roadmap
Phase 1 — Laboratory Prototype (current)

    Architecture defined

    Project name and identity

    lond basic daemon: mesh join + 1-hop onion

    Test with 2 physical OpenWrt routers

    Minimal Android app (manual connection)

Phase 2 — Functional MVP

    Multi-hop onion circuits (automatic path selection)

    Optional Tor exit integration

    Automatic neighbor discovery (local DHT)

    User-friendly mobile app

Phase 3 — Community Pilot

    Test network in a neighborhood or campus

    End-user documentation

    .ipk package for easy OpenWrt installation

    Grant applications (NLnet, Open Technology Fund)

Phase 4 — Scale

    Support for multiple router models

    Optional incentive layer (in study)

    Integration with existing mesh networks (Guifi.net, NYC Mesh, LibreMesh)

🤝 How to Contribute

LON is in its early stages — this is the perfect time to join and shape the architecture!
We're looking for:

    C/C++ developers — embedded systems, network protocols, cryptography

    OpenWrt enthusiasts — packaging, hardware testing, kernel tweaks

    Mobile developers — Android (Kotlin/NDK) and iOS (Swift/C++)

    Tor/I2P specialists — onion routing, DHT, anonymity protocols

    UX/UI designers — mobile app experience for non-technical users

    Writers & translators — documentation, localization, tutorials

    Testers — real-world deployment, bug reports, feedback

Getting started:

    ⭐ Star this repo — it helps visibility!

    📖 Read CONTRIBUTING.md

    💬 Join our community (links coming soon)

    🔍 Look for issues labeled good first issue

    🧵 Introduce yourself in the discussion tab

⚠️ Legal & Ethical Notes

    ISP Terms of Service: Many residential internet contracts prohibit sharing. Exit via Tor mitigates legal risk, but does not eliminate it entirely. Consult a lawyer if concerned.

    Responsible use: LON is built for legitimate privacy and connectivity. We do not condone or support illegal activities.

    No warranties: Use at your own risk. See LICENSE for details.

📚 Inspirations & Related Projects
Project	Relationship to LON
Tor Project	Onion routing — direct inspiration
I2P / i2pd	Anonymous network layer; i2pd is lightweight C++
Byzantium	Linux mesh + Tor
Hyperboria / cjdns	Encrypted mesh networking
LibreMesh	OpenWrt-based community firmware
Althea	Mesh with micropayments
NYC Mesh	Community-owned mesh network
Guifi.net	Massive community network in Catalonia
Fon	Pioneering WiFi sharing model
📄 License

Live Onion Network (LON) is free software licensed under the GNU General Public License v3.0.

See LICENSE for the full text.
✉️ Contact

    GitHub: github.com/liveonion

    Email: contact@liveonion.org

    Community: Links coming soon (Discord / Matrix)



🧅 Live Onion Network (LON)

The internet we want is not a service — it's a common good.

Layer by layer. Neighbor by neighbor.



PORTUGUESE VERSION

# live-onion-network-LON----A internet que queremos não é um serviço, é um bem comum.
live onion network LON -- A internet que queremos não é um serviço — é um bem comum.

# 🧅 Live Onion Network (LON)

> **A internet que queremos não é um serviço — é um bem comum.**

[![Licença: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
[![Status: Desenvolvimento Ativo](https://img.shields.io/badge/status-active%20development-brightgreen)](https://github.com/liveonion/lon)
[![Código Aberto](https://img.shields.io/badge/open%20source-%E2%9D%A4-brightgreen)](https://opensource.org/)

---

## 🧠 O que é a Live Onion Network?

**Live Onion Network (LON)** transforma roteadores domésticos comuns em nós de uma rede mesh descentralizada. Todo o tráfego é automaticamente roteado através de múltiplos saltos criptografados — como na rede Tor — protegendo tanto a privacidade dos usuários quanto a segurança daqueles que compartilham sua conexão.

> Você instala o LON no seu roteador e no seu celular. Quando estiver próximo de qualquer outro roteador LON, seu tráfego flui por ele — e por outros vizinhos — antes de alcançar a internet. Ninguém consegue rastrear o que você acessa, e o IP do vizinho nunca é exposto.

---

## 🎯 Por que o LON importa

| Princípio | O que significa |
|-----------|---------------|
| 🔒 **Privacidade por padrão** | Todo o tráfego é roteado em camadas por múltiplos saltos |
| 🛡️ **Segurança jurídica para quem compartilha** | Saída opcional via Tor — o IP do voluntário nunca é a saída visível |
| 📡 **Resiliência** | Sem ponto único de falha; a malha se autorrecupera quando nós ficam offline |
| 🌍 **Conectividade em qualquer lugar** | Ideal para comunidades pouco atendidas, áreas rurais e situações de emergência |
| 🏠 **Soberania digital** | Infraestrutura controlada pela comunidade, não por corporações |
| 🧅 **Crescimento em camadas** | Cada novo nó fortalece a rede — literalmente crescendo em camadas |

---

## 🏗️ Arquitetura

[Celular] <--WiFi--> [Roteador A] <--Mesh--> [Roteador B] <--Mesh--> [Roteador C (Saída via Tor)]
| | |
LAN Privada LAN Privada Internet
(isolada) (isolada) (via nó de saída Tor)


| Camada | Tecnologia | Finalidade |
|-------|------------|---------|
| **Mesh** | `batman-adv` ou `802.11s` | Rede mesh sem fio entre roteadores |
| **Onion** | `lond` (daemon em C++) | Túneis criptografados com múltiplos saltos, roteamento onion |
| **Saída** | Integração com Tor / I2P | Saída anônima para a internet pública |

---

## 🧰 Stack do Projeto

| Componente | Tecnologia |
|------------|------------|
| **Daemon principal** | C++17, Boost.Asio, libsodium / Botan |
| **Firmware** | OpenWrt (imagem personalizada ou pacote `.ipk`) |
| **Protocolo mesh** | batman-adv ou 802.11s |
| **Roteamento onion** | Implementação própria inspirada em Tor e I2P; integração opcional com `i2pd` |
| **Criptografia** | libsodium (Curve25519, XSalsa20-Poly1305) |
| **Aplicativo Android** | Kotlin/Java + C++ (NDK) para o núcleo de rede |
| **Aplicativo iOS** | Swift + C++ (via bridging headers) |
| **Gerenciamento de chaves** | Par de chaves Ed25519 por nó, DHT local para descoberta de pares |

---

## 📦 Estrutura do Projeto


---

## 🚀 Início Rápido

*Em breve — fase de protótipo.*

### Pré-requisitos:
- 2 ou mais roteadores compatíveis com OpenWrt (TP-Link Archer C6, Xiaomi Mi Router 4A, dispositivos GL.iNet)
- OpenWrt 23.05 ou posterior

```bash
# Placeholder — ainda não funcional
git clone https://github.com/liveonion/lon.git
cd lon
make TARGET=ramips/mt7621
scp bin/lond root@192.168.1.1:/usr/bin/
ssh root@192.168.1.1 "lond start"

lonctl start              # Inicia o daemon LON
lonctl stop               # Para o daemon LON
lonctl status             # Mostra o status do nó
lonctl mesh peers         # Lista vizinhos da malha
lonctl onion circuit      # Mostra o circuito onion atual
lonctl keys generate      # Gera o par de chaves do nó
lonctl keys show          # Exibe a chave pública

🗺️ Roteiro
Fase 1 — Protótipo de Laboratório (atual)

    Arquitetura definida

    Nome e identidade do projeto definidos

    Daemon básico lond: entrada na malha + onion de 1 salto

    Teste com 2 roteadores OpenWrt físicos

    Aplicativo Android mínimo (conexão manual)

Fase 2 — MVP Funcional

    Circuitos onion com múltiplos saltos (seleção automática de caminhos)

    Integração opcional com saída Tor

    Descoberta automática de vizinhos (DHT local)

    Aplicativo móvel amigável ao usuário

Fase 3 — Piloto Comunitário

    Teste da rede em um bairro ou campus

    Documentação para usuários finais

    Pacote .ipk para instalação fácil no OpenWrt

    Solicitações de financiamento (NLnet, Open Technology Fund)

Fase 4 — Escala

    Suporte para múltiplos modelos de roteador

    Camada opcional de incentivos (em estudo)

    Integração com redes mesh existentes (Guifi.net, NYC Mesh, LibreMesh)

🤝 Como Contribuir

O LON está em seus estágios iniciais — este é o momento perfeito para participar e ajudar a moldar a arquitetura!
Estamos procurando:

    Desenvolvedores C/C++ — sistemas embarcados, protocolos de rede, criptografia

    Entusiastas de OpenWrt — empacotamento, testes de hardware, ajustes de kernel

    Desenvolvedores mobile — Android (Kotlin/NDK) e iOS (Swift/C++)

    Especialistas em Tor/I2P — roteamento onion, DHT, protocolos de anonimato

    Designers UX/UI — experiência do aplicativo móvel para usuários não técnicos

    Redatores e tradutores — documentação, localização e tutoriais

    Testadores — implantação em ambiente real, relatórios de bugs e feedback

Primeiros passos:

    ⭐ Dê uma estrela neste repositório — isso ajuda na visibilidade!

    📖 Leia o CONTRIBUTING.md

    💬 Entre na nossa comunidade (links em breve)

    🔍 Procure issues marcadas como good first issue

    🧵 Apresente-se na aba de discussões

⚠️ Notas Legais e Éticas

    Termos de Serviço do ISP: Muitos contratos residenciais de internet proíbem compartilhamento. A saída via Tor reduz o risco jurídico, mas não o elimina completamente. Consulte um advogado se estiver preocupado.

    Uso responsável: O LON foi criado para privacidade e conectividade legítimas. Não apoiamos nem incentivamos atividades ilegais.

    Sem garantias: Use por sua conta e risco. Consulte a LICENSE para mais detalhes.

📚 Inspirações e Projetos Relacionados

Projeto	Relação com o LON
Tor Project	Roteamento onion — inspiração direta
I2P / i2pd	Camada de rede anônima; i2pd é uma implementação leve em C++
Byzantium	Mesh Linux + Tor
Hyperboria / cjdns	Redes mesh criptografadas
LibreMesh	Firmware comunitário baseado em OpenWrt
Althea	Mesh com micropagamentos
NYC Mesh	Rede mesh administrada pela comunidade
Guifi.net	Grande rede comunitária na Catalunha
Fon	Modelo pioneiro de compartilhamento de Wi-Fi

📄 Licença

A Live Onion Network (LON) é um software livre licenciado sob a GNU General Public License v3.0.

Consulte a LICENSE para o texto completo.

✉️ Contato

    GitHub: github.com/liveonion

    E-mail: contact@liveonion.org

    Comunidade: Links em breve (Discord / Matrix)

<div align="center">

🧅 Live Onion Network (LON)

A internet que queremos não é um serviço — é um bem comum.

Camada por camada. Vizinho por vizinho.
</div> ```


