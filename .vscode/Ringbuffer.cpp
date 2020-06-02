#include<iostream>
#include<vector>
#include<thread>
using namespace std;
void read(vector<int> R)
{
    while(1)
    {
        for(int i=0;i<R.size();i++)
        {
            cout<<"Now read : "<<R[i]<<endl;
        }
    }
}
void write(vector<int> R)
{  
   int i=0; 
   while(1)
   {   
       i%=10;
       R[i]=i;
       cout<<"now write="<<i<<endl;
   }
}
int main()
{ 
    vector<int> Ring(10,0);
    thread(write,Ring);
    thread(read,Ring);

}