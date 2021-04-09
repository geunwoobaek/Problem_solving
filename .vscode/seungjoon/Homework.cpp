#include <bits/stdc++.h>
using namespace std;
enum
{
    NONE,
    RENT,
    STATICS,
    EXIT
};
class Book
{
public:
    string name,
        author;
    int createdDate, page;
    Book(string name, string author, int createdDate, int page)
    {
        this->name = name;
        this->author = author;
        this->createdDate = createdDate;
        this->page = page;
    }
};
class Libirary
{
private:
    Book **list;
    bool rentalAvailable[10];
    int capacity;
    int statics;

public:
    Libirary()
    {
        statics = 0;
        capacity = 0;
        list = new Book *[10];
    }
    ~Libirary()
    {
        delete this;
    }
    void add(Book *book)
    {
        list[capacity++] = book;
    }
    void rent(int bookNum)
    {
        rentalAvailable[bookNum] = false;
        statics += (1 + list[bookNum]->page);
    }
    void printList()
    {
        for (int i = 0; i < capacity; i++)
            if (rentalAvailable[i])
            {
                cout << i << "번" << (list[i]->name) << " ";
            }
    }
    void printStatics()
    {
        cout << this->statics<<"\n";
    }
};
int main()
{
    Libirary *libirary = new Libirary();
    libirary->add(new Book("Bird", "Kim", 2010, 234));
    libirary->add(new Book("Dog", "Lee", 2010, 234));
    libirary->add(new Book("Hippo", "Park", 2010, 234));
    int COMMAND = NONE;
    while (COMMAND != EXIT)
    {
        cout << "1번은 대여, 2번은 통계, 3번은 종료입니다."
             << "\n";
        cin >> COMMAND;
        if (COMMAND = RENT)
        {
            libirary->printList();
            int num;
            cin >> num;
            libirary->rent(num);
        }
        else if (COMMAND = STATICS)
        {
            libirary->printStatics();
        }
    }
}
