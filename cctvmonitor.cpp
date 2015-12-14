/********************************************************************
 * cctvmonitor.cpp
 * License: GNU, GPL
 * (c) 2014, Bernd Porr
 ********************************************************************/

#include "cctvmonitor.h"

#include <stdio.h>

#include <QPainter>
#include <QPixmap>

// in ms
#define REFRESH_RATE 100

CCTVMonitor::CCTVMonitor( QWidget* FFTWindowTmp, time_t theTime)
	: QWidget( FFTWindowTmp )
{
	t = (double)theTime;
	setAttribute(Qt::WA_DeleteOnClose);
	startTimer( REFRESH_RATE );
}

void CCTVMonitor::timerEvent( QTimerEvent * )
{
	repaint();
}

void CCTVMonitor::paintEvent(QPaintEvent *)
{
	struct tm *tm;
	char tmp[256];
	QPainter paint( this );			// painter object

	time_t epochs = (time_t)t;

	tm = localtime(&epochs);
	strftime(tmp,255,"%c",tm);

	int w = paint.device()->width();
	int h = paint.device()->height();

	QPixmap pix(w,h);

	QPainter p(&pix);

	for(int x = 0;x<w;x=x+4) {
		for(int y = 0;y<h;y=y+4) {
			p.fillRect(x,y,3,2, QColor(0 + (qrand() % 100), 
						   0 + (qrand() % 100), 
						   0 + (qrand() % 255)));
		}
	}		

	QFont font("Courier",20,QFont::Bold,(qrand()%2));
	QPen pen(QColor(0, 0, 255, 255));
	p.setFont(font);
	p.setPen(pen);
	p.drawText(10 + (qrand()%3),30,QString(tmp));

	p.end();

	paint.drawPixmap(QPoint(0,0),pix);

	t=t+((double)REFRESH_RATE)/((double)1000.0);
}
