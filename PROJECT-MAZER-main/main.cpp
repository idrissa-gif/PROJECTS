#include"pause.h"
#include<graphics.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include"movement.h"
#include"Coins.h"
#include"bonus.h"

int cnt=300 , cnt2=450 ;
void initialize();

int choice=1;
int main ()
{
    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
    initwindow(screenWidth,screenHeight,"",-3,-3);

    initialize();
    cleardevice();
    choice=gamescreen();
    if(choice==0) return 0;

game:
    int reset=1;
    cnt=225;
    cnt2=450;
    srand(time(NULL));
    coin_gen(5);
    food_order();
    while(1)
    {
        feast();
        movement(choice);
        if(display(reset)==12||Check_coin(reset)==5)
        {
            choice=gamescreen();
            if(choice==0) return 0;
            goto game;
        }
        redraw_food(Che_color);
        eaten_food(Che_color);
        if(cnt==100) draw_bonu();
        if(bonu(0)==1)
        {
            bonu_sound();
            _second+=20;
        }
        if(cnt==0)
        {
            bonu(1);
            cnt=300;
        }

        if(cnt2==200) draw_must_bonu();
        if(must_bonu(0)==1)
        {
            bonu_sound();
            _second+=5;
            cnt2=450;
        }
        else
        if(cnt2==0)
        {
            must_bonu(1);
            _second-=10;
            reduce_sound();
            cnt2=450;
        }
        if(GetAsyncKeyState(VK_SPACE))
        {
            display(reset);
            if(pause()==2) break;
            else
            {
                feast();
                Check_coin(reset);
                movement(choice);
                redraw_coin(5);

                if(display(reset)==12||Check_coin(reset)==5)
                {
                    choice=gamescreen();
                    if(choice==0) return 0;
                }
            }
        }
        reset=0;
        cnt--;
        cnt2--;
    }
    choice=gamescreen();
    if(choice!=0) goto game;
    return 0;
}




