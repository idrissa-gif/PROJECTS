#include<iostream>
#include<vector>
#include<cmath>
#include<ctime>

using namespace std;

typedef long long int lld;

void InsertionSort(vector<lld> A)
{
    for(int j=1 ; j<A.size() ; j++)
    {
        lld key = A[j];
        int i=j-1;
        while(i>=0&&A[i]>key)
        {
            A[i+1]=A[i];
            i--;
        }
        A[i+1]=key;
    }
    for(auto pr : A)
        cout<<pr<<" ";
    cout<<endl;
}
void BubbleSort(vector<lld>A)
{
    for(int i=0 ; i<A.size() ; i++)
    {
        for(int j=A.size()-1 ; j>i ;j--)
        if(A[j]<A[j-1])
        {
            lld temp=A[j];
            A[j]=A[j-1];
            A[j-1]=temp;
        }
    }
    for(auto pr : A)
        cout<<pr<<" ";
    cout<<endl;
}
int main()
{
    vector<lld>A;
    lld n ;
    cout<<"Give size of Input: ";
    cin>>n;
    cout<<"\n\nGenerating random input set . . .Done.\n\n";
    srand(time(0));
    while(n--)
    {
        A.push_back(rand());
    }
    cout<<"Applying Insertion sort . . ."<<endl;
    clock_t time_req =clock();
    InsertionSort(A);
    time_req = clock() - time_req;
    cout<<"Total comparisons: "<<clock()<<endl;
    cout<<"Total clock ticks: "<<time_req<<"("<<(float)time_req/CLOCKS_PER_SEC<<" seconds)"<<endl;

    cout<<"\nApplying Bubble sort . . ."<<endl;
    time_req =clock();
    BubbleSort(A);
    time_req = clock() - time_req;
    cout<<"Total comparisons: "<<clock()<<endl;
    cout<<"Total clock ticks: "<<time_req<<"("<<(float)time_req/CLOCKS_PER_SEC<<" seconds)"<<endl;
    return 0;
}
