
#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
    int x;
    int y;
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    Point()
    {
        x = 0;
        y = 0;
    }
};


struct Node
{
    Point position;
    int key;
    Node(Point pos, int key)
    {
        position = pos;
        this->key = key;
    }
    Node()
    {
        key = 0;
    }
};

struct QuadTree
{

    Point topLeft;
    Point botRight;


    Node *n;


    QuadTree *topLeftTree;
    QuadTree *topRightTree;
    QuadTree *botLeftTree;
    QuadTree *botRightTree;

    QuadTree()
    {
        topLeft = Point(0, 0);
        botRight = Point(0, 0);
        n = nullptr;
        topLeftTree  = nullptr;
        topRightTree = nullptr;
        botLeftTree  = nullptr;
        botRightTree = nullptr;
    }
    QuadTree(Point topL, Point botR)
    {
        n = nullptr;
        topLeftTree  = nullptr;
        topRightTree = nullptr;
        botLeftTree  = nullptr;
        botRightTree = nullptr;
        topLeft = topL;
        botRight = botR;
    }

    void insert(Node *node)
    {
        if (node == nullptr)
            return;


        if (!inBoundary(node->position))
            return;


        if (abs(topLeft.x - botRight.x) <= 1 &&
            abs(topLeft.y - botRight.y) <= 1)
        {
            if (n == nullptr)
                n = node;
            return;
        }

        if ((topLeft.x + botRight.x) / 2 >= node->position.x)
        {

            if ((topLeft.y + botRight.y) / 2 >= node->position.y)
            {
                if (topLeftTree == nullptr)
                    topLeftTree = new QuadTree(
                            Point(topLeft.x, topLeft.y),
                            Point((topLeft.x + botRight.x) / 2,
                                  (topLeft.y + botRight.y) / 2));
                topLeftTree->insert(node);
            }


            else
            {
                if (botLeftTree == nullptr)
                    botLeftTree = new QuadTree(
                            Point(topLeft.x,
                                  (topLeft.y + botRight.y) / 2),
                            Point((topLeft.x + botRight.x) / 2,
                                  botRight.y));
                botLeftTree->insert(node);
            }
        }
        else
        {

            if ((topLeft.y + botRight.y) / 2 >= node->position.y)
            {
                if (topRightTree == nullptr)
                    topRightTree = new QuadTree(
                            Point((topLeft.x + botRight.x) / 2,
                                  topLeft.y),
                            Point(botRight.x,
                                  (topLeft.y + botRight.y) / 2));
                topRightTree->insert(node);
            }


            else
            {
                if (botRightTree == nullptr)
                    botRightTree = new QuadTree(
                            Point((topLeft.x + botRight.x) / 2,
                                  (topLeft.y + botRight.y) / 2),
                            Point(botRight.x, botRight.y));
                botRightTree->insert(node);
            }
        }
    }

    Node* search(Point p)
    {

        if (!inBoundary(p))
            return nullptr;

        if (n != nullptr)
            return n;

        if ((topLeft.x + botRight.x) / 2 >= p.x)
        {

            if ((topLeft.y + botRight.y) / 2 >= p.y)
            {
                if (topLeftTree == nullptr)
                    return nullptr;
                return topLeftTree->search(p);
            }


            else
            {
                if (botLeftTree == nullptr)
                    return nullptr;
                return botLeftTree->search(p);
            }
        }
        else
        {

            if ((topLeft.y + botRight.y) / 2 >= p.y)
            {
                if (topRightTree == nullptr)
                    return nullptr;
                return topRightTree->search(p);
            }


            else
            {
                if (botRightTree == nullptr)
                    return nullptr;
                return botRightTree->search(p);
            }
        }
    }

    bool inBoundary(Point p)
    {
        return (p.x >= topLeft.x &&
                p.x <= botRight.x &&
                p.y >= topLeft.y &&
                p.y <= botRight.y);
    }
};




int main()
{
    QuadTree center(Point(0, 0), Point(8, 8));

    Node x(Point(1, 1), 1);
    Node y(Point(2, 5), 2);
    Node z(Point(7, 6), 3);

    center.insert(&x);
    center.insert(&y);
    center.insert(&z);

    cout << "Node x: " <<
         center.search(Point(1, 1))->key << endl;
    cout << "Node y: " <<
         center.search(Point(2, 5))->key << endl;
    cout << "Node z: " <<
         center.search(Point(7, 6))->key << endl;
    cout << "Non-existing node: "
         << center.search(Point(5, 5));
    return 0;

    return 0;
}