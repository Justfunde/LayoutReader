#include <QApplication>

#include "Include/GeometryWidget.hpp"
#include "Include/LayerSelectWidget.hpp"
#include "Include/LayoutReader.hpp"
#include "Include/LayoutWidget.hpp"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    std::string_view fileName = "F:/layout-reader/Libs/LayoutReader/Test/MskFiles/4.MSK";

    LayoutWidget layoutWidget(fileName);

    layoutWidget.resize(1280, 720);
    layoutWidget.show();

    return app.exec();
}