#include<iostream>
#include<algorithm>
using namespace std;

struct TRIE //트라이 
{
    bool Finish;//끝인지아닌지 판단
    TRIE *Node[26]; //알파벳담고있음 총26가지
    TRIE()  //초기화
    { 
        Finish = false;  // finish는 비어있음
        for (int i = 0; i < 26; i++) Node[i] = NULL;
    } 
bool Find(char *Str) //문자열찾기
{
    if (*Str == NULL) //문자열비어있을경우
    {
        if (Finish == true) return true; //끝일경우
        return false; //끝이아닐경우 return false
    }
    int Cur = *Str - 'A'; //현재위치 
    if (Node[Cur] == NULL) return false; //해당노드가 비어있을경우
    return Node[Cur]->Find(Str + 1); //해당알파벳에 대해 발견하였을경우
};
void IsSorting(TRIE *N, char Str[], int Idx) //마지막문자열꺼내기
{
    if (N->Finish == true) 
        cout << Str << endl;
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
 
    int Cur = *Str - '  ';
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
