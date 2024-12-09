#include<graphics.h>
#include<conio.h>
#include<stdio.h>

void bonu_sound()
{
    PlaySound(TEXT("BONUS.wav"),NULL,SND_ASYNC);
}
int select_sound()
{
    PlaySound(TEXT("mazer.wav"),NULL,SND_ASYNC);
    return 1;
}
void GAME_sound()
{
    PlaySound(TEXT("transition.wav"),NULL,SND_ASYNC);
}
void reduce_sound()
{
    PlaySound(TEXT("Wasted.wav"),NULL,SND_ASYNC);
}
void eat_sound()
{
    PlaySound(TEXT("eat.wav"),NULL,SND_ASYNC);
}

void win_sound()
{
    PlaySound(TEXT("WIN.wav"),NULL,SND_ASYNC);
}

void begin_sound()
{
    PlaySound(TEXT("begin2.wav"),NULL,SND_ASYNC);
}
void loss_sound()
{
    PlaySound(TEXT("loss.wav"),NULL,SND_ASYNC);
}

// To display the introduction
void feast()
{

    setcolor(7);
    setfillstyle(1,7);
    arc(1250, 225, 0, 270, 10);
    arc(1250, 225, 0, 270, 21);
    arc(1090, 225, 180, 270, 10);
    arc(1090, 225, 180, 270, 21);
    arc(1250, 65, 0, 90, 10);
    arc(1250, 65, 0, 90, 21);
    arc(1090, 65, 90, 180, 10);
    arc(1090, 65, 90, 180, 21);

    line(1000,0,1000,800);

    line(1080,45,1260,45);
    line(1070,55,1070,235);
    line(1270,55,1270,235);
    line(1080,245,1260,245);

    line(1090,55,1250,55);
    line(1080,65,1080,225);
    line(1260,65,1260,225);
    line(1090,235,1250,235);

    line(1055,680,1285,680);
    line(1055,600,1285,600);
    line(1045,610,1045,675);
    line(1295,610,1295,675);

    line(1045,690,1295,690);
    line(1045,590,1300,590);
    line(1035,600,1035,685);
    line(1305,600,1305,685);

    arc(1285, 670, 0, 270, 10);
    arc(1285, 670, 0, 270, 21);
    arc(1055, 670, 180, 270, 10);
    arc(1055, 670, 180, 270, 21);
    arc(1285, 610, 0, 90, 10);
    arc(1285, 610, 0, 90, 21);
    arc(1055, 610, 90, 180, 10);
    arc(1055, 610, 90, 180, 21);

    floodfill(1075, 65, 7);
    floodfill(1240, 215, 7);
    floodfill(1045, 600, 7);
    floodfill(1275, 660, 7);
    settextstyle(8,0,6);
    outtextxy(1170,33,(char *)"MAZER");
    settextstyle(1,0,1);
    outtextxy(1190,355,(char *)"PAUSE:  SPACE");

}

// INTRODUCTION OF THE GROUP MEMBER'S NAME
void initialize()
{
    begin_sound();
    int maxx, maxy ;
    maxx=getmaxx();
    maxy=getmaxy();
    setcolor(GREEN);
    rectangle(0,0,maxx,maxy);
    setcolor(BLUE);
    rectangle(2,2,maxx-2,maxy-2);
    line(55,1,55,maxy-2);
    setcolor(6);
    settextjustify (CENTER_TEXT,CENTER_TEXT);
    settextstyle (4,HORIZ_DIR,12);
    outtextxy(maxx/2,50,(char *)"Project of CSE 4202");
    outtextxy(maxx/2,80,(char *)"Idrissa Mahamoudou Dicko 190041242");
    outtextxy(maxx/2,110,(char *)"Gadenga Abubakar 190041245");
    outtextxy(maxx/2,140,(char *)"Shalanyuy Nabil Kindzeka 190041246");
    outtextxy(maxx/2,170,(char *)"Mbouwap Njoya Zouleiha 190041247");
    settextstyle (0,HORIZ_DIR,16);
    setcolor(4);
    outtextxy(maxx/2,maxy/2,(char *)"MAZER");
    outtextxy(400,600,(char*) "LOADING......");
    rectangle(425,550,885,555);
    for(int i=0 ; i<450 ; i++)
    {
      line(425+i,550,425+i,555);
      delay(1);
    }
    getch();
    cleardevice();
}

//TO DISPLAY TO ORDER TO EAT THE FOODS
void food_order()
{
    setcolor(1);
    setfillstyle(1,1);
    circle(1090,643,10);
    floodfill(1090,643,1);

    setcolor(3);
    setfillstyle(1,3);
    circle(1120,643,10);
    floodfill(1120,643,3);

    setcolor(5);
    setfillstyle(1,5);
    circle(1150,643,10);
    floodfill(1150,643,5);

    setcolor(7);
    setfillstyle(1,7);
    circle(1180,643,10);
    floodfill(1180,643,7);

    setcolor(13);
    setfillstyle(1,13);
    circle(1210,643,10);
    floodfill(1210,643,13);
}

void eaten_food (int eaten)
{
    if(eaten==1)
    {
        setcolor(0);
        setfillstyle(1,0);
        circle(1090,643,10);
        floodfill(1090,643,0);
    }
    else if(eaten==2)
    {
        setcolor(0);
        setfillstyle(1,0);
        circle(1120,643,10);
        floodfill(1120,643,0);

    }
    else if(eaten==3)
    {
        setcolor(0);
        setfillstyle(1,0);
        circle(1150,643,10);
        floodfill(1150,643,0);

    }
    else if(eaten==4)
    {
        setcolor(0);
        setfillstyle(1,0);
        circle(1180,643,10);
        floodfill(1180,643,0);

    }
    else if(eaten==5)
    {
        setcolor(0);
        setfillstyle(1,0);
        circle(1210,643,10);
        floodfill(1210,643,0);
    }
}

void redraw_food(int remain)
{
    if(remain==0)
    {
        setcolor(1);
        setfillstyle(1,1);
        circle(1090,643,10);
        floodfill(1090,643,1);

        setcolor(3);
        setfillstyle(1,3);
        circle(1120,643,10);
        floodfill(1120,643,3);

        setcolor(5);
        setfillstyle(1,5);
        circle(1150,643,10);
        floodfill(1150,643,5);

        setcolor(7);
        setfillstyle(1,7);
        circle(1180,643,10);
        floodfill(1180,643,7);

        setcolor(13);
        setfillstyle(1,13);
        circle(1210,643,10);
        floodfill(1210,643,13);
    }
    else if(remain==1)
    {
        setcolor(3);
        setfillstyle(1,3);
        circle(1120,643,10);
        floodfill(1120,643,3);

        setcolor(5);
        setfillstyle(1,5);
        circle(1150,643,10);
        floodfill(1150,643,5);

        setcolor(7);
        setfillstyle(1,7);
        circle(1180,643,10);
        floodfill(1180,643,7);

        setcolor(13);
        setfillstyle(1,13);
        circle(1210,643,10);
        floodfill(1210,643,13);
    }
    else if(remain==2)
    {
        setcolor(5);
        setfillstyle(1,5);
        circle(1150,643,10);
        floodfill(1150,643,5);

        setcolor(7);
        setfillstyle(1,7);
        circle(1180,643,10);
        floodfill(1180,643,7);

        setcolor(13);
        setfillstyle(1,13);
        circle(1210,643,10);
        floodfill(1210,643,13);
    }
    else if(remain==3)
    {
        setcolor(7);
        setfillstyle(1,7);
        circle(1180,643,10);
        floodfill(1180,643,7);

        setcolor(13);
        setfillstyle(1,13);
        circle(1210,643,10);
        floodfill(1210,643,13);
    }
    else if(remain==3)
    {
        setcolor(13);
        setfillstyle(1,13);
        circle(1210,643,10);
        floodfill(1210,643,13);
    }
}

