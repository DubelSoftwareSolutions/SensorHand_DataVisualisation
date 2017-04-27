#include "includes.h"

using namespace QtDataVisualization;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*MainWindow w;
    w.show();*/

    Hand hand;

    QVector<QVector3D> vec=hand.GetJointPoints();
    for(auto Current: vec)
        std::cout<<Current.x()<<'|'<<Current.y()<<'|'<<Current.z()<<std::endl;

    Q3DScatter scatter;
    scatter.setFlags(scatter.flags() ^ Qt::FramelessWindowHint);

    QScatter3DSeries *series = new QScatter3DSeries;
    QScatterDataArray data;

    for(auto current : vec)
        data<<current;

    series->dataProxy()->addItems(data);
    scatter.addSeries(series);

    scatter.show();
    return a.exec();
}
