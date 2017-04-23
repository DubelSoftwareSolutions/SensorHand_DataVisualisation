#include "includes.h"

int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();*/

    QVector<Joint> joints;
    for(int i=0;i<3;++i)
        joints.push_back(Joint(12));

    ManipulatorRotational man(joints);

    QVector<double> coords=QVector<double>(3);
    coords[0]=-90;
    coords[1]=30;
    coords[2]=60;

    man.SetInternalCoordinates(coords);

    QVector<QVector3D> vec=man.GetPointsInGlobal();
    for(auto Current: vec)
        cout<<Current.x()<<'|'<<Current.y()<<'|'<<Current.z()<<endl;
    //return a.exec();
    return 0;
}
