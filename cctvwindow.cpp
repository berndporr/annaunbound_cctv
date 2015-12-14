/********************************************************************
 * cctvwindow.cpp
 * License: GNU, GPL
 * (c) 2014, Bernd Porr
 ********************************************************************/

#include "cctvwindow.h"
#include "cctvmonitor.h"

CCTVWindow::CCTVWindow(Dialog *,
		       time_t t)
{
	setWindowFlags(Qt::WindowStaysOnTopHint);
	cctvmonitor = new CCTVMonitor( this,t );
        cctvmonitor->setSizePolicy (QSizePolicy(QSizePolicy::Ignored,
						QSizePolicy::Ignored));
        cctvmonitor->setMinimumWidth ( CCTV_WIN_WIDTH );
        cctvmonitor->setMinimumHeight ( CCTV_WIN_HEIGHT );
        cctvmonitor->setSizeIncrement(1,1);
	resize(CCTV_WIN_WIDTH, CCTV_WIN_HEIGHT);
}

CCTVWindow::~CCTVWindow() {
	delete cctvmonitor;
}


