#include<iostream>
#include<vector>
using namespace std;
void backtrack(vector<int>& arr, vector<int> & subset, int index , vector<vector<int>> & result)
{
    if(subset.size()!=0) result.push_back(subset);
    for(int i=index ; i<arr.size() ; i++)
    {
        subset.push_back(arr[i]);
        backtrack(arr,subset,i+1,result);
        subset.pop_back();
    }
    return ;
}
vector<vector<int>> subsets(vector<int> A)
{
    vector<vector<int>> result;
    vector<int>subset;
    backtrack(A,subset,0,result);
    return result;
}
int main()
{
    vector<int> arr = {1,2 ,3};
    vector<vector<int>> ans = subsets(arr);
    for(auto i:ans)
    {
         for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
