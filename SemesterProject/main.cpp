#include <iostream>
#include <string>

using namespace std;

struct Node
{
    int key;
    int degree;
    Node *sibling, *parent, *child;

    Node()
    {
        this->key = 0;
        this->degree = 0;
        this->sibling = this->parent = this->child = nullptr;
    }

    Node(int key)
    {
        this->key = key;
        this->degree = 0;
        this->sibling = this->parent = this->child = nullptr;
    }
};

struct BinomialHeap
{
    Node *root;
    Node *min;

    BinomialHeap()
    {
        this->root = nullptr;
    }

    BinomialHeap(Node *x)
    {
        this->
                root = x;
    }

    bool isEmpty()
    {
        return  (this->root == nullptr);
    }
    //merging trees with the same degree, where z has lesser key than y
    static void linkTrees(Node *y, Node *z)
    {
        y->parent = z;
        y->sibling = z->child;
        z->child = y;
        z->degree = z->degree + 1;
    }
    //the whole point of this method is just adding a single node to the edge of this heap
    static Node *mergeTree(BinomialHeap *x, BinomialHeap *y)
    {
        Node *res = new Node();
        Node *end = res;

        Node *left = x->root;
        Node *right = y->root;

        if (left == nullptr) return right;
        if (right == nullptr) return left;

        while (left != nullptr || right != nullptr)
        {
            if (left == nullptr)
            {
                end->sibling = right;
                end = end->sibling;
                right = right->sibling;
            } else if (right == nullptr)
            {
                end->sibling = left;
                end = end->sibling;
                left = left->sibling;
            } else
            {
                if (left->degree < right->degree)
                {
                    end->sibling = left;
                    end = end->sibling;
                    left = left->sibling;

                } else
                {
                    end->sibling = right;
                    end = end->sibling;
                    right = right->sibling;

                }
            }
        }

        return (res->sibling);
    }
    //we can see 4 cases while uniting
    void unionHeaps(BinomialHeap *bh)
    {
        BinomialHeap *H = new BinomialHeap();
        H->root = mergeTree(this, bh);

        if (H->root == nullptr)
        {
            this->root = nullptr;
            this->min = nullptr;
            return;
        }

        Node *prevX = nullptr;
        Node *x = H->root;
        Node *nextX = x->sibling;
        //keep repeating till there are no trees with the same degree
        while (nextX != nullptr)
        {
            //case 1 and 2
            if (x->degree != nextX->degree || (nextX->sibling != nullptr && nextX->sibling->degree == x->degree))
            {
                prevX = x;
                x = nextX;
            }

            else if (x->key <= nextX->key)
            {
                x->sibling = nextX->sibling;
                linkTrees(nextX, x);
            } else
            {
                if (prevX == nullptr) H->root = nextX;
                else prevX->sibling = nextX;
                linkTrees(x, nextX);
                x = nextX;
            }
            nextX = x->sibling;
        }
        this->root = H->root;
        //just searching for the minimal value
        this->min = H->root;
        Node *current = this->root;
        while (current != nullptr)
        {
            if (current->key < this->min->key) this->min = current;
            current = current->sibling;
        }
    }

    void insert(Node *x)
    {
        this->unionHeaps(new BinomialHeap(x));
    }

    Node *first()
    {
        return this->min;
    }

    Node *extractMin()
    {
        Node *res = this->first();

        // delete res from the list of root
        Node *prevX = nullptr;
        Node *x = this->root;
        while (x != res)
        {
            prevX = x;
            x = x->sibling;
        }
        if (prevX == nullptr)
            this->root = x->sibling;
        else
            prevX->sibling = x->sibling;

        // reverse the list of min node children
        Node *revChd = nullptr;
        Node *cur = res->child;
        while (cur != nullptr)
        {
            Node *next = cur->sibling;
            cur->sibling = revChd;
            revChd = cur;
            cur = next;
        }

        // unionHeaps the two lists
        BinomialHeap *H = new BinomialHeap();
        H->root = revChd;
        this->unionHeaps(H);

        return res;
    }

    void decreaseKey(Node *x, int newKey)
    {
        // Precondition: x -> key > newKey
        x->
                key = newKey;
        Node *y = x;
        Node *z = y->parent;
        while (z != nullptr && y->key < z->key)
        {
            // swap contents
            swap(y
                         ->key, z->key);

            y = z;
            z = y->parent;
        }

        if (y->key < this->min->key)
            this->
                    min = y;
    }
};


int main()
{
    BinomialHeap *bh = new BinomialHeap();

    bh->insert(new Node(3));
    bh->insert(new Node(8));
    bh->insert(new Node(4));

    for (int i = 0; i < 10; ++i)
    {
        int x = rand() % 100;
        cout<<x<<" ";
        bh->insert(new Node(x));
    }

    cout<<endl;
    while (!bh->isEmpty())
    {
        cout<<bh->extractMin()->key<<" ";
    }
    return 0;
}