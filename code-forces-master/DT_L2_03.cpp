#include<iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n , a , b;
        cin>>n>>a>>b;
        int x , y , x_res, y_res , result , temp=INT_MAX;
        x = a>b ? 0 : n;
        y = a>b ? n : 0;
        if(n==1)
        {
            a>b?cout<<b<<" "<<0<<" "<<n<<endl:cout<<a<<" "<<n<<" "<<0<<endl;
        }
        else
        for(int i=0 ; i<n ; i++)
        {
            result=a*(x*x) + b*(y*y);
            //cout<<result<<" "<< temp<<" "<<x_res<<" "<<y_res<< endl;

            if(temp<result)
            {
                cout<<temp<<" "<<x_res<<" "<<y_res<<endl;
                break;
            }
            temp=result;
             if(x>y)
            {
                x_res=x;
                y_res=y;
                x--;
                y++;
            }
            else
            {
                x_res=x;
                y_res=y;
                x++;
                y--;
            }
        }
    }
    return 0;
}
