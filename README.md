# 👾 Space Invaders (C++ & Raylib)

A recreation of the classic arcade game **Space Invaders**, implemented from scratch in **C++17** using the **[Raylib](https://www.raylib.com/)** multimedia library and **CMake**.

Defend Earth from waves of descending alien invaders, take cover behind destructible shields, shoot down high-value mystery UFOs, and climb the high-score leaderboard!

---

## 🎮 Features

- **Classic Arcade Gameplay**: 5 rows of 11 alien invaders marching side-to-side and descending toward Earth.
- **Dynamic Scoring**:
  - 🛸 **Mystery UFO**: `500 pts`
  - 👾 **Alien Type 3 (Top Row)**: `300 pts`
  - 👾 **Alien Type 2 (Middle Rows)**: `200 pts`
  - 👾 **Alien Type 1 (Bottom Rows)**: `100 pts`
- **Destructible Defense Bunkers**: 4 modular shield barriers that chip away pixel-by-pixel when hit by lasers or aliens.
- **Persistent High Scores**: Automatically tracks and saves your best score locally to `highscore.txt`.
- **Audio & Visual FX**: Retro chiptune background soundtrack, laser blasts, explosion sound effects, and classic arcade styling.
- **Dual Control Schemes**: Full support for both standard arrow keys and **Vim-style** navigation.

---

## 🕹️ Controls

| Action | Primary Key | Alternative (Vim) |
| :--- | :--- | :--- |
| **Move Left** | `Left Arrow` | `H` |
| **Move Right** | `Right Arrow` | `L` |
| **Fire Laser** | `Spacebar` | `K` |
| **Start / Restart** | `Enter` | `Enter` |

---

## 📁 Project Structure

```text
Space-Invaders/
├── CMakeLists.txt        # CMake build configuration
├── fonts/                # Custom arcade typography (dogica.ttf)
├── graphics/             # Sprites (aliens, spaceship, mystery ship, background)
├── sound/                # Music and sound effects (.ogg)
├── highscore.txt         # Persistent high score storage
├── include/              # Header files
│   ├── alien.h
│   ├── block.h
│   ├── game.h
│   ├── laser.h
│   ├── mysteryship.h
│   ├── obstacle.h
│   └── spaceship.h
├── src/                  # Implementation files
│   ├── alien.cpp
│   ├── block.cpp
│   ├── game.cpp
│   ├── laser.cpp
│   ├── main.cpp
│   ├── mysteryship.cpp
│   ├── obstacle.cpp
│   └── spaceship.cpp
└── README.md
```

---

## 🛠️ Prerequisites & Dependencies

To build and run this project, make sure you have:

1. **C++17 Compiler** (Clang, GCC, or MSVC)
2. **CMake** (v3.5 or later)
3. **Raylib** (v4.0 or newer)

### Installing Raylib

- **macOS** (via Homebrew):
  ```bash
  brew install cmake raylib
  ```

- **Ubuntu / Debian**:
  ```bash
  sudo apt update
  sudo apt install cmake g++ libraylib-dev
  ```

- **Arch Linux**:
  ```bash
  sudo pacman -S cmake raylib
  ```

- **Windows**:
  Install Raylib using [vcpkg](https://vcpkg.io/):
  ```bash
  vcpkg install raylib:x64-windows
  ```

---

## 🚀 Building & Running

1. **Clone the repository** (or navigate to the project directory):
   ```bash
   cd Space-Invaders
   ```

2. **Create a build directory and configure with CMake**:
   ```bash
   cmake -B build -S .
   ```

3. **Compile the game**:
   ```bash
   cmake --build build
   ```

4. **Run the executable**:
   ```bash
   ./build/space_invaders
   ```

> [!NOTE]
> Make sure to launch the game from the root directory of the project (or copy the `graphics/`, `sound/`, and `fonts/` folders to your executable directory) so the game can find its assets.

---

## 📜 License

This project is open-source. Feel free to modify, distribute, and build upon it!
