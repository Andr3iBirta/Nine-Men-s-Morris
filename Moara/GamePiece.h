#pragma once
#include <string>
using std::string;

class GamePiece {
public:
    string color;
    string position;
    bool alive;
    bool secure;
    explicit GamePiece(const string& color);
};