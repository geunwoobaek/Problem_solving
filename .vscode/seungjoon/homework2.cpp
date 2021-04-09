#include <bits/stdc++.h>
using namespace std;

class Business
{
public:
    char *name;
    Business(char *name)
    {
        strcpy(this->name, name,50);
    }
    ~Business()
    {
        delete this;
    }
};

class BuisnessList
{
    Business **List;
    int capacity;

public:
    BuisnessList()
    {
        List = new Business *[1000];
        capacity = 0;
    }
    ~BuisnessList()
    {
        delete this;
    }
    void add(Business *business)
    {
        List[capacity++] = business;
        cout << business->name;
    }
};
int main()
{
    BuisnessList *buisnessList = new BuisnessList();
    char *name = "홍콩";
    Business *business = new Business(name);
    buisnessList->add(business);
    return 0;
}