#ifndef GEOMETRY_WIDGET_H
#define GEOMETRY_WIDGET_H

#include <QMouseEvent>
#include <QObject>
#include <QResizeEvent>
#include <QWheelEvent>
#include <QWidget>

#include "Include/LayoutData.hpp"
#include "Include/PaintData.hpp"

struct Scale {
    uint32_t initialW {};
    uint32_t initialH {};
    double initial { 1.0 };
    double current { 1.0 };
};

struct Mouse {
    QPoint triggerPos {};
};

struct Axes {
    QPoint pos {};
    QPoint moveIn {};
};

class GeometryWidget : public QWidget {
    Q_OBJECT

    lds::LayoutData* layout {};
    lds::Coord min { std::numeric_limits<int32_t>::max(), std::numeric_limits<int32_t>::max() };
    lds::Coord max { 0, 0 };
    Scale m_scale {};
    Mouse m_mouse {};
    Axes m_axes {};

public:
    GeometryWidget(lds::LayoutData* t_layout, QWidget* t_parent = nullptr);

protected:
    void paintEvent(QPaintEvent* t_event);
    void resizeEvent(QResizeEvent* t_event);
    void wheelEvent(QWheelEvent* t_event);
    void mousePressEvent(QMouseEvent* t_event);
    void mouseMoveEvent(QMouseEvent* t_event);
    void mouseReleaseEvent(QMouseEvent* event);

private:
    void rescaleToSize();
    void paintGrid(QPainter* t_painter);
    void paintPath(lds::Path* t_path, QPainter* t_painter);
    void paintPolygon(lds::Polygon* t_polygon, QPainter* t_painter);
    void paintRectangle(lds::Rectangle* t_rectangle, QPainter* t_painter);
    void paintReference(lds::Reference* t_reference, QPainter* t_painter);

public slots:
    void updateLayer(const uint16_t& t_key, const bool& t_isChecked);
};

#endif