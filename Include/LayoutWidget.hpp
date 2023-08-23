#ifndef LAYOUT_WIDGET_H
#define LAYOUT_WIDGET_H

#include <QWidget>
#include <string_view>

class LayoutWidget : public QWidget {
    Q_OBJECT

public:
    LayoutWidget(std::string_view t_fileName, QWidget* t_parent = nullptr);
};

#endif