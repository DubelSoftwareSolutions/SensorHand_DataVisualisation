#include "includes.h"

Scene::Scene(Qt3DCore::QEntity *rootEntity,MainWindow& p_mainWindow):
    m_rootEntity(rootEntity), m_Hand3DModel(rootEntity)
{
    view = new Qt3DExtras::Qt3DWindow();
    view->defaultFrameGraph()->setClearColor(QColor(175,175,175));
    container = QWidget::createWindowContainer(view);
    QSize screenSize = view->screen()->size();
    container->setMinimumSize(QSize(200,100));
    container->setMaximumSize(screenSize);

    widget = new QWidget;
    hLayout = new QHBoxLayout(widget);
    vLayout = new QVBoxLayout();
    vLayout->setAlignment(Qt::AlignTop);
    hLayout->addWidget(container,1);
    hLayout->addLayout(vLayout);

    widget->setWindowTitle(QString("SensorGloveQt"));
    p_mainWindow.AddWidgetToGlove3DLayout(widget);

    input = new Qt3DInput::QInputAspect;
    view->registerAspect(input);

    //Camera
    cameraEntity = view->camera();
    cameraEntity->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    cameraEntity->setPosition(QVector3D(10,10,25));
    cameraEntity->setUpVector(QVector3D(0,1,0));
    cameraEntity->setViewCenter(QVector3D(0,10,0));

    camController = new Qt3DExtras::QFirstPersonCameraController(rootEntity);
    camController->setCamera(cameraEntity);

    //Light
    lightEntity = new Qt3DCore::QEntity(rootEntity);
    light = new Qt3DRender::QPointLight(lightEntity);
    light->setColor(QColor("white"));
    light->setIntensity(1);
    lightEntity->addComponent(light);
    lightTransform = new Qt3DCore::QTransform(lightEntity);
    lightTransform->setTranslation(cameraEntity->position());
    lightEntity->addComponent(lightTransform);

    //Light 2
    lightEntity2 = new Qt3DCore::QEntity(rootEntity);
    light2 = new Qt3DRender::QPointLight(lightEntity2);
    light2->setColor(QColor("white"));
    light2->setIntensity(1);
    lightEntity2->addComponent(light2);
    lightTransform2 = new Qt3DCore::QTransform(lightEntity2);
    lightTransform2->setTranslation(QVector3D(0,0,-20));
    lightEntity2->addComponent(lightTransform2);

    view->setRootEntity(rootEntity);
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
