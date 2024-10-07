#include "GameBoard.h"

GameError::GameError(const string &msg) : msg { msg } {}

const string& GameError::getMsg() {
    return msg;
}

Slot::Slot(const string& id, const vector<string>& nbs) :
    id { id }, nbs { nbs } { empty = true; }

const string& Slot::getId() {
    return id;
}

const vector<string>& Slot::getNbs() { return nbs; }

bool Slot::isEmpty() const { return empty; }

GameBoard::GameBoard() {
    slots.push_back(Slot("A1",{"A4","D1"}));
    slots.push_back(Slot("D1",{"A1","D2","G1"}));
    slots.push_back(Slot("G1",{"D1","G4"}));
    slots.push_back(Slot("B2",{"B4","D2"}));
    slots.push_back(Slot("D2",{"B2","D1","D3","F2"}));
    slots.push_back(Slot("F2",{"D2","F4"}));
    slots.push_back(Slot("C3",{"C4","D3"}));
    slots.push_back(Slot("D3",{"C3","D2","E3"}));
    slots.push_back(Slot("E3",{"D3","E4"}));
    slots.push_back(Slot("A4",{"A1","B4","A7"}));
    slots.push_back(Slot("B4",{"A4","B2","B6","C4"}));
    slots.push_back(Slot("C4",{"B4","C3","C5"}));
    slots.push_back(Slot("E4",{"E3","E5","F4"}));
    slots.push_back(Slot("F4",{"E4","F2","F6","G4"}));
    slots.push_back(Slot("G4",{"F4","G1","G7"}));
    slots.push_back(Slot("C5",{"C4","D5"}));
    slots.push_back(Slot("D5",{"C5","D6","E5"}));
    slots.push_back(Slot("E5",{"D5","E4"}));
    slots.push_back(Slot("B6",{"B4","D6"}));
    slots.push_back(Slot("D6",{"B6","D5","D7","F6"}));
    slots.push_back(Slot("F6",{"D6","F4"}));
    slots.push_back(Slot("A7",{"A4","D7"}));
    slots.push_back(Slot("D7",{"A7","D6","G7"}));
    slots.push_back(Slot("G7",{"D7","G4"}));
}

Slot& GameBoard::searchById(const string& id) {
    for (auto& slot : slots)
        if (slot.getId() == id)
            return slot;
    throw GameError("Invalid move");
}