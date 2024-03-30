#include <iostream>

template <typename T>
struct Node
{
    T value;
    Node<T>* next{ nullptr };
};

template <typename T>
void ForwardListPushHead(Node<T>*& head, T value);
template <typename T>
void ForwardListPushTail(Node<T>*& head, T value);

template <typename T>
T ForwardListPopHead(Node<T>*& head);
template <typename T>
T ForwardListPopTail(Node<T>*& head);

template <typename T>
void ForwardListPrint(Node<T>* head);

int main()
{
    Node<int>* head{ nullptr };

    ForwardListPushHead(head, 100);
    ForwardListPushHead(head, 200);
    ForwardListPushHead(head, 300);

    ForwardListPrint(head);
    std::cout << "\n";

    std::cout << ForwardListPopTail(head) << "\n";
    std::cout << ForwardListPopTail(head) << "\n";
    std::cout << ForwardListPopTail(head) << "\n";

    /*ForwardListPushTail(head, 400);
    ForwardListPushTail(head, 500);*/

    ForwardListPrint(head);
}

template <typename T>
void ForwardListPushHead(Node<T>*& head, T value)
{
    Node<T>* nodeNew = new Node<T>;
    nodeNew->value = value;
    nodeNew->next = head;

    head = nodeNew;
}

template <typename T>
void ForwardListPushTail(Node<T>*& head, T value)
{
    Node<T>* nodeLast = head;
    while (nodeLast->next)
        nodeLast = nodeLast->next;

    Node<T>* nodeNew = new Node<T>;
    nodeNew->value = value;
    nodeLast->next = nodeNew;
}

template<typename T>
T ForwardListPopHead(Node<T>*& head)
{
    T value = head->value;

    Node<T>* nodeDelete = head;
    head = head->next;
    delete nodeDelete;

    return value;
}

template<typename T>
T ForwardListPopTail(Node<T>*& head)
{
    Node<T>* nodeCurrent{ head };
    while (nodeCurrent->next && nodeCurrent->next->next)
        nodeCurrent = nodeCurrent->next;

    T value;

    if (!nodeCurrent->next)
    {
        value = nodeCurrent->value;
        delete nodeCurrent;
        head = nullptr;
    }
    else
    {
        value = nodeCurrent->next->value;
        delete nodeCurrent->next;
        nodeCurrent->next = nullptr;
    }
    return value;
}

template <typename T>
void ForwardListPrint(Node<T>* head)
{
    while (head)
    {
        std::cout << head->value << "\n";
        head = head->next;
    }
}
