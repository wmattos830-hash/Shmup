# 🎮 Space Shooter MD

Jogo de Mega Drive gerado pelo **MD Shmup Maker 95**.

## 📥 Baixar a ROM

A ROM compilada fica disponível em **3 lugares**:

### 1. 📁 Pasta `output/` (Recomendado)
A ROM é commitada automaticamente nesta pasta após cada build:
- `output/rom.bin` - ROM genérica
- `output/megadrive-rom.bin` - ROM com nome do repositório

👉 [Clique aqui para baixar diretamente](../../raw/main/output/rom.bin)

### 2. 📦 GitHub Actions Artifacts
Vá em **Actions** → clique no último build → baixe em **Artifacts**
- Disponível por 90 dias

### 3. 🏷️ GitHub Releases (Tags)
Crie uma tag (`v1.0`, por exemplo) e a ROM será anexada automaticamente em **Releases**.

## 🕹️ Controles
- **D-Pad**: Mover
- **A**: Atirar
- **Start**: Pausar

## ⚙️ Configurações
- Velocidade inimigo: 3
- Frequência de tiros: 30
- Vidas: 3
- Dano por hit: 1
- Frames de invencibilidade: 60

## 🔨 Compilar Localmente
```bash
export GDK=/caminho/para/SGDK
make -f $GDK/makefile.gen
```

---
Gerado por MD Shmup Maker 95 em 22/08/2026
