#include<iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a;
    vector<int>A;
    for(int i=0 ; i<3 ; i++)
    {
        cin>>a;
        A.push_back(a);
    }
    sort(A.begin(),A.end());
    if ((A[2]-A[1])==(A[1]-A[0])) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
