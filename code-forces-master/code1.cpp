#include<iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n] , flat=0;
        for(int i=0 ; i<n ; i++)
        {
            cin>>arr[i];
            if(arr[i]!=i+1) flat =1;
        }
        if(flat==0) cout<<0<<endl;
        else if(arr[n-1]==n || arr[0]==1) cout<<1<<endl;
        else if(arr[n-1]==1 && arr[0]==n) cout<<3<<endl;
        else cout<<2<<endl;

    }
    return 0;
}
