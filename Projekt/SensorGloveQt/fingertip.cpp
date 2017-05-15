#include "includes.h"

Fingertip::Fingertip(float p_fingertipValue,
                     Qt3DCore::QEntity *p_rootEntity,
                     Joint *p_PrevJoint) :
    m_rootEntity(p_rootEntity), m_TransformMatrix(p_PrevJoint->TransformMatrix())
{
    Qt3DExtras::QSphereMesh *sphereMesh = new Qt3DExtras::QSphereMesh();
    sphereMesh->setRings(SPHERE_RINGS_COUNT);
    sphereMesh->setSlices(SPHERE_SLICES_COUNT);
    sphereMesh->setRadius(p_fingertipValue);

    Qt3DExtras::QPhongMaterial *sphereMaterial = new Qt3DExtras::QPhongMaterial();
    sphereMaterial->setDiffuse(QColor("green"));

    // Sphere mesh transform
    Qt3DCore::QTransform *sphereTransform = new Qt3DCore::QTransform();

    sphereTransform->setScale(1);
    m_TransformMatrix.translate(QVector3D(0,p_PrevJoint->length()/2+p_fingertipValue/2,0));

    sphereTransform->setMatrix(m_TransformMatrix);

    // Sphere
    m_sphereEntity = new Qt3DCore::QEntity(m_rootEntity);
    m_sphereEntity->addComponent(sphereMesh);
    m_sphereEntity->addComponent(sphereMaterial);
    m_sphereEntity->addComponent(sphereTransform);
}
