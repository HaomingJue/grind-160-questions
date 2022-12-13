#include <algorithm>
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
    bool isBalanced(TreeNode* root) {
        return isValid(root) != -1;
    }

private:
    int isValid(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = isValid(root->left);
        int right = isValid(root->right);
        if (left == -1 || right == -1 || abs(left - right) > 1) return -1;
        return max(left, right) + 1;
    }
};