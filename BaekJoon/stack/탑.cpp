#include<iostream>
#include<stack>
using namespace std;
stack<pair<int,int>> st;
int N;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cin>>N;
for(int i=0;i<N;i++)
{   bool check=true;
    int temp; 
    cin>>temp;
    while(!st.empty()) //비어있지않을때
    {   
        if(st.top().second>temp) {check =false; printf("%d ",st.top().first+1); break;}
        st.pop();
    }
    st.push({i,temp});
    if(check) printf("0 ");
}
return 0;
}