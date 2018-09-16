#include "widget.h"
#include <QApplication>
#include "my_personal_tools.h"
#include <QtDebug>
#include <QScrollArea>
#include "gradientcolor.h"

void addRandomSources(vector<PointSource *> &pointSources, const GridSettings &myGrid)
{
    pointSources.push_back(new PointSource(100,100,0,90));

//// random sources
//    int nSources=2;
//    int min_x = static_cast<int>(myGrid.getLeft());
//    int max_x = static_cast<int>(myGrid.getRight());
//    int min_y = static_cast<int>(myGrid.getTop());
//    int max_y = static_cast<int>(myGrid.getBottom());
//    int min_z = -5;
//    int max_z = 5;
//    qDebug()<<myGrid.getTop();

//    for(int i=0; i<nSources; i++){
//        pointSources.push_back(new PointSource(MyPersonalTools::intRandom(min_x, max_x),
//                                               MyPersonalTools::intRandom(-min_y, -max_y),
//                                               MyPersonalTools::intRandom(min_z, max_z),
//                                               MyPersonalTools::intRandom(80, 85)));
//    }
}



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    GridSettings myGrid;
    ReceiversGrid receivers;
    vector<PointSource *> pointSources;

    QImage *image;
    image = new QImage(1260,468, QImage::Format_ARGB32);

    image->fill(Qt::transparent);
    QPainter painter(image);

    myGrid.setRect(QRectF(50, 20, 220, 220));
    myGrid.setDeltaX(1);
    myGrid.setDeltaY(1);
    myGrid.setInterpolationFactor(5);
    receivers.setGrid(myGrid);

    MyPersonalTools::calculateNoiseFromSources(&pointSources, &receivers);

    double zoom = 1;
    if(zoom<0.1){
        zoom=0.1; // limit the zoomm to positive values greater than 0.1
    }
    painter.translate(myGrid.getRect().bottomLeft());

    qreal side = qMin(painter.device()->width(), painter.device()->height());

    painter.scale(zoom*side/painter.device()->width(), -zoom*side/painter.device()->height());




    image->save("../test.png", "PNG");

    w.show();
    return a.exec();

}




