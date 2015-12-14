/********************************************************************
 * cctvmonitor.h
 * License: GNU, GPL
 * (c) 2014, Bernd Porr
 ********************************************************************/

class CCTVMonitor;
#ifndef CCTVMonitor_H
#define CCTVMonitor_H

#include "dialog.h"
#include <time.h>


class CCTVMonitor : public QWidget
{
    Q_OBJECT
public:
/**
 * Constructor:
 **/
    CCTVMonitor( QWidget* CCTVWindowTmp,
		 time_t theTime);

    void paintEvent(QPaintEvent *);

    void timerEvent( QTimerEvent * );

    double t;

};

#endif
