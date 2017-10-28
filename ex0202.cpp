#include <iostream>

using namespace std;

int main() {
    int input_n, sum = 0;
    cin >> input_n;

    for (int i = 0; i <= input_n; i = i + 2) {
        sum = sum + i;
    }

    cout << sum << endl;

    return 0;
}