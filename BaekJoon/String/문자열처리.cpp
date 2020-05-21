#include <iostream>
#include<queue>
#include<string>
#include<vector>

using namespace std;
string str;
int main() //:를 split로해서 받음
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cin>>str;
int index=0,second=0;
int last=0;
int count=1,Start=-1;
while(second!=-1) 
{
   second=str.find(":",index);
   if(second==-1 ) last=index;
   else if(second==index) {Start=second-1;}
   else 
   {  count++;
   if(second-index<4) 
   {  
      str.insert(index,4-(second-index),'0');
      second+=(4-(second-index));
   }  
   }
   index=second+1; 
}
str.insert(last,4-(str.length()-last),'0'); //위치부터 갯수만큼
if(Start>=0) str.erase(str.begin()+Start+1,str.begin()+Start+2);
for(int i=0;i<8-count;i++)
{str.insert(Start+1,"0000:"); Start+=5;}
if(str[0]==':') {str.erase(str.begin(),str.begin()+1);}
cout<<str;
return 0;
}