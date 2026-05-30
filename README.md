# 🧅 Live Onion Network (LON) (Autor:Piromasbr)

> **A internet que queremos não é um serviço — é um bem comum.**

[![Licença: GPL v3](https://img.shields.io/badge/Licen%C3%A7a-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
[![Status: Desenvolvimento Ativo](https://img.shields.io/badge/status-desenvolvimento%20ativo-brightgreen)](https://github.com/liveonion/lon)
[![Código Aberto](https://img.shields.io/badge/c%C3%B3digo%20aberto-%E2%9D%A4-brightgreen)](https://opensource.org/)
[![Feito no Brasil](https://img.shields.io/badge/feito%20no-Brasil-%2300A859)](https://github.com/liveonion/lon)

---

## 🧠 O que é a Live Onion Network?

A **Live Onion Network (LON)** é uma rede mesh comunitária e anônima **criada no Brasil** que qualquer pessoa pode montar usando um dispositivo barato conectado ao seu roteador doméstico. Todo o tráfego é automaticamente roteado por múltiplos saltos criptografados — como a rede Tor — protegendo tanto a privacidade de quem usa quanto a segurança de quem compartilha sua conexão.

> Você conecta um dispositivo LON (como um Raspberry Pi) no seu roteador comum. Quando alguém com o app LON está por perto, o tráfego passa por você e por outros vizinhos antes de chegar à internet. Ninguém consegue rastrear o que a pessoa acessa, e o IP de quem compartilha nunca fica exposto.

---

## 🇧🇷 Por que o LON é importante para o Brasil?

| Princípio | O que significa |
|-----------|-----------------|
| 🔒 **Privacidade por padrão** | Todo o tráfego é roteado em cebola por múltiplos saltos |
| 🛡️ **Segurança jurídica para quem compartilha** | Saída opcional via Tor — o IP do voluntário nunca é o IP de saída visível |
| 📡 **Resiliência** | Sem ponto único de falha; a malha se autorregenera quando nós ficam offline |
| 🌍 **Conectividade em qualquer lugar** | Ideal para comunidades carentes, áreas rurais, periferias, situações de emergência |
| 🏠 **Soberania digital** | Infraestrutura controlada pela comunidade brasileira, não por big techs estrangeiras |
| 🧅 **Crescimento em camadas** | Cada novo nó fortalece a rede — literalmente crescendo em camadas |
| 🔌 **Funciona com qualquer roteador** | Basta conectar o dispositivo LON no seu roteador atual — sem trocar nada |

---

## 🏗️ Arquitetura

[Celular com app LON] <--WiFi--> [Dispositivo LON A] <--Mesh--> [Dispositivo LON B] <--Mesh--> [Dispositivo LON C (Saída via Tor)]
| | |
Roteador comum Roteador comum Roteador comum
(qualquer marca) (qualquer marca) (qualquer marca)
| | |
Internet Internet Internet


| Camada | Tecnologia | Propósito |
|--------|------------|-----------|
| **Dispositivo** | Raspberry Pi, GL.iNet, ESP32, PC antigo | Nó físico da rede — conecta no roteador via cabo Ethernet |
| **Mesh** | `batman-adv` ou `802.11s` | Malha sem fio entre os dispositivos LON |
| **Onion** | `lond` (daemon C++) | Túneis criptografados com múltiplos saltos, roteamento cebola |
| **Saída** | Integração Tor / I2P | Saída anônima para a internet pública |

---

## 🧰 Stack Tecnológica

| Componente | Tecnologia |
|------------|------------|
| **Hardware principal** | Raspberry Pi Zero 2 W, Raspberry Pi 3/4/5, GL.iNet, PC Linux |
| **Sistema operacional** | Raspberry Pi OS (Linux) ou OpenWrt |
| **Daemon principal** | C++17, Boost.Asio, libsodium / Botan |
| **Protocolo Mesh** | batman-adv ou 802.11s |
| **Roteamento Onion** | Implementação própria inspirada no Tor e I2P; integração opcional com `i2pd` |
| **Criptografia** | libsodium (Curve25519, XSalsa20-Poly1305) |
| **App Android** | Kotlin/Java + C++ (NDK) para o núcleo de rede |
| **App iOS** | Swift + C++ (via bridging headers) |
| **Gerenciamento de chaves** | Par de chaves Ed25519 por nó, DHT local para descoberta de vizinhos |

---

## 📦 O que você precisa para montar um nó LON?

| Opção | Dispositivo | Custo médio | Dificuldade |
|-------|-------------|-------------|-------------|
| 🥇 **Recomendado** | Raspberry Pi Zero 2 W + cabo Ethernet + cartão microSD | R$ 150-200 | Fácil — só gravar a imagem no cartão |
| 🥈 | Raspberry Pi 3/4/5 | R$ 300-600 | Fácil |
| 🥉 | GL.iNet AR300M ou similar | R$ 150-250 | Muito fácil — já vem pronto |
| 🔧 | Qualquer PC/Linux antigo com WiFi | Grátis (reaproveitado) | Média |
| 🚀 | ESP32 (funcionalidades reduzidas) | R$ 40-60 | Avançado |

---

## 🚀 Início Rápido

*Em breve — fase de protótipo.*

### Opção 1: Imagem pronta para Raspberry Pi (recomendado)
1. Baixe a imagem LON do nosso site
2. Grave no cartão microSD com Raspberry Pi Imager
3. Insira o cartão no Raspberry Pi
4. Conecte o Raspberry Pi no seu roteador com o cabo Ethernet
5. Ligue na tomada — pronto!

### Opção 2: Instalação manual
```bash
# Em breve — ainda não funcional
git clone https://github.com/liveonion/lon.git
cd lon
sudo ./install.sh
lond start

lonctl start              # Inicia o daemon LON
lonctl stop               # Para o daemon LON
lonctl status             # Mostra o status do nó
lonctl mesh peers         # Lista vizinhos na malha
lonctl onion circuit      # Mostra o circuito onion atual
lonctl keys generate      # Gera par de chaves do nó
lonctl keys show          # Mostra a chave pública

📱 App Mobile (em desenvolvimento)

O app LON para celular permite:

    Conectar automaticamente a qualquer dispositivo LON por perto

    Visualizar a rede mesh e quantos saltos seu tráfego está dando

    Verificar se a saída está anonimizada via Tor

    Modo passageiro: só usa a rede | Modo contribuidor: também compartilha

🗺️ Roadmap
Fase 1 — Protótipo de Laboratório (atual)

    Arquitetura definida

    Nome e identidade do projeto

    Estratégia de dispositivo externo universal

    Documentação inicial em português

    Daemon lond rodando em Raspberry Pi

    Teste com 2 Raspberry Pis + mesh + 1 salto onion

    App Android mínimo (conexão manual)

Fase 2 — MVP Funcional

    Circuitos onion com múltiplos saltos (seleção automática de caminho)

    Integração com saída Tor

    Descoberta automática de vizinhos (DHT local)

    Imagem pronta para Raspberry Pi (gravar e usar)

    App mobile amigável para o usuário final

Fase 3 — Piloto Comunitário

    Rede de teste em um bairro ou campus universitário brasileiro

    Documentação completa em português para usuário final

    Produção de kits LON (Raspberry Pi + cartão + case)

    Candidatura a grants nacionais e internacionais

Fase 4 — Escala

    Suporte a múltiplos dispositivos (ESP32, GL.iNet, PCs)

    Loja virtual para comprar dispositivos LON prontos no Brasil

    Parcerias com fabricantes e universidades brasileiras

    Integração com redes mesh existentes no Brasil e América Latina

🤝 Como Contribuir

O LON é um projeto brasileiro em estágio inicial — este é o momento perfeito para entrar e ajudar a moldar a arquitetura!
Procuramos pessoas com experiência em:

    Desenvolvimento C/C++ — sistemas embarcados, protocolos de rede, criptografia

    Linux embarcado / Raspberry Pi — criação de imagens, otimização, testes

    Desenvolvimento Mobile — Android (Kotlin/NDK) e iOS (Swift/C++)

    Tor/I2P — roteamento onion, DHT, protocolos de anonimato

    Hardware / Eletrônica — design de cases, testes com ESP32, otimização de consumo

    UX/UI Design — experiência do app mobile e do processo de instalação

    Documentação e tradução — tutoriais, conteúdo educativo (português e outras línguas)

    Testes — implantação em campo, relatórios de bugs, feedback

Primeiros passos:

    ⭐ Dê uma estrela neste repositório — ajuda na visibilidade!

    📖 Leia o CONTRIBUTING.md

    💬 Entre na nossa comunidade (links em breve)

    🔍 Procure issues com a label good first issue

    🧵 Se apresente na aba de discussões

⚠️ Notas Legais e Éticas

    Termos de uso do provedor: Muitos contratos de internet residencial proíbem compartilhamento. A saída via Tor mitiga o risco jurídico, mas não o elimina completamente. Consulte um advogado se tiver dúvidas.

    Uso responsável: O LON é construído para privacidade e conectividade legítima. Não toleramos nem apoiamos atividades ilegais.

    Sem garantias: Use por sua conta e risco. Veja o arquivo LICENSE para detalhes.

📚 Inspirações e Projetos Relacionados
Projeto	Relação com o LON
Tor Project	Roteamento onion — inspiração direta
I2P / i2pd	Camada de rede anônima; i2pd é leve e em C++
Byzantium	Mesh Linux + Tor
Hyperboria / cjdns	Rede mesh criptografada
LibreMesh	Firmware comunitário baseado em OpenWrt
Althea	Mesh com micropagamentos
NYC Mesh	Rede mesh comunitária em Nova York
Guifi.net	Enorme rede comunitária na Catalunha
Fon	Modelo pioneiro de compartilhamento de WiFi
📄 Licença

A Live Onion Network (LON) é software livre licenciado sob a GNU General Public License v3.0.

Veja o arquivo LICENSE para o texto completo.
✉️ Contato

    GitHub: github.com/liveonion

    Email: contact@liveonion.org

    Comunidade: Links em breve (Discord / Matrix)

🧅 Live Onion Network (LON)

A internet que queremos não é um serviço — é um bem comum.

Tecnologia brasileira. Soberania digital. Camada por camada. Vizinho por vizinho.

O brasil ate pode não investir em tecnologia por conta propria pôs não traz retorno imediato

mas, se a gente se juntar ninguem para a gente.
