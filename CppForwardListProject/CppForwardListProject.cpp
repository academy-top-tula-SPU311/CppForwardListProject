#include <iostream>

struct Node
{
    int value;
    Node* next{ nullptr };
};

void ForwardListPushHead(Node*& head, int value);
void ForwardListPushTail(Node*& head, int value);
void ForwardListPrint(Node* head);

int main()
{
    Node* head{ nullptr };

    ForwardListPushHead(head, 100);
    ForwardListPushHead(head, 200);
    ForwardListPushHead(head, 300);

    ForwardListPrint(head);
    std::cout << "\n";

    ForwardListPushTail(head, 400);
    ForwardListPushTail(head, 500);

    ForwardListPrint(head);
}

void ForwardListPushHead(Node*& head, int value)
{
    Node* nodeNew = new Node;
    nodeNew->value = value;
    nodeNew->next = head;

    head = nodeNew;
}

void ForwardListPushTail(Node*& head, int value)
{
    Node* nodeLast = head;
    while (nodeLast->next)
        nodeLast = nodeLast->next;

    Node* nodeNew = new Node;
    nodeNew->value = value;
    nodeLast->next = nodeNew;
}

void ForwardListPrint(Node* head)
{
    while (head)
    {
        std::cout << head->value << "\n";
        head = head->next;
    }
}
