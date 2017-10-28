#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> bag_a;
vector<int> bag_b;
char command;
int input;
string line;

int main() {

    while (cin >> command >> input) {
        if (command == 'a') {
            bag_a.push_back(input);
        }
        if (command == 'b') {
            bag_b.push_back(input);
        }
    }

    sort(bag_a.begin(), bag_a.end());
    sort(bag_b.begin(), bag_b.end());

    for (int i = 0; i < bag_a.size(); i++) {
        cout << bag_a[i] << ' ';
    }
    for (int i = 0; i < bag_b.size(); i++) {
        cout << bag_b[i] << ' ';
    }

    return 0;
}
