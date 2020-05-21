#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> vec;
int N,K; //if 3*3 a[2][2]까지가 최대 즉 N-1인 숫자 두개를 조합하는것.!
int value=0;
int min(int a,int b){return a<b?a:b;}
void binary_search() //K번째 수를 구해야함 
{ 
    int first=1, last=K;
   int mid=(first+last)/2;
   while(first<=last)
   {    
        mid=(first+last)/2;
        long long cnt=0;
       for(int i=1;i<=N;i++)
       {
           cnt+=min(mid/i,N);
       }
       if(cnt<K)
       { 
           first=mid+1;
       }
       else{
           value=mid;   
           last=mid-1;
       }
   }
   cout<<value;
}
int main()
{  
    cin>>N>>K;
    binary_search();
    return 0;
}