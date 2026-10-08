#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

void printArray(const vector<int>& arr) {
    for (int num : arr) cout << num << " ";
    cout << "\n";
}

int main() {
    srand(time(0));

    int n;
    cout << "1. Enter n: ";
    cin >> n;

    vector<int> arr(n);
    generate(arr.begin(), arr.end(), []() { return rand() % 100; });
        
    cout << "2. Original array:\n";
    printArray(arr);

    int indexToDelete;
    cout << "\n3. Index to delete (1 to " << arr.size() << "): "; cin >> indexToDelete;
    if (indexToDelete >= 1 && indexToDelete <= arr.size()) {
        arr.erase(arr.begin() + (indexToDelete - 1));
        cout << "4. After deletion:\n";
        printArray(arr);
    }

    int N, K;
    cout << "\n5. Number of elements to add (N) and index (K) (1 to " << arr.size() + 1 << "): ";
    cin >> N >> K;
    if (K >= 1 && K <= arr.size() + 1) {
        vector<int> temp(N);
        generate(temp.begin(), temp.end(), []() { return rand() % 100; });

        arr.insert(arr.begin() + (K - 1), temp.begin(), temp.end());
        cout << "6. After insertion:\n";
        printArray(arr);
    }

    int M;
    cout << "\n7. Shift left by (M): "; cin >> M;
    if (!arr.empty()) {
        rotate(arr.begin(), arr.begin() + (M % arr.size()), arr.end());
        cout << "8. After shift:\n";
        printArray(arr);
    }

    int key;
    cout << "\n9. Element for search: "; cin >> key;

    int compCount = 0;
    auto itLinear = find_if(arr.begin(), arr.end(), [&compCount, key](int val) {
        compCount++;
        return val == key;
        });

    cout << "10. Linear search result:\n";
    if (itLinear != arr.end()) {
        cout << "Found at index: " << distance(arr.begin(), itLinear) + 1 << "\n";
    }
    else {
        cout << "Not found.\n";
    }
    cout << "Comparisons: " << compCount << "\n";

    cout << "\n11. Insertion sort...\n";
    for (auto i = arr.begin(); i != arr.end(); ++i) {
        rotate(upper_bound(arr.begin(), i, *i), i, i + 1);
    }

    cout << "12. Sorted array:\n";
    printArray(arr);

    cout << "\n13. Element for binary search: "; cin >> key;

    compCount = 0;
    auto itBinary = lower_bound(arr.begin(), arr.end(), key, [&compCount](int a, int b) {
        compCount++;
        return a < b;
        });

    cout << "14. Binary search result:\n";
    if (itBinary != arr.end() && *itBinary == key) {
        cout << "Found at index: " << distance(arr.begin(), itBinary) + 1 << "\n";
    }
    else {
        cout << "Not found.\n";
    }
    cout << "Comparisons: " << compCount << "\n";

    return 0;
}