/********************************************************************************
** Form generated from reading UI file 'outImageDisplay.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUTIMAGEDISPLAY_H
#define UI_OUTIMAGEDISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_outImageDisplay
{
public:
    QGridLayout *gridLayout;
    QLabel *inputDisplay;
    QLabel *histDisplay;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *outImageDisplay)
    {
        if (outImageDisplay->objectName().isEmpty())
            outImageDisplay->setObjectName(QStringLiteral("outImageDisplay"));
        outImageDisplay->resize(764, 472);
        gridLayout = new QGridLayout(outImageDisplay);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        inputDisplay = new QLabel(outImageDisplay);
        inputDisplay->setObjectName(QStringLiteral("inputDisplay"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
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

        gridLayout->addWidget(inputDisplay, 0, 0, 2, 1);

        histDisplay = new QLabel(outImageDisplay);
        histDisplay->setObjectName(QStringLiteral("histDisplay"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(2);
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

        gridLayout->addWidget(histDisplay, 0, 1, 1, 1);

        textBrowser = new QTextBrowser(outImageDisplay);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        sizePolicy1.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(12);
        textBrowser->setFont(font);
        textBrowser->setAutoFillBackground(false);
        textBrowser->setFrameShape(QFrame::Box);

        gridLayout->addWidget(textBrowser, 1, 1, 1, 1);


        retranslateUi(outImageDisplay);

        QMetaObject::connectSlotsByName(outImageDisplay);
    } // setupUi

    void retranslateUi(QDialog *outImageDisplay)
    {
        outImageDisplay->setWindowTitle(QApplication::translate("outImageDisplay", "CV | Pop Display", Q_NULLPTR));
        inputDisplay->setText(QString());
        histDisplay->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class outImageDisplay: public Ui_outImageDisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTIMAGEDISPLAY_H
