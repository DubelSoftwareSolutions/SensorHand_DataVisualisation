#include "includes.h"

Scene::Scene(Qt3DCore::QEntity *rootEntity):
    m_rootEntity(rootEntity), m_Hand3DModel(rootEntity)
{

}

Scene::~Scene()
{

}
