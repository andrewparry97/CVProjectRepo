/********************************************************************************
** Form generated from reading UI file 'histogramSettingsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTOGRAMSETTINGSDIALOG_H
#define UI_HISTOGRAMSETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_histogramSettingsDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *optionPercentage;
    QLabel *label_2;
    QCheckBox *optionScalePI;
    QLabel *label_3;
    QLineEdit *optionScalePXI;
    QLabel *label_4;
    QLineEdit *optionDataScale;
    QLabel *label_5;
    QCheckBox *optionLineGraph;
    QLabel *label_6;
    QCheckBox *optionSmoothedLine;
    QLabel *label_7;
    QLineEdit *optionThreshold;
    QLabel *label_8;
    QCheckBox *optionShowThreshold;
    QHBoxLayout *horizontalLayout;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *histogramSettingsDialog)
    {
        if (histogramSettingsDialog->objectName().isEmpty())
            histogramSettingsDialog->setObjectName(QStringLiteral("histogramSettingsDialog"));
        histogramSettingsDialog->resize(595, 200);
        gridLayout = new QGridLayout(histogramSettingsDialog);
        gridLayout->setSpacing(4);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(4, 4, 4, 4);
        label = new QLabel(histogramSettingsDialog);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        optionPercentage = new QComboBox(histogramSettingsDialog);
        optionPercentage->setObjectName(QStringLiteral("optionPercentage"));

        gridLayout->addWidget(optionPercentage, 0, 1, 1, 1);

        label_2 = new QLabel(histogramSettingsDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        optionScalePI = new QCheckBox(histogramSettingsDialog);
        optionScalePI->setObjectName(QStringLiteral("optionScalePI"));

        gridLayout->addWidget(optionScalePI, 1, 1, 1, 1);

        label_3 = new QLabel(histogramSettingsDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 1, 2, 1, 1);

        optionScalePXI = new QLineEdit(histogramSettingsDialog);
        optionScalePXI->setObjectName(QStringLiteral("optionScalePXI"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(optionScalePXI->sizePolicy().hasHeightForWidth());
        optionScalePXI->setSizePolicy(sizePolicy);

        gridLayout->addWidget(optionScalePXI, 1, 3, 1, 1);

        label_4 = new QLabel(histogramSettingsDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        optionDataScale = new QLineEdit(histogramSettingsDialog);
        optionDataScale->setObjectName(QStringLiteral("optionDataScale"));
        sizePolicy.setHeightForWidth(optionDataScale->sizePolicy().hasHeightForWidth());
        optionDataScale->setSizePolicy(sizePolicy);

        gridLayout->addWidget(optionDataScale, 2, 1, 1, 1);

        label_5 = new QLabel(histogramSettingsDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        optionLineGraph = new QCheckBox(histogramSettingsDialog);
        optionLineGraph->setObjectName(QStringLiteral("optionLineGraph"));

        gridLayout->addWidget(optionLineGraph, 3, 1, 1, 1);

        label_6 = new QLabel(histogramSettingsDialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setEnabled(false);
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 3, 2, 1, 1);

        optionSmoothedLine = new QCheckBox(histogramSettingsDialog);
        optionSmoothedLine->setObjectName(QStringLiteral("optionSmoothedLine"));
        optionSmoothedLine->setEnabled(false);

        gridLayout->addWidget(optionSmoothedLine, 3, 3, 1, 1);

        label_7 = new QLabel(histogramSettingsDialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 4, 0, 1, 1);

        optionThreshold = new QLineEdit(histogramSettingsDialog);
        optionThreshold->setObjectName(QStringLiteral("optionThreshold"));
        sizePolicy.setHeightForWidth(optionThreshold->sizePolicy().hasHeightForWidth());
        optionThreshold->setSizePolicy(sizePolicy);

        gridLayout->addWidget(optionThreshold, 4, 1, 1, 1);

        label_8 = new QLabel(histogramSettingsDialog);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        gridLayout->addWidget(label_8, 5, 0, 1, 1);

        optionShowThreshold = new QCheckBox(histogramSettingsDialog);
        optionShowThreshold->setObjectName(QStringLiteral("optionShowThreshold"));

        gridLayout->addWidget(optionShowThreshold, 5, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        okButton = new QPushButton(histogramSettingsDialog);
        okButton->setObjectName(QStringLiteral("okButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(okButton->sizePolicy().hasHeightForWidth());
        okButton->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(okButton);

        cancelButton = new QPushButton(histogramSettingsDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        sizePolicy1.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(cancelButton);


        gridLayout->addLayout(horizontalLayout, 5, 3, 1, 1);


        retranslateUi(histogramSettingsDialog);
        QObject::connect(okButton, SIGNAL(clicked()), histogramSettingsDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(histogramSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *histogramSettingsDialog)
    {
        histogramSettingsDialog->setWindowTitle(QApplication::translate("histogramSettingsDialog", "CV | Histogram Settings", Q_NULLPTR));
        label->setText(QApplication::translate("histogramSettingsDialog", "Y-Axis Percentage/Pixels", Q_NULLPTR));
        optionPercentage->clear();
        optionPercentage->insertItems(0, QStringList()
         << QApplication::translate("histogramSettingsDialog", "Pixels", Q_NULLPTR)
         << QApplication::translate("histogramSettingsDialog", "Percentage", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("histogramSettingsDialog", "Scale per intensity", Q_NULLPTR));
        optionScalePI->setText(QString());
        label_3->setText(QApplication::translate("histogramSettingsDialog", "Per x intensity", Q_NULLPTR));
        label_4->setText(QApplication::translate("histogramSettingsDialog", "Data Scale", Q_NULLPTR));
        label_5->setText(QApplication::translate("histogramSettingsDialog", "Line graph", Q_NULLPTR));
        optionLineGraph->setText(QString());
        label_6->setText(QApplication::translate("histogramSettingsDialog", "Smoothed", Q_NULLPTR));
        optionSmoothedLine->setText(QString());
        label_7->setText(QApplication::translate("histogramSettingsDialog", "Threshold", Q_NULLPTR));
        label_8->setText(QApplication::translate("histogramSettingsDialog", "Show Threshold", Q_NULLPTR));
        optionShowThreshold->setText(QString());
        okButton->setText(QApplication::translate("histogramSettingsDialog", "OK", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("histogramSettingsDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class histogramSettingsDialog: public Ui_histogramSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTOGRAMSETTINGSDIALOG_H
