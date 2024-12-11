
#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

int main ()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n ;
        cin>>n;
        if(n<10) cout<<n<<endl;
        else
        {
            if(n%10==0) cout<<int(log10(n)*9)<<endl;
            else
            {
                int result = (int)log10(n);
                cout<<(result*9)-1<<endl;
            }
        }
    }
    return 0;
}
