#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<graphics.h>
//#include"Feauture.h"
int _second , m_sec=0;

// To display the Timer on the board
int display(int reset)
{
    if(reset==1)
    {
        _second=60;
        m_sec=120;
    }
    char *str_min=(char *)malloc(sizeof(char)*10);
    itoa(_second, str_min, 10);
    setcolor(2);
    settextstyle(9,0,8);
    outtextxy(1170,150,str_min);
    free(str_min);
    if(m_sec==0)
    {
        _second--;
        m_sec=150;
    }

    if(_second==0)
    {
        cleardevice();
        setbkcolor(0);
        loss_sound();
        outtextxy(getmaxx()/2,getmaxy()/2,(char*) "TIME UP");
        settextstyle(1,0,1);
        setcolor(4);
        outtextxy(getmaxx()/2,getmaxy()/2+200,(char *)"PRESS 5 TO CONTINUE");
        for(;;)
        {

            if(GetAsyncKeyState(VK_NUMPAD5)||GetAsyncKeyState(0x35))
            {
                cleardevice();
                return 12;
            }
        }

    }

    delay(1);
    m_sec-=5;
}
