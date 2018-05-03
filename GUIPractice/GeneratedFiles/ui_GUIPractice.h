/********************************************************************************
** Form generated from reading UI file 'GUIPractice.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIPRACTICE_H
#define UI_GUIPRACTICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUIPracticeClass
{
public:
    QAction *actionDirectory;
    QAction *actionExit;
    QAction *actionHistogram;
    QAction *actionResults;
    QAction *actionOutput_Directory;
    QAction *actionLog_Location;
    QAction *actionLog_History;
    QAction *actionWelcome;
    QAction *actionUser_Manual;
    QAction *actionAbout;
    QAction *actionImage;
    QAction *actionAll;
    QAction *actionHistogram_2;
    QAction *actionCustomHistogram;
    QAction *actionPop_Contents;
    QAction *actionSpot_Mode;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *inputDisplay;
    QLabel *histDisplay;
    QPushButton *previousImage;
    QComboBox *sortOptions;
    QPushButton *nextImage;
    QTextBrowser *textBrowser;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuSelect;
    QMenu *menuExport;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GUIPracticeClass)
    {
        if (GUIPracticeClass->objectName().isEmpty())
            GUIPracticeClass->setObjectName(QStringLiteral("GUIPracticeClass"));
        GUIPracticeClass->resize(1280, 736);
        GUIPracticeClass->setMinimumSize(QSize(0, 0));
        GUIPracticeClass->setMaximumSize(QSize(16777215, 16777215));
        GUIPracticeClass->setAutoFillBackground(true);
        actionDirectory = new QAction(GUIPracticeClass);
        actionDirectory->setObjectName(QStringLiteral("actionDirectory"));
        actionExit = new QAction(GUIPracticeClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionHistogram = new QAction(GUIPracticeClass);
        actionHistogram->setObjectName(QStringLiteral("actionHistogram"));
        actionResults = new QAction(GUIPracticeClass);
        actionResults->setObjectName(QStringLiteral("actionResults"));
        actionOutput_Directory = new QAction(GUIPracticeClass);
        actionOutput_Directory->setObjectName(QStringLiteral("actionOutput_Directory"));
        actionLog_Location = new QAction(GUIPracticeClass);
        actionLog_Location->setObjectName(QStringLiteral("actionLog_Location"));
        actionLog_History = new QAction(GUIPracticeClass);
        actionLog_History->setObjectName(QStringLiteral("actionLog_History"));
        actionWelcome = new QAction(GUIPracticeClass);
        actionWelcome->setObjectName(QStringLiteral("actionWelcome"));
        actionUser_Manual = new QAction(GUIPracticeClass);
        actionUser_Manual->setObjectName(QStringLiteral("actionUser_Manual"));
        actionAbout = new QAction(GUIPracticeClass);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionImage = new QAction(GUIPracticeClass);
        actionImage->setObjectName(QStringLiteral("actionImage"));
        actionAll = new QAction(GUIPracticeClass);
        actionAll->setObjectName(QStringLiteral("actionAll"));
        actionHistogram_2 = new QAction(GUIPracticeClass);
        actionHistogram_2->setObjectName(QStringLiteral("actionHistogram_2"));
        actionCustomHistogram = new QAction(GUIPracticeClass);
        actionCustomHistogram->setObjectName(QStringLiteral("actionCustomHistogram"));
        actionPop_Contents = new QAction(GUIPracticeClass);
        actionPop_Contents->setObjectName(QStringLiteral("actionPop_Contents"));
        actionSpot_Mode = new QAction(GUIPracticeClass);
        actionSpot_Mode->setObjectName(QStringLiteral("actionSpot_Mode"));
        centralWidget = new QWidget(GUIPracticeClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setAutoFillBackground(true);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        inputDisplay = new QLabel(centralWidget);
        inputDisplay->setObjectName(QStringLiteral("inputDisplay"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(inputDisplay->sizePolicy().hasHeightForWidth());
        inputDisplay->setSizePolicy(sizePolicy);
        inputDisplay->setMinimumSize(QSize(0, 0));
        inputDisplay->setMaximumSize(QSize(16777215, 16777215));
        inputDisplay->setBaseSize(QSize(847, 1380));
        inputDisplay->setAutoFillBackground(false);
        inputDisplay->setFrameShape(QFrame::Box);
        inputDisplay->setFrameShadow(QFrame::Sunken);
        inputDisplay->setLineWidth(1);
        inputDisplay->setScaledContents(true);

        gridLayout->addWidget(inputDisplay, 0, 0, 3, 1);

        histDisplay = new QLabel(centralWidget);
        histDisplay->setObjectName(QStringLiteral("histDisplay"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(10);
        sizePolicy1.setHeightForWidth(histDisplay->sizePolicy().hasHeightForWidth());
        histDisplay->setSizePolicy(sizePolicy1);
        histDisplay->setMinimumSize(QSize(0, 0));
        histDisplay->setMaximumSize(QSize(16777215, 16777215));
        histDisplay->setBaseSize(QSize(1722, 660));
        histDisplay->setAutoFillBackground(false);
        histDisplay->setFrameShape(QFrame::Box);
        histDisplay->setFrameShadow(QFrame::Sunken);
        histDisplay->setLineWidth(1);
        histDisplay->setScaledContents(true);

        gridLayout->addWidget(histDisplay, 0, 1, 1, 3);

        previousImage = new QPushButton(centralWidget);
        previousImage->setObjectName(QStringLiteral("previousImage"));
        previousImage->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(2);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(previousImage->sizePolicy().hasHeightForWidth());
        previousImage->setSizePolicy(sizePolicy2);
        previousImage->setMaximumSize(QSize(16777215, 16777215));
        previousImage->setBaseSize(QSize(0, 0));
        previousImage->setAutoFillBackground(true);
        previousImage->setAutoDefault(false);
        previousImage->setFlat(true);

        gridLayout->addWidget(previousImage, 1, 1, 1, 1);

        sortOptions = new QComboBox(centralWidget);
        sortOptions->setObjectName(QStringLiteral("sortOptions"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(sortOptions->sizePolicy().hasHeightForWidth());
        sortOptions->setSizePolicy(sizePolicy3);
        sortOptions->setAutoFillBackground(true);

        gridLayout->addWidget(sortOptions, 1, 2, 1, 1);

        nextImage = new QPushButton(centralWidget);
        nextImage->setObjectName(QStringLiteral("nextImage"));
        sizePolicy2.setHeightForWidth(nextImage->sizePolicy().hasHeightForWidth());
        nextImage->setSizePolicy(sizePolicy2);
        nextImage->setMaximumSize(QSize(16777215, 16777215));
        nextImage->setAutoFillBackground(true);
        nextImage->setAutoDefault(false);
        nextImage->setFlat(true);

        gridLayout->addWidget(nextImage, 1, 3, 1, 1);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        sizePolicy1.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(12);
        textBrowser->setFont(font);
        textBrowser->setAutoFillBackground(false);
        textBrowser->setFrameShape(QFrame::Box);

        gridLayout->addWidget(textBrowser, 2, 1, 1, 3);

        GUIPracticeClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GUIPracticeClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 22));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(10);
        menuBar->setFont(font1);
        menuBar->setAutoFillBackground(true);
        menuBar->setNativeMenuBar(false);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuFile->setFont(font1);
        menuFile->setAutoFillBackground(true);
        menuSelect = new QMenu(menuFile);
        menuSelect->setObjectName(QStringLiteral("menuSelect"));
        menuSelect->setFont(font1);
        menuSelect->setAutoFillBackground(true);
        menuExport = new QMenu(menuFile);
        menuExport->setObjectName(QStringLiteral("menuExport"));
        menuExport->setFont(font1);
        menuExport->setAutoFillBackground(true);
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuEdit->setFont(font1);
        menuEdit->setAutoFillBackground(true);
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuView->setFont(font1);
        menuView->setAutoFillBackground(true);
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuHelp->setFont(font1);
        menuHelp->setAutoFillBackground(true);
        GUIPracticeClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(GUIPracticeClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setAutoFillBackground(true);
        GUIPracticeClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(menuSelect->menuAction());
        menuFile->addAction(menuExport->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuSelect->addAction(actionDirectory);
        menuSelect->addAction(actionImage);
        menuExport->addAction(actionHistogram);
        menuExport->addAction(actionResults);
        menuExport->addSeparator();
        menuExport->addAction(actionAll);
        menuEdit->addAction(actionCustomHistogram);
        menuEdit->addSeparator();
        menuEdit->addAction(actionLog_Location);
        menuView->addAction(actionLog_History);
        menuView->addAction(actionPop_Contents);
        menuView->addSeparator();
        menuView->addAction(actionSpot_Mode);
        menuHelp->addAction(actionWelcome);
        menuHelp->addAction(actionUser_Manual);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout);

        retranslateUi(GUIPracticeClass);
        QObject::connect(actionExit, SIGNAL(triggered()), GUIPracticeClass, SLOT(close()));

        previousImage->setDefault(true);
        nextImage->setDefault(true);


        QMetaObject::connectSlotsByName(GUIPracticeClass);
    } // setupUi

    void retranslateUi(QMainWindow *GUIPracticeClass)
    {
        GUIPracticeClass->setWindowTitle(QApplication::translate("GUIPracticeClass", "CV | Glass Report", Q_NULLPTR));
        actionDirectory->setText(QApplication::translate("GUIPracticeClass", "Directory", Q_NULLPTR));
        actionExit->setText(QApplication::translate("GUIPracticeClass", "Exit", Q_NULLPTR));
        actionHistogram->setText(QApplication::translate("GUIPracticeClass", "Histogram", Q_NULLPTR));
        actionResults->setText(QApplication::translate("GUIPracticeClass", "Results", Q_NULLPTR));
        actionOutput_Directory->setText(QApplication::translate("GUIPracticeClass", "Output Directory", Q_NULLPTR));
        actionLog_Location->setText(QApplication::translate("GUIPracticeClass", "Log Location", Q_NULLPTR));
        actionLog_History->setText(QApplication::translate("GUIPracticeClass", "Log History", Q_NULLPTR));
        actionWelcome->setText(QApplication::translate("GUIPracticeClass", "Welcome", Q_NULLPTR));
        actionUser_Manual->setText(QApplication::translate("GUIPracticeClass", "User Manual", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("GUIPracticeClass", "About", Q_NULLPTR));
        actionImage->setText(QApplication::translate("GUIPracticeClass", "Image", Q_NULLPTR));
        actionAll->setText(QApplication::translate("GUIPracticeClass", "All", Q_NULLPTR));
        actionHistogram_2->setText(QApplication::translate("GUIPracticeClass", "Histogram", Q_NULLPTR));
        actionCustomHistogram->setText(QApplication::translate("GUIPracticeClass", "Customise Histogram", Q_NULLPTR));
        actionPop_Contents->setText(QApplication::translate("GUIPracticeClass", "Pop Contents", Q_NULLPTR));
        actionSpot_Mode->setText(QApplication::translate("GUIPracticeClass", "Spot Mode", Q_NULLPTR));
        inputDisplay->setText(QString());
        histDisplay->setText(QString());
        previousImage->setText(QApplication::translate("GUIPracticeClass", "Previous", Q_NULLPTR));
        sortOptions->clear();
        sortOptions->insertItems(0, QStringList()
         << QApplication::translate("GUIPracticeClass", "Default Sort", Q_NULLPTR)
         << QApplication::translate("GUIPracticeClass", "Spot Sort", Q_NULLPTR)
         << QApplication::translate("GUIPracticeClass", "Film Sort", Q_NULLPTR)
         << QApplication::translate("GUIPracticeClass", "Aesthetic Sort", Q_NULLPTR)
        );
        nextImage->setText(QApplication::translate("GUIPracticeClass", "Next", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("GUIPracticeClass", "File", Q_NULLPTR));
        menuSelect->setTitle(QApplication::translate("GUIPracticeClass", "Select", Q_NULLPTR));
        menuExport->setTitle(QApplication::translate("GUIPracticeClass", "Export", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("GUIPracticeClass", "Edit", Q_NULLPTR));
        menuView->setTitle(QApplication::translate("GUIPracticeClass", "View", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("GUIPracticeClass", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GUIPracticeClass: public Ui_GUIPracticeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIPRACTICE_H
