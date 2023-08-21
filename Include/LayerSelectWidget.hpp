#ifndef LAYER_SELECT_WIDGET_H
#define LAYER_SELECT_WIDGET_H

#include <QCheckBox>
#include <QString>
#include <QWidget>

#include "Include/PaintData.hpp"

class BrushIcon : public QWidget {
    Q_OBJECT

    QColor brushColor {};
    Qt::BrushStyle brushStyle {};

public:
    BrushIcon(QColor t_brushColor, Qt::BrushStyle t_brushStyle, QWidget* t_parent = nullptr);

protected:
    void paintEvent(QPaintEvent* t_event);
};

class CheckBox : public QWidget {
    Q_OBJECT

    uint16_t m_number {};

public:
    CheckBox(uint16_t t_number, QString t_text, QColor t_brushColor, Qt::BrushStyle t_brushStyle, QWidget* t_parent = nullptr);

public slots:
signals:
    void sendChecked(const uint16_t& t_key, const bool& t_isChecked);
};

class LayerSelectWidget : public QWidget {
    Q_OBJECT

public:
    LayerSelectWidget(QWidget* t_parent = nullptr);

public slots:
signals:
    void sendLayer(const uint16_t& t_key, const bool& t_isChecked);
};

#endif