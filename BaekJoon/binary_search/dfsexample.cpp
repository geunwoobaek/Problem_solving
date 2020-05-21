#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

 
int main() {
    vector<int> a;
    for (int i = 0; i < 10; i++) 
    {
		a.push_back(i);
	}
	a.erase(a.begin()+5,a.begin()+6);
	vector<int>::iterator it1=lower_bound(a.begin(),a.end(),5);
    cout<<it1-a.begin();
    vector<int>::iterator it2=upper_bound(a.begin(),a.end(),5);
    return 0;
}