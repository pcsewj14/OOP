/********************************************************************************
** Form generated from reading UI file 'yootmarbleengine.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YOOTMARBLEENGINE_H
#define UI_YOOTMARBLEENGINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_yootMarbleEngineClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *yootMarbleEngineClass)
    {
        if (yootMarbleEngineClass->objectName().isEmpty())
            yootMarbleEngineClass->setObjectName(QStringLiteral("yootMarbleEngineClass"));
        yootMarbleEngineClass->resize(600, 400);
        menuBar = new QMenuBar(yootMarbleEngineClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        yootMarbleEngineClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(yootMarbleEngineClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        yootMarbleEngineClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(yootMarbleEngineClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        yootMarbleEngineClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(yootMarbleEngineClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        yootMarbleEngineClass->setStatusBar(statusBar);

        retranslateUi(yootMarbleEngineClass);

        QMetaObject::connectSlotsByName(yootMarbleEngineClass);
    } // setupUi

    void retranslateUi(QMainWindow *yootMarbleEngineClass)
    {
        yootMarbleEngineClass->setWindowTitle(QApplication::translate("yootMarbleEngineClass", "yootMarbleEngine", 0));
    } // retranslateUi

};

namespace Ui {
    class yootMarbleEngineClass: public Ui_yootMarbleEngineClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YOOTMARBLEENGINE_H
