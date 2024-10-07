#include "GUI.h"
#include <QPainter>
#include <QMouseEvent>

UIGameBoard::UIGameBoard(QWidget *parent)
    : QWidget(parent), draggedPieceIndex { -1 }, pieceRadius { 28 }
{
    pieceCoords.append(QPointF(311, 90));
    pieceCoords.append(QPointF(361, 141));

    slotPositions = {
        QPointF(261+50, 41+50),       // A7
        QPointF(261+150+220, 41+50),  // D7
        QPointF(261+250+440, 41+50),  // G7
        QPointF(261+50, 41+150+220),  // A4
        QPointF(261+250+440, 41+150+220), // G4
        QPointF(261+50, 41+250+440),  // A1
        QPointF(261+150+220, 41+250+440), // D1
        QPointF(261+250+440, 41+250+440), // G1

        QPointF(361+50, 141+50),    // B6
        QPointF(361+150+120, 141+50),  // D6
        QPointF(361+250+240, 141+50),  // F6
        QPointF(361+50, 141+150+120),  // B4
        QPointF(361+250+240, 141+150+120),  // F4
        QPointF(361+50, 141+250+240),  // B2
        QPointF(361+150+120, 141+250+240),  // D2
        QPointF(361+250+240, 141+250+240),  // F2

        QPointF(461+50, 241+50),    // C5
        QPointF(461+150+20, 241+50),  // D5
        QPointF(461+250+40, 241+50),  // E5
        QPointF(461+50, 241+150+20),  // C4
        QPointF(461+250+40, 241+150+20),  // E4
        QPointF(461+50, 241+250+40),  // C3
        QPointF(461+150+20, 241+250+40),  // D3
        QPointF(461+250+40, 241+250+40),  // E3
    };
}

