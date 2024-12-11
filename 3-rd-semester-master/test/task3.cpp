#include <iostream>
#include <bits/stdc++.h>

using namespace std;
unordered_map<int,int> pairSum(int arr[], int n, int sum)
{
    unordered_map<int,int> a;
    unordered_map<int,int> HashSet;
    for(int i=0 ; i<n ; i++) 
    {
        if(HashSet.find(arr[i])==HashSet.end()) HashSet.insert(i,arr[i]);
    }
    for(int i=0 ; i<n ; i++)
    {
        int s=sum-arr[i];
        if(a.find(arr[i])==a.end()) i++;
        else  a.insert(arr[i],s);
    }
    return a;
}
int main()
{
    int n, sum;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[n];
    cin >> sum;
    unordered_map<int,int> a = pairSum(arr, n, sum);
    for (auto i : a)
        cout << '(' << i.first << ", " << i.second << ')' << ' ';
    
    return 0;
}