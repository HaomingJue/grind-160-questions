#include <iostream>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        getDepth(root);
        return ans;
    }

private:
    int ans = 0;
    int getDepth(TreeNode* node) {
        if (node == NULL) return 0;
        int left = getDepth(node->left);
        int right = getDepth(node->right);
        ans = max(ans, left + right);
        return max(right, left) + 1;
    }
};