#include "includes.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QVector<Joint> joints;
    for(int i=0;i<6;++i)
        joints.push_back(Joint());
    ManipulatorRotational man(joints,QVector3D(),0);
    return a.exec();
}
