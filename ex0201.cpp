#include <iostream>

using namespace std;

int main() {
    int input_n, n = 0;
    cin >> input_n;

    for (int i = 1; i <= input_n; i++) {
        n = n + i;
    }

    cout << n << endl;

    return 0;
}