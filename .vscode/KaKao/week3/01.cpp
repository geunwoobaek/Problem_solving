#include <bits/stdc++.h>
using namespace std;
struct Trie
{
    int child_size_ = 0;
    int order = 0;
    Trie *child[26];
    Trie()
    {
        int size_ = 0;
        int order = 0;
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
    void insert(const string &sentence, int index)
    {
        if (int(sentence.length()) <= index)
            return;
        else
        {
            child_size_++;
            if (child[sentence[index] - 'a'] == NULL)
            {
                child[sentence[index] - 'a'] = new Trie();
                child[sentence[index] - 'a']->order = this->order + 1;
            }
            child[sentence[index] - 'a']->insert(sentence, index + 1);
        }
    }
    int find(const string &sentence, int index)
    {
        if (child[sentence[index] - 'a']->child_size_ == 1)
        {
            return this->order + 1;
        }
        else
            return child[sentence[index] - 'a']->find(sentence, index + 1);
    }
};

int solution(vector<string> words)
{
    Trie *tree = new Trie();
    int answer = 0;
    for (auto &word : words)
        tree->insert(word, 0);
    for (auto &word : words)
        answer += tree->find(word, 0);
    return answer;
}
int main(){
    
}