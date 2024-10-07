#pragma once
#include <QWidget>

class UIGameBoard : public QWidget {
    QList<QPointF> pieceCoords;
    int draggedPieceIndex;
    QPointF dragOffset;
    int pieceRadius;
public:
    UIGameBoard(QWidget* parent = nullptr);
protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

    QList<QPointF> slotPositions;
    QPointF findClosestSlot(QPointF position);
};
