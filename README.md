# 🎮 Tres Uno Dos Game

## 📌 Description

Tres Uno Dos is a simple command-line-based turn-based strategy game where three players—**Tres, Uno, and Dos**—take turns making moves on a **4x4 board**. The objective is to form a **straight line of four marks** (horizontally, vertically, or diagonally) to win the game.

## ✨ Features

✅ Three-player turn-based gameplay
✅ Interactive **4x4 board**
✅ Colored board display for better visibility
✅ Simple **keyboard controls**
✅ Automatic **winner detection**

## 🚀 Installation and Setup

### 📌 Prerequisites

Ensure you have the following:

- **C compiler** (GCC or Clang recommended)
- **Terminal/Command Prompt**

### 📥 Install & Run

1️⃣ **Clone the repository**

```sh
 git clone git@github.com:mbchavez27/MP_CCDSTRU_BoardGame.git
 cd MP_CCDSTRU_BOARDGAME
```

2️⃣ **Compile the program**

```sh
 gcc -Wall -std=c99 -o tres_uno_dos main.c
```

_(Use `clang` instead of `gcc` if needed.)_

3️⃣ **Run the game**

```sh
 ./tres_uno_dos
```

## 🎮 How to Play

- The game starts with **Tres' turn**.
- Move the cursor using:
  - 🔼 `W` - Move Up
  - 🔽 `S` - Move Down
  - ◀️ `A` - Move Left
  - ▶️ `D` - Move Right
  - ✅ `Q` - Confirm selection
- Players take turns placing their marks (`T` for Tres, `U` for Uno, and `D` for Dos).
- The game ends when a player aligns **four marks** or when the board is full.

## 👨‍💻 Author

Developed by **Max Benedict Chavez**
