#pragma once
#include "GameBoard.h"
#include "GamePiece.h"

class Mill {
public:
    vector<string> slots;
    int devotion;
    explicit Mill(const vector<string>& slots);
};

class GameController {
    GameBoard& board;
    vector<Mill> mills;
    vector<GamePiece> pieces;
public:
    GameController(GameBoard& gameBoard);
    void placePiece(GamePiece& piece, const string& pos);
};