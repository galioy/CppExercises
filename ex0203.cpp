#include <iostream>

using namespace std;

int main() {
    int input_n, z = 2;
    cin >> input_n;

    while (input_n > 1) {
        if (input_n % z == 0) {
            if (input_n == z){
                cout << z;
            } else {
                cout << z << " * ";
            }
            input_n /= z;
        } else {
            z++;
        }
    }

    return 0;
}