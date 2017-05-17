#include "includes.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity();
    Scene *scene3D = new Scene(rootEntity,w);

    QVector<double> thumbAngles(2,60);
    QVector<double> indexAngles(3,10);
    QVector<double> middleAngles(3,90);
    QVector<double> ringAngles(3,90);
    QVector<double> pinkyAngles(3,10);
    QVector<QVector<double>> Angles;
    Angles.push_back(thumbAngles);
    Angles.push_back(indexAngles);
    Angles.push_back(middleAngles);
    Angles.push_back(ringAngles);
    Angles.push_back(pinkyAngles);

    QVector<float> fingertips(5,2);

    //scene3D->SetHandTransformation(Angles);
    //scene3D->SetHandFingertipValues(fingertips);

    return a.exec();
}
