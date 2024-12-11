#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool issubarray(vector<int> a, vector<int> b) 
{
    set<int> hashSet;
    for(auto i:a)
    {
        hashSet.insert(i);
    }
    for(auto j:b)
    {
        if(hashSet.find(j)==hashSet.end())
            return false;
    }
    return true;
}

int main()
{
    int size_a, size_b;
    cin >> size_a >> size_b;
    vector<int> a_arr(size_a), b_arr(size_b);
    for (int i = 0; i < size_a; i++)
    {
        int a;
        cin >> a;
        a_arr.push_back(a);
    }
    for (int i = 0; i < size_b; i++)
    {
        int b;
        cin >> b;
        b_arr.push_back(b);
    }
    bool ch = issubarray(a_arr,b_arr);
    if(ch)
        cout << "B is the subarray of the array A" << endl;
    else
        cout << "B is not the subarray of the array A" << endl;
    return 0;
}