#include<iostream>
#include<math.h>
using namespace std;
int __gcd(int a , int b)
{
    if(b==0) return a;
    return __gcd(b,a%b);

}
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        int b=100;
        while(1)
        {
            if(__gcd(b,k)==1) break;
            b=b/__gcd(b,k);
            k=k/__gcd(b,k);
        }

        cout<<b<<endl;
    }
    return 0;
}
