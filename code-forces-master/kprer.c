#include<iostream>

using namespace std;

int main ()
{
    int t;
    while(t--)
    {
        int k;
        cin>>k;
        int b=100;
        int g=__gcd(k,b);
        b=b/g;
        k=a/g;
        cout<<k<<endl;
    }
    return 0;
}
