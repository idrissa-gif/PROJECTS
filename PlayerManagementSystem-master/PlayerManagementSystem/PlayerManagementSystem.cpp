#include "PlayerManagementSystem.h"
#include<qsplashscreen.h>
#include<qtimer.h>
PlayerManagementSystem::PlayerManagementSystem(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    setWindowTitle("Player Management System");
    mainlayout = new QWidget(this);
    vlayout = new QVBoxLayout(this);
    mainlayout->setLayout(vlayout);
    vlayout->addSpacerItem(new QSpacerItem(300,300,QSizePolicy::Minimum,QSizePolicy::Minimum));
    setCentralWidget(mainlayout);
}

void PlayerManagementSystem :: display(PlayerManagementSystem* win)
{
    QSplashScreen* splash = new QSplashScreen();
    splash->setPixmap(QPixmap("C:\\Users\\Idrissa Mahamoudou\\source\\repos\\PlayerManagementSystem\\PlayerManagementSystem\\superleague.jpg"));
    splash->show();

    vlayout->addWidget(ui.continue_btn);
    vlayout->addWidget(ui.create_btn);
    vlayout->addWidget(ui.exit_btn);
    vlayout->addWidget(ui.group_members);
    vlayout->addWidget(ui.ID_242);
    vlayout->addWidget(ui.ID_245);
    vlayout->addWidget(ui.ID_246);
    vlayout->addWidget(ui.ID_247);
    vlayout->addWidget(ui.course_teachers);
    vlayout->addWidget(ui.teachers);
    vlayout->addWidget(ui.label);
    vlayout->addWidget(ui.lineEdit);
    QTimer::singleShot(2500, splash, SLOT(close()));
    QTimer::singleShot(2500, win, SLOT(show()));
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    updateGeometry();

}