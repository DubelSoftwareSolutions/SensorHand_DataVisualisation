#include "includes.h"

Fingertip::Fingertip(float p_fingertipValue,
                     Qt3DCore::QEntity *p_rootEntity,
                     Joint *p_PrevJoint) :
    m_rootEntity(p_rootEntity), m_TransformMatrix(p_PrevJoint->TransformMatrix()), m_fingertipValue(p_fingertipValue)
{
    Qt3DExtras::QSphereMesh *sphereMesh = new Qt3DExtras::QSphereMesh();
    sphereMesh->setRings(SPHERE_RINGS_COUNT);
    sphereMesh->setSlices(SPHERE_SLICES_COUNT);
    sphereMesh->setRadius(p_fingertipValue);

    Qt3DExtras::QPhongMaterial *sphereMaterial = new Qt3DExtras::QPhongMaterial();
    sphereMaterial->setDiffuse(QColor("green"));

    // Sphere mesh transform
    m_sphereTransform = new Qt3DCore::QTransform();

    m_sphereTransform->setScale(1);
    m_TransformMatrix.translate(QVector3D(0,p_PrevJoint->length()/2+p_fingertipValue/2,0));

    m_sphereTransform->setMatrix(m_TransformMatrix);

    // Sphere
    m_sphereEntity = new Qt3DCore::QEntity(m_rootEntity);
    m_sphereEntity->addComponent(sphereMesh);
    m_sphereEntity->addComponent(sphereMaterial);
    m_sphereEntity->addComponent(m_sphereTransform);
}

void Fingertip::TransformFingertip(Joint *p_prevJoint)
{
    m_TransformMatrix = p_prevJoint->TransformMatrix();
    m_TransformMatrix.translate(QVector3D(0,p_prevJoint->length()/2+m_fingertipValue/2,0));
    m_sphereTransform->setMatrix(m_TransformMatrix);
}

void Fingertip::setFingertipValue(float p_newValue)
{
    m_TransformMatrix.translate(QVector3D(0,(p_newValue-m_fingertipValue)/2,0));
    m_sphereTransform->setMatrix(m_TransformMatrix);
    m_sphereTransform->setScale(p_newValue/m_fingertipValue);
    m_fingertipValue = p_newValue;
}

float Fingertip::getFingertipValue() const
{
    return m_fingertipValue;
}
