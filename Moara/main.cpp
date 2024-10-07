#include <QApplication>
#include "GUI.h"

int main(int argc, char **argv) {
    QApplication a(argc, argv);

    UIGameBoard gameboard;
    gameboard.resize(1260, 820);
    gameboard.show();

    return a.exec();
}
