#include<iostream>
#include<cmath>

using namespace std;

typedef  long long int  lld;
int main()
{
    lld n , a , b=0 , c;
    cin>>n;
    c=n%2;
    lld num=n-c;

    cout<<b<<endl;
    a=num/pow(2,b-1);
        cout<<a+b-1+c<<endl;
    return 0;
}
