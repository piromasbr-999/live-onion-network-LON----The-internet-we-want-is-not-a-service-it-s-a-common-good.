# 🤝 Contribuindo com a Live Onion Network (LON)

Obrigado pelo interesse em contribuir com o LON! Este documento explica como você pode ajudar.

---

## 📋 Código de Conduta

- Seja respeitoso e acolhedor com todos.
- Críticas são bem-vindas, ataques pessoais não.
- Foque no que é melhor para a comunidade.
- Leia o [Código de Conduta](CODE_OF_CONDUCT.md) completo.

---

## 🛠️ Como Contribuir

### Reportando Bugs
1. Verifique se o bug já não foi reportado nas [Issues](https://github.com/liveonion/lon/issues).
2. Use o template de bug report.
3. Inclua: versão do OpenWrt, modelo do roteador, passos para reproduzir, logs.

### Sugerindo Funcionalidades
1. Verifique se a ideia já não existe nas Issues.
2. Use o template de feature request.
3. Explique o problema que resolve e por que é importante.

### Contribuindo com Código
1. Faça um fork do repositório.
2. Crie uma branch: `git checkout -b feature/minha-funcionalidade`.
3. Siga o estilo de código do projeto.
4. Escreva testes quando aplicável.
5. Commit com mensagens claras.
6. Push e abra um Pull Request.

---

## 💻 Configurando o Ambiente

### Pré-requisitos
- Compilador C++17 (GCC 9+ ou Clang 10+)
- CMake 3.16+
- Boost 1.75+
- libsodium
- OpenWrt SDK (para build do pacote)

### Build do Daemon (lond)
```bash
git clone https://github.com/seu-user/lon.git
cd lon
mkdir build && cd build
cmake ..
make -j$(nproc)