#include<iostream>
#include<vector>
using namespace std;
int main()
{
vector<int> vec;
vec.push_back(1);
vec.push_back(2);
vec.push_back(3);
vec.push_back(4);
vec.push_back(5);
vec.push_back(6);
int k=-1;
for(vector<int>::iterator e=vec.begin();e!=vec.end();e++)
{
*e+=10;
if(*e==12)
 vec.erase(e--);
}
for(auto &i:vec)
{
    cout<<i<<endl;
}
return 0;
}


