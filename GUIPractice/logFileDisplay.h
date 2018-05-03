#pragma once

#include <QDialog>
#include "ui_logFileDisplay.h"

class logFileDisplay : public QDialog, public Ui::logFileDisplay
{
	Q_OBJECT

public:
	logFileDisplay(QWidget *parent = Q_NULLPTR);
	~logFileDisplay();
};
