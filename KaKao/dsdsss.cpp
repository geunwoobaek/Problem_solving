#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cstring>
using namespace std;
vector<int> vec(10);
int main()
{	//2 //7 //10
	fill (vec.begin(), vec.begin()+3, 1);
	fill (vec.begin()+3, vec.begin()+8, 2);
	fill (vec.begin()+8, vec.end(), 3);
	cout<<"c";
}