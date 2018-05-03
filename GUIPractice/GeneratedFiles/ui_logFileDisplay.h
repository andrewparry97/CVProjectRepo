/********************************************************************************
** Form generated from reading UI file 'logFileDisplay.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGFILEDISPLAY_H
#define UI_LOGFILEDISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_logFileDisplay
{
public:
    QGridLayout *gridLayout;
    QTextBrowser *logDisplay;

    void setupUi(QDialog *logFileDisplay)
    {
        if (logFileDisplay->objectName().isEmpty())
            logFileDisplay->setObjectName(QStringLiteral("logFileDisplay"));
        logFileDisplay->resize(642, 467);
        gridLayout = new QGridLayout(logFileDisplay);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        logDisplay = new QTextBrowser(logFileDisplay);
        logDisplay->setObjectName(QStringLiteral("logDisplay"));

        gridLayout->addWidget(logDisplay, 0, 0, 1, 1);


        retranslateUi(logFileDisplay);

        QMetaObject::connectSlotsByName(logFileDisplay);
    } // setupUi

    void retranslateUi(QDialog *logFileDisplay)
    {
        logFileDisplay->setWindowTitle(QApplication::translate("logFileDisplay", "CV | Log File Display", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class logFileDisplay: public Ui_logFileDisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGFILEDISPLAY_H
