#include <iostream>
using namespace std;
//Чет не так робит, когда создаю сразу Stack and LinkedList вместе,
//все норм когда один не мешает другому

struct Node
{
    int value;
    Node * next;
};
struct Stack
{
    Node * pHead;

    void push(int value)
    {
         Node * node = new Node;
         node->value = value;
         node->next = pHead;
         pHead = node;
    }

    int pop()
    {
        if(!pHead)
            throw 1;
        Node * temp = pHead;
        pHead = temp->next;
        return temp->value;
    }

    int peek()
    {
        if(!pHead)
            throw 1;
        return pHead->value;
    }

    void printAll()
    {
        Node * temp = pHead;
        while (temp != nullptr)
        {
            cout<<temp->value<<endl;
            temp = temp->next;
        }
        cout<<"End of stuck printing"<<endl;
    }};
struct LinkedList
{
    Node * pHead = nullptr;

    void add(int i)
    {
        if(pHead == nullptr)
        {
            Node * temp = new Node;
            temp->value = i;
            pHead = temp;
            return;
        } else
        {
            Node *temp = pHead;
            while (pHead->next != nullptr)
            {
                pHead = pHead->next;
            }
            Node *node = new Node();
            node->value = i;
            pHead->next = node;
            pHead = temp;
            return;
        }

    }
    void printAll()
    {
        Node * temp = pHead;
        while (temp != nullptr)
        {
            cout<<temp->value<<endl;
            temp = temp->next;
        }
    }
    int size()
    {
        Node * temp = pHead;
        int counter = 0;
        while (temp != nullptr)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
    }
    int get(int index)
    {
        int counter = 0;
        Node * node = pHead;
        while (counter!=index)
        {
            counter++;
            node = node->next;

        }
        return node->value;
    }
};
int main()
{
    /*Stack stack;
    stack.push(324);
    stack.push(76);
    stack.push(123);
    stack.push(124567);
    stack.push(873);
    stack.printAll();*/



    LinkedList list;

    list.add(234);
    list.add(24235);
    list.add(1234);
    list.add(8765);
    list.add(898543);
    cout<<list.size()<<endl;
    list.printAll();

    cout<<"The second element is "<<list.get(2)<<endl;
    return 0;
}