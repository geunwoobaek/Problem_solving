#include <stdio.h>
#include <stdlib.h> 
struct ListNode {
    int number;
    ListNode* link = NULL;
};
ListNode* head, * newNode;

//반복을 이용하여
void displayList1(ListNode* head)
{
    ListNode* temp = head;
    while (temp!= NULL)
    {
        printf("%d ->", temp->number);
        temp = temp->link;
    }
    printf("NULL\n");
}
// 7) 순환을 이용하여 노드리스트를 출력
// 출력 예: 1->10->20->30->44->
void displayList2(ListNode* head)
{
    printf("%d ->", head->number);
    if (head->link != NULL) displayList2(head->link);
    else if (head->link == NULL) printf("NULL\n");
}
void link_newNode(int num)
{
    newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->number = num;
    newNode->link = NULL;
    ListNode *temp = head;
    while (temp->link!=NULL)
    {
        temp = temp->link;
    }
    temp->link = newNode;
    printf("\n");
}
void main(void)
{
    head = (ListNode*)malloc(sizeof(ListNode));
    head->number = 1;
    head->link = NULL;
    link_newNode(10);
    link_newNode(20);
    link_newNode(30);
    link_newNode(44);
    displayList1(head);
    printf("\n");
    displayList2(head);
}