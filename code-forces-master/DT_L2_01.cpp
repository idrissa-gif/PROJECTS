#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n , num , sum = 0, cnt=0 , flat=1 , mn=INT_MIN;
    cin>>n;
    for(int i=0 ; i<n ; i++)
    {
        cin>>num;
        if(num>=0)
        {
            sum+=num;
            cnt++;
            flat=0;
        }
        if(mn<num)
            mn=num;
    }
    flat==0 ? cout<<sum<<" "<<cnt<<endl: cout<<mn<<" "<<1<<endl;
    return 0;
}
