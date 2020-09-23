#include <iostream>
#include <cstdlib>
using namespace std;

class MyIntVector
{

private:
    int *data;
    int size;
    int capacity;

public:
    MyIntVector()
    {
    }
    MyIntVector(const MyIntVector &v)
    {
    }
    void operator=(MyIntVector v) //deepcopy
    {
    }
    void operator+=(MyIntVector v) //두개더하기
    {
    }
    int &operator[](MyIntVector v) //반환
    {
    }
    MyIntVector operator+(MyIntVector v) //더하기
    {
    }
    MyIntVector operator-(MyIntVector v) //차이빼기
    {
    }
    MyIntVector operator*(MyIntVector v)
    {
    }
    MyIntVector operator-() //-해서반환
    {
    }
    bool operator==(MyIntVector v)
    {
    }
    void operator()() //make int
    {
    }
    void pop_back() //make int
    {
    }
    void push_back() //make int
    {
    }
    size_t capacity()
    {
        return this->capacity;
    }
    size_t size()
    {
        return this->size;
    }
    void reserve(size_t n)
    {
    }
    bool is_empty() const
    {
        return this->size == 0;
    }
    void clear()
    {
    }
    ~MyIntVector();
}