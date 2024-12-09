#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n , num;
    vector<int>arr;
    cin>>n;
    for(int  i=0 ; i<n ; i++)
    {
        cin>>num;
        arr.push_back(num);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int l = 0 , h = n-1;
        int m;
        cin>>m;
        int mid=l+(h-l)/2;
        while(l<=h)
        {
            mid=l+(h-l)/2;
            if(arr[mid]>m) h=mid-1;
            else l = mid + 1;
        }
                cout<<l<<" ";
                int result=0;
                for(int i=0 ; i<l; i++)
                    result+=arr[i];
                cout<<result<<endl;
    }
    return 0;
}
