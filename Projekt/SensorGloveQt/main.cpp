#include "includes.h"

using namespace QtDataVisualization;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*MainWindow w;
    w.show();*/

    QVector<Joint> joints;
    for(int i=0;i<3;++i)
        joints.push_back(Joint(12));

    ManipulatorRotational man(joints);

    QVector<double> coords=QVector<double>(3);
    coords[0]=90;
    coords[1]=0;
    coords[2]=0;

    man.SetInternalCoordinates(coords);

    QVector<QVector3D> vec=man.GetPointsInGlobal();
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
