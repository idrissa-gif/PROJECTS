#include<graphics.h>
#include<stdio.h>
//static int maxx , maxy;

void map1()
{
    int val=30;
    setcolor(6);
    line(val,val,val*31,val);
    line(val,val,val,val*25);
    line(val,val*25,val*31,val*25);
    line(val*31,val,val*31,val*25);

    //Vertical lines
    line(val*3,val*3,val*5,val*3);
    line(val*9,val*3,val*13,val*3);
    line(val*15,val*3,val*17,val*3);
    line(val*21,val*3,val*23,val*3);
    line(val*25,val*3,val*31,val*3);

    line(val*5,val*5,val*7,val*5);
    line(val*9,val*5,val*13,val*5);
    line(val*19,val*5,val*21,val*5);
    line(val*23,val*5,val*27,val*5);

    line(val,val*7,val*3,val*7);
    line(val*7,val*7,val*11,val*7);
    line(val*15,val*7,val*23,val*7);
    line(val*27,val*7,val*31,val*7);

    line(val*3,val*9,val*7,val*9);
    line(val*17,val*9,val*21,val*9);
    line(val*23,val*9,val*25,val*9);
    line(val*27,val*9,val*29,val*9);

    line(val*9,val*11,val*19,val*11);
    line(val*21,val*11,val*23,val*11);
    line(val*25,val*11,val*27,val*11);
    line(val*29,val*11,val*31,val*11);

    line(val*7,val*13,val*9,val*13);
    line(val*13,val*13,val*21,val*13);
    line(val*23,val*13,val*25,val*13);
    line(val*27,val*13,val*29,val*13);

    line(val*3,val*15,val*5,val*15);
    line(val*11,val*15,val*15,val*15);
    line(val*17,val*15,val*19,val*15);
    line(val*21,val*15,val*23,val*15);

    line(val,val*17,val*3,val*17);
    line(val*5,val*17,val*7,val*17);
    line(val*13,val*17,val*19,val*17);
    line(val*21,val*17,val*25,val*17);

    line(val*7,val*19,val*9,val*19);
    line(val*11,val*19,val*15,val*19);
    line(val*19,val*19,val*21,val*19);
    line(val*23,val*19,val*29,val*19);

    line(val,val*21,val*5,val*21);
    line(val*7,val*21,val*9,val*21);
    line(val*21,val*21,val*23,val*21);

    line(val*9,val*23,val*21,val*23);
    line(val*27,val*23,val*29,val*23);

    //Horizontal lines
    line(val*3,val*3,val*3,val*7);
    line(val*3,val*9,val*3,val*13);
    line(val*3,val*17,val*3,val*19);
    line(val*3,val*23,val*3,val*25);

    line(val*5,val*5,val*5,val*7);
    line(val*5,val*11,val*5,val*23);

    line(val*7,val,val*7,val*15);
    line(val*7,val*19,val*7,val*21);
    line(val*7,val*23,val*7,val*25);

    line(val*9,val*9,val*9,val*11);
    line(val*9,val*15,val*9,val*19);
    line(val*9,val*21,val*9,val*23);

    line(val*11,val*7,val*11,val*9);
    line(val*11,val*11,val*11,val*13);
    line(val*11,val*15,val*11,val*21);

    line(val*13,val*3,val*13,val*11);
    line(val*13,val*21,val*13,val*23);

    line(val*15,val*3,val*15,val*9);
    line(val*15,val*13,val*15,val*15);
    line(val*15,val*19,val*15,val*21);//
    line(val*15,val*23,val*15,val*25);

    line(val*17,val*5,val*17,val*7);
    line(val*17,val*9,val*17,val*11);
    line(val*17,val*15,val*17,val*23);

    line(val*19,val,val*19,val*5);
    line(val*19,val*19,val*19,val*23);

    line(val*21,val*9,val*21,val*13);
    line(val*21,val*15,val*21,val*19);

    line(val*23,val*3,val*23,val*5);
    line(val*23,val*7,val*23,val*9);
    line(val*23,val*11,val*23,val*13);
    line(val*23,val*19,val*23,val*25);

    line(val*25,val,val*25,val*3);
    line(val*25,val*5,val*25,val*11);
    line(val*25,val*13,val*25,val*17);
    line(val*25,val*19,val*25,val*23);

    line(val*27,val*9,val*27,val*11);
    line(val*27,val*13,val*27,val*19);
    line(val*27,val*21,val*27,val*23);

    line(val*29,val*3,val*29,val*5);
    line(val*29,val*13,val*29,val*17);
    line(val*29,val*19,val*29,val*23);
}

void map3()
{
    setcolor(YELLOW);
    int s=30;
    //Horizontal lines                                  Vertical lines
    line(s,s,s,25*s);
    line(32*s,s,32*s,25*s);
    line(1*s,1*s,32*s,1*s);                              line(3*s,1*s,3*s,3*s);
    line(1*s,2*s,2*s,2*s);                              line(2*s,4*s,2*s,5*s);
    line(1*s,6*s,2*s,6*s);                              line(2*s,8*s,2*s,9*s);
    line(1*s,9*s,2*s,9*s);                              line(2*s,12*s,2*s,13*s);
    line(1*s,12*s,3*s,12*s);                              line(2*s,16*s,2*s,17*s);
    line(1*s,15*s,3*s,15*s);                              line(2*s,19*s,2*s,22*s);
    line(1*s,18*s,2*s,18*s);                              line(2*s,23*s,2*s,24*s);
    line(1*s,25*s,32*s,25*s);                              line(3*s,5*s,3*s,8*s);
    line(2*s,3*s,3*s,3*s);                              line(3*s,9*s,3*s,10*s);
    line(2*s,4*s,4*s,4*s);                              line(3*s,13*s,3*s,14*s);
    line(2*s,7*s,3*s,7*s);                              line(3*s,15*s,3*s,16*s);
    line(2*s,8*s,3*s,8*s);                              line(3*s,17*s,3*s,20*s);
    line(2*s,10*s,3*s,10*s);                              line(3*s,22*s,3*s,23*s);
    line(2*s,11*s,4*s,11*s);                              line(4*s,2*s,4*s,5*s);
    line(2*s,14*s,3*s,14*s);                              line(4*s,6*s,4*s,9*s);
    line(2*s,17*s,6*s,17*s);                              line(4*s,10*s,4*s,16*s);
    line(2*s,20*s,3*s,20*s);                              line(4*s,18*s,4*s,24*s);
    line(2*s,22*s,3*s,22*s);                              line(5*s,3*s,5*s,4*s);
    line(2*s,23*s,3*s,23*s);                              line(5*s,7*s,5*s,8*s);
    line(3*s,5*s,5*s,5*s);                              line(5*s,9*s,5*s,10*s);
    line(3*s,9*s,4*s,9*s);                              line(5*s,13*s,5*s,15*s);
    line(3*s,13*s,4*s,13*s);                              line(5*s,20*s,5*s,23*s);
    line(3*s,16*s,5*s,16*s);                              line(5*s,24*s,5*s,25*s);
    line(3*s,21*s,4*s,21*s);                              line(6*s,2*s,6*s,3*s);
    line(3*s,24*s,4*s,24*s);                              line(6*s,4*s,6*s,6*s);
    line(4*s,2*s,5*s,2*s);                              line(6*s,8*s,6*s,9*s);
    line(4*s,6*s,8*s,6*s);                              line(6*s,10*s,6*s,13*s);
    line(4*s,8*s,5*s,8*s);                              line(6*s,15*s,6*s,20*s);
    line(4*s,10*s,5*s,10*s);                              line(7*s,2*s,7*s,3*s);
    line(4*s,12*s,5*s,12*s);                              line(7*s,4*s,7*s,5*s);
    line(4*s,18*s,5*s,18*s);                              line(7*s,7*s,7*s,10*s);
    line(4*s,20*s,5*s,20*s);                              line(7*s,12*s,7*s,13*s);
    line(5*s,3*s,6*s,3*s);                              line(7*s,14*s,7*s,17*s);
    line(5*s,4*s,6*s,4*s);                              line(7*s,20*s,7*s,21*s);
    line(5*s,7*s,8*s,7*s);                              line(7*s,23*s,7*s,25*s);
    line(5*s,9*s,6*s,9*s);                              line(8*s,1*s,8*s,4*s);
    line(5*s,11*s,6*s,11*s);                              line(8*s,5*s,8*s,6*s);
    line(5*s,13*s,6*s,13*s);                              line(8*s,9*s,8*s,11*s);
    line(5*s,15*s,6*s,15*s);                              line(8*s,12*s,8*s,14*s);
    line(5*s,19*s,9*s,19*s);                              line(8*s,17*s,8*s,19*s);
    line(5*s,21*s,7*s,21*s);                              line(8*s,20*s,8*s,22*s);
    line(5*s,23*s,8*s,23*s);                              line(9*s,5*s,9*s,7*s);
    line(5*s,24*s,6*s,24*s);                              line(9*s,8*s,9*s,10*s);
    line(6*s,2*s,7*s,2*s);                              line(9*s,11*s,9*s,12*s);
    line(6*s,10*s,7*s,10*s);                              line(9*s,13*s,9*s,15*s);
    line(6*s,18*s,7*s,18*s);                              line(8*s,15*s,8*s,16*s);
    line(6*s,22*s,9*s,22*s);                              line(9*s,16*s,9*s,18*s);
    line(7*s,4*s,11*s,4*s);                              line(9*s,19*s,9*s,21*s);
    line(7*s,11*s,10*s,11*s);                              line(9*s,22*s,9*s,24*s);
    line(7*s,17*s,8*s,17*s);                              line(10*s,2*s,10*s,3*s);
    line(8*s,3*s,9*s,3*s);                              line(10*s,7*s,10*s,9*s);
    line(8*s,5*s,12*s,5*s);                              line(10*s,10*s,10*s,11*s);
    line(8*s,8*s,9*s,8*s);                              line(10*s,12*s,10*s,14*s);
    line(8*s,12*s,9*s,12*s);                              line(10*s,15*s,10*s,16*s);
    line(8*s,15*s,9*s,15*s);                              line(10*s,18*s,10*s,19*s);
    line(8*s,16*s,9*s,16*s);                              line(10*s,21*s,10*s,23*s);
    line(9*s,2*s,11*s,2*s);                              line(10*s,24*s,10*s,25*s);
    line(9*s,7*s,10*s,7*s);                              line(11*s,2*s,11*s,4*s);
    line(9*s,9*s,10*s,9*s);                              line(11*s,6*s,11*s,7*s);
    line(9*s,13*s,10*s,13*s);                              line(11*s,11*s,11*s,12*s);
    line(9*s,18*s,10*s,18*s);                              line(11*s,13*s,11*s,14*s);
    line(9*s,23*s,11*s,23*s);                              line(11*s,16*s,11*s,20*s);
    line(10*s,6*s,17*s,6*s);                              line(11*s,23*s,11*s,24*s);
    line(10*s,8*s,11*s,8*s);                              line(12*s,2*s,12*s,5*s);
    line(10*s,10*s,13*s,10*s);                              line(12*s,7*s,12*s,9*s);
    line(10*s,12*s,14*s,12*s);                              line(12*s,10*s,12*s,11*s);
    line(10*s,15*s,14*s,15*s);                              line(12*s,13*s,12*s,14*s);
    line(10*s,17*s,11*s,17*s);                              line(12*s,17*s,12*s,18*s);
    line(10*s,20*s,11*s,20*s);                              line(12*s,19*s,12*s,22*s);
    line(10*s,21*s,12*s,21*s);                              line(12*s,22*s,12*s,24*s);
    line(11*s,7*s,12*s,7*s);                              line(13*s,1*s,13*s,3*s);
    line(11*s,9*s,12*s,9*s);                              line(13*s,7*s,13*s,10*s);
    line(11*s,13*s,12*s,13*s);                              line(13*s,11*s,13*s,12*s);
    line(11*s,16*s,13*s,16*s);                              line(13*s,14*s,13*s,15*s);
    line(11*s,19*s,12*s,19*s);                              line(13*s,18*s,13*s,21*s);
    line(11*s,22*s,16*s,22*s);                              line(13*s,24*s,13*s,25*s);
    line(12*s,4*s,14*s,4*s);                              line(14*s,2*s,14*s,5*s);
    line(12*s,14*s,13*s,14*s);                              line(14*s,6*s,14*s,7*s);
    line(12*s,17*s,14*s,17*s);                              line(14*s,10*s,14*s,11*s);
    line(12*s,18*s,13*s,18*s);                              line(14*s,13*s,14*s,14*s);
    line(12*s,24*s,13*s,24*s);                              line(14*s,15*s,14*s,17*s);
    line(13*s,5*s,16*s,5*s);                              line(14*s,19*s,14*s,20*s);
    line(13*s,8*s,18*s,8*s);                              line(14*s,21*s,14*s,22*s);
    line(13*s,11*s,15*s,11*s);                              line(14*s,23*s,14*s,24*s);
    line(13*s,13*s,14*s,13*s);                              line(15*s,1*s,15*s,2*s);
    line(13*s,20*s,14*s,20*s);                              line(15*s,7*s,15*s,8*s);
    line(13*s,23*s,15*s,23*s);                              line(15*s,9*s,15*s,10*s);
    line(14*s,3*s,17*s,3*s);                              line(15*s,11*s,15*s,13*s);
    line(13*s,9*s,15*s,9*s);                              line(15*s,14*s,15*s,21*s);
    line(14*s,14*s,16*s,14*s);                              line(16*s,6*s,16*s,7*s);
    line(14*s,18*s,15*s,18*s);                              line(16*s,8*s,16*s,9*s);
    line(14*s,24*s,19*s,24*s);                              line(16*s,10*s,16*s,11*s);
    line(15*s,2*s,16*s,2*s);                              line(16*s,12*s,16*s,13*s);
    line(15*s,4*s,19*s,4*s);                              line(16*s,18*s,16*s,20*s);
    line(15*s,10*s,16*s,10*s);                              line(16*s,21*s,16*s,23*s);
    line(15*s,12*s,16*s,12*s);                              line(17*s,2*s,17*s,3*s);
    line(15*s,16*s,17*s,16*s);                              line(17*s,4*s,17*s,6*s);
    line(15*s,21*s,16*s,21*s);                              line(17*s,9*s,17*s,11*s);
    line(16*s,7*s,17*s,7*s);                              line(17*s,13*s,17*s,15*s);
    line(15*s,17*s,20*s,17*s);                              line(17*s,19*s,17*s,22*s);
    line(16*s,11*s,22*s,11*s);                           //   line(17*s,24*s,17*s,25*s);
    line(16*s,13*s,18*s,13*s);                              line(18*s,2*s,18*s,3*s);
    line(16*s,15*s,17*s,15*s);                              line(18*s,5*s,18*s,10*s);
    line(16*s,18*s,21*s,18*s);                              line(18*s,12*s,18*s,17*s);
    line(16*s,20*s,17*s,20*s);                              line(18*s,18*s,18*s,19*s);
    line(16*s,23*s,18*s,23*s);                              line(18*s,22*s,18*s,23*s);
    line(17*s,2*s,20*s,2*s);                              line(19*s,3*s,19*s,6*s);
    line(17*s,21*s,20*s,21*s);                              line(19*s,11*s,19*s,16*s);
    line(18*s,7*s,20*s,7*s);                              line(19*s,19*s,19*s,20*s);
    line(18*s,10*s,19*s,10*s);                              line(19*s,23*s,19*s,24*s);
    line(18*s,20*s,20*s,20*s);                              line(20*s,4*s,20*s,5*s);
    line(18*s,22*s,19*s,22*s);                              line(20*s,7*s,20*s,8*s);
    line(19*s,3*s,21*s,3*s);                              line(20*s,9*s,20*s,10*s);
    line(19*s,6*s,21*s,6*s);                              line(20*s,12*s,20*s,15*s);
    line(19*s,9*s,21*s,9*s);                              line(20*s,21*s,20*s,23*s);
    line(19*s,16*s,21*s,16*s);                              line(21*s,1*s,21*s,4*s);
    line(19*s,19*s,21*s,19*s);                              line(21*s,6*s,21*s,9*s);
    line(19*s,23*s,20*s,23*s);                              line(21*s,14*s,21*s,18*s);
    line(20*s,5*s,22*s,5*s);                              line(21*s,19*s,21*s,21*s);
    line(20*s,10*s,21*s,10*s);                              line(21*s,23*s,21*s,24*s);
    line(20*s,14*s,21*s,14*s);                              line(22*s,2*s,22*s,6*s);
    line(20*s,22*s,22*s,22*s);                              line(22*s,8*s,22*s,11*s);
    line(21*s,7*s,22*s,7*s);                              line(22*s,13*s,22*s,17*s);
    line(20*s,12*s,24*s,12*s);                              line(22*s,18*s,22*s,19*s);
    line(21*s,13*s,23*s,13*s);                              line(22*s,21*s,22*s,23*s);
    line(21*s,20*s,23*s,20*s);                              line(23*s,1*s,23*s,2*s);
    line(21*s,24*s,24*s,24*s);                              line(23*s,3*s,23*s,4*s);
    line(22*s,3*s,24*s,3*s);                              line(23*s,6*s,23*s,8*s);
    line(22*s,6*s,23*s,6*s);                              line(23*s,9*s,23*s,10*s);
    line(22*s,8*s,23*s,8*s);                              line(23*s,13*s,23*s,14*s);
    line(22*s,10*s,23*s,10*s);                              line(23*s,17*s,23*s,19*s);
    line(22*s,15*s,25*s,15*s);                              line(23*s,20*s,23*s,23*s);
    line(22*s,17*s,24*s,17*s);                              line(24*s,2*s,24*s,3*s);
    line(22*s,19*s,26*s,19*s);                              line(24*s,4*s,24*s,6*s);
    line(22*s,23*s,23*s,23*s);                              line(24*s,7*s,24*s,9*s);
    line(23*s,5*s,24*s,5*s);                              line(24*s,10*s,24*s,11*s);
    line(23*s,7*s,25*s,7*s);                              line(24*s,12*s,24*s,13*s);
    line(23*s,11*s,25*s,11*s);                              line(24*s,20*s,24*s,24*s);
    line(23*s,14*s,24*s,14*s);                              line(25*s,3*s,25*s,4*s);
    line(23*s,16*s,28*s,16*s);                              line(25*s,5*s,25*s,6*s);
    line(24*s,2*s,26*s,2*s);                              line(25*s,9*s,25*s,12*s);
    line(24*s,4*s,26*s,4*s);                              line(25*s,13*s,25*s,15*s);
    line(24*s,6*s,26*s,6*s);                              line(25*s,16*s,25*s,18*s);
    line(24*s,9*s,25*s,9*s);                              line(25*s,21*s,25*s,23*s);
    line(24*s,18*s,25*s,18*s);                              line(26*s,2*s,26*s,3*s);
    line(24*s,20*s,25*s,20*s);                              line(26*s,4*s,26*s,5*s);
    line(24*s,23*s,25*s,23*s);                              line(26*s,6*s,26*s,9*s);
    line(25*s,8*s,26*s,8*s);                              line(26*s,14*s,26*s,16*s);
    line(26*s,3*s,27*s,3*s);                              line(26*s,18*s,26*s,20*s);
    line(27*s,2*s,28*s,2*s);                              line(26*s,22*s,26*s,24*s);
    line(26*s,5*s,27*s,5*s);                              line(27*s,1*s,27*s,2*s);
    line(26*s,9*s,27*s,9*s);                              line(27*s,3*s,27*s,4*s);
    line(25*s,10*s,26*s,10*s);                              line(27*s,5*s,27*s,7*s);
    line(25*s,13*s,27*s,13*s);                              line(27*s,9*s,27*s,11*s);
    line(25*s,17*s,31*s,17*s);                              line(27*s,12*s,27*s,15*s);
    line(26*s,18*s,27*s,18*s);                              line(27*s,22*s,27*s,23*s);
    line(26*s,20*s,30*s,20*s);                              line(28*s,2*s,28*s,3*s);
    line(25*s,21*s,28*s,21*s);                              line(28*s,4*s,28*s,6*s);
    line(26*s,22*s,27*s,22*s);                              line(28*s,9*s,28*s,11*s);
    line(25*s,24*s,27*s,24*s);                              line(28*s,13*s,28*s,16*s);
    line(27*s,23*s,28*s,23*s);                              line(28*s,17*s,28*s,19*s);
    line(27*s,19*s,31*s,19*s);                              line(28*s,0*s,28*s,0*s);
    line(27*s,4*s,29*s,4*s);                              line(28*s,21*s,28*s,22*s);
    line(27*s,8*s,30*s,8*s);                              line(28*s,23*s,28*s,25*s);
    line(25*s,12*s,29*s,12*s);                              line(29*s,2*s,29*s,4*s);
    line(27*s,8*s,31*s,8*s);                              line(29*s,8*s,29*s,9*s);
    line(28*s,6*s,29*s,6*s);                              line(29*s,10*s,29*s,12*s);
    line(26*s,11*s,28*s,11*s);                              line(29*s,13*s,29*s,14*s);
    line(28*s,9*s,29*s,9*s);                              line(29*s,20*s,29*s,21*s);
    line(28*s,22*s,29*s,22*s);                              line(29*s,22*s,29*s,24*s);
    line(29*s,5*s,30*s,5*s);                              line(30*s,1*s,30*s,7*s);
    line(29*s,10*s,30*s,10*s);                              line(30*s,9*s,30*s,10*s);
    line(28*s,13*s,31*s,13*s);                              line(30*s,11*s,30*s,13*s);
    line(28*s,15*s,30*s,15*s);                              line(30*s,14*s,30*s,15*s);
    line(29*s,16*s,32*s,16*s);                              line(30*s,20*s,30*s,24*s);
    line(29*s,18*s,32*s,18*s);                              line(31*s,2*s,31*s,3*s);
    line(29*s,24*s,30*s,24*s);                              line(31*s,4*s,31*s,11*s);
    line(30*s,11*s,31*s,11*s);                              line(31*s,12*s,31*s,13*s);
    line(30*s,23*s,31*s,23*s);                              line(31*s,14*s,31*s,16*s);
    line(31*s,3*s,32*s,3*s);                              line(31*s,19*s,31*s,22*s);
    line(31*s,24*s,32*s,24*s);


}
void map2()
{
    setcolor(YELLOW);
    int val=30;
    line(4*val,2*val,24*val,2*val);
    line(4*val,2*val,4*val,22*val);
    line(24*val,2*val,24*val,22*val);
    line(4*val,22*val,24*val,22*val);


    line(4*val,4*val,5*val,4*val);
    line(5*val,2*val,5*val,3*val);
    line(6*val,3*val,6*val,8*val);

    line(7*val,3*val,10*val,3*val);
    line(11*val,3*val,17*val,3*val);
    line(19*val,3*val,23*val,3*val);

    line(7*val,4*val,9*val,4*val);
    line(14*val,4*val,16*val,4*val);
    line(23*val,4*val,24*val,4*val);
    line(10*val,4*val,13*val,4*val);
    line(19*val,4*val,22*val,4*val);

    line(5*val,5*val,6*val,5*val);
    line(8*val,5*val,13*val,5*val);
    line(14*val,5*val,18*val,5*val);
    line(19*val,5*val,24*val,5*val);

    line(6*val,6*val,11*val,6*val);
    line(12*val,6*val,16*val,6*val);
    line(17*val,6*val,19*val,6*val);
    line(20*val,6*val,21*val,6*val);
    line(23*val,6*val,24*val,6*val);

    line(10*val,7*val,15*val,7*val);
    line(16*val,7*val,20*val,7*val);
    line(22*val,7*val,24*val,7*val);

    line(12*val,8*val,16*val,8*val);
    line(17*val,8*val,21*val,8*val);
    line(22*val,8*val,23*val,8*val);

    line(5*val,9*val,7*val,9*val);
    line(13*val,9*val,17*val,9*val);
    line(18*val,9*val,20*val,9*val);
    line(21*val,9*val,22*val,9*val);

    line(6*val,10*val,17*val,10*val);
    line(18*val,10*val,23*val,10*val);

    line(8*val,11*val,13*val,11*val);
    line(14*val,11*val,17*val,11*val);
    line(18*val,11*val,22*val,11*val);

    line(4*val,12*val,5*val,12*val);
    line(7*val,12*val,10*val,12*val);
    line(12*val,12*val,13*val,12*val);
    line(15*val,12*val,19*val,12*val);
    line(20*val,12*val,21*val,12*val);
    line(23*val,12*val,24*val,12*val);

    line(5*val,13*val,7*val,13*val);
    line(14*val,13*val,19*val,13*val);
    line(20*val,13*val,22*val,13*val);

    line(4*val,14*val,9*val,14*val);
    line(10*val,14*val,11*val,14*val);
    line(12*val,14*val,14*val,14*val);
    line(16*val,14*val,21*val,14*val);
    line(22*val,14*val,24*val,14*val);

    line(4*val,15*val,5*val,15*val);
    line(7*val,15*val,11*val,15*val);
    line(13*val,15*val,18*val,15*val);
    line(19*val,15*val,22*val,15*val);
    line(23*val,15*val,24*val,15*val);

    line(5*val,16*val,6*val,16*val);
    line(8*val,16*val,10*val,16*val);
    line(11*val,16*val,19*val,16*val);
    line(20*val,16*val,23*val,16*val);

    line(9*val,17*val,15*val,17*val);
    line(19*val,17*val,24*val,17*val);

    line(7*val,18*val,11*val,18*val);
    line(13*val,18*val,14*val,18*val);
    line(18*val,18*val,21*val,18*val);
    line(22*val,18*val,24*val,18*val);

    line(6*val,19*val,8*val,19*val);
    line(12*val,19*val,17*val,19*val);
    line(18*val,19*val,22*val,19*val);

    line(6*val,20*val,7*val,20*val);
    line(11*val,20*val,15*val,20*val);
    line(16*val,20*val,17*val,20*val);
    line(18*val,20*val,21*val,20*val);
    line(22*val,20*val,24*val,20*val);

    line(4*val,21*val,5*val,21*val);
    line(10*val,21*val,12*val,21*val);
    line(13*val,21*val,15*val,21*val);
    line(16*val,21*val,22*val,21*val);
    //*//
    line(5*val,2*val,5*val,3*val);
    line(5*val,6*val,5*val,12*val);
    line(5*val,16*val,5*val,20*val);

    line(6*val,10*val,6*val,12*val);
    line(6*val,14*val,6*val,15*val);
    line(6*val,17*val,6*val,19*val);
    line(6*val,21*val,6*val,22*val);

    line(7*val,4*val,7*val,5*val);
    line(7*val,7*val,7*val,9*val);
    line(7*val,10*val,7*val,14*val);
    line(7*val,15*val,7*val,17*val);
    line(7*val,20*val,7*val,22*val);

    line(8*val,6*val,8*val,10*val);
    line(8*val,12*val,8*val,13*val);
    line(8*val,16*val,8*val,17*val);
    line(8*val,19*val,8*val,22*val);

    line(9*val,2*val,9*val,3*val);
    line(9*val,5*val,9*val,6*val);
    line(9*val,7*val,9*val,9*val);
    line(9*val,13*val,9*val,14*val);
    line(9*val,15*val,9*val,16*val);
    line(9*val,18*val,9*val,21*val);

    line(10*val,6*val,10*val,9*val);
    line(10*val,11*val,10*val,12*val);
    line(10*val,13*val,10*val,14*val);
    line(10*val,13*val,10*val,14*val);
    line(10*val,16*val,10*val,17*val);
    line(10*val,18*val,10*val,21*val);

    line(11*val,8*val,11*val,10*val);
    line(11*val,11*val,11*val,13*val);
    line(11*val,19*val,11*val,20*val);

    line(12*val,8*val,12*val,9*val);
    line(12*val,12*val,12*val,13*val);
    line(12*val,14*val,12*val,16*val);
    line(12*val,18*val,12*val,19*val);
    line(12*val,21*val,12*val,22*val);

    line(13*val,4*val,13*val,5*val);
    line(13*val,13*val,13*val,14*val);

    line(14*val,3*val,14*val,4*val);
    line(14*val,8*val,14*val,9*val);
    line(14*val,11*val,14*val,12*val);
    line(14*val,13*val,14*val,14*val);
    line(14*val,17*val,14*val,18*val);

    line(15*val,6*val,15*val,7*val);
    line(15*val,14*val,15*val,15*val);
    line(15*val,17*val,15*val,19*val);
    line(15*val,20*val,15*val,22*val);

    line(16*val,7*val,16*val,8*val);
    line(16*val,16*val,16*val,18*val);

    line(17*val,4*val,17*val,5*val);
    line(17*val,9*val,17*val,10*val);
    line(17*val,16*val,17*val,19*val);
    line(17*val,20*val,17*val,21*val);

    line(18*val,2*val,18*val,5*val);
    line(18*val,6*val,18*val,7*val);
    line(18*val,10*val,18*val,11*val);
    line(18*val,12*val,18*val,13*val);
    line(18*val,16*val,18*val,18*val);
    line(18*val,19*val,18*val,20*val);

    line(19*val,7*val,19*val,8*val);
    line(19*val,9*val,19*val,10*val);
    line(19*val,15*val,19*val,17*val);

    line(20*val,11*val,20*val,13*val);

    line(21*val,2*val,21*val,3*val);
    line(21*val,6*val,21*val,8*val);
    line(21*val,16*val,21*val,17*val);

    line(22*val,3*val,22*val,4*val);
    line(22*val,6*val,22*val,7*val);
    line(22*val,9*val,22*val,10*val);
    line(22*val,13*val,22*val,14*val);
    line(22*val,19*val,22*val,20*val);

    line(23*val,8*val,23*val,10*val);
    line(23*val,11*val,23*val,13*val);
    line(23*val,18*val,23*val,19*val);
    line(23*val,21*val,23*val,22*val);

}
void map4()
{
    int scale=30;
    setcolor(6);

    //Vertical
    line(scale*1,scale*1,scale*1,scale*25);
    line(scale*32,scale*1,scale*32,scale*25);


    line(scale*4,scale*1,scale*4,scale*4);
    line(scale*8,scale*1,scale*8,scale*1);
    line(scale*11,scale*1,scale*11,scale*3);
    line(scale*24,scale*1,scale*24,scale*5);
     line(scale*22,scale*4,scale*22,scale*5);
    line(scale*25,scale*2,scale*25,scale*6);
    line(scale*29,scale*1,scale*29,scale*3);
    line(scale*9,scale*2,scale*9,scale*4);
    line(scale*13,scale*2,scale*13,scale*3);
    line(scale*15,scale*2,scale*15,scale*4);
    line(scale*2,scale*2,scale*2,scale*3);
    line(scale*6,scale*2,scale*6,scale*5);
    line(scale*9,scale*2,scale*9,scale*7);
    line(scale*14,scale*2,scale*14,scale*6);
    line(scale*16,scale*2,scale*16,scale*3);
    line(scale*19,scale*2,scale*19,scale*3);
    line(scale*21,scale*2,scale*21,scale*4);
    line(scale*23,scale*2,scale*23,scale*4);
    line(scale*28,scale*2,scale*28,scale*4);
    line(scale*31,scale*2,scale*31,scale*4);
    line(scale*5,scale*3,scale*5,scale*5);
    line(scale*7,scale*3,scale*7,scale*4);
    line(scale*17,scale*3,scale*17,scale*4);
    line(scale*18,scale*3,scale*18,scale*4);
    line(scale*8,scale*4,scale*8,scale*6);
    line(scale*12,scale*4,scale*12,scale*6);
    line(scale*16,scale*4,scale*16,scale*5);
    line(scale*20,scale*4,scale*20,scale*6);
    line(scale*28,scale*2,scale*28,scale*7);
    line(scale*29,scale*4,scale*29,scale*6);
    //line 5
    line(scale*7,scale*5,scale*7,scale*6);
    line(scale*10,scale*5,scale*10,scale*6);
    line(scale*17,scale*5,scale*17,scale*6);
    line(scale*18,scale*5,scale*18,scale*10);
    line(scale*23,scale*5,scale*23,scale*6);
    line(scale*27,scale*5,scale*27,scale*6);
    //line 6
    line(scale*5,scale*6,scale*5,scale*9);
    line(scale*6,scale*6,scale*6,scale*7);
    line(scale*11,scale*6,scale*11,scale*9);
    line(scale*13,scale*6,scale*13,scale*7);
    line(scale*15,scale*6,scale*15,scale*9);
    line(scale*16,scale*6,scale*16,scale*7);
    line(scale*19,scale*6,scale*19,scale*7);
    line(scale*21,scale*6,scale*21,scale*8);
    line(scale*26,scale*6,scale*26,scale*7);
    line(scale*30,scale*6,scale*30,scale*8);
    //7
    line(scale*7,scale*7,scale*7,scale*10);
    line(scale*10,scale*7,scale*10,scale*8);
    line(scale*12,scale*7,scale*12,scale*8);
    line(scale*17,scale*7,scale*17,scale*8);
    line(scale*20,scale*7,scale*20,scale*8);
    line(scale*22,scale*7,scale*22,scale*10);
    line(scale*24,scale*7,scale*24,scale*9);
    line(scale*27,scale*7,scale*27,scale*8);
    //8
    line(scale*4,scale*8,scale*4,scale*10);
    line(scale*8,scale*8,scale*8,scale*9);
    line(scale*14,scale*8,scale*14,scale*10);
    line(scale*16,scale*8,scale*16,scale*9);
    line(scale*26,scale*8,scale*26,scale*10);
    line(scale*28,scale*8,scale*28,scale*9);
    //9
    line(scale*2,scale*9,scale*2,scale*11);
    line(scale*3,scale*9,scale*3,scale*10);
    line(scale*6,scale*9,scale*6,scale*10);
    line(scale*10,scale*9,scale*10,scale*13);
    line(scale*12,scale*9,scale*12,scale*11);
    line(scale*17,scale*9,scale*17,scale*11);
    line(scale*20,scale*9,scale*20,scale*12);
    line(scale*23,scale*9,scale*23,scale*14);
    line(scale*27,scale*9,scale*27,scale*12);
    line(scale*29,scale*9,scale*29,scale*10);
    //10
    line(scale*5,scale*10,scale*5,scale*12);
    line(scale*9,scale*10,scale*9,scale*12);
    line(scale*13,scale*10,scale*13,scale*12);
    line(scale*15,scale*10,scale*15,scale*12);
    line(scale*21,scale*10,scale*21,scale*15);
    line(scale*30,scale*10,scale*30,scale*11);
    //11
    line(scale*3,scale*11,scale*3,scale*15);
    line(scale*6,scale*11,scale*6,scale*12);
    line(scale*11,scale*11,scale*11,scale*12);
    line(scale*16,scale*11,scale*16,scale*12);
    line(scale*19,scale*11,scale*19,scale*12);
    line(scale*24,scale*11,scale*24,scale*13);
    line(scale*29,scale*11,scale*29,scale*13);
    line(scale*31,scale*11,scale*31,scale*12);
    //12
    line(scale*2,scale*12,scale*2,scale*14);
    line(scale*4,scale*12,scale*4,scale*13);
    line(scale*7,scale*12,scale*7,scale*14);
    line(scale*8,scale*12,scale*8,scale*13);
    line(scale*12,scale*12,scale*12,scale*13);
    line(scale*14,scale*12,scale*14,scale*13);
    line(scale*17,scale*12,scale*17,scale*15);
    line(scale*22,scale*12,scale*22,scale*17);
    line(scale*26,scale*12,scale*26,scale*13);
    line(scale*28,scale*12,scale*28,scale*14);

    //13
    line(scale*6,scale*13,scale*6,scale*14);
    line(scale*9,scale*13,scale*9,scale*14);
    line(scale*11,scale*13,scale*11,scale*14);
    line(scale*16,scale*13,scale*16,scale*15);
    line(scale*25,scale*13,scale*25,scale*16);
    line(scale*27,scale*13,scale*27,scale*14);
    line(scale*31,scale*13,scale*31,scale*19);
    //14
    line(scale*8,scale*14,scale*8,scale*15);
    line(scale*10,scale*14,scale*10,scale*15);
    line(scale*12,scale*14,scale*12,scale*15);
    line(scale*15,scale*14,scale*15,scale*16);
    line(scale*19,scale*14,scale*19,scale*16);
    line(scale*20,scale*14,scale*20,scale*20);
    line(scale*24,scale*14,scale*24,scale*15);
    line(scale*26,scale*14,scale*26,scale*17);
    line(scale*29,scale*14,scale*29,scale*16);
    line(scale*30,scale*14,scale*30,scale*15);
    //15
    line(scale*2,scale*15,scale*2,scale*16);
    line(scale*6,scale*15,scale*6,scale*17);
    line(scale*9,scale*15,scale*9,scale*18);
    line(scale*11,scale*15,scale*11,scale*16);
    line(scale*13,scale*15,scale*13,scale*16);
    line(scale*14,scale*15,scale*14,scale*18);
    line(scale*23,scale*15,scale*23,scale*17);
    line(scale*28,scale*15,scale*28,scale*17);
    //16
    line(scale*4,scale*16,scale*4,scale*17);
    line(scale*7,scale*16,scale*7,scale*19);
    line(scale*10,scale*16,scale*10,scale*17);
    line(scale*12,scale*16,scale*12,scale*19);
    line(scale*30,scale*16,scale*30,scale*17);
//17
    line(scale*3,scale*17,scale*3,scale*20);
    line(scale*5,scale*17,scale*5,scale*20);
    line(scale*8,scale*17,scale*8,scale*19);
    line(scale*11,scale*17,scale*11,scale*20);
    line(scale*13,scale*17,scale*13,scale*18);
    line(scale*15,scale*17,scale*15,scale*18);
    line(scale*16,scale*17,scale*16,scale*19);
    line(scale*17,scale*17,scale*17,scale*19);
    line(scale*18,scale*17,scale*18,scale*18);
    line(scale*21,scale*17,scale*21,scale*19);
    line(scale*25,scale*17,scale*25,scale*20);
    line(scale*27,scale*17,scale*27,scale*18);
    line(scale*29,scale*17,scale*29,scale*18);

    //18
    line(scale*2,scale*18,scale*2,scale*21);
    line(scale*4,scale*18,scale*4,scale*21);
    line(scale*19,scale*18,scale*19,scale*19);
    line(scale*22,scale*18,scale*22,scale*20);
    line(scale*23,scale*18,scale*23,scale*20);
    line(scale*24,scale*18,scale*24,scale*24);
    line(scale*26,scale*18,scale*26,scale*19);
    line(scale*28,scale*18,scale*28,scale*19);
//19
    line(scale*9,scale*19,scale*9,scale*20);
    line(scale*14,scale*19,scale*14,scale*20);
    line(scale*16,scale*19,scale*16,scale*20);
    line(scale*18,scale*19,scale*18,scale*20);
    //20
    line(scale*6,scale*20,scale*6,scale*21);
    line(scale*10,scale*20,scale*10,scale*21);
    line(scale*13,scale*20,scale*13,scale*23);
    line(scale*15,scale*20,scale*15,scale*24);
    line(scale*19,scale*20,scale*19,scale*21);
    line(scale*21,scale*20,scale*21,scale*21);
    line(scale*22,scale*20,scale*22,scale*21);
    line(scale*27,scale*20,scale*27,scale*22);
    line(scale*29,scale*20,scale*29,scale*24);
    //21
    line(scale*3,scale*21,scale*3,scale*22);
    line(scale*5,scale*21,scale*5,scale*22);
    line(scale*8,scale*21,scale*8,scale*23);
    line(scale*18,scale*21,scale*18,scale*22);
    line(scale*23,scale*21,scale*23,scale*22);
    line(scale*26,scale*21,scale*26,scale*23);
    line(scale*30,scale*21,scale*30,scale*22);
    //22
    line(scale*4,scale*22,scale*4,scale*23);
    line(scale*14,scale*22,scale*14,scale*24);
    line(scale*16,scale*22,scale*16,scale*23);
    line(scale*19,scale*22,scale*19,scale*24);
    line(scale*21,scale*22,scale*21,scale*24);
    line(scale*28,scale*22,scale*28,scale*23);
    line(scale*31,scale*22,scale*31,scale*24);
    //23
    line(scale*2,scale*23,scale*2,scale*24);
    line(scale*3,scale*23,scale*3,scale*24);
    line(scale*5,scale*23,scale*5,scale*24);
    line(scale*9,scale*23,scale*9,scale*24);
    line(scale*10,scale*23,scale*10,scale*24);
    line(scale*17,scale*23,scale*17,scale*24);
    line(scale*20,scale*23,scale*20,scale*25);
    line(scale*23,scale*23,scale*23,scale*25);
    line(scale*27,scale*23,scale*27,scale*24);
    //24
    line(scale*4,scale*24,scale*4,scale*25);
    line(scale*8,scale*24,scale*8,scale*25);
    line(scale*16,scale*24,scale*16,scale*25);
    line(scale*18,scale*24,scale*18,scale*25);
    line(scale*26,scale*24,scale*26,scale*25);


//Horizontal lines |

line(scale*1,scale*1,scale*32,scale*1);
line(scale*1,scale*25,scale*32,scale*25);

//2
    line(scale*2,scale*2,scale*3,scale*2);
    line(scale*4,scale*2,scale*5,scale*2);
    line(scale*6,scale*2,scale*8,scale*2);
    line(scale*9,scale*2,scale*10,scale*2);
    line(scale*12,scale*2,scale*14,scale*2);
    line(scale*16,scale*2,scale*19,scale*2);
    line(scale*20,scale*2,scale*21,scale*2);
    line(scale*22,scale*2,scale*23,scale*2);
    line(scale*26,scale*2,scale*28,scale*2);
    line(scale*30,scale*2,scale*31,scale*2);
//3
    line(scale*2,scale*3,scale*3,scale*3);
    line(scale*7,scale*3,scale*9,scale*3);
    line(scale*10,scale*3,scale*12,scale*3);
    line(scale*15,scale*3,scale*16,scale*3);
    line(scale*17,scale*3,scale*18,scale*3);
    line(scale*19,scale*3,scale*20,scale*3);
    line(scale*21,scale*3,scale*22,scale*3);
    line(scale*25,scale*3,scale*27,scale*3);
    line(scale*29,scale*3,scale*30,scale*3);

    //4
    line(scale*1,scale*4,scale*2,scale*4);
    line(scale*7,scale*4,scale*8,scale*4);
    line(scale*9,scale*4,scale*12,scale*4);
    line(scale*16,scale*4,scale*17,scale*4);
    line(scale*18,scale*4,scale*21,scale*4);
    line(scale*22,scale*4,scale*24,scale*4);
    line(scale*26,scale*4,scale*31,scale*4);
//5
    line(scale*2,scale*5,scale*7,scale*5);
    line(scale*10,scale*5,scale*11,scale*5);
    line(scale*13,scale*5,scale*16,scale*5);
    line(scale*17,scale*5,scale*19,scale*5);
    line(scale*21,scale*5,scale*22,scale*5);
    line(scale*25,scale*5,scale*27,scale*5);
    line(scale*30,scale*5,scale*32,scale*5);
//6
    line(scale*2,scale*6,scale*6,scale*6);
    line(scale*10,scale*6,scale*11,scale*6);
    line(scale*12,scale*6,scale*13,scale*6);
    line(scale*15,scale*6,scale*17,scale*6);
    line(scale*19,scale*6,scale*25,scale*6);
    line(scale*26,scale*6,scale*27,scale*6);
    line(scale*29,scale*6,scale*31,scale*6);
//7

    line(scale*1,scale*7,scale*4,scale*7);
    line(scale*6,scale*7,scale*9,scale*7);
    line(scale*11,scale*7,scale*12,scale*7);
    line(scale*13,scale*7,scale*15,scale*7);
    line(scale*16,scale*7,scale*17,scale*7);
    line(scale*22,scale*7,scale*23,scale*7);
    line(scale*24,scale*7,scale*26,scale*7);
    line(scale*27,scale*7,scale*29,scale*7);
    line(scale*31,scale*7,scale*32,scale*7);
//8
    line(scale*1,scale*8,scale*4,scale*8);
    line(scale*6,scale*8,scale*7,scale*8);
    line(scale*8,scale*8,scale*9,scale*8);
    line(scale*12,scale*8,scale*14,scale*8);
    line(scale*17,scale*8,scale*20,scale*8);
    line(scale*22,scale*8,scale*24,scale*8);
    line(scale*25,scale*8,scale*27,scale*8);
    line(scale*28,scale*8,scale*30,scale*8);

//9
    line(scale*2,scale*9,scale*3,scale*9);
    line(scale*5,scale*9,scale*6,scale*9);
    line(scale*8,scale*9,scale*11,scale*9);
    line(scale*13,scale*9,scale*14,scale*9);
    line(scale*15,scale*9,scale*17,scale*9);
    line(scale*19,scale*9,scale*22,scale*9);
    line(scale*24,scale*9,scale*25,scale*9);
    line(scale*29,scale*9,scale*32,scale*9);

//10
    line(scale*4,scale*10,scale*5,scale*10);
    line(scale*7,scale*10,scale*9,scale*10);
    line(scale*12,scale*10,scale*13,scale*10);
    line(scale*14,scale*10,scale*15,scale*10);
    line(scale*18,scale*10,scale*19,scale*10);
    line(scale*23,scale*10,scale*26,scale*10);
    line(scale*27,scale*10,scale*31,scale*10);


//11
    line(scale*2,scale*11,scale*4,scale*11);
    line(scale*6,scale*11,scale*9,scale*11);
    line(scale*11,scale*11,scale*12,scale*11);
    line(scale*14,scale*11,scale*15,scale*11);
    line(scale*16,scale*11,scale*19,scale*11);
    line(scale*21,scale*11,scale*23,scale*11);
    line(scale*24,scale*11,scale*26,scale*11);
    line(scale*28,scale*11,scale*29,scale*11);


//12
    line(scale*4,scale*12,scale*6,scale*12);
    line(scale*7,scale*12,scale*8,scale*12);
    line(scale*13,scale*12,scale*14,scale*12);
    line(scale*17,scale*12,scale*18,scale*12);
    line(scale*19,scale*12,scale*20,scale*12);
    line(scale*25,scale*12,scale*26,scale*12);
    line(scale*29,scale*12,scale*32,scale*12);

//13
    line(scale*4,scale*13,scale*5,scale*13);
    line(scale*6,scale*13,scale*7,scale*13);
    line(scale*8,scale*13,scale*10,scale*13);
    line(scale*11,scale*13,scale*16,scale*13);
    line(scale*17,scale*13,scale*21,scale*13);
    line(scale*24,scale*13,scale*27,scale*13);
    line(scale*29,scale*13,scale*31,scale*13);

    //14
    line(scale*1,scale*14,scale*2,scale*14);
    line(scale*3,scale*14,scale*6,scale*14);
    line(scale*10,scale*14,scale*11,scale*14);
    line(scale*12,scale*14,scale*15,scale*14);
    line(scale*18,scale*14,scale*20,scale*14);
    line(scale*23,scale*14,scale*24,scale*14);
    line(scale*27,scale*14,scale*30,scale*14);

    //15
    line(scale*2,scale*15,scale*3,scale*15);
    line(scale*4,scale*15,scale*10,scale*15);
    line(scale*11,scale*15,scale*12,scale*15);
    line(scale*16,scale*15,scale*18,scale*15);
    line(scale*21,scale*15,scale*22,scale*15);
    line(scale*23,scale*15,scale*24,scale*15);
    line(scale*26,scale*15,scale*28,scale*15);

    //16
    line(scale*2,scale*16,scale*5,scale*16);
    line(scale*8,scale*16,scale*9,scale*16);
    line(scale*10,scale*16,scale*13,scale*16);
    line(scale*14,scale*16,scale*19,scale*16);
    line(scale*20,scale*16,scale*21,scale*16);
    line(scale*24,scale*16,scale*25,scale*16);
    line(scale*26,scale*16,scale*27,scale*16);
    line(scale*29,scale*16,scale*30,scale*16);

    //17
    line(scale*2,scale*17,scale*3,scale*17);
    line(scale*4,scale*17,scale*5,scale*17);
    line(scale*6,scale*17,scale*7,scale*17);
    line(scale*15,scale*17,scale*16,scale*17);
    line(scale*18,scale*17,scale*20,scale*17);
    line(scale*21,scale*17,scale*22,scale*17);
    line(scale*23,scale*17,scale*26,scale*17);
    line(scale*27,scale*17,scale*29,scale*17);
    line(scale*30,scale*17,scale*31,scale*17);

    //18
    line(scale*1,scale*18,scale*2,scale*18);
    line(scale*3,scale*18,scale*4,scale*18);
    line(scale*5,scale*18,scale*6,scale*18);
    line(scale*9,scale*18,scale*11,scale*18);
    line(scale*13,scale*18,scale*14,scale*18);
    line(scale*17,scale*18,scale*18,scale*18);


    //19
    line(scale*6,scale*19,scale*8,scale*19);
    line(scale*9,scale*19,scale*10,scale*19);
    line(scale*12,scale*19,scale*16,scale*19);
    line(scale*18,scale*19,scale*19,scale*19);
    line(scale*26,scale*19,scale*31,scale*19);

//20
    line(scale*5,scale*20,scale*9,scale*20);
    line(scale*10,scale*20,scale*13,scale*20);
    line(scale*16,scale*20,scale*18,scale*20);
    line(scale*20,scale*20,scale*22,scale*20);
    line(scale*23,scale*20,scale*24,scale*20);
    line(scale*25,scale*20,scale*31,scale*20);

    //21
    line(scale*3,scale*21,scale*5,scale*21);
    line(scale*6,scale*21,scale*8,scale*21);
    line(scale*9,scale*21,scale*12,scale*21);
    line(scale*13,scale*21,scale*20,scale*21);
    line(scale*22,scale*21,scale*23,scale*21);
    line(scale*25,scale*21,scale*26,scale*21);
    line(scale*27,scale*21,scale*28,scale*21);
    line(scale*30,scale*21,scale*32,scale*21);

//22
    line(scale*1,scale*22,scale*3,scale*22);
    line(scale*5,scale*22,scale*7,scale*22);
    line(scale*8,scale*22,scale*12,scale*22);
    line(scale*17,scale*22,scale*18,scale*22);
    line(scale*19,scale*22,scale*23,scale*22);
    line(scale*24,scale*22,scale*25,scale*22);
    line(scale*30,scale*22,scale*31,scale*22);

    //23
    line(scale*3,scale*23,scale*9,scale*23);
    line(scale*10,scale*23,scale*13,scale*23);
    line(scale*16,scale*23,scale*19,scale*23);
    line(scale*22,scale*23,scale*24,scale*23);
    line(scale*25,scale*23,scale*28,scale*23);
    line(scale*29,scale*23,scale*30,scale*23);

    //24
    line(scale*2,scale*24,scale*3,scale*24);
    line(scale*6,scale*24,scale*8,scale*24);
    line(scale*9,scale*24,scale*10,scale*24);
    line(scale*11,scale*24,scale*14,scale*24);
    line(scale*16,scale*24,scale*17,scale*24);
    line(scale*21,scale*24,scale*22,scale*24);
    line(scale*25,scale*24,scale*26,scale*24);
    line(scale*27,scale*24,scale*29,scale*24);
    line(scale*30,scale*24,scale*31,scale*24);
}




void map5()
{
    setcolor(WHITE);
    line(20,40,20,700);
    line(50,40,1000,40);
    line(1000,40,1000,700);
    line(20,700,970,700);
    line(50,100,50,300);
    line(50,100,150,100);
    line(50,300,300,300);
    line(100,300,100,450);
    line(20,550,150,550);
    line(250,40,250,300);
    line(300,300,300,400);
    line(300,400,200,400);
    line(200,400,200,600);
    line(200,600,50,600);
    line(550,700,550,600);
    line(300,700,300,600);
    line(450,600,700,600);
    line(700,600,700,400);
    line(450,600,450,400);
    line(550,400,800,400);
    line(550,400,550,300);
    line(800,400,800,250);
    line(1000,600,900,600);
    line(1000,450,800,450);
    line(950,450,950,500);
    line(650,150,800,150);
    line(850,450,850,650);
    line(700,150,800,150);
    line(600,40,600,300);
    line(500,40,500,560);
    line(400,40,400,600);
}


void map7()
{
    setcolor(6);
    line(20,40,20,640);
    line(20,40,320,40);
    line(350,40,620,40);
    line(620,40,620,640);
    line(20,640,620,640);
    line(50,40,50,100);
    line(20,130,80,130);
    line(80,130,80,70);
    line(80,100,110,100);

    line(80,100,110,100);
    line(110,100,110,160);
    line(50,130,50,220);
    line(50,220,110,220);
    line(110,220,110,280);
    line(20,250,80,250);
    line(80,250,80,310);
    line(80,310,170,310);

    line(140,70,140,280);
    line(110,70,170,70);
    line(140,130,170,130);
    line(140,160,230,160);
    line(80,190,140,190);
    line(80,190,80,160);
    line(140,250,170,250);
    line(200,40,200,130);
    line(170,100,200,100);

    line(260,40,260,70);
    line(230,70,260,70);
    line(230,100,260,100);
    line(260,100,260,160);
    line(260,160,290,160);
    line(290,160,290,220);
    line(290,220,320,220);
    line(320,100,320,220);
    line(290,100,320,100);
    line(290,100,290,130);
    line(320,160,350,160);
    line(350,160,350,70);
    line(350,70,290,70);
    line(350,130,440,130);

    line(440,130,440,190);
    line(440,190,500,190);
    line(500,130,500,190);
    line(470,130,590,130);
    line(620,100,590,100);
    line(590,70,560,70);
    line(560,70,560,160);
    line(590,160,560,160);
    line(590,160,590,190);

    line(560,130,560,70);
    line(560,70,590,70);
    line(440,100,500,100);
    line(530,70,530,130);
    line(530,70,470,70);
    line(470,70,470,100);
    line(530,160,530,190);
    line(530,190,560,190);
    line(560,190,560,280);
    line(560,220,590,220);
    line(530,250,560,250);
    line(530,250,530,220);
    line(560,280,590,280);
    line(590,250,620,250);
    line(620,310,590,310);
    line(590,280,590,310);

    line(440,40,440,70);
    line(410,70,440,70);
    line(410,70,410,130);
    line(380,40,380,100);
    line(230,130,230,220);
    line(230,190,260,190);
    line(200,190,170,190);
    line(170,190,170,220);
    line(200,220,170,220);
    line(200,220,200,280);
    line(260,190,260,250);
    line(260,250,380,250);
    line(380,250,380,220);

    line(350,190,350,430);
    line(350,430,380,430);
    line(380,430,380,340);
    line(380,340,440,340);
    line(380,400,410,400);
    line(350,190,380,190);
    line(380,190,380,160);
    line(380,160,410,160);
    line(410,160,410,310);
    line(380,310,410,310);

    line(410,220,500,220);
    line(500,220,500,280);
    line(470,280,530,280);
    line(470,370,470,280);
    line(440,310,470,310);
    line(530,280,530,310);
    line(530,310,560,310);
    line(560,310,560,400);
    line(530,400,560,400);

    line(470,130,470,160);
    line(440,250,470,250);
    line(440,250,440,280);
    line(380,280,440,280);
    line(530,340,530,400);
    line(500,340,530,340);
    line(500,310,500,340);
    line(560,340,590,340);
    line(590,370,590,520);
    line(500,430,590,430);
    line(500,430,500,460);
    line(500,460,560,460);
    line(560,490,590,490);
    line(530,460,530,520);

    line(500,520,560,520);
    line(500,520,500,550);
    line(470,550,500,550);
    line(470,550,470,640);
    line(500,580,500,640);
    line(590,610,620,610);
    line(560,610,530,610);
    line(560,580,590,580);
    line(590,550,620,550);
    line(590,550,590,580);
    line(560,580,560,610);
    line(560,520,560,550);
    line(530,550,560,550);
    line(530,550,530,580);

    line(500,370,410,370);
    line(500,370,500,400);
    line(470,400,500,400);
    line(470,400,470,520);
    line(440,520,470,520);
    line(440,520,440,610);
    line(440,610,380,610);
    line(380,610,380,580);
    line(410,580,290,580);
    line(290,580,290,610);
    line(260,610,290,610);
    line(200,610,230,610);
    line(200,610,200,640);
    line(230,610,230,520);
    line(200,580,200,520);
    line(170,580,200,580);
    line(170,610,170,550);
    line(50,550,170,550);
    line(140,610,170,610);
    line(80,640,80,550);
    line(20,580,50,580);
    line(20,520,170,520);
    line(80,520,80,460);

    line(50,580,50,610);
    line(110,580,110,640);
    line(110,580,140,580);
    line(140,490,140,520);
    line(50,280,50,370);
    line(20,370,50,370);
    line(80,340,80,400);
    line(80,370,140,370);
    line(140,340,140,430);
    line(140,400,170,400);
    line(170,400,170,430);
    line(20,490,50,490);
    line(50,460,80,460);
    line(50,430,110,430);
    line(50,400,50,430);
    line(110,400,110,490);
    line(110,460,230,460);

    line(170,490,260,490);
    line(170,490,170,460);
    line(260,430,260,580);
    line(260,550,290,550);
    line(260,520,320,520);


    line(110,310,110,340);
    line(170,340,170,280);
    line(170,280,230,280);
    line(230,280,230,250);
    line(200,310,290,310);
    line(260,370,260,280);
    line(230,370,350,370);
    line(170,430,200,430);
    line(200,400,320,400);

    line(440,550,320,550);
    line(320,520,320,550);
    line(350,520,350,460);
    line(290,460,350,460);
    line(290,490,350,490);
    line(380,460,440,460);
    line(440,460,440,490);
    line(410,490,410,520);
    line(380,490,380,550);
    line(380,490,410,490);
    line(410,430,410,460);

    line(440,370,440,400);
    line(140,340,230,340);
    line(200,340,200,400);
    line(230,430,290,430);
    line(170,370,200,370);
    line(290,340,320,340);
    line(320,280,320,340);
    line(290,280,290,250);
    line(260,250,290,250);
    line(470,430,410,430);
    line(290,280,320,280);
    line(320,400,320,460);
    line(470,490,500,490);
    line(320,640,320,580);
    line(350,610,350,640);

}
