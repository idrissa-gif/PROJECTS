#include<graphics.h>
#include<windows.h>
#include"Feauture.h"

//The menu for the choice
int gamescreen()
{
    int maxx=getmaxx()/2 , maxy=getmaxy()/2;
    setbkcolor(12);
    cleardevice();
    settextstyle(4,8,12);
    select_sound();
    for(int is=1 ; ;is++){

    outtextxy(maxx-10,maxy-200,(char *)"CHOOSE ANY LEVEL");
    outtextxy(maxx-20,maxy-100,(char *)"1-TRIVIAL");
    outtextxy(maxx,maxy,(char *)"2-MODERATE");
    outtextxy(maxx-30,maxy+100,(char *)"3-HARD");
    outtextxy(maxx,maxy+200,(char *)"4-VERY HARD");
    outtextxy(maxx-20,maxy+300,(char *)"esc to exit");
    if(GetAsyncKeyState(VK_NUMPAD1)||GetAsyncKeyState(0x31))
    {
        setbkcolor(0);
        cleardevice();
        GAME_sound();
        return 1;
    }
    else if(GetAsyncKeyState(VK_NUMPAD2)||GetAsyncKeyState(0x32))
    {
        setbkcolor(0);
        cleardevice();
        GAME_sound();
        return 2;
    }
    else if(GetAsyncKeyState(VK_NUMPAD3)||GetAsyncKeyState(0x33))
    {
         setbkcolor(0);
         cleardevice();
         GAME_sound();
        return 3;
    }
    else if(GetAsyncKeyState(VK_NUMPAD4)||GetAsyncKeyState(0x34))
    {
         setbkcolor(0);
         GAME_sound();
         cleardevice();
        return 4;
    }
    else if(GetAsyncKeyState(VK_ESCAPE)) return 0;
    if(is==950)
    {
        select_sound();
        is=0;
    }
}
    return 10;
}

//To Pause the game
int pause()
{
    int maxx=getmaxx()/2 , maxy=getmaxy()/2;
    cleardevice();
    for(;;)
    {
        setbkcolor(0);
        settextstyle(4,12,14);
        outtextxy(maxx,maxy,(char *)"DO YOU WANT TO LEAVE THE GAME ?");
        outtextxy(maxx,maxy+100,(char *)"PRESS Y FOR YES OR N FOR NO");
        settextstyle(4,12,14);
        outtextxy(maxx-100,maxy+200,(char *)"YES");
        outtextxy(maxx+100,maxy+200,(char *)"NO");
        if(GetAsyncKeyState(0x004E))
        {
          cleardevice();
          return 1;
        }
        else if(GetAsyncKeyState(0x0059))
        {
            cleardevice();
            return 2;
        }
    }
    getch();
}
