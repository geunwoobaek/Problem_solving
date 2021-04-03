// 정렬되어 있지않은 값을 가지는
// LinkedList가 주어졌을 때 이
// 리스트에서 중복되는 원소를 제거하는
// 코드를 작성하라 단 버퍼는 사용할 수 없으며
// LinkedList는 직접 구현하여야 한다.
//  구현된 LinkedList 에는 리스트의 사이즈를 확인
// 할수 있는 기능을 구현하라.
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *next_;
    int data;
    Node(int data)
    {
        this->data = data;
        next_ = nullptr;
    }
    bool end()
    {
        if (this == nullptr)
            cout << "";
        return this == nullptr;
    }
};
struct LinkedList
{
    int size;
    Node *root;

    LinkedList()
    {
        size = 0;
        root = nullptr;
    }
    void insert(int data)
    {
        size++;
        if (root == nullptr)
            root = new Node(data);
        else
        {
            Node *cur = root;
            while (cur->next_ != nullptr)
                cur = cur->next_;
            cur->next_ = new Node(data);
        }
    }
    Node *deleteNode(Node *node)
    {
        if (root->end())
            return nullptr;
        else
        {
            Node *cur = root;
            if (cur == node)
            {
                size--;
                cur = root->next_;
                delete root;
                return cur;
            }
            else
            {
                while (cur->next_ != nullptr)
                {
                    if (cur->next_ == node)
                    {
                        size--;
                        Node *deleted = cur->next_;
                        cur->next_ = cur->next_->next_;
                        delete deleted;
                        return cur->next_;
                    }
                    else
                        cur = cur->next_;
                }
            }
            return nullptr;
        }
    }
};
void deleteOverLap(LinkedList *list)
{
    unordered_map<int, bool> um;
    Node *iterator = list->root;
    um[iterator->data] = true;
    iterator = iterator->next_;
    while (!iterator->end())
    {
        if (um[iterator->data])
            iterator = list->deleteNode(iterator);
        else
        {
            um[iterator->data] = true;
            iterator = iterator->next_;
        }
    }
}
void search(LinkedList *list)
{
    Node *iterator = list->root;
    cout<<iterator->data<<"->";
    iterator = iterator->next_;
    while (!iterator->end())
    {   
        cout<<iterator->data<<"->";
        iterator = iterator->next_;
    }
    cout<<"...end"<<"\n";
}
int main()
{
    LinkedList *linkedList = new LinkedList();
    linkedList->insert(2);
    linkedList->insert(3);
    linkedList->insert(2);
    linkedList->insert(4);
    linkedList->insert(6);
    linkedList->insert(3);
    cout<<"처음 list:";
    search(linkedList);
    deleteOverLap(linkedList);
    cout<<"중복제거후 list:";
    search(linkedList);
    return 0;
}