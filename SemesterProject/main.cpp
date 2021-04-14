#include <iostream>
#include <vector>
#include "fstream"
#include "ctime"

using namespace std;

#include <iostream>
#include <string>
#include <chrono>

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
        return (this->root == nullptr);
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
            } else if (x->key <= nextX->key)
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

    int extractMin()
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

        return res->key;
    }

    void decreaseKey(Node *x, int newKey)
    {
        // Precondition: x -> key > newKey
        x->key = newKey;
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

    void nodeDelete(Node *node)
    {
        decreaseKey(node, INT16_MIN);
        extractMin();
    }
};


int main()
{
    BinomialHeap *test = new BinomialHeap;

    ifstream inputTEST;
    inputTEST.open("C:\\Users\\Мансур\\CLionProjects\\SemesterProject\\Testin Data\\text.txt");
    while (true)//reading
    {
        if (inputTEST.eof())
            break;
        long x;
        inputTEST >> x;
        test->insert(new Node(x));
    }
    inputTEST.close();

    cout << "read";

    ifstream input;
    string str = "C:\\Users\\Мансур\\CLionProjects\\SemesterProject\\Testin Data\\Samples";
    string txt = ".txt";

    ofstream output;
    string outputDir = "C:\\Users\\Мансур\\CLionProjects\\SemesterProject\\Results";
    string fileSample = "\\TimeComplexityRes";

    //time complexity measurements
    for (int i = 0; i < 200; ++i)
    {
        cout<<i<<endl;
        if(i==150)
            int sdfsdaf= 1345;
        inputTEST.open("C:\\Users\\Мансур\\CLionProjects\\SemesterProject\\Testin Data\\text.txt");
        while (true)//reading
        {
            if (inputTEST.eof())
                break;
            long x;
            inputTEST >> x;
            test->insert(new Node(x));
        }
        inputTEST.close();
        BinomialHeap *bh = new BinomialHeap;
        input.open(str + to_string(i + 1) + txt);
        output.open(outputDir + fileSample + to_string(i + 1) + txt);
        auto start = std::chrono::high_resolution_clock::now();
        while (true)//insert
        {
            if (input.eof())
                break;
            long x;
            input >> x;
            bh->insert(new Node(x));
        }
        auto end = std::chrono::high_resolution_clock::now();
        output << "Insert: " << (end - start) / std::chrono::milliseconds(1) << endl;

        //decrease key
        Node *node = bh->root;
        start = std::chrono::high_resolution_clock::now();
        bh->decreaseKey(node, -1);
        end = std::chrono::high_resolution_clock::now();
        output << "Decrease key: " << (end - start) / std::chrono::milliseconds(1) << endl;

        //delete

        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j <450; ++j)

        {
            node = bh->root;
            bh->nodeDelete(node);
        }
        end = std::chrono::high_resolution_clock::now();
        output << "Delete: " << (end - start) / std::chrono::milliseconds(1) << endl;

        //union
        start = std::chrono::high_resolution_clock::now();
        bh->unionHeaps(test);
        end = std::chrono::high_resolution_clock::now();
        output << "Union: " << (end - start) / std::chrono::milliseconds(1) << endl;

        //extract min
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 450; ++j)
        {
            bh->extractMin();
        }

        end = std::chrono::high_resolution_clock::now();
        output << "Extract min (first 200 nodes): " << (end - start) / std::chrono::milliseconds(1) << endl;

        output.close();
        input.close();
        delete bh;
    }

    return 0;
}