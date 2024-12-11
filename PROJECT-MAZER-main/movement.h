#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>
#include <windows.h>
#include "map.h"
#include "timer.h"
#define BARSIZE 10

int x=125, y=100 ,speed = 15;

//To draw the player on the field
void drawbar(int colour)
{
    setfillstyle(1,colour);
    bar(x,y,x+BARSIZE,y+BARSIZE);
}

//To Check for the free space up side or the presence of the line (wall)
int checkfreespaceup(int p)
{
    int flag=1;
    for(int i=0;i<=BARSIZE;i++)
        if(getpixel(x+i,y-p)!=0){flag=0;break;}
    return flag;
}

//To Check for the free space left side or the presence of the line (wall)
int checkfreespaceleft(int p)
{
    int flag=1;
    for(int i=0;i<=BARSIZE;i++)
        if(getpixel(x-p,y+i)!=0){flag=0;break;}
    return flag;
}

//To Check for the free space right side or the presence of the line (wall)
int checkfreespaceright(int p)
{
    int flag=1;
    for(int i=0;i<=BARSIZE;i++)
        if(getpixel(x+BARSIZE+p,y+i)!=0){flag=0;break;}
    return flag;
}

//To check for the free space down side or the presence of the line (wall)
int checkfreespacedown(int p)
{
    int flag=1;
    for(int i=0;i<=BARSIZE;i++)
        if(getpixel(x+i,y+BARSIZE+p)!=0){flag=0;break;}
    return flag;
}

//To check the movement of the player
void movement(int choice)
{
        setcolor(6);
        if(choice == 1)map1();
        else if(choice == 2) map2();
        else if(choice == 3) map3();
        else if (choice == 4) map4();
        drawbar(2);
        if(GetAsyncKeyState(VK_UP)&&checkfreespaceup(1))
        {
            drawbar(0);
            for(int i=1;i<=speed;i++)
            if(checkfreespaceup(i)==0||i==speed){
                    i--;
                y-=i;
                break;

        }

        }
        else if(GetAsyncKeyState(VK_LEFT)&&checkfreespaceleft(1))
        {
            drawbar(0);
            for(int i=1;i<=speed;i++)
            if(checkfreespaceleft(i)==0||i==speed){
                    i--;
                x-=i;
                break;

        }
        }
        else if(GetAsyncKeyState(VK_RIGHT)&&checkfreespaceright(1))
        {
            drawbar(0);
            for(int i=1;i<=speed;i++)
            if(checkfreespaceright(i)==0||i==speed){
                    i--;
                x+=i;
                break;

        }
        }
        else if(GetAsyncKeyState(VK_DOWN)&&checkfreespacedown(1))
        {
            drawbar(0);
            for(int i=1;i<=speed;i++)
            if(checkfreespacedown(i)==0||i==speed){
                    i--;
                y+=i;
                break;
                }
        }
        drawbar(2);

}
