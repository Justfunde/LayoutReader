#ifndef PAINT_DATA_H
#define PAINT_DATA_H

#include <QBrush>
#include <QPen>
#include <unordered_map>

struct PaintData {
    QColor penColor {};
    QColor brushColor {};
    Qt::BrushStyle brushStyle {};
    bool isActive {};

    PaintData(QColor t_penColor, QColor t_brushColor, Qt::BrushStyle t_brushStyle = Qt::SolidPattern, bool t_isActive = true)
        : penColor(t_penColor)
        , brushColor(t_brushColor)
        , brushStyle(t_brushStyle)
        , isActive(t_isActive) {};
};

static std::unordered_map<uint16_t, PaintData> paintData {
    { 1, PaintData(QColor(0, 94, 0), QColor(0, 94, 0, 125), Qt::Dense4Pattern) },
    { 16, PaintData(QColor(0, 94, 0), QColor(0, 94, 0, 125)) },
    { 17, PaintData(QColor(120, 112, 0), QColor(120, 112, 0, 125)) },
    { 13, PaintData(QColor(238, 20, 0), QColor(238, 20, 0, 125)) },
    { 19, PaintData(QColor(255, 255, 255), QColor(255, 255, 255, 125)) },
    { 23, PaintData(QColor(0, 47, 240), QColor(0, 47, 240, 125), Qt::Dense6Pattern) },
    { 27, PaintData(QColor(0, 9, 168), QColor(0, 9, 168, 125)) },
    { 34, PaintData(QColor(56, 60, 113), QColor(56, 60, 113, 125), Qt::BDiagPattern) },
    { 36, PaintData(QColor(102, 155, 3), QColor(102, 155, 3, 125), Qt::FDiagPattern) },
    { 53, PaintData(QColor(76, 73, 134), QColor(76, 73, 134, 125), Qt::HorPattern) },
    { 55, PaintData(QColor(127, 127, 127), QColor(127, 127, 127, 125), Qt::DiagCrossPattern) },
};

#endif