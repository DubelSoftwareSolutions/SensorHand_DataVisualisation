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
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *Glove3DLayout;
    QTableWidget *GyroTable;
    QTabWidget *FingersTab;
    QWidget *tabThumb;
    QWidget *tabIndex;
    QWidget *tabMiddle;
    QWidget *tabRing;
    QWidget *tab_6;
    QComboBox *CommunicationBox;
    QSlider *GloveSizeSlider;
    QLabel *CommunicationLabel;
    QLabel *GloveSizeLabel;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *StartStopButton;
    QLabel *label;
    QSlider *CameraOrientationSlider;
    QLabel *CameraOrientationLabel;
    QLineEdit *CameraOrientationLineEdit;
    QLineEdit *GloveSizeLineEdit;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(821, 624);
        QPalette palette;
        QBrush brush(QColor(215, 240, 80, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        MainWindow->setPalette(palette);
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
        GyroTable->setGeometry(QRect(10, 450, 121, 111));
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
        FingersTab->setGeometry(QRect(140, 450, 471, 111));
        tabThumb = new QWidget();
        tabThumb->setObjectName(QStringLiteral("tabThumb"));
        FingersTab->addTab(tabThumb, QString());
        tabIndex = new QWidget();
        tabIndex->setObjectName(QStringLiteral("tabIndex"));
        FingersTab->addTab(tabIndex, QString());
        tabMiddle = new QWidget();
        tabMiddle->setObjectName(QStringLiteral("tabMiddle"));
        FingersTab->addTab(tabMiddle, QString());
        tabRing = new QWidget();
        tabRing->setObjectName(QStringLiteral("tabRing"));
        FingersTab->addTab(tabRing, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        FingersTab->addTab(tab_6, QString());
        CommunicationBox = new QComboBox(centralWidget);
        CommunicationBox->setObjectName(QStringLiteral("CommunicationBox"));
        CommunicationBox->setGeometry(QRect(768, 400, 45, 20));
        GloveSizeSlider = new QSlider(centralWidget);
        GloveSizeSlider->setObjectName(QStringLiteral("GloveSizeSlider"));
        GloveSizeSlider->setGeometry(QRect(640, 30, 160, 22));
        GloveSizeSlider->setValue(50);
        GloveSizeSlider->setOrientation(Qt::Horizontal);
        CommunicationLabel = new QLabel(centralWidget);
        CommunicationLabel->setObjectName(QStringLiteral("CommunicationLabel"));
        CommunicationLabel->setGeometry(QRect(650, 400, 111, 16));
        GloveSizeLabel = new QLabel(centralWidget);
        GloveSizeLabel->setObjectName(QStringLiteral("GloveSizeLabel"));
        GloveSizeLabel->setGeometry(QRect(650, 10, 51, 16));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(610, 240, 201, 131));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        StartStopButton = new QPushButton(gridLayoutWidget);
        StartStopButton->setObjectName(QStringLiteral("StartStopButton"));
        QPalette palette1;
        QBrush brush1(QColor(215, 240, 90, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        StartStopButton->setPalette(palette1);

        gridLayout->addWidget(StartStopButton, 0, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(670, 210, 100, 20));
        label->setMaximumSize(QSize(100, 20));
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);
        CameraOrientationSlider = new QSlider(centralWidget);
        CameraOrientationSlider->setObjectName(QStringLiteral("CameraOrientationSlider"));
        CameraOrientationSlider->setGeometry(QRect(640, 80, 160, 22));
        CameraOrientationSlider->setMaximum(360);
        CameraOrientationSlider->setValue(180);
        CameraOrientationSlider->setOrientation(Qt::Horizontal);
        CameraOrientationLabel = new QLabel(centralWidget);
        CameraOrientationLabel->setObjectName(QStringLiteral("CameraOrientationLabel"));
        CameraOrientationLabel->setGeometry(QRect(650, 60, 91, 16));
        CameraOrientationLineEdit = new QLineEdit(centralWidget);
        CameraOrientationLineEdit->setObjectName(QStringLiteral("CameraOrientationLineEdit"));
        CameraOrientationLineEdit->setGeometry(QRect(750, 60, 41, 20));
        CameraOrientationLineEdit->setMaxLength(3);
        GloveSizeLineEdit = new QLineEdit(centralWidget);
        GloveSizeLineEdit->setObjectName(QStringLiteral("GloveSizeLineEdit"));
        GloveSizeLineEdit->setGeometry(QRect(750, 10, 41, 20));
        GloveSizeLineEdit->setMaxLength(3);
        GloveSizeLineEdit->setCursorMoveStyle(Qt::LogicalMoveStyle);
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

        retranslateUi(MainWindow);

        FingersTab->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
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

        FingersTab->setTabText(FingersTab->indexOf(tabThumb), QApplication::translate("MainWindow", "Thumb", Q_NULLPTR));
        FingersTab->setTabText(FingersTab->indexOf(tabIndex), QApplication::translate("MainWindow", "Index", Q_NULLPTR));
        FingersTab->setTabText(FingersTab->indexOf(tabMiddle), QApplication::translate("MainWindow", "Middle", Q_NULLPTR));
        FingersTab->setTabText(FingersTab->indexOf(tabRing), QApplication::translate("MainWindow", "Ring", Q_NULLPTR));
        FingersTab->setTabText(FingersTab->indexOf(tab_6), QApplication::translate("MainWindow", "Pinky", Q_NULLPTR));
        CommunicationBox->clear();
        CommunicationBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "USB", Q_NULLPTR)
         << QApplication::translate("MainWindow", "BT", Q_NULLPTR)
        );
        CommunicationLabel->setText(QApplication::translate("MainWindow", "Communicaion through", Q_NULLPTR));
        GloveSizeLabel->setText(QApplication::translate("MainWindow", "Glove Size", Q_NULLPTR));
        StartStopButton->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Measurements", Q_NULLPTR));
        CameraOrientationLabel->setText(QApplication::translate("MainWindow", "Camera orientation:", Q_NULLPTR));
        CameraOrientationLineEdit->setText(QApplication::translate("MainWindow", "180", Q_NULLPTR));
        GloveSizeLineEdit->setText(QApplication::translate("MainWindow", "50", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
        menuView->setTitle(QApplication::translate("MainWindow", "View", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
