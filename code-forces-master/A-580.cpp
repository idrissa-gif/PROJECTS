#include<iostream>
#include<vector>

using namespace std;

int main ()
{
    int n , a , max = INT_MIN , count =0 ;
    cin>>n;
    vector<int> arr;
    for(int i=0 ; i<n ; i++)
    {
        cin>>a;
        arr.push_back(a);
    }
    for(int i=0 ; i<n-1 ; i++)
    {
        if(arr[i]<=arr[i+1]) count++;
        else 
        {
            if(count>max) max=count;
            count=0;
        }
    }
    if(count>max) max=count;
    cout<<max+1;
    return 0;
}