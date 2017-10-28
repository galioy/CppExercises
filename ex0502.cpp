#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> bag_a;
vector<int> bag_b;
vector<int> result;
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

    long a_size = bag_a.size();
    long b_size = bag_b.size();

    long loops = a_size > b_size ? a_size : b_size;

    for (int i = 0; i < loops; i++) {
        if (i >= a_size) {
            if (i >= b_size) {
                continue;
            }
            cout << bag_b.at(i) << ' ';
        } else {
            cout << bag_a.at(i) << ' ';
            if (i >= b_size) {
                continue;
            }
            cout << bag_b.at(i) << ' ';
        }
    }

    return 0;
}
