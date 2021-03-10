#include <iostream>

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

struct SortedList
{
    Node *head = nullptr;

    void add(int value)
    {
        if (!head)
        {
            head = new Node(value);
            return;
        }
        if (!head->next)
        {
            if (head->value >= value)
            {
                Node *temp = head;
                head = new Node(value);
                head->next = temp;
            } else
            {
                head->next = new Node(value);
            }
            return;
        }

        Node *headLink = head;
        Node *previous = nullptr;
        while ((head) && (head->value <= value))
        {
            previous = head;
            head = head->next;
        }
        if ((head != nullptr) && (head->value >= value))
        {
            if (headLink->value >= value)
            {
                head = new Node(value);
                head->next = headLink->next;
                add(headLink->value);
                return;
            }
            previous->next = new Node(value);
            previous->next->next = head;
            head = headLink;
            return;
        } else
        {
            head = new Node(value);
            previous->next = head;
            head = headLink;
        }


    }

    void printAll()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    int size()
    {
        Node *temp = head;
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
        Node *node = head;
        while (counter != index)
        {
            counter++;
            node = node->next;

        }
        return node->value;
    }

    void remove(int i)
    {
        Node *temp = head;
        int counter = 0;
        while (head)
        {
            counter++;
            head = head->next;
            if (i - 1 == counter)
            {
                Node *x = head->next;
                head->next = x->next;
            }

        }
        head = temp;
    }

    void addUnique(int value)
    {
        if (!head)
        {
            head = new Node(value);
            return;
        }
        if ((!head->next) && (value != head->value))
        {
            if (head->value >= value)
            {
                Node *temp = head;
                head = new Node(value);
                head->next = temp;
            } else
            {
                head->next = new Node(value);
            }
            return;
        }
        if (!head->next)
            return;
        bool flag = true;
        for (int i = 0; i < size(); ++i)
        {
            if (value == get(i))
                flag = false;
        }
        if (flag)
        {


            Node *headLink = head;
            Node *previous = nullptr;
            while ((head) && (head->value <= value))
            {
                previous = head;
                head = head->next;
            }
            if ((head != nullptr) && (head->value >= value))
            {
                if (headLink->value >= value)
                {
                    head = new Node(value);
                    head->next = headLink->next;
                    add(headLink->value);
                    return;
                }
                previous->next = new Node(value);
                previous->next->next = head;
                head = headLink;
                return;
            } else
            {
                head = new Node(value);
                previous->next = head;
                head = headLink;
            }
        }
    }

    void Union(SortedList *a, SortedList *b)
    {
        for (int i = 0; i < a->size() + b->size(); ++i)
        {
            if (i < a->size())
            {
                addUnique(a->get(i));
            } else
            {
                addUnique(b->get(i-a->size()));
            }
        }
    }

    void Intersect(SortedList *a, SortedList *b)
    {
        for (int i = 0; i < a->size(); ++i)
        {
            for (int j = 0; j < b->size(); ++j)
            {
                if(a->get(i)==b->get(j))
                {
                    addUnique(a->get(i));
                }
            }
        }
    }

    void Difference(SortedList *a, SortedList *b)
    {
        for (int i = 0; i < a->size(); ++i)
        {
            bool flag = true;
            for (int j = 0; j < b->size(); ++j)
            {
                if(a->get(i)==b->get(j))
                {
                    flag = false;
                }
            }
            if(flag)
                add(a->get(i));
            flag = true;
        }
    }

};

int main()
{
    int rand();
    SortedList* list = new SortedList;
    SortedList *list1 = new SortedList;
    SortedList *list2 = new SortedList;


    /*list.addUnique(3);
    list.addUnique(2);
    list.addUnique(4);
    list.printAll();*/
    for (int i = 0; i < 20; ++i)
    {
        int temp = rand()%20;
        list1->addUnique(temp);
    }
    for (int i = 0; i < 20; ++i)
    {
        int temp = rand()%20;
        list2->addUnique(temp);
    }

    list->Difference(list1,list2);
    list->printAll();
    cout<<"size "<<list->size();

    return 0;
}
