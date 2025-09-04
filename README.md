# cub3D 🎮

<div align="center">
  
<!-- ![cub3D Demo](assets/demo.gif) -->
*A retro-style 3D maze game built with raycasting*

[![42 School](https://img.shields.io/badge/School-000000?style=flat-square&logo=42&logoColor=white)](https://42.fr/)
[![C](https://img.shields.io/badge/C-00599C?style=flat-square&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![MiniLibX](https://img.shields.io/badge/MiniLibX-Graphics-orange?style=flat-square)](https://github.com/42Paris/minilibx-linux)

</div>

## 📖 About

**cub3D** is a 42 school project that recreates the classic first-person perspective of early 90s games like Wolfenstein 3D and DOOM. This project implements a **raycasting engine** from scratch using only the MiniLibX graphics library, creating a pseudo-3D environment where players can navigate through a maze-like world.

## 🎯 Objectives

- Implement a **raycasting algorithm** to render a 3D-like environment from a 2D map
- Create smooth player movement and rotation mechanics
- Handle texture mapping for walls and sprites
- Parse and validate map configurations
- Manage real-time graphics rendering and user input

## 🎮 Features

- ✨ **Real-time 3D rendering** using raycasting techniques
- 🕹️ **Smooth player movement** with WASD controls
- 🖱️ **Mouse look** horizontal movement only
- 🧱 **Textured walls** with support for different textures per direction (North, South, East, West)
- 🎨 **Customizable floor and ceiling colors**
- 🗺️ **Map validation** with comprehensive error checking

## 🚀 Getting Started

### Prerequisites

- **GCC** compiler
- **Make**
- **MiniLibX** library (included for Linux/macOS)
- **X11** development libraries (Linux only)

### Installation

1. **Clone the repository**
```bash
git clone https://github.com/eth1711/cub3d.git
cd cub3d
```

2. **Compile the project**
```bash
make
```

3. **Run the game**
```bash
./cub3D maps/example.cub
```

## 🎲 Usage

### Controls
- **W, A, S, D** - Move forward, left, backward, right
- **← →** - Rotate camera left/right
- **ESC** - Exit game
- **X** (close button) - Exit game

### Map Configuration

Create your own maps using the `.cub` format:

```
NO ./textures/north_texture.xpm
SO ./textures/south_texture.xpm
WE ./textures/west_texture.xpm
EA ./textures/east_texture.xpm

F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000002000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10002000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

**Map Legend:**
- `0` - Empty space (walkable)
- `1` - Wall
- `2` - Sprite position
- `N/S/E/W` - Player starting position and orientation

## 🛠️ Skills Developed

Through this project, we gained hands-on experience with:

### 🎨 **Computer Graphics**
- **Raycasting algorithms** - Understanding the mathematical principles behind pseudo-3D rendering
- **Texture mapping** - Applying 2D textures to 3D surfaces for realistic wall appearances
- **Color manipulation** and pixel-level graphics programming
- **Frame buffer management** for smooth real-time rendering

### 📐 **Mathematics & Algorithms**
- **Trigonometry** - Extensive use of sine, cosine, and angle calculations
- **Vector mathematics** - 2D vector operations for movement and collision detection
- **Distance calculations** - Implementing efficient distance formulas for ray-wall intersections

### 💻 **System Programming**
- **Arithmetic type conversion** - Properly converting floating point values to integers
- **Event handling** - Managing keyboard input for real-time player controls
- **File I/O operations** - Parsing configuration and map files
- **Performance optimization** - Writing efficient code for real-time graphics

### 🏗️ **Software Architecture**
- **Modular design** - Structuring code into logical, reusable components
- **Error handling** - Robust validation of user input and system resources

## 📄 License

This project is part of the 42 School curriculum and follows the school's academic guidelines.

## 🤝 Contributing

As this is an academic project, direct contributions are not accepted. However, feel free to:
- Report bugs or issues
- Suggest improvements
- Use this as reference for your own learning

---

<div align="center">

**Made with sweat and tears @42kl!**

</div>