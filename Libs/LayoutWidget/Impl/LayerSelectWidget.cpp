#include <QHBoxLayout>
#include <QLabel>
#include <QPainter>
#include <QVBoxLayout>

#include "Include/LayerSelectWidget.hpp"

BrushIcon::BrushIcon(QColor t_brushColor, Qt::BrushStyle t_brushStyle, QWidget* t_parent)
    : brushColor(t_brushColor)
    , brushStyle(t_brushStyle)
    , QWidget(t_parent) {};

void BrushIcon::paintEvent(QPaintEvent* t_event)
{
    Q_UNUSED(t_event);

    QPainter* painter = new QPainter();

    painter->begin(this);
    painter->setBrush(QBrush(brushColor, brushStyle));
    painter->drawRect(QRect(0, 0, 20, 20));
    painter->end();
}

CheckBox::CheckBox(uint16_t t_number, QString t_text, QColor t_brushColor, Qt::BrushStyle t_brushStyle, QWidget* t_parent)
    : m_number(t_number)
    , QWidget(t_parent)
{
    QHBoxLayout* hbox = new QHBoxLayout(this);
    QCheckBox* checkBox = new QCheckBox("", this);
    BrushIcon* brushIcon = new BrushIcon(t_brushColor, t_brushStyle, this);
    QLabel* label = new QLabel(t_text, this);

    checkBox->setCheckable(Qt::Checked);
    checkBox->setChecked(true);
    brushIcon->setMinimumSize(QSize(21, 21));
    label->setFont(QFont("Purisa", 9));

    hbox->addWidget(label, 0);
    hbox->addWidget(brushIcon, 0);
    hbox->addWidget(checkBox, 0);
    hbox->setSpacing(10);
    hbox->setContentsMargins(0, 5, 0, 5);

    connect(checkBox, QCheckBox::toggled, this, CheckBox::setChecked);

    setLayout(hbox);
}

void CheckBox::setChecked(const bool& t_isChecked)
{
    sendChecked(m_number);
}

LayerSelectWidget::LayerSelectWidget(QWidget* t_parent)
    : QWidget(t_parent)
{
    QVBoxLayout* vbox = new QVBoxLayout(this);

    for (auto& [first, second] : paintData) {
        CheckBox* checkBox = new CheckBox(first, "metal1", second.brushColor, second.brushStyle, this);

        connect(checkBox, CheckBox::sendChecked, this, LayerSelectWidget::changeLayer);

        vbox->addWidget(checkBox, 0, Qt::AlignLeft | Qt::AlignVCenter);
    }

    vbox->addStretch();

    setLayout(vbox);
}

void LayerSelectWidget::changeLayer(const uint16_t& t_key)
{
    sendLayer(t_key);
}