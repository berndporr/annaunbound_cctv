/********************************************************************
 * cctvpushbutton.h
 * License: GNU, GPL
 * (c) 2014, Bernd Porr
 ********************************************************************/

class CCTVpushbutton;
#ifndef _CCTVPUSHBUTTON
#define _CCTVPUSHBUTTON

#include <QPushButton>
#include <QString>
#include <time.h>

class CCTVpushButton : public QPushButton {

    Q_OBJECT

public:
    CCTVpushButton ( time_t theTime );

    ~CCTVpushButton();

    time_t t;
    QString *buttonText;

signals:
    void buttonPressed(time_t theTime);

public slots:
    void pushbuttonPressed() {
	    emit buttonPressed(t);
    }

};

#endif
