#include <bits/stdc++.h>

using namespace std;

class Business
{
private:
    char* companyName;

public:
    Business()
    {
        char name[50];
        cout << "추가할 업체명을 입력하시오 : ";
        cin >> name;
        int len = strlen(name) + 1;
        companyName = new char[len];
        strcpy(companyName,name);
    }

    void ShowcompanyName() const
    {
        cout << "업체명: " << companyName << endl;
    }

    ~Business()
    {
        delete[] companyName;
    }
};
class ManufacturingBusiness : public Business
{
private:
    int salesMoney;
public:
    ManufacturingBusiness() : Business()
    {
        cin >> salesMoney;
    }
    int getsalesMoney()
    {
        return salesMoney;
    }

    void ShowcompanyName() const
    {   Business::ShowcompanyName();
        
        // cout << "업체명: " << super().companyName << salesMoney << endl;
    }

};

class BusinessList
{
private:
    Business* company[10];
    int companyNum;

public:
    BusinessList()
    {
        companyNum = 0;
    }

    void addBusiness()
    {
        company[companyNum++] = new ManufacturingBusiness();
    }

    void ShowCompanyInfo() const
    {
        for (int i=0; i<companyNum; i++) {
            company[i]->ShowcompanyName();
        }
    }

    ~BusinessList()
    {
        for (int i=0; i<companyNum; i++) {
            delete company[i];
        }
    }
};

class TaxOffice
{
private:
    BusinessList* List;

public:
    TaxOffice()
    {
        List = new BusinessList();
    }

    void addBusinessObj()
    {
        List->addBusiness();
    }
    
    void ShowObjInfo() const
    {
        List->ShowCompanyInfo();
    }

    ~TaxOffice()
    {
        delete List;
    }
};


int main(){
    TaxOffice TO;
    TO.addBusinessObj();
    cout << "추가된 업체명 정보: " << endl;
    TO.ShowObjInfo();
    return 0;
}