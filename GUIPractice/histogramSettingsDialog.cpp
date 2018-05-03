#include "histogramSettingsDialog.h"
#include "applicationGUI.h"
#include <windows.h>

histogramSettingsDialog::histogramSettingsDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
	this->resize(595, 200);
}

histogramSettingsDialog::~histogramSettingsDialog()
{
}