#include <iostream>
#include<queue>
#include<cstring>
#include<vector>
int solution(int A, int B) {
   int result=0;
   int num=A*B;
   int count=0;
   for(int i=1;num>0;i*=10)
   {
       int binary=num%2;
       if(binary!=0) count++;
       result+=binary*i;
       num/=2;
   }
   return count;
}
using namespace std;
string str;
int main()
{
   cout<<solution(9,10);
   return 0;
}