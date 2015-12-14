/********************************************************************
 * cctvwindow.h
 * License: GNU, GPL
 * (c) 2014, Bernd Porr
 ********************************************************************/

class CCTVwindow;
#ifndef CCTVWINDOW_H
#define CCTVWINDOW_H

#include "dialog.h"
#include "cctvmonitor.h"
#include <time.h>

#include <QMainWindow>

#define CCTV_WIN_WIDTH 500
#define CCTV_WIN_HEIGHT (CCTV_WIN_WIDTH*3/4)

class CCTVWindow : public QMainWindow
{
	Q_OBJECT
public:
        CCTVWindow(Dialog *parent = 0,
		   time_t t = 0);

/**
 * Destructor
 **/
    ~CCTVWindow();

private:
    CCTVMonitor *cctvmonitor;
	   

};
#endif
