#include <iostream>
#include <vector>

using namespace std;

vector<int> bag_a;
vector<int> bag_b;
char command;
int input;
int sum;

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
    int current_a, current_b;

    for (int i = 0; i < loops; i++) {
        current_a = i >= a_size ? 0 : bag_a.at(i);
        current_b = i >= b_size ? 0 : bag_b.at(i);

        sum += current_a * current_b;
    }

    cout << sum;

    return 0;
}
