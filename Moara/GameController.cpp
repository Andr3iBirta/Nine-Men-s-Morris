#include "GameController.h"

Mill::Mill(const vector<string>& slots) : slots { slots } {
    devotion = 0;
}

GameController::GameController(GameBoard& gameBoard):
    board { gameBoard } {
    mills.push_back(Mill({"A7","D7","G7"}));
    mills.push_back(Mill({"B6","D6","F6"}));
    mills.push_back(Mill({"C5","D5","E5"}));
    mills.push_back(Mill({"A4","B4","C4"}));
    mills.push_back(Mill({"E4","F4","G4"}));
    mills.push_back(Mill({"C3","D3","E3"}));
    mills.push_back(Mill({"B2","D2","F2"}));
    mills.push_back(Mill({"A1","D1","G1"}));

    mills.push_back(Mill({"A1","A4","A7"}));
    mills.push_back(Mill({"B2","B4","B6"}));
    mills.push_back(Mill({"C3","C4","C5"}));
    mills.push_back(Mill({"D1","D2","D3"}));
    mills.push_back(Mill({"D5","D6","D7"}));
    mills.push_back(Mill({"E3","E4","E5"}));
    mills.push_back(Mill({"F2","F4","F6"}));
    mills.push_back(Mill({"G1","G4","G7"}));

    for (int i = 0; i < 9; i++)
        pieces.push_back(GamePiece("white"));
    for (int i = 0; i < 9; i++)
        pieces.push_back(GamePiece("black"));
}

void GameController::placePiece(GamePiece& piece, const string& pos) {
    auto& slot = board.searchById(pos);
    if (!slot.isEmpty())
        throw GameError("Invalid move");
    piece.position = pos;
    for (auto& mill : mills) {
        bool found = false;
        for (const auto& id : mill.slots)
            if (id == pos)
                found = true;
        if (found) {
            if (piece.color == "white")
                mill.devotion++;
            else
                mill.devotion--;
            if (mill.devotion == 3 || mill.devotion == -3)
                for (const auto& position : mill.slots)
                    for (auto& piece : pieces)
                        if (piece.position == position) {
                            piece.secure = true;
                            break;
                        }
        }
    }
}
