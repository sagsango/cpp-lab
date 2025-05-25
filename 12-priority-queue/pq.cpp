#include <iostream>
//#include <priority_queue>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

struct maxHeapNode {
    int val;
    bool operator<(const maxHeapNode &other) const {
        return val < other.val;
    }
};

int main() {
    vector <int> arr = {1, 2, 10, -1, 4, 5, 10, -20};
    priority_queue<maxHeapNode> pq;
    for (const int x: arr) {
        pq.push({x});
    }

    while (!pq.empty()) {
        cout << pq.top().val << endl;
        pq.pop();
    }
}
