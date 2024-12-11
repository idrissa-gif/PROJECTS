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
        int arr[n] , count =0 ;
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];
        for(int i=0 ; i< n-1  ; i++)
            if(arr[i]>arr[i]) count++;
        cout<<count<<endl;
    }
    return 0;
}
