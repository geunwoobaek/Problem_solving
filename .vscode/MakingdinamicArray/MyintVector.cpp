#include "MyIntVector.h"
#include<iostream>
using namespace std;

MyIntVector::MyIntVector()	
{
}
MyIntVector::MyIntVector(const MyIntVector &v)
{
	this->capacity_ = v.capacity_;
	this->size_ = v.size_;
    data=new int[size_];
	for(int i=0;i<v.size_;i++)
    {
        data[i]=v.data[i];
    }
}
void MyIntVector::operator=(const MyIntVector &v)
{
	delete data;
	capacity_ = v.capacity_;
	this->size_ = v.size_;
	data = new int[size_];
	for (int i = 0; i < capacity_; i++)
	{
		this->data[i] = v.data[i];
	}
}
void MyIntVector::operator+=(const MyIntVector &v)
{
	if (this->size_ > (this->capacity_ + v.capacity_))
	{
		cout << "NOW" << endl;
		for (int i = 0; i < v.capacity_; i++)
		{
			this->push_back(v.data[i]);
		}
	}
	else
	{
		cout << "lack of capacity" << endl;
		exit(1);
	}
}
int& MyIntVector::operator[](int a)
{
	return (data[a]);
}
MyIntVector MyIntVector::operator+(const MyIntVector &v)
{
	if (this->size_ == v.size_)
	{
		for (int i = 0; i < v.size_; i++)
		{
			this->data[i] += v.data[i];
		}
	}
	else
	{
		cout << "size error" << endl;
		exit(1);
	}
	return *this;
}
MyIntVector MyIntVector::operator-(const MyIntVector &v)
{
	if (this->size_ == v.size_)
	{
		for (int i = 0; i < v.size_; i++)
		{
			this->data[i] -= v.data[i];
		}
	}
	else
	{
		cout << "size error" << endl;
		exit(1);
	}
	return *this;
}
MyIntVector MyIntVector::operator*(const MyIntVector &v)
{
	if (this->size_ == v.size_)
	{
		for (int i = 0; i < v.size_; i++)
		{
			this->data[i] *= v.data[i];
		}
	}
	else
	{
		cout << "size error" << endl;
		exit(1);
	}
	return *this;
}
MyIntVector MyIntVector::operator-(int i)
{
	if (i >this->size_)
	{
		cout << "error size" << endl;
		exit(1);
	}
	else
	data[i] = -data[i];

	return *this;
}
bool MyIntVector::operator==(const MyIntVector &v)
{
	if (this->size_ == v.size_)
	{
		return true;
	}
	else
		return false;
}
void MyIntVector::operator()(void)
{
	for (int i = 0; i < this->size_; i++)
	{
		data[i] = (int)data[i];
	}
}
void MyIntVector::pop_back()
{
	this->data[capacity_-1] = NULL;
}
void MyIntVector::push_back(int x)
{  
	if (this->capacity_ < this->size_)
	{
		this->capacity_++;
		this->data[this->capacity_-1] = x;
	}
	else
	{
		cout << "full of size_" << endl;
	}
}
size_t MyIntVector::capacity() const
{
	return this->capacity_;
}
size_t MyIntVector::size() const
{
	return this->size_;
}
void MyIntVector::reserve(size_t n)
{
	if (n > size_ - capacity_)
	{
		size_ += (n-(size_-capacity_));
		int	*data_ = new int[size_];
		for (int i = 0; i < capacity_; i++)
		{
			data_[i] = data[i];
		}
		delete data;
		data = new int[size_];
		for (int i = 0; i < capacity_; i++)
		{
			data[i] = data_[i];
		}
	}
}
bool MyIntVector::isEmpty() const
{
	if (size_ == 0)
		return true;
	else
		return false;
}
void MyIntVector::clear()
{
	delete[] data;
	size_ = 0;
	capacity_ = 0;
}
MyIntVector::~MyIntVector()
{
}