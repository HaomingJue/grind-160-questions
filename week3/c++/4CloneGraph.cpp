#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        Node* cur = new Node(node->val);
        visited[node] = cur;
        for (auto neighbor : node->neighbors) {
            if (visited.find(neighbor) != visited.end()) {
                cur->neighbors.push_back(visited[neighbor]);
            }
            else {
                cur->neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return cur;
    }
private:
    unordered_map<Node*, Node*> visited;
};