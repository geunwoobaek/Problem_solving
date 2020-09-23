#include<iostream>
class MyIntVector
{

private:
    int *data;
    int size_ = 0;
    int capacity_ = 0;

public:
    MyIntVector();
    MyIntVector(const MyIntVector &v);
    void operator=(const MyIntVector &v);
    void operator+=(const MyIntVector &v);
    int& operator[](int a);
    MyIntVector operator+(const MyIntVector &v);
    MyIntVector operator-(const MyIntVector &v);
    MyIntVector operator*(const MyIntVector &v);
    MyIntVector operator-(int i);
    bool operator==(const MyIntVector &v);
    void operator()(void);
    void pop_back();
    void push_back(int x);
    size_t capacity() const;
    size_t size() const;
    void reserve(size_t n);
    bool isEmpty() const;
    void clear();
    virtual ~MyIntVector();
};