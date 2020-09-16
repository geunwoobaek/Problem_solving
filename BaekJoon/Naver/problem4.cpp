#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
int solution(vector<int> &A)
{
    int count = 1;
    int Maximum = 0;
    int prevMaximum=0;
    int singlecount = 0;
    bool check = true;
    bool check = A[0] <= A[1]; //감소하고있는가?
    for (int i = 0; i < A.size(); i++)
    {
        singlecount++;
        if (singlecount < 3 && A[i] < Maximum)
        {
            break;
            check = false;
        }
        if (singlecount <= 3 && Maximum < A[i])
        {   prevMaximum=Maximum;
            Maximum=A[i];
            count++;
        }
        else if(A)
    }
    return count;
}
int main()
{
    vector<int> A;
    A.push_back(4);
    A.push_back(3);
    A.push_back(2);
    A.push_back(6);
    A.push_back(1);
    solution(A);
}