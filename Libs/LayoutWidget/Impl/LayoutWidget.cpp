#include <QHBoxLayout>

#include "Include/GeometryWidget.hpp"
#include "Include/LayerSelectWidget.hpp"
#include "Include/LayoutReader.hpp"
#include "Include/LayoutWidget.hpp"

LayoutWidget::LayoutWidget(std::string_view& t_fileName, QWidget* t_parent)
    : QWidget(t_parent)
{
    lds::LayoutData* layout = new lds::LayoutData();
    LayoutReader* p_reader = GetReader(std::wstring(t_fileName.begin(), t_fileName.end()));
    p_reader->Read(layout);

    QHBoxLayout* hbox = new QHBoxLayout(this);

    GeometryWidget* geometryWidget = new GeometryWidget(layout, this);
    LayerSelectWidget* layerSelectWidget = new LayerSelectWidget(this);

    connect(layerSelectWidget, LayerSelectWidget::sendLayer, geometryWidget, GeometryWidget::updateLayer);

    geometryWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layerSelectWidget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);

    geometryWidget->setContentsMargins(0, 0, 0, 0);
    layerSelectWidget->setContentsMargins(0, 0, 0, 0);

    hbox->addWidget(geometryWidget);
    hbox->addWidget(layerSelectWidget);
    hbox->setContentsMargins(0, 0, 0, 0);

    setLayout(hbox);
}
