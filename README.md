#  Sand Simulation ⏳

A simple yet captivating sand simulation built with SFML. This project allows users to interact with a grid of "sand" particles, placing them with mouse clicks and watching them interact according to basic physics. It's a great example of simple 2D simulation and game development using SFML.

🚀 **Key Features**

*   **Interactive Placement:** Place sand particles on the grid with left mouse clicks.
*   **Grid Clearing:** Clear the entire grid with a right mouse click.
*   **Basic Physics Simulation:** `updateDots()` function (external) simulates sand movement (e.g., gravity).
*   **Visual Rendering:** Renders sand particles as rectangles using SFML.
*   **Framerate Control:** Limits the framerate to 60 FPS for smooth performance.

🛠️ **Tech Stack**

*   **Language:** C++
*   **Graphics Library:** SFML (Simple and Fast Multimedia Library)
*   **Standard Library:** STL (Standard Template Library)
*   **Dependencies:**
    *   `<SFML/Graphics.hpp>`
    *   `<SFML/System.hpp>`
    *   `<bits/stdc++.h>` (Consider replacing with specific headers for better practice)
    *   `std::array`
    *   `std::pair`

📦 **Getting Started**

### Prerequisites

*   SFML library installed and configured on your system.
*   C++ compiler (e.g., g++)

### Installation

1.  Clone the repository:

    ```bash
    git clone <repository_url>
    cd <repository_directory>
    ```

2.  Compile the code:

    ```bash
    g++ -o sand src/main.cpp -lsfml-graphics -lsfml-window -lsfml-system
    ```
    *Note:* You may need to adjust the compilation command based on your SFML installation and system.

### Running Locally

1.  Run the executable:

    ```bash
    ./sand
    ```

💻 **Usage**

1.  Run the compiled executable.
2.  Click the left mouse button on the window to place sand particles.
3.  Click the right mouse button to clear the entire grid.
4.  Observe the sand particles moving according to the simulation.

📂 **Project Structure**

```
├── README.md
└── src
    └── main.cpp
```

📸 **Screenshots**

<img width="628" height="666" alt="image" src="https://github.com/user-attachments/assets/b982fe93-627c-420a-8e2e-4700d85df91c" />


📬 **Contact**

[Your Name/Organization] - [Your Email/Website]

💖 **Thanks**

Thank you for checking out the Sand Simulation project! We hope you find it interesting and useful.
