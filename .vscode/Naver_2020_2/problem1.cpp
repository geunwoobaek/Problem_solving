#include<iostream>
#include<queue>
#include<cstring>
#include <map>
#include<vector>
#include<string>
using namespace std;
string solution(string m,string k)
{
int cur=0;
for (string::iterator it=m.begin(); it!=m.end()&&cur<k.length(); ++it)
{
if(*it==k[cur]) {cur++;m.erase(it);}
else it++;
}
return m;
}
int main()
{
   string a="kkaxbycz";
   string b="abc";
   cout<<solution(a,b);
   return 0;
}