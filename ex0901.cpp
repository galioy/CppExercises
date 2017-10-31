#include <iostream>
#include <vector>

using namespace std;

//void reverse(int *p, int lim) {
//    if (lim > 0) {
//        reverse(++p, --lim);
//        cout << *(p - 1) << ' ';
//    }
//}

void reverseVector(vector<int> numbers, int idx) {
    if (idx <= numbers.size()) {
        cout << numbers[idx] << ' ';
        reverseVector(numbers, idx - 1);
    }
}

int main() {
    int n;
    vector<int> numbers;

//    for (int i = 1; i <= 10; i++) {
//        numbers.push_back(i);
//    }

    cin >> n;
    while(cin) {
        numbers.push_back(n);
        cin >> n;
    }

    int *p = new int[numbers.size()];
    for (int i = 0; i < numbers.size(); i++) {
        *(p + i) = numbers[i];
    }

//    reverse(p, numbers.size());
    reverseVector(numbers, numbers.size() - 1);

    return 0;
}
