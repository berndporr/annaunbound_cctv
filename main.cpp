/********************************************************************
 * main.cpp
 * License: GNU, GPL
 * (c) 2014, Bernd Porr
 ********************************************************************/

#include <QApplication>

#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Dialog dialog;
    dialog.show();
    return app.exec();
}
