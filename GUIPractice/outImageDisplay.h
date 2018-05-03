#pragma once

#include <QDialog>
#include "ui_outImageDisplay.h"

class outImageDisplay : public QDialog, public Ui::outImageDisplay
{
	Q_OBJECT

public:
	outImageDisplay(QWidget *parent = Q_NULLPTR);
	~outImageDisplay();
};
