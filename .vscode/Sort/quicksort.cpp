#include<iostream>
#include<vector>
using namespace std;
void quicksort(vector<int> &arr)
{   int size=arr.size();
    vector<int> left;
    vector<int> right;
    for(int i=1;i<size;i++)
    {
        if(arr[0]>arr[i]) right.push_back(arr[i]);
        else left.push_back(arr[i]);
    }
    int index=left.size();
    arr[index]=arr[0];
    if(left.size()>0) quicksort(left);
    if(right.size()>0) quicksort(right);
    copy(left.begin(),left.end(),arr.begin());
    copy(right.begin(),right.end(),arr.begin()+index+1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[]={12,32,14,43,55,21,11,31,5,17,9,4,2,100,49,321,134,27,33,19};
    vector<int> vec(20);
    copy(arr+0,arr+20,vec.begin());
    quicksort(vec);
    for(int i=0;i<20;i++) cout<<vec[i]<<endl;
    return 0;
}