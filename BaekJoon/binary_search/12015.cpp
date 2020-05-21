#include<iostream>
using namespace std;
int DP[1000000];
int arr[1000000];
int N;
int main()
{ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>N; //전값보다 크면 cnt++;
  for(int i=0;i<N;i++)
  {   
      cin>>arr[i];
  }
  for(int i=0;i<N;i++)
  {
      for(int j=i;j<N;j++)
      {

      }
  }
  return 0;
}