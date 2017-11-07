#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
};

// Class List
class Fibonacci {

public:
    explicit Fibonacci(Node *first) {
        this->first = first;
    }

    int fibonacci(int n, Node *node, int &size, int &leafs, int &depth) {
        size++;

        Node *temp = new Node;

        if (n == 0 || n == 1) {
            temp->val = 1;
            temp->left = nullptr;
            temp->right = nullptr;

            cout << 1 << ' ';

            return 1;
        } else {
            leafs++;
            depth++;

            temp->val = n;
            Node *left = new Node;
            Node *right = new Node;

            cout << n << ' ';

            return fibonacci(n - 1, left, size, leafs, depth) + fibonacci(n - 2, right, size, leafs, depth);
        }
    }

private:
    Node *first;
};


int main(void) {

    int n;
    cin >> n;

    if (n < 0) {
        return 0;
    }

    Node *first = new Node;
    first->val = n;

    int size = 0;
    int leafs = 1;
    int depth = 1;

    Fibonacci tree(first);

    cout << "Call tree in pre-order: ";
    tree.fibonacci(n, first, size, leafs, depth);
    cout << endl;

    cout << "Call tree size: " << size << endl;
    cout << "Call tree depth: " << depth << endl;
    cout << "Call tree leafs: " << leafs << endl;

    return 0;

}