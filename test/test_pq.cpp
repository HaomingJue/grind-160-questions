#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

template<typename T> void print_pq(T &pq) {
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

int main() {
    auto comp = [](int &a, int &b) {return a < b;};
    priority_queue<int, vector<int>, decltype(comp)> pq(comp);
    pq.push(4);
    pq.push(3);
    pq.push(5);
    pq.push(1);
    print_pq(pq);

    return 0;
}