#include<iostream>
#include<QDataStream>
#include<QFile>
#include "scene.h"

Scene::Scene(Qt3DCore::QEntity *rootEntity) : m_rootEntity(rootEntity)
{
    Qt3DExtras::QCylinderMesh *cylinder = new Qt3DExtras::QCylinderMesh();
    cylinder->setRadius(1);
    cylinder->setLength(4);
    cylinder->setRings(100);
    cylinder->setSlices(20);

    Qt3DExtras::QPhongMaterial *cylinderMaterial = new Qt3DExtras::QPhongMaterial();
    cylinderMaterial->setDiffuse(QColor(255,173,96));

    Qt3DCore::QTransform *cylinderTransform = new Qt3DCore::QTransform();
    cylinderTransform->setScale(1.0);
    QMatrix4x4 matrix;

    matrix.rotate(5,QVector3D(1,0,0));
    matrix.translate(QVector3D(0,cylinder->length()/2,0));
    matrix.rotate(12,QVector3D(0,0,1));

    cylinderTransform->setMatrix(matrix);

    m_Cylinder1Entity = new Qt3DCore::QEntity(m_rootEntity);
    m_Cylinder1Entity->addComponent(cylinder);
    m_Cylinder1Entity->addComponent(cylinderMaterial);
    m_Cylinder1Entity->addComponent(cylinderTransform);

    Qt3DExtras::QCylinderMesh *cylinder2 = new Qt3DExtras::QCylinderMesh();
    cylinder2->setRadius(1);
    cylinder2->setLength(8);
    cylinder2->setRings(100);
    cylinder2->setSlices(20);

    Qt3DCore::QTransform *cylinderTransform2 = new Qt3DCore::QTransform();
    cylinderTransform2->setScale(1.0);

    matrix.translate(QVector3D(0,cylinder->length()/2,0));
    matrix.rotate(45,QVector3D(0,0,1));
    matrix.translate(QVector3D(0,cylinder2->length()/2,0));

    cylinderTransform2->setMatrix(matrix);

    m_Cylinder2Entity = new Qt3DCore::QEntity(m_rootEntity);
    m_Cylinder2Entity->addComponent(cylinder2);
    m_Cylinder2Entity->addComponent(cylinderMaterial);
    m_Cylinder2Entity->addComponent(cylinderTransform2);

    matrix.translate(QVector3D(1,0,1));
    cylinderTransform2->setMatrix(matrix);
/*
    matrix.translate(QVector3D(0,cylinder->length()/2,0));
    matrix.rotate(45,QVector3D(0,0,1));
    matrix.translate(QVector3D(0,cylinder->length()/2,0));

    Qt3DCore::QTransform *cylinderTransform3 = new Qt3DCore::QTransform();
    cylinderTransform3->setScale(1.0);
    cylinderTransform3->setMatrix(matrix);

    m_Cylinder3Entity = new Qt3DCore::QEntity(m_rootEntity);
    m_Cylinder3Entity->addComponent(cylinder);
    m_Cylinder3Entity->addComponent(cylinderMaterial);
    m_Cylinder3Entity->addComponent(cylinderTransform3);


    //drugi palec
    QMatrix4x4 matrix2;
    Qt3DCore::QTransform *cylinderTransform_2 = new Qt3DCore::QTransform();
    cylinderTransform_2->setScale(1.0);

    matrix2.translate(QVector3D(0,0,-2));
    matrix2.rotate(-5,QVector3D(1,0,0));
    matrix2.translate(QVector3D(0,cylinder->length()/2,0));
    matrix2.rotate(60,QVector3D(0,0,1));

    cylinderTransform_2->setMatrix(matrix2);

    m_Cylinder1Entity2 = new Qt3DCore::QEntity(m_rootEntity);
    m_Cylinder1Entity2->addComponent(cylinder);
    m_Cylinder1Entity2->addComponent(cylinderMaterial);
    m_Cylinder1Entity2->addComponent(cylinderTransform_2);

    Qt3DCore::QTransform *cylinderTransform22 = new Qt3DCore::QTransform();
    cylinderTransform22->setScale(1.0);

    matrix2.translate(QVector3D(0,cylinder->length()/2,0));
    matrix2.rotate(60,QVector3D(0,0,1));
    matrix2.translate(QVector3D(0,cylinder->length()/2,0));

    cylinderTransform22->setMatrix(matrix2);

    m_Cylinder2Entity2 = new Qt3DCore::QEntity(m_rootEntity);
    m_Cylinder2Entity2->addComponent(cylinder);
    m_Cylinder2Entity2->addComponent(cylinderMaterial);
    m_Cylinder2Entity2->addComponent(cylinderTransform22);

    Qt3DCore::QTransform *cylinderTransform32 = new Qt3DCore::QTransform();
    cylinderTransform32->setScale(1.0);

    matrix2.translate(QVector3D(0,cylinder->length()/2,0));
    matrix2.rotate(80,QVector3D(0,0,1));
    matrix2.translate(QVector3D(0,cylinder->length()/2,0));

    cylinderTransform32->setMatrix(matrix2);

    m_Cylinder3Entity2 = new Qt3DCore::QEntity(m_rootEntity);
    m_Cylinder3Entity2->addComponent(cylinder);
    m_Cylinder3Entity2->addComponent(cylinderMaterial);
    m_Cylinder3Entity2->addComponent(cylinderTransform32);*/
}

Scene::~Scene()
{
}

void Scene::EnableCylinders()
{
}
