#pragma once

#include <QtWidgets/QMainWindow>
#include<QVBoxLayout>
#include<qtimer.h>
#include<qsplashscreen.h>
#include "ui_PlayerManagementSystem.h"

class PlayerManagementSystem : public QMainWindow
{
    Q_OBJECT

public:
    PlayerManagementSystem(QWidget *parent = Q_NULLPTR);
    void display(PlayerManagementSystem* win);
private:
    Ui::PlayerManagementSystemClass ui;
    QBoxLayout* vlayout;
    QWidget* mainlayout;
};
