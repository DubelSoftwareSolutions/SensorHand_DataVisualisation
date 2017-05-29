/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExport_data;
    QAction *actionMeasurements;
    QAction *actionConfiguration;
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *Glove3DLayout;
    QTableWidget *GyroTable;
    QTabWidget *FingersTab;
    QWidget *tabThumb;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *tabIndex;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QWidget *tabMiddle;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QWidget *tabRing;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QWidget *tab_6;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QWidget *MeasurementWidget;
    QGridLayout *MeasurementLayout;
    QComboBox *CommunicationBox;
    QLabel *CommunicationLabel;
    QPushButton *StartStopButton;
    QLabel *label;
    QWidget *ConfigurationWidget;
    QFormLayout *ConfigurationLayout;
    QLabel *GloveSizeLabel;
    QLineEdit *GloveZoomLineEdit;
    QSlider *GloveZoomSlider;
    QLabel *CameraOrientationLabel;
    QLineEdit *CameraOrientationLineEdit;
    QSlider *CameraOrientationSlider;
    QWidget *chartLayout;
    QFormLayout *formLayout;
    QLabel *label_17;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuTools;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(821, 624);
        MainWindow->setMinimumSize(QSize(600, 400));
        QPalette palette;
        QBrush brush(QColor(215, 240, 80, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        MainWindow->setPalette(palette);
        actionExport_data = new QAction(MainWindow);
        actionExport_data->setObjectName(QStringLiteral("actionExport_data"));
        actionMeasurements = new QAction(MainWindow);
        actionMeasurements->setObjectName(QStringLiteral("actionMeasurements"));
        actionConfiguration = new QAction(MainWindow);
        actionConfiguration->setObjectName(QStringLiteral("actionConfiguration"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 611, 421));
        Glove3DLayout = new QVBoxLayout(verticalLayoutWidget);
        Glove3DLayout->setSpacing(6);
        Glove3DLayout->setContentsMargins(11, 11, 11, 11);
        Glove3DLayout->setObjectName(QStringLiteral("Glove3DLayout"));
        Glove3DLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        Glove3DLayout->setContentsMargins(0, 0, 0, 0);
        GyroTable = new QTableWidget(centralWidget);
        if (GyroTable->columnCount() < 1)
            GyroTable->setColumnCount(1);
        QFont font;
        font.setPointSize(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        GyroTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (GyroTable->rowCount() < 3)
            GyroTable->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        GyroTable->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        GyroTable->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        GyroTable->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        GyroTable->setItem(0, 0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        GyroTable->setItem(1, 0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        GyroTable->setItem(2, 0, __qtablewidgetitem6);
        GyroTable->setObjectName(QStringLiteral("GyroTable"));
        GyroTable->setGeometry(QRect(0, 460, 121, 111));
        GyroTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        GyroTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        GyroTable->setAutoScroll(true);
        GyroTable->setAutoScrollMargin(10);
        GyroTable->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        GyroTable->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);
        GyroTable->setShowGrid(true);
        GyroTable->setGridStyle(Qt::SolidLine);
        FingersTab = new QTabWidget(centralWidget);
        FingersTab->setObjectName(QStringLiteral("FingersTab"));
        FingersTab->setGeometry(QRect(140, 460, 481, 111));
        tabThumb = new QWidget();
        tabThumb->setObjectName(QStringLiteral("tabThumb"));
        label_2 = new QLabel(tabThumb);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 20, 47, 13));
        label_3 = new QLabel(tabThumb);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 40, 47, 13));
        label_4 = new QLabel(tabThumb);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 60, 47, 13));
        FingersTab->addTab(tabThumb, QString());
        tabIndex = new QWidget();
        tabIndex->setObjectName(QStringLiteral("tabIndex"));
        label_5 = new QLabel(tabIndex);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 20, 47, 13));
        label_6 = new QLabel(tabIndex);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 60, 47, 13));
        label_7 = new QLabel(tabIndex);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 40, 47, 13));
        FingersTab->addTab(tabIndex, QString());
        tabMiddle = new QWidget();
        tabMiddle->setObjectName(QStringLiteral("tabMiddle"));
        label_8 = new QLabel(tabMiddle);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 20, 47, 13));
        label_9 = new QLabel(tabMiddle);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 60, 47, 13));
        label_10 = new QLabel(tabMiddle);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 40, 47, 13));
        FingersTab->addTab(tabMiddle, QString());
        tabRing = new QWidget();
        tabRing->setObjectName(QStringLiteral("tabRing"));
        label_11 = new QLabel(tabRing);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 20, 47, 13));
        label_12 = new QLabel(tabRing);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 60, 47, 13));
        label_13 = new QLabel(tabRing);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 40, 47, 13));
        FingersTab->addTab(tabRing, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        label_14 = new QLabel(tab_6);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 20, 47, 13));
        label_15 = new QLabel(tab_6);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(10, 60, 47, 13));
        label_16 = new QLabel(tab_6);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(10, 40, 47, 13));
        FingersTab->addTab(tab_6, QString());
        MeasurementWidget = new QWidget(centralWidget);
        MeasurementWidget->setObjectName(QStringLiteral("MeasurementWidget"));
        MeasurementWidget->setGeometry(QRect(620, 120, 191, 211));
        MeasurementLayout = new QGridLayout(MeasurementWidget);
        MeasurementLayout->setSpacing(6);
        MeasurementLayout->setContentsMargins(11, 11, 11, 11);
        MeasurementLayout->setObjectName(QStringLiteral("MeasurementLayout"));
        CommunicationBox = new QComboBox(MeasurementWidget);
        CommunicationBox->setObjectName(QStringLiteral("CommunicationBox"));
        CommunicationBox->setMaximumSize(QSize(50, 16777215));

        MeasurementLayout->addWidget(CommunicationBox, 6, 2, 1, 1);

        CommunicationLabel = new QLabel(MeasurementWidget);
        CommunicationLabel->setObjectName(QStringLiteral("CommunicationLabel"));

        MeasurementLayout->addWidget(CommunicationLabel, 6, 0, 1, 2);

        StartStopButton = new QPushButton(MeasurementWidget);
        StartStopButton->setObjectName(QStringLiteral("StartStopButton"));
        QPalette palette1;
        QBrush brush1(QColor(215, 240, 90, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        StartStopButton->setPalette(palette1);

        MeasurementLayout->addWidget(StartStopButton, 2, 1, 1, 1);

        label = new QLabel(MeasurementWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(100, 20));
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);

        MeasurementLayout->addWidget(label, 1, 1, 1, 1);

        ConfigurationWidget = new QWidget(centralWidget);
        ConfigurationWidget->setObjectName(QStringLiteral("ConfigurationWidget"));
        ConfigurationWidget->setGeometry(QRect(620, 10, 191, 104));
        ConfigurationLayout = new QFormLayout(ConfigurationWidget);
        ConfigurationLayout->setSpacing(6);
        ConfigurationLayout->setContentsMargins(11, 11, 11, 11);
        ConfigurationLayout->setObjectName(QStringLiteral("ConfigurationLayout"));
        GloveSizeLabel = new QLabel(ConfigurationWidget);
        GloveSizeLabel->setObjectName(QStringLiteral("GloveSizeLabel"));

        ConfigurationLayout->setWidget(0, QFormLayout::LabelRole, GloveSizeLabel);

        GloveZoomLineEdit = new QLineEdit(ConfigurationWidget);
        GloveZoomLineEdit->setObjectName(QStringLiteral("GloveZoomLineEdit"));
        GloveZoomLineEdit->setMaximumSize(QSize(30, 16777215));
        GloveZoomLineEdit->setMaxLength(3);
        GloveZoomLineEdit->setCursorMoveStyle(Qt::LogicalMoveStyle);

        ConfigurationLayout->setWidget(0, QFormLayout::FieldRole, GloveZoomLineEdit);

        GloveZoomSlider = new QSlider(ConfigurationWidget);
        GloveZoomSlider->setObjectName(QStringLiteral("GloveZoomSlider"));
        GloveZoomSlider->setMinimum(0);
        GloveZoomSlider->setMaximum(100);
        GloveZoomSlider->setValue(50);
        GloveZoomSlider->setOrientation(Qt::Horizontal);

        ConfigurationLayout->setWidget(1, QFormLayout::SpanningRole, GloveZoomSlider);

        CameraOrientationLabel = new QLabel(ConfigurationWidget);
        CameraOrientationLabel->setObjectName(QStringLiteral("CameraOrientationLabel"));

        ConfigurationLayout->setWidget(2, QFormLayout::LabelRole, CameraOrientationLabel);

        CameraOrientationLineEdit = new QLineEdit(ConfigurationWidget);
        CameraOrientationLineEdit->setObjectName(QStringLiteral("CameraOrientationLineEdit"));
        CameraOrientationLineEdit->setMaximumSize(QSize(30, 16777215));
        CameraOrientationLineEdit->setMaxLength(3);

        ConfigurationLayout->setWidget(2, QFormLayout::FieldRole, CameraOrientationLineEdit);

        CameraOrientationSlider = new QSlider(ConfigurationWidget);
        CameraOrientationSlider->setObjectName(QStringLiteral("CameraOrientationSlider"));
        CameraOrientationSlider->setMaximum(360);
        CameraOrientationSlider->setValue(180);
        CameraOrientationSlider->setOrientation(Qt::Horizontal);

        ConfigurationLayout->setWidget(3, QFormLayout::SpanningRole, CameraOrientationSlider);

        chartLayout = new QWidget(centralWidget);
        chartLayout->setObjectName(QStringLiteral("chartLayout"));
        chartLayout->setGeometry(QRect(630, 420, 171, 141));
        formLayout = new QFormLayout(chartLayout);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_17 = new QLabel(chartLayout);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::FieldRole, label_17);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 821, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionExport_data);
        menuView->addAction(actionConfiguration);
        menuView->addAction(actionMeasurements);

        retranslateUi(MainWindow);

        FingersTab->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionExport_data->setText(QApplication::translate("MainWindow", "Export data", Q_NULLPTR));
        actionMeasurements->setText(QApplication::translate("MainWindow", "Measurements", Q_NULLPTR));
        actionConfiguration->setText(QApplication::translate("MainWindow", "Configuration", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = GyroTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "G", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = GyroTable->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = GyroTable->verticalHeaderItem(1);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Y", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = GyroTable->verticalHeaderItem(2);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Z", Q_NULLPTR));

        const bool __sortingEnabled = GyroTable->isSortingEnabled();
        GyroTable->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem4 = GyroTable->item(0, 0);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = GyroTable->item(1, 0);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = GyroTable->item(2, 0);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        GyroTable->setSortingEnabled(__sortingEnabled);

        label_2->setText(QApplication::translate("MainWindow", "angle 1", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "angle 2", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "angle 3", Q_NULLPTR));
        FingersTab->setTabText(FingersTab->indexOf(tabThumb), QApplication::translate("MainWindow", "Thumb", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "angle 1", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "angle 3", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "angle 2", Q_NULLPTR));
        FingersTab->setTabText(FingersTab->indexOf(tabIndex), QApplication::translate("MainWindow", "Index", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "angle 1", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "angle 3", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "angle 2", Q_NULLPTR));
        FingersTab->setTabText(FingersTab->indexOf(tabMiddle), QApplication::translate("MainWindow", "Middle", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "angle 1", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "angle 3", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "angle 2", Q_NULLPTR));
        FingersTab->setTabText(FingersTab->indexOf(tabRing), QApplication::translate("MainWindow", "Ring", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "angle 1", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "angle 3", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "angle 2", Q_NULLPTR));
        FingersTab->setTabText(FingersTab->indexOf(tab_6), QApplication::translate("MainWindow", "Pinky", Q_NULLPTR));
        CommunicationBox->clear();
        CommunicationBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "USB", Q_NULLPTR)
         << QApplication::translate("MainWindow", "BT", Q_NULLPTR)
        );
        CommunicationLabel->setText(QApplication::translate("MainWindow", "Communicaion through", Q_NULLPTR));
        StartStopButton->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Measurements", Q_NULLPTR));
        GloveSizeLabel->setText(QApplication::translate("MainWindow", "Glove Zoom", Q_NULLPTR));
        GloveZoomLineEdit->setText(QApplication::translate("MainWindow", "50", Q_NULLPTR));
        CameraOrientationLabel->setText(QApplication::translate("MainWindow", "Camera orientation:", Q_NULLPTR));
        CameraOrientationLineEdit->setText(QApplication::translate("MainWindow", "180", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "Preassure", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
        menuView->setTitle(QApplication::translate("MainWindow", "View", Q_NULLPTR));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
