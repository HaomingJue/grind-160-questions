#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

template<typename T> void print_vector(T & vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> vec = {3, 4, 1, 2, 5};
    auto comp = [](int &a, int &b) {return a < b;};
    sort(vec.begin(), vec.end(), comp);
    print_vector(vec);
    return 0;
}