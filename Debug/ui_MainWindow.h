/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox;
    QPushButton *AqcuireInitialPosition;
    QPushButton *AqcuireTargetPosition;
    QPushButton *AqcuireCurrentBallPosition;
    QPushButton *FinishedHole;
    QTextBrowser *textBrowser;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(777, 474);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(comboBox);

        AqcuireInitialPosition = new QPushButton(centralWidget);
        AqcuireInitialPosition->setObjectName(QStringLiteral("AqcuireInitialPosition"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(AqcuireInitialPosition->sizePolicy().hasHeightForWidth());
        AqcuireInitialPosition->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(AqcuireInitialPosition);

        AqcuireTargetPosition = new QPushButton(centralWidget);
        AqcuireTargetPosition->setObjectName(QStringLiteral("AqcuireTargetPosition"));
        sizePolicy1.setHeightForWidth(AqcuireTargetPosition->sizePolicy().hasHeightForWidth());
        AqcuireTargetPosition->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(AqcuireTargetPosition);

        AqcuireCurrentBallPosition = new QPushButton(centralWidget);
        AqcuireCurrentBallPosition->setObjectName(QStringLiteral("AqcuireCurrentBallPosition"));
        sizePolicy1.setHeightForWidth(AqcuireCurrentBallPosition->sizePolicy().hasHeightForWidth());
        AqcuireCurrentBallPosition->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(AqcuireCurrentBallPosition);

        FinishedHole = new QPushButton(centralWidget);
        FinishedHole->setObjectName(QStringLiteral("FinishedHole"));
        sizePolicy.setHeightForWidth(FinishedHole->sizePolicy().hasHeightForWidth());
        FinishedHole->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(FinishedHole);


        horizontalLayout->addLayout(verticalLayout);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        horizontalLayout->addWidget(textBrowser);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Clean", nullptr));
        AqcuireInitialPosition->setText(QApplication::translate("MainWindow", "Abschlagposition Erfassen", nullptr));
        AqcuireTargetPosition->setText(QApplication::translate("MainWindow", "Zielrichtung Erfassen", nullptr));
        AqcuireCurrentBallPosition->setText(QApplication::translate("MainWindow", "Ballposition erfassen", nullptr));
        FinishedHole->setText(QApplication::translate("MainWindow", "Loch Beendet", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
