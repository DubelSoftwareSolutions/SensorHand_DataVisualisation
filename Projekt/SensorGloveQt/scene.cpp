#include "includes.h"

//Scene::Scene(Qt3DCore::QEntity *rootEntity,MainWindow& p_mainWindow):
Scene::Scene(Qt3DCore::QEntity *rootEntity):
    m_rootEntity(rootEntity), m_Hand3DModel(rootEntity), m_CameraHeight(8), m_CameraDistance(30)
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
    //p_mainWindow.AddWidgetToGlove3DLayout(widget);

    input = new Qt3DInput::QInputAspect;
    view->registerAspect(input);

    //Camera
    cameraEntity = view->camera();
    cameraEntity->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    cameraEntity->setPosition(QVector3D(0,m_CameraHeight,m_CameraDistance)); //10,10,25
    cameraEntity->setUpVector(QVector3D(0,1,0));
    cameraEntity->setViewCenter(QVector3D(0,m_CameraHeight,0));

    camController = new Qt3DExtras::QFirstPersonCameraController(rootEntity);
    camController->setCamera(cameraEntity);

    //Light
    lightEntity = new Qt3DCore::QEntity(rootEntity);
    light = new Qt3DRender::QPointLight(lightEntity);
    light->setColor(QColor("white"));
    light->setIntensity(1);
    lightEntity->addComponent(light);
    lightTransform = new Qt3DCore::QTransform(lightEntity);
    lightTransform->setTranslation(QVector3D(0,m_CameraHeight,m_CameraDistance));
    lightEntity->addComponent(lightTransform);

    //Light 2
    lightEntity2 = new Qt3DCore::QEntity(rootEntity);
    light2 = new Qt3DRender::QPointLight(lightEntity2);
    light2->setColor(QColor("white"));
    light2->setIntensity(1);
    lightEntity2->addComponent(light2);
    lightTransform2 = new Qt3DCore::QTransform(lightEntity2);
    lightTransform2->setTranslation(QVector3D(0,m_CameraHeight,-m_CameraDistance));
    lightEntity2->addComponent(lightTransform2);

    view->setRootEntity(rootEntity);
}

Scene::~Scene()
{

}

void Scene::SetHandRotation(float p_Roll, float p_Pitch, float p_Yaw)
{
    float CameraPositionX = m_CameraHeight*(-cos(Roll)*sin(Yaw)+sin(Roll)*sin(Pitch)*cos(Yaw)) + m_CameraDistance*sin(Roll)*cos(Pitch);   //h*sin(Roll)*sin(Pitch) + R*sin(Roll)*cos(Pitch);
    float CameraPositionY = m_CameraHeight*cos(Pitch)*cos(Yaw) - m_CameraDistance*sin(Pitch);                                             //h*cos(Pitch) - R*sin(Pitch);
    float CameraPositionZ = m_CameraHeight*(sin(Roll)*sin(Yaw)+cos(Roll)*sin(Pitch)*cos(Yaw)) + m_CameraDistance*cos(Roll)*cos(Pitch);    //h*cos(Roll)*sin(Pitch) + R*cos(Roll)*cos(Pitch);

    cameraEntity->setUpVector(QVector3D(sin(Yaw),cos(Yaw),0));
    cameraEntity->setPosition(QVector3D(x,y,z));

    lightTransform->setTranslation(QVector3D(x,y,z));
    lightTransform2->setTranslation(QVector3D(-x,-y,-z));
}

void Scene::SetHandTransformation(QVector<QVector<float> > p_FingerAngles)
{
    m_Hand3DModel.SetFingerJoints(p_FingerAngles);
}

void Scene::SetHandFingertipValues(QVector<int> p_NewValues)
{
    m_Hand3DModel.SetFingertipValues(p_NewValues);
}
