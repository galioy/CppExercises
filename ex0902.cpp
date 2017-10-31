#include <iostream>
#include <vector>

using namespace std;

int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;
    vector<int> numbers;

//    for (int i = 0; i <= 10; i++) {
//        numbers.push_back(i);
//    }

    cin >> n;
    while(cin) {
        numbers.push_back(n);
        cin >> n;
    }

    for (int i = 0; i < numbers.size(); i++) {
        cout << fibonacci(numbers[i]) << ' ';
    }

    return 0;
}
