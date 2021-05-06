#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> qN;
        bool p_isfound = false, q_isfound = false;
        vector<TreeNode*> p_path;
        vector<TreeNode*> q_path;
        do{
            while(root){
                if(root->right) qN.push(root->right);
                qN.push(root);

                if(!p_isfound) p_path.push_back(root);
                if(!q_isfound) q_path.push_back(root);

                root = root->left;
            }
            root = qN.top();
            qN.pop();

            if(!qN.empty() && root->right && root->right == qN.top()){
                qN.pop();
                qN.push(root);
                root = root->right;
            }else{

                if(!p_isfound && root == p){
                    p_isfound = true;
                }else if(!p_isfound){
                    p_path.pop_back();
                }

                if(!q_isfound && root == q){
                    q_isfound = true;
                }else if(!q_isfound){
                    q_path.pop_back();
                }

                root = nullptr;
            }
        }while(!qN.empty() && (!p_isfound || !q_isfound));

        int i = 0;
        while(i < p_path.size() &&
                i < q_path.size() &&
                p_path[i] == q_path[i]){
            i++;
        }

        if(i > 0) i = i - 1;
        return p_path[i];
}
int main() {
    /* test 1 pass
    TreeNode * root = new TreeNode(3);
    TreeNode* p = new TreeNode(5);
    TreeNode* q = new TreeNode(4);
    root->left = p;
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    p->left = new TreeNode(6);
    p->right = new TreeNode(2);
    p->right->left = new TreeNode(7);
    p->right->right = q;
    */

    /* test 2 */
    TreeNode* root = new TreeNode(2);
    root->right = new TreeNode(1);
    lowestCommonAncestor(root, root, root->right);

    return 0;
}
