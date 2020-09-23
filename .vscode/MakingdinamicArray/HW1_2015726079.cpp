#include <iostream>
#include "MyIntVector.h"
using namespace std;
MyIntVector *V;
MyIntVector *V2;
void deepcopy_test()
{
}
// void append_test()
// {
// }
// void Plus_test()
// {
// }
void Minus_test()
{
}
void Multiply_test()
{
}
void get_Reference_test()
{
    cout << "get_Reference_test"
         << "현재 V[1]=" << (*V)[1] << endl;
    cout << "변경할 값은 100" << endl;
    (*V)[1] = 100;
    cout << " (*V)[1]=100=>"
         << "현재 V[1]=" << (*V)[1] << endl;
}
void Push_test()
{
    cout << "Push_test"
         << "현재 capacity=" << V->capacity() << endl;
    cout << "넣을값은 0부터 99까지 100개" << endl;
    for (int i = 0; i < 100; i++)
        V->push_back(i);
    cout << "Loof 0<=i<100 push_back(i)=>"
         << "현재 capacity=" << V->capacity() << endl;
}
void Pop_test()
{
    cout << "Pop_test"
         << "현재 마지막값은=" << (*V)[(V->capacity() - 1)] << endl;
    V->pop_back();
    cout << "pop_back()=> 현재 마지막값은=" << (*V)[V->capacity() - 1] << endl;
}
void Empty_test()
{
    cout << "Empty_test"
         << "현재 사이즈=" << V->size() << endl;
    if (V->isEmpty())
        cout << "비었습니다." << endl;
    else
        cout << "비어 있지 않습니다." << endl;
}
void clear_test()
{
    cout << "clear_test"
         << "현재 사이즈=" << V->size() << endl;
    V->clear();
    cout << "변경된 사이즈=" << V->size() << endl;
}
void reserve_test()
{
    cout << "reserve_test"
         << "현재 사이즈=" << V->size() << endl;
    V->reserve(100);
    cout << "변경된 사이즈=" << V->size() << endl;
}
int main()
{
    MyIntVector Vec;
    V = new MyIntVector();
    V2 = new MyIntVector();
    reserve_test();
    Push_test();
    get_Reference_test();
    return 0;
}
