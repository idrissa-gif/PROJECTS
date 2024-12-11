#include<iostream>
#include<vector>
using namespace std;

int main ()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int> arr;
        for(int i=0 ; i<n ; i++)
        {
            int a;
            cin>>a;
            arr.push_back(a);
        }
        bool ch=true;
        for(int i=0 , j=n-1 ; i<=j; )
        {
            if(ch==true)
            {
                cout<<arr[i]<<' ';
                ch=false;
                i++;
            }
            else 
            {
                cout<<arr[j]<<' ';
                ch=true;
                j++;
            }
        }
        cout<<endl;
    }
    return 0;
}