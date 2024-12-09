#include<cmath>
#include<iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int A,B,temp=0, res,no=1,mul=1,x;
        cin>>A>>B;
        again:
        temp=A*B*10;
            while(res%A!=0)
            {
                x=no*A;
                res=temp-x;
                no++;
            }
            if(res+x==temp)
            {
                cout<<"YES"<<endl;
                cout<<x<<" "<<res<<" "<<temp<<endl;
            }
            else if(mul<=1000)
            {
                mul*=10;
                goto again;
            }
            else
                cout<<"NO"<<endl;

       // cout<<x<<" "<<res<<" "<<temp<<endl;
    }
    return 0;
}
