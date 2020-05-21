#include <iostream>
#include<queue>
#include<cstring>
#include<vector>

using namespace std;
string str;
int main() //:를 split로해서 받음
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cin>>str;
cout<<str.find(':',0);
str.insert(2,6,'S');
cout<<str;
return 0;
}