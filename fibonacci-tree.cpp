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

    void constructTree(int n, Node *node, int &size, int &leafs, int &depth) {
        size++;
        Node *temp = new Node;

        if (n == 0 || n == 1) {
            temp->val = 1;
            temp->left = nullptr;
            temp->right = nullptr;

            cout << 1 << ' ';
        } else {
            leafs++;
            depth++;

            temp->val = fibonacci(n);
            Node *left = new Node;
            Node *right = new Node;

            cout << temp->val << ' ';
            constructTree(n - 1, left, size, leafs, depth);
            constructTree(n - 2, right, size, leafs, depth);
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
    tree.constructTree(n, first, size, leafs, depth);
    cout << endl;

    cout << "Call tree size: " << size << endl;
    cout << "Call tree depth: " << tree.depth(first) << endl;
    cout << "Call tree leafs: " << leafs << endl;

    return 0;

}