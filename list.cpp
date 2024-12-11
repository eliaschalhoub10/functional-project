#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

class ArrayList {
private:
    vector<int> data;

public:
    // Insert at the end
    void insertEnd(int val) {
        data.push_back(val);
    }

    // Search for a value
    bool search(int val) {
        for (int elem : data) {
            if (elem == val) return true;
        }
        return false;
    }

    // Traverse and print all elements
    void traverse() {
        for (int elem : data) {
            cout << elem << " ";
        }
        cout << endl;
    }
};

int main() {
    ArrayList list;
    for (int i = 1; i <= 30000; i++) {
        list.insertEnd(i);
    }

    auto start = high_resolution_clock::now();
    cout << list.search(5000) << endl;
    auto end = high_resolution_clock::now();
    cout << "Time taken for search: " << duration_cast<seconds>(end - start).count() << " seconds" << endl;

    start = high_resolution_clock::now();
    list.traverse();
    end = high_resolution_clock::now();
    cout << "Time taken for traversal: " << duration_cast<seconds>(end - start).count() << " seconds" << endl;

    return 0;
}
