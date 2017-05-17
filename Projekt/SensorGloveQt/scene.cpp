#include "includes.h"

Scene::Scene(Qt3DCore::QEntity *rootEntity):
    m_rootEntity(rootEntity), m_Hand3DModel(rootEntity)
{
}

Scene::~Scene()
{

}

void Scene::SetHandTransformation(QVector<QVector<double> > p_FingerAngles)
{
    m_Hand3DModel.TransformFingerAngles(p_FingerAngles);
}

void Scene::SetHandFingertipValues(QVector<float> p_NewValues)
{
    m_Hand3DModel.SetFingertipValues(p_NewValues);
}
