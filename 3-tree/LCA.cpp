//
// Created by xing on 2022/2/19.
//

#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 * LCA
 * */

class Solution {
public:
    TreeNode* ans;
    // 定义：在以 root 为根的二叉树中寻找值为 val1 或 val2 的节点
    TreeNode* find(TreeNode* root, int val1, int val2) {
        // base case
        if (root == nullptr) {
            return nullptr;
        }
        // 前序位置，看看 root 是不是目标值
        if (root->val == val1 || root->val == val2) {
            return root;
        }
        // 去左右子树寻找
        TreeNode* left = find(root->left, val1, val2);
        TreeNode* right = find(root->right, val1, val2);
        // 后序位置，已经知道左右子树是否存在目标值
        if (left != nullptr && right != nullptr) {
            // 当前节点是 LCA 节点
            return root;
        }
        return left != nullptr ? left : right;
    }

    // 判断p，q是在不在root及其子树里面
    bool dfs(TreeNode* root,TreeNode* p,TreeNode* q) {
        if (root== nullptr) return false;
        bool lson = dfs(root->left,p,q);
        bool rson = dfs(root->right,p,q);
        if ((lson&&rson)||((root->val==p->val||root->val==q->val)&&(lson||rson))) {
            ans = root;
        }
        return lson||rson|| (root->val==p->val||root->val==q->val);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root,p,q);
        return ans;
    }

    /*
     * 哈希：递归存储所有节点的父节点，然后不断往上跳寻找
     * 1. 从根节点开始遍历整棵二叉树，用哈希表记录每个节点的父节点指针。
     * 2. 从 p 节点开始不断往它的祖先移动，并用数据结构记录已经访问过的祖先节点。
     * 3. 同样，我们再从 q 节点开始不断往它的祖先移动，如果有祖先已经被访问过，即意味着这是 p 和 q 的深度最深的公共祖先，即 LCA 节点。
     * */
    unordered_map<int,TreeNode*> fa;
    unordered_map<int,bool> vis;
    void dfs2(TreeNode* root) {
        if (root->left!= nullptr) {
            fa[root->left->val] = root;
            dfs2(root->left);
        }
        if (root->right!= nullptr) {
            fa[root->right->val] = root;
            dfs2(root->right);
        }
    }

    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        fa[root->val] = nullptr;
        dfs2(root);
        while (p!= nullptr) {
            vis[p->val] = true;
            p = fa[p->val];
        }
        while (q != nullptr) {
            if (vis[q->val]) return q;
            q = fa[q->val];
        }
        return nullptr;
    }
};