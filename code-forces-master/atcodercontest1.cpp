#include<iostream>
#include<iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int h , w;
    cin>>h>>w;
    char grid[h][w];
    for(int i= 0 ; i<h ; i++)
        for(int j=0 ; j<w ; j++)
            cin>>grid[i][j];
    if(h==1&&w==1) cout<<"Draw"<<endl;
    else
    if(grid[h-1][w-1]=='-') cout<<"Takahashi"<<endl;
    else  cout<<"Aoki"<<endl;
    return 0;
}

