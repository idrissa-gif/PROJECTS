#include "PlayerManagementSystem.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <sql.h>
#include<Qfile>
#include <QLabel>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QFile styleSheetFile("./Fibrary.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    app.setStyleSheet(styleSheet);
    PlayerManagementSystem win;
    win.display(&win);

    return app.exec();
    return 0;
}

