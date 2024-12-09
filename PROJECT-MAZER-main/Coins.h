#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

int PosX, PosY ;
int Che_color=0;
int arr[5][2], color[5]= {1,3,5,7,13};


int randInt(int a, int b)
{
    return a+(int)rand()%(b-a+1);

}
void coin_gen(int num_coin)
{

    int i, j, flag=0;
    int bx_down=4, bx_up=23, by_down=2,by_up=21;

    for(j=0 ; j<num_coin ; )
    {

        PosX=randInt(bx_down,bx_up)*30+15;
        PosY=randInt(by_down,by_up)*30+15;
        for( i=0 ; i<9 ; i++)
        {
            if((getpixel(PosX+i,PosY)!=6)&&(getpixel(PosX,PosY+i)!=6)&&(getpixel(PosX-i,PosY)!=6)&&(getpixel(PosX,PosY-i)!=6))
            {
                flag=0;
            }
            else
            {

                flag=1;
                break;
            }

        }

        if(flag==0)
        {
            setcolor(color[j]);
            setfillstyle(1,color[j]);
            circle(PosX,PosY,5);
            floodfill(PosX,PosY,color[j]);
            arr[j][0]=PosX;
            arr[j][1]=PosY;
            j++;
        }
    }
}

void redraw_coin(int num_coin)
{
    for(int ii=Che_color ; ii<num_coin ; ii++)
    {
        setcolor(color[ii]);
        setfillstyle(1,color[ii]);
        circle(arr[ii][0],arr[ii][1],5);
        floodfill(arr[ii][0],arr[ii][1],color[ii]);
    }
}

void eat(int Ex, int Ey)
{

    setcolor(0);
    setfillstyle(1,0);
    circle(Ex,Ey,5);
    floodfill(Ex,Ey,0);
}

int check_coinUp()
{
    for(int i=0; i<=10; i++)
        if(getpixel(x+i,y-1)==color[0]) return 1;
        else if(getpixel(x+i,y-1)==color[1]) return 2;
        else if(getpixel(x+i,y-1)==color[2]) return 3;
        else if(getpixel(x+i,y-1)==color[3]) return 4;
        else if(getpixel(x+i,y-1)==color[4]) return 5;
}

int check_coinLeft()
{
    for(int i=0; i<=10; i++)
        if(getpixel(x-1,y+i)==color[0])   return 1;
        else if(getpixel(x-1,y+i)==color[1]) return 2;
        else if(getpixel(x-1,y+i)==color[2]) return 3;
        else if(getpixel(x-1,y+i)==color[3]) return 4;
        else if(getpixel(x-1,y+i)==color[4]) return 5;
}

int check_coinRight()
{
    for(int i=0; i<=10; i++)
        if(getpixel(x+11,y+i)==color[0]) return 1;
        else if(getpixel(x+11,y+i)==color[1]) return 2;
        else if(getpixel(x+11,y+i)==color[2]) return 3;
        else if(getpixel(x+11,y+i)==color[3]) return 4;
        else if(getpixel(x+11,y+i)==color[4]) return 5;
}

int check_coinDown()
{
    for(int i=0; i<=10; i++)
        if(getpixel(x+i,y+11)==color[0]) return 1;
        else if(getpixel(x+i,y+11)==color[1]) return 2;
        else if(getpixel(x+i,y+11)==color[2]) return 3;
        else if(getpixel(x+i,y+11)==color[3]) return 4;
        else if(getpixel(x+i,y+11)==color[4]) return 5;
}

int Check_coin(int reset)
{
    if(reset==1) Che_color=0;
    if ( (check_coinDown()==1 || check_coinUp()==1 || check_coinLeft()==1 || check_coinRight()==1)&&Che_color==0 )
    {
        eat_sound();
        eat(arr[0][0],arr[0][1]);
        Che_color=1;
        return 2;
    }
    else if ( (check_coinDown()==2|| check_coinUp()==2 || check_coinLeft()==2|| check_coinRight()==2)&&Che_color==1 )
    {
        eat_sound();
        eat(arr[1][0],arr[1][1]);
        Che_color=2;
        return 2;
    }
    else if ( (check_coinDown()==3|| check_coinUp()==3 || check_coinLeft()==3 || check_coinRight()==3)&&Che_color==2 )
    {
        eat_sound();
        eat(arr[2][0],arr[2][1]);
        Che_color=3;
        return 2;
    }
    else if ( (check_coinDown()==4 || check_coinUp()==4 || check_coinLeft()==4 || check_coinRight()==4)&&Che_color==3 )
    {
        eat_sound();
        eat(arr[3][0],arr[3][1]);
        Che_color=4;
        return 2;
    }

    else if ( (check_coinDown()==5 || check_coinUp()==5 || check_coinLeft()==5 || check_coinRight()==5)&&Che_color==4 )
    {
        eat_sound();
        eat(arr[4][0],arr[4][1]);
        Che_color=0;
        cleardevice();
        setbkcolor(0);
        setcolor(GREEN);
        outtextxy(getmaxx()/2,getmaxy()/2,(char *) "YOU WIN");
        win_sound();
        settextstyle(1,0,1);
        setcolor(4);
        outtextxy(getmaxx()/2,getmaxy()/2+200,(char *)"PRESS 5 TO CONTINUE");
        for(;;)
        {
            if(GetAsyncKeyState(VK_NUMPAD5)||GetAsyncKeyState(0x35))
            {
                cleardevice();
                return 5;
            }
        }

    }
}
