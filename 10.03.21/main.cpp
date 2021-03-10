#include "iostream"

using namespace std;

struct Node
{
    int value;
    Node *next = nullptr;
    Node *previous = nullptr;

    Node()
    {

    }

    Node(int value)
    {
        this->value = value;

    }
};

struct DLinkedList
{
    Node *pHead = nullptr;


    void add(int i)
    {
        if (pHead == nullptr)
        {
            Node *temp = new Node;
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
        Node *temp = pHead;
        while (temp != nullptr)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    int size()
    {
        Node *temp = pHead;
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
        Node *node = pHead;
        while (counter != index)
        {
            counter++;
            node = node->next;

        }
        return node->value;
    }

    void remove(int i)
    {
        Node *temp = pHead;
        int counter = 0;
        while (pHead != nullptr)
        {
            counter++;
            pHead = pHead->next;
            if (i - 1 == counter)
            {
                Node *x = pHead->next;
                pHead->next = x->next;
            }

        }
        pHead = temp;
    }

    void insertAt(int value, int index)
    {
        Node *temp = pHead;
        int counter = 0;
        while (pHead != nullptr)
        {
            counter++;
            Node *previous = pHead;
            pHead = pHead->next;

            if (index == counter)
            {
                Node *node = new Node;
                node->value = value;
                Node *current = pHead;
                pHead = node;
                node->next = current;
                previous->next = node;
                /*Node * nextLink = pHead->next;
                Node * current = pHead;
                pHead = node;
                pHead->next = current;
                current->next = nextLink;*/

            }

        }
        pHead = temp;
    }


};

struct Queue
{
    Node *head = nullptr;

    void add(int x)
    {
        if (!head)
        {
            Node *node = new Node;

            node->value = x;
            head = node;
            return;
        }
        Node *temp = head;
        while (head->next)
        {
            head = head->next;
        }

        Node *node = new Node;
        node->value = x;

        head->next = node;
        head = temp;

    }

    int poll()
    {
        Node *temp = head;
        head = head->next;
        return temp->value;
    }

    void printAll()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
        cout << "End of queue printing" << endl;
    }
};

int main()
{
    Queue queue;
    queue.add(876);
    queue.add(234);
    queue.add(1234);
    queue.add(87);
    queue.add(930);
    queue.printAll();
    queue.poll();
    queue.poll();
    queue.printAll();
    return 0;
}