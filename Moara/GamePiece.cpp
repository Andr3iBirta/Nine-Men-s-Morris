#include "GamePiece.h"

GamePiece::GamePiece(const string& color) : color { color } {
    position = "";
    alive = true;
    secure = false;
}