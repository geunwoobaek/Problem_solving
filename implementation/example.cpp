#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <time.h> 
#include<stack>
using namespace std;
vector<int> vec;
stack<int> st;
time_t start, E;
void benchMarkVector();
void benchMarkStack();
int main(){
    benchMarkVector();
    benchMarkStack();
return 0;
}
void benchMarkStack()
{
    time_t start, E;
    start=clock();
    for(int i=0;i<100000000;i++)
        st.push(i);
    E=clock();
    cout<<(double)(E-start)<<"\n";
}
void benchMarkVector()
{
    time_t start, E;
    start=clock();
    for(int i=0;i<100000000;i++)
        vec.push_back(i);
    E=clock();
    cout<<(double)(E-start)<<"\n";
}