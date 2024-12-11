#include<iostream>
#include<cstring>
#include<bits/stdc++.h>

using namespace std;

int main ()
{
    int n ;
    map<char,int> mp;
    cin>>n;
    char t[n] , s[n];
    for(int i = 0 ; i<n; i++)
    {
        cin>>t[i];
        mp[t[i]]++;
    }
    for(int i = 0 ; i<n; i++)
    {
        cin>>s[i];
        mp[s[i]]--;
    }
    int flat=1;
    for(auto m : mp)
    {
       if(m.second)
       {
           cout<<-1<<endl;
             flat=0;
           break;

       }
    }
    if(flat!=0)
    {
        int cnt=0;
        for(int i=0 ;  i< n ; i++)
            if(s[i]!=t[i]) cnt++;
        cout<<cnt<<endl;
    }
    return 0;
}
