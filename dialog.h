/********************************************************************
 * dialog.h
 * License: GNU, GPL
 * (c) 2014, Bernd Porr
 ********************************************************************/

#ifndef DIALOG_H
#define DIALOG_H

#include <QGroupBox>
#include <QPushButton>
#include <QLabel>
#include <QDialog>
#include <QScrollArea>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include <time.h>

#include "cctvpushbutton.h"



class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog();

private:
    CCTVpushButton **buttons;
    QScrollArea **scrollArea;
    QHBoxLayout *mainLayout;
    // QLabel *labels[NumButtons];

    int NumButtons;

private slots:
    void openCCTVWindow(time_t);

};
//! [0]

#endif
