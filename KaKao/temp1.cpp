#include <bits/stdc++.h>
using namespace std;
struct Trie
{
    bool Check = false;  //현재노드에 해당하는 실제값이 있다면
    Trie *ChildNode[26]; //알파뱃갯수
    Trie()
    {
        for (auto &node : ChildNode)
        {
            node = NULL;
        }
    }
    void insert(string &str, int index)
    {
        if (index != str.size())
        {
            int now = str[index] - 'a';
            if (ChildNode[now] == NULL)
            {
                ChildNode[now] = new Trie();
                ChildNode[now]->insert(str, ++index);
            }
            else
                ChildNode[now]->insert(str, ++index);
        }
        else
            Check = true;
    }
    int search(string &str, int index)
    {
        if (index == str.size())
            return Check; //true=1 false=0
        else
        {
            int answer = 0;
            if (str[index] == '?')
            { //만약 wild card
                for (auto &node : ChildNode)
                {
                    if (node != NULL)
                        answer += node->search(str, index + 1);
                }
            }
            else
            { //wild card아니면
                int now = str[index] - 'a';
                if (ChildNode[now] != NULL)
                    answer = ChildNode[now]->search(str, index + 1);
                else
                    answer = 0;
            }
            return answer;
        }
    }
} trie;
Trie converse_trie;
string getConverse(string &words){
    string converse_word;
    for(int i=words.size()-1;i>=0;i--){
        converse_word.push_back(words[i]);
    }
    return converse_word;
}
vector<int> solution(vector<string> words, vector<string> queries)
{
    vector<int> answer;
    //when
    for (auto &word : words)
    {
        trie.insert(word, 0);
        string converse=getConverse(word);
        converse_trie.insert(converse,0);
    }
    //then
    for (auto query : queries)
    {    //앞에 물음표가있다면
        answer.push_back(trie.search(query, 0));
    }
    return answer;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
