#include<iostream>
#include<cstring>
#include<bits/stdc++.h>

using namespace std;

int main ()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n , flat = 0;
        map<char, int> countchar;
        cin>>n;
        char str[n];
        cin>>str;
        for(int i=1 ; i < n; i++)
        {
            while(str[i]==str[i-1])
            {
                i++;
            }
            countchar[str[i-1]]=1;
            if(countchar.find(str[i])->second==1)
            {
                cout<<"NO"<<endl;
                flat=1;
                break;
            }
        }

        if(flat==0) cout<<"YES"<<endl;
    }
    return 0;
}
