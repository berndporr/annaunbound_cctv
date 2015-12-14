/********************************************************************
 * cctvpushbutton.cpp
 * License: GNU, GPL
 * (c) 2014, Bernd Porr
 ********************************************************************/

#include "cctvpushbutton.h"

CCTVpushButton::CCTVpushButton( time_t theTime ) {

	char tmp[256];
	struct tm *tm;

	t = theTime;

	tm = localtime(&t);
	strftime(tmp,255,"%c",tm);

	buttonText = new QString(tmp);
	
	setText(*buttonText);

        connect(this, 
                SIGNAL( pressed () ),
                this, 
                SLOT( pushbuttonPressed() ) );

}

CCTVpushButton::~CCTVpushButton() {
	delete buttonText;
}