void UIGameBoard::paintEvent(QPaintEvent* event) {
    QPainter painter(this);

    painter.fillRect(rect(), QBrush(Qt::lightGray));

    int gameAreaLeft = 280;
    int gameAreaTop = 60;
    int gameAreaWidth = 700;
    int gameAreaHeight = 700;

    QRect gameAreaRect(gameAreaLeft, gameAreaTop, gameAreaWidth, gameAreaHeight);

    int borderThickness = 20;
    QRect outerRect(gameAreaLeft - borderThickness, gameAreaTop - borderThickness,
                    gameAreaWidth + 2 * borderThickness, gameAreaHeight + 2 * borderThickness);

    QLinearGradient gradient(outerRect.left(), 0, outerRect.right(), 0);
    for (float i = 0.0; i <= 1.0; i += 0.2) {
        gradient.setColorAt(i, QColor(152,82,49));
        gradient.setColorAt(i + 0.1, QColor(169,102,73));
    }

    painter.setBrush(QBrush(gradient));

    painter.drawRect(outerRect);

    painter.setBrush(QBrush(Qt::transparent));
    painter.drawRect(gameAreaRect);

    QPen gridPen(Qt::gray, 1);
    painter.setPen(gridPen);

    int gridSpacing = 20;

    for (int x = 0; x <= width(); x += gridSpacing) {
        painter.drawLine(x, 0, x, height());
    }

    for (int y = 0; y <= height(); y += gridSpacing) {
        painter.drawLine(0, y, width(), y);
    }

    painter.setBrush(QBrush(Qt::black));
    painter.setPen(QPen(Qt::black, 2));

    int radius = 9, x1 = 261, y1 = 41, x2 = 361, y2 = 141, x3 = 461, y3 = 241;

    QPointF A7(x1+50, y1+50);
    QPointF D7(x1+150+220, y1+50);
    QPointF G7(x1+250+440, y1+50);
    QPointF A4(x1+50, y1+150+220);
    QPointF G4(x1+250+440, y1+150+220);
    QPointF A1(x1+50, y1+250+440);
    QPointF D1(x1+150+220, y1+250+440);
    QPointF G1(x1+250+440, y1+250+440);

    QPointF B6(x2+50, y2+50);
    QPointF D6(x2+150+120, y2+50);
    QPointF F6(x2+250+240, y2+50);
    QPointF B4(x2+50, y2+150+120);
    QPointF F4(x2+250+240, y2+150+120);
    QPointF B2(x2+50, y2+250+240);
    QPointF D2(x2+150+120, y2+250+240);
    QPointF F2(x2+250+240, y2+250+240);

    QPointF C5(x3+50, y3+50);
    QPointF D5(x3+150+20, y3+50);
    QPointF E5(x3+250+40, y3+50);
    QPointF C4(x3+50, y3+150+20);
    QPointF E4(x3+250+40, y3+150+20);
    QPointF C3(x3+50, y3+250+40);
    QPointF D3(x3+150+20, y3+250+40);
    QPointF E3(x3+250+40, y3+250+40);

    painter.drawEllipse(A7, radius, radius);
    painter.drawEllipse(D7, radius, radius);
    painter.drawEllipse(G7, radius, radius);
    painter.drawEllipse(A4, radius, radius);
    painter.drawEllipse(G4, radius, radius);
    painter.drawEllipse(A1, radius, radius);
    painter.drawEllipse(D1, radius, radius);
    painter.drawEllipse(G1, radius, radius);

    painter.drawEllipse(B6, radius, radius);
    painter.drawEllipse(D6, radius, radius);
    painter.drawEllipse(F6, radius, radius);
    painter.drawEllipse(B4, radius, radius);
    painter.drawEllipse(F4, radius, radius);
    painter.drawEllipse(B2, radius, radius);
    painter.drawEllipse(D2, radius, radius);
    painter.drawEllipse(F2, radius, radius);

    painter.drawEllipse(C5, radius, radius);
    painter.drawEllipse(D5, radius, radius);
    painter.drawEllipse(E5, radius, radius);
    painter.drawEllipse(C4, radius, radius);
    painter.drawEllipse(E4, radius, radius);
    painter.drawEllipse(C3, radius, radius);
    painter.drawEllipse(D3, radius, radius);
    painter.drawEllipse(E3, radius, radius);

    painter.drawLine(A7, D7);
    painter.drawLine(D7, G7);
    painter.drawLine(G7, G4);
    painter.drawLine(G4, G1);
    painter.drawLine(G1, D1);
    painter.drawLine(D1, A1);
    painter.drawLine(A1, A4);
    painter.drawLine(A4, A7);

    painter.drawLine(B6, D6);
    painter.drawLine(D6, F6);
    painter.drawLine(F6, F4);
    painter.drawLine(F4, F2);
    painter.drawLine(F2, D2);
    painter.drawLine(D2, B2);
    painter.drawLine(B2, B4);
    painter.drawLine(B4, B6);

    painter.drawLine(C5, D5);
    painter.drawLine(D5, E5);
    painter.drawLine(E5, E4);
    painter.drawLine(E4, E3);
    painter.drawLine(E3, D3);
    painter.drawLine(D3, C3);
    painter.drawLine(C3, C4);
    painter.drawLine(C4, C5);

    painter.drawLine(D7, D6);
    painter.drawLine(D6, D5);
    painter.drawLine(A4, B4);
    painter.drawLine(B4, C4);
    painter.drawLine(E4, F4);
    painter.drawLine(F4, G4);
    painter.drawLine(D3, D2);
    painter.drawLine(D2, D1);

    for (const auto& coords : pieceCoords) {
        QRadialGradient gradient(coords, pieceRadius);
        gradient.setColorAt(0, QColor(251,219,184));
        gradient.setColorAt(0.5, QColor(218,180,143));
        gradient.setColorAt(0.8, QColor(251,219,184));
        gradient.setColorAt(0.9, QColor(218,180,143));
        gradient.setColorAt(1, QColor(174,138,102));
        painter.setBrush(gradient);
        painter.setPen(Qt::NoPen);
        painter.drawEllipse(coords, pieceRadius, pieceRadius);
    }
}

void UIGameBoard::mousePressEvent(QMouseEvent* event) {
    for (int i = 0; i < pieceCoords.size(); i++)
        if (QLineF(event->pos(), pieceCoords[i]).length() <= pieceRadius) {
            draggedPieceIndex = i;
            dragOffset = event->pos() - pieceCoords[i];
            return;
        }
}

void UIGameBoard::mouseMoveEvent(QMouseEvent* event) {
    if (draggedPieceIndex != -1) {
        pieceCoords[draggedPieceIndex] = event->pos() - dragOffset;
        update();
    }
}

void UIGameBoard::mouseReleaseEvent(QMouseEvent* event) {
    if (draggedPieceIndex != -1) {
        pieceCoords[draggedPieceIndex] = findClosestSlot(pieceCoords[draggedPieceIndex]);
        draggedPieceIndex = -1;
        update();
    }
}

QPointF UIGameBoard::findClosestSlot(QPointF position) {
    QPointF closestDot = slotPositions[0];
    qreal minDistance = QLineF(position, closestDot).length();

    for (const auto&    dot : slotPositions) {
        qreal distance = QLineF(position, dot).length();
        if (distance < minDistance) {
            closestDot = dot;
            minDistance = distance;
        }
    }

    return closestDot;
}