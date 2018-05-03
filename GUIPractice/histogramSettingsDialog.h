#pragma once

#include <QDialog>
#include "ui_histogramSettingsDialog.h"
#include "applicationGUI.h"

class histogramSettingsDialog : public QDialog, public Ui::histogramSettingsDialog
{
	Q_OBJECT

public:
	histogramSettingsDialog(QWidget *parent = Q_NULLPTR);
	~histogramSettingsDialog();
};
