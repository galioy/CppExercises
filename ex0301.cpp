#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int intervals, set_size, k, max_el, count = 0;
    cin >> intervals;
    cin >> set_size;
    int dataset[set_size];

    // Fill up the array
    while (count < set_size) {
        cin >> dataset[count];
        count++;
    }

    max_el = dataset[0];
    // Find the max of the array
    for (int i = 1; i < set_size; i++) {
        if (dataset[i] > max_el) {
            max_el = dataset[i];
        }
    }

    // Get the size of the interval, according to the given input
    k = ceil((double) max_el / (double) intervals);

    int needed_size;
    for (int i = 1; i < set_size; i++) {
        if ((i * k) > max_el) {
            needed_size = i;
            break;
        }
    }

    // Construct the initial bounds interval
    struct bounds {
        int upper;
        int lower;
        int count;
    };
    bounds result[needed_size];

    result[0].lower = 0;
    result[0].upper = k;
    result[0].count = 0;

    // Construct the rest of the bounds intervals
    for (int i = 1; i < needed_size; i++) {
        result[i].lower = i * k;
        result[i].upper = ((i + 1) * k) - 1;
        result[i].count = 0;
    }

    for (int i = 0; i < needed_size; i++) {
        for (int j = 0; j < needed_size; j++) {
            if (dataset[i] >= result[j].lower && dataset[i] <= result[j].upper) {
                result[j].count += 1;
            }
        }
    }

    for (int i = 0; i < needed_size; i++) {
        cout << result[i].lower;
        cout << ": ";
        cout << result[i].count << endl;
    }

    // Exit
    return 0;
}
