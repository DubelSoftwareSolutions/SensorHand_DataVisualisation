#include "includes.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity();
    Scene *scene3D = new Scene(rootEntity);
    w.getScene(scene3D);
    QVector<float> thumbAngles(2,60);
    QVector<float> indexAngles(3,10);
    QVector<float> middleAngles(3,90);
    QVector<float> ringAngles(3,90);
    QVector<float> pinkyAngles(3,10);
    QVector<QVector<float>> Angles;
    Angles.push_back(thumbAngles);
    Angles.push_back(indexAngles);
    Angles.push_back(middleAngles);
    Angles.push_back(ringAngles);
    Angles.push_back(pinkyAngles);

    QVector<int> fingertips(5,4095);

    //scene3D->SetHandTransformation(Angles);
    //scene3D->SetHandFingertipValues(fingertips);

    return a.exec();
}
