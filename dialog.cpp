/********************************************************************
 * dialog.cpp
 * License: GNU, GPL
 * (c) 2014, Bernd Porr
 ********************************************************************/

#include <QtGui>

#include "dialog.h"

#include "cctvwindow.h"

#include <QLabel>
#include <QPushButton>

Dialog::Dialog()
{
	QVBoxLayout *mainLayout = new QVBoxLayout;

	// the corresponding box which contains all the controls
	QGroupBox *titleBox = new QGroupBox ();
	titleBox->setStyleSheet("padding:0px;margin:0px;border:0px");

	// now we create another layout which contains all the controls
	QVBoxLayout * titleLayout = new QVBoxLayout(titleBox);

	QLabel title("CCTV");
	title.setStyleSheet("color: black; background-color:#202020");
	titleLayout->addWidget(&title);

	// the corresponding box which contains all the controls
	QGroupBox *controlBox = new QGroupBox ();
	controlBox->setStyleSheet("padding:0px;margin:0px;border:0px");

	// now we create another layout which contains all the controls
	QVBoxLayout * controlLayout = new QVBoxLayout(controlBox);

	// we create a scroll area
	QScrollArea *allChScrollArea = new QScrollArea();
	// this is the layout containing the scrollArea
	QVBoxLayout *allChScrollLayout = new QVBoxLayout();
	// to this layout we add just one widget which is the scroll area
	allChScrollLayout->addWidget(allChScrollArea);

	QGridLayout *allChLayout = new QGridLayout;
	QGroupBox *allChGroup = new QGroupBox;
	allChLayout->setSpacing(10);
	allChGroup->setStyleSheet("padding:10px;margin:5px;border:5px;background-color:black");
	allChGroup->setLayout(allChLayout);
	allChGroup->setSizePolicy ( QSizePolicy(QSizePolicy::Fixed,
						QSizePolicy::Expanding ) );

	int row = 1;
	int col = 1;

	NumButtons = 159;
	buttons = new CCTVpushButton*[NumButtons];

	int offset = (2014-1970+0.7)*60*60*24*365+60*20;

       	for (int i = 0; i < NumButtons; ++i) {
		time_t t = i*5000+offset;
		buttons[i] = new CCTVpushButton(t);
		buttons[i]->setStyleSheet("QPushButton{color: white; background-color:#202020; border: 2px solid #8f8f91; border-radius: 6px;font: bold 14px;}QPushButton:hover{background-color: rgb(224, 0, 0);border-style: inset;}");
		allChLayout->addWidget(buttons[i],row,col);
		allChGroup->connect(buttons[i], 
				    SIGNAL( buttonPressed (time_t) ),
				    this, 
				    SLOT( openCCTVWindow(time_t) ));
		row++;
		if (row > 30) {
			row = 1;
			col++;
		}
	}


	controlLayout->addWidget(allChScrollArea);
	allChScrollArea->setWidget(allChGroup);

	mainLayout->addWidget(titleBox);
	mainLayout->addWidget(controlBox);

	setLayout(mainLayout);
	
	setWindowTitle(tr("CCTV"));
}


void Dialog::openCCTVWindow(time_t t) {
	char tmp[256];
	struct tm *tm;
	CCTVWindow* cctvWin = new CCTVWindow(this,t);

	tm = localtime(&t);
	strftime(tmp,255,"%c",tm);

	cctvWin->setWindowTitle(tmp);
	cctvWin->show();
}
