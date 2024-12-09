#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n , num , mn=INT_MAX , mx=INT_MIN , maxSum = 0 , minSum=0;
    cin>>n;
    vector<int>arr;
    while(n--)
    {
        cin>>num;
        if(num<mn) mn=num;
        if(num>mx) mx=num;
        arr.push_back(num);
    }
    for(int i=0 ; i<arr.size() ; i++)
    {
        if(mn!=arr[i])maxSum+=arr[i];
        if(mx!=arr[i])minSum+=arr[i];
    }
    cout<<minSum<<" "<<maxSum<<endl;
    return 0;
}
