#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
};

class Fibonacci {

public:
    explicit Fibonacci() {
    }

    void constructTree(int n, Node *node, int &size, int &leafs) {
        size++;

        if (n == 0 || n == 1) {
            node->val = 1;
            node->left = nullptr;
            node->right = nullptr;

            cout << 1 << ' ';
        } else {
            leafs++;

            node->val = fibonacci(n);
            Node *left = new Node;
            Node *right = new Node;
            node->left = left;
            node->right = right;

            cout << node->val << ' ';
            constructTree(n - 1, left, size, leafs);
            constructTree(n - 2, right, size, leafs);
        }
    }

    int fibonacci(int n) {
        if (n == 0 || n == 1) {
            return 1;
        } else {
            return fibonacci(n - 1) + fibonacci(n - 2);
        }
    }

    int depth(Node *node) {
        if (node == NULL)
            return 0;
        else {
            /* compute the depth of each subtree */
            int lDepth = depth(node->left);
            int rDepth = depth(node->right);

            /* use the larger one */
            if (lDepth > rDepth)
                return (lDepth + 1);
            else return (rDepth + 1);
        }
    }
};


int main(void) {

    int n;
    cin >> n;

    if (n < 0) {
        return 0;
    }

    int size = 0;
    int leafs = 1;

    Fibonacci tree;
    Node *first = new Node;

    cout << "Call tree in pre-order: ";
    tree.constructTree(n, first, size, leafs);
    cout << endl;

    cout << "Call tree size: " << size << endl;
    cout << "Call tree depth: " << tree.depth(first) << endl;
    cout << "Call tree leafs: " << leafs << endl;

    return 0;

}