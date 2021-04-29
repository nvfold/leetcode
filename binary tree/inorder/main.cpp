#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

vector<int> inorderTraversal(TreeNode* root) {
    // iterative
    vector<int> result;
    vector < TreeNode * > fathers;

    if (root == nullptr) return result;
    bool notFatherNode = true;
    while (root) {
        if (root->left && notFatherNode) {
            // store daddy before left
            fathers.push_back(root);

            // go left
            root = root->left;
        } else {
            // print root
            result.push_back(root->val);

            // go right
            root = root->right; // maybe nullptr
        }
        if (root == nullptr && !fathers.empty()) {
            root = fathers.back();
            fathers.pop_back();
            notFatherNode = false;
        }
    }

    return result;
}
int main() {
    TreeNode* root = new TreeNode{1, nullptr, nullptr};
    root->right = new TreeNode{2, nullptr, nullptr};
    root->right->left = new TreeNode{3, nullptr, nullptr};
    vector<int>res = inorderTraversal(root);
    return 0;
}
