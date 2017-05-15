#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include <Qt3DCore/QEntity>
#include "joint.h"
#include "finger.h"
#include "hand.h"

class Scene : public QObject
{
    Q_OBJECT
private:
    Qt3DCore::QEntity *m_rootEntity;
    Hand m_Hand3DModel;

public:
    explicit Scene(Qt3DCore::QEntity *rootEntity);
    ~Scene();

signals:

public slots:
};

#endif // SCENE_H
