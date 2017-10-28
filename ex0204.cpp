#include <iostream>

using namespace std;

double pi(int n) {
    double partial = 0.0;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            partial += 1 / ((2.0 * i) + 1);
        } else {
            partial -= 1 / ((2.0 * i) + 1);
        }
    }

    double newPi = 4 * partial;
    cout << newPi;
}

int main() {
    int input_n, z = 2;
    cin >> input_n;

    pi(input_n);

    return 0;
}
