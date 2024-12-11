#include <iostream>
#include <bits/stdc++.h>

using namespace std;
pair<int, int> mostfrequent(int arr[], int sze)
{
    int n, max = INT_MIN;
    unordered_map<int, int> HashSet;
    for (int i = 0; i < sze; i++)
    {
        HashSet[arr[i]]++;
    }
    for (auto j : HashSet)
    {
        if (j.second > max)
        {
            max = j.second;
            n = j.first;
        }
    }
    return pair<int, int>(n, max);
}
int main()
{
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    pair<int, int> a = mostfrequent(arr, size);
    cout << a.first << " " << a.second << endl;
    return 0;
}