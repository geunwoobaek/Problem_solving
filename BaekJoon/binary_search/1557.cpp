#include<iostream>
#include<math.h>
using namespace std;
int Right=1000000000;
int Left=1;
int N;
int main()
{
cin>>N;
while(Left<Right) //N*N 뒤에서 제곱수는 N-1개이다. 100일경우 제곱수가 9개이다.  90번째수는
{  //바이너리서치통해서 해당숫자뒤에 제곱수가 몇개인지 발견 그리고 해당숫자가 몇번째숫자인지 발견
   int mid=(Left+Right)/2;
   double number=mid-sqrt(mid)-1;
   if(number>N) Right=mid;
   else if((int)number==N)
   {
      if(number-(int)number>0)
        cout<<mid;  
      else cout<<mid;
      return 0;       
   }
   else Left=mid+1;
}
cout<<Left;
return 0;
}