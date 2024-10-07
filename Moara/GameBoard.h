#pragma once
#include <vector>
#include <string>
using std::vector;
using std::string;
using std::exception;

class GameError : public exception {
    string msg;
public:
    explicit GameError(const string& msg);
    const string& getMsg();
};

class Slot {
    string id;
    vector<string> nbs;
    bool empty;
public:
    Slot(const string& id, const vector<string>& nbs);
    const string& getId();
    const vector<string>& getNbs();
    bool isEmpty() const;
};

class GameBoard {
public:
    vector<Slot> slots;
    GameBoard();
    Slot& searchById(const string& id);
};