#include<stdio.h>
#include<math.h>
int B_PosX , B_PosY ,D_PosX , D_PosY;

int B_check_keyUp()
{
    for(int i=0; i<=10; i++)
        if(getpixel(x+i,y-1)==15) return 1;
}

int B_check_keyLeft()
{
    for(int i=0; i<=10; i++)
        if(getpixel(x-1,y+i)==15)   return 1;
}

int B_check_keyRight()
{
    for(int i=0; i<=10; i++)
        if(getpixel(x+11,y+i)==15) return 1;

}

int B_check_keyDown()
{
    for(int i=0; i<=10; i++)
        if(getpixel(x+i,y+11)==15) return 1;
}

void eat_bonu(int Ex, int Ey)
{
    setcolor(0);
    setfillstyle(1,0);
    bar(Ex,Ey,Ex+5,Ey+5);
    floodfill(Ex,Ey,0);
}

//To draw the bonu
void draw_bonu()
{
    int bx_down=4, bx_up=23 , by_down=2,by_up=21;
    again:
    B_PosX=randInt(bx_down,bx_up)*30+15;
    B_PosY=randInt(by_down,by_up)*30+15;
    setfillstyle(1,15);
    if(getpixel(B_PosX,B_PosY)==0) bar(B_PosX,B_PosY,B_PosX+5,B_PosY+5);
    else goto again;
}
//To Eat the bonu or use the bonu
int bonu(int del_bonus)
{
    if ( (B_check_keyDown()==1 || B_check_keyUp()==1 || B_check_keyLeft()==1 || B_check_keyRight()==1) || del_bonus==1 )
    {
        eat_bonu(B_PosX,B_PosY);
        return 1;
    }
}

int D_check_keyUp()
{
    for(int i=0; i<=10; i++)
        if(getpixel(x+i,y-1)==4) return 1;
}


int D_check_keyLeft()
{
    for(int i=0; i<=10; i++)
        if(getpixel(x-1,y+i)==4)   return 1;
}

int D_check_keyRight()
{
    for(int i=0; i<=10; i++)
        if(getpixel(x+11,y+i)==4) return 1;

}

int D_check_keyDown()
{
    for(int i=0; i<=10; i++)
        if(getpixel(x+i,y+11)==4) return 1;
}

void draw_must_bonu()
{
    int bx_down=4, bx_up=23 , by_down=2,by_up=21;
    again1:
    D_PosX=randInt(bx_down,bx_up)*30+15;
    D_PosY=randInt(by_down,by_up)*30+15;
    setfillstyle(1,4);
    if(getpixel(D_PosX,D_PosY)==0) bar(D_PosX,D_PosY,D_PosX+5,D_PosY+5);
    else goto again1;
}
int must_bonu(int del_bonus)
{
    if ( (D_check_keyDown()==1 || D_check_keyUp()==1 || D_check_keyLeft()==1 || D_check_keyRight()==1) || del_bonus==1 )
    {
        eat_bonu(D_PosX,D_PosY);
        return 1;
    }
}
