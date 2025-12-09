# Chess Game in C++

## Overview
This is a console-based Chess game implemented in C++ as a semester project for Object-Oriented Programming (OOP). The game supports two players and includes basic chess rules such as piece movements, check,
checkmate, pawn promotion, and scoring. It demonstrates OOP concepts like inheritance, polymorphism (via virtual functions), encapsulation, and static members.

The game features a colored board display, sound effects for moves (using Windows Beep API), and error handling for invalid moves.

## Features
- **Two-Player Mode**: Players take turns moving pieces (Player 1: Red/White pieces, Player 2: Green/Black pieces).
- **Piece Movements**: Accurate rules for Pawn, Rook, Knight, Bishop, Queen, and King.
- **Check and Checkmate Detection**: Alerts when a king is in check; ends the game on checkmate.
- **Pawn Promotion**: Pawns reaching the opposite side can promote to Queen, Knight, Rook, or Bishop.
- **Scoring System**: Points awarded for capturing opponent pieces (Pawn: 1, Knight/Bishop: 3, Rook: 5, Queen: 9).
- **Path Validation**: Ensures clear paths for sliding pieces (Rook, Bishop, Queen).
- **Sound and Visual Feedback**: Beep sounds for valid/invalid moves; colored console output using ANSI escape codes.
- **Board Display**: 8x8 grid with coordinates and alternating square colors.

## Technologies Used
- **Language**: C++
- **Libraries**: 
  - `<iostream>`, `<cstring>`, `<cstdlib>` for input/output and system commands.
  - `<windows.h>` for sound effects (Beep function) – Windows-specific.
- **OOP Concepts**: Base class `pieces` with derived classes for each piece type (e.g., `knight`, `queen`). Virtual functions for polymorphic behavior.
- **Console Enhancements**: ANSI escape codes for colors and backgrounds.

**Note**: This project is designed for Windows due to the use of `<windows.h>`. For cross-platform compatibility, sound effects may need replacement (e.g., with a library like SFML).

## How to Run
1. **Prerequisites**:
   - A C++ compiler (e.g., g++ from MinGW on Windows).
   - Windows OS for sound effects (or modify the code for other platforms).

2. **Compile the Code**:
   ```
   g++ chess_game.cpp -o chess_game
   ```

3. **Run the Executable**:
   ```
   chess_game.exe
   ```

4. **Gameplay Instructions**:
   - The board is displayed with rows (1-8) and columns (a-h).
   - Select a piece type (1-6) and enter source/destination coordinates (e.g., "a 2" to "a 4").
   - Follow prompts for moves and promotions.
   - The game ends on checkmate, displaying the winner and final scores.

**Example Input**:
- Choose piece: 6 (Pawn)
- Source: a 2
- Destination: a 4

## Group Members
This project was developed by a three-member team:
- **Muhammad Uzair Hussain** (Lead Developer)
- **Zainab Sagheer**
- **Saadan Khan**

## Limitations and Future Improvements
- No support for castling or en passant.
- No AI; only human vs. human.
- No undo moves or save/load game state.
- Potential improvements: Add GUI using SFML/SDL, implement AI with minimax, or add online multiplayer.

## License
This project is for educational purposes. Feel free to use or modify it, but please credit the original authors.

If you encounter issues or have suggestions, open an issue on this GitHub repo!
