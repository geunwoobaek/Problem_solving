#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=10;
    ofstream myfile ("testcase.txt");
    while (--n>=0)
    {
        myfile<<"100"<<"\n";
        for (int i = 0; i < 100; i++)
        {
            int a = rand() % 3;
            myfile<< (rand() % 2 + 2)+" "+(rand() % 3)+" "+rand() % 3<<"\n";
        }
    }
     myfile.close();
}