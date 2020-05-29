#include<iostream>
#include<algorithm>
using namespace std;

struct TRIE
{
    bool Finish;//마지막 문자
    TRIE *Node[26]; //알파벳담고있음 총26가지
    TRIE()  //초기화
    { 
        Finish = false;   
        for (int i = 0; i < 26; i++) Node[i] = NULL;
    } 
bool Find(char *Str) //문자열찾기
{
    if (*Str == NULL)
    {
        if (Finish == true) return true;
        return false;
    }
    int Cur = *Str - 'A';
    if (Node[Cur] == NULL) return false;
    return Node[Cur]->Find(Str + 1);
};
void IsSorting(TRIE *N, char Str[], int Idx)
{
    if (N->Finish == true) cout << Str << endl;
    for (int i = 0; i < 26; i++)
    {
        if (N->Node[i] != NULL)
        {
            char C = i + 'A';
            Str[Idx] = C;
            N->IsSorting(N->Node[i], Str, Idx + 1);
        }
    }
};
    void Insert(char *Str)
    {
    if (*Str == NULL)
    {
        Finish = true;
        return;
    }
 
    int Cur = *Str - 'A';
    if (Node[Cur] == NULL) Node[Cur] = new TRIE();
    Node[Cur]->Insert(Str + 1);
    };

};

 
int main(void)
{
    TRIE *Root = new TRIE();
    char *String[5];
    String[0] = "ZYX";
    String[1] = "BCG";
    String[2] = "ABC";
    String[3] = "BDE";
    String[4] = "ABCD";
 
    for (int i = 0; i < 5; i++)
    {
        Root->Insert(String[i]);
    }
 
    for (int i = 0; i < 26; i++)
    {
        if (Root->Node[i] != NULL)
        {
            char Str[5] = { NULL };
            Str[0] = i + 'A';
            Root->IsSorting(Root->Node[i], Str, 1);
        }
    }
}
