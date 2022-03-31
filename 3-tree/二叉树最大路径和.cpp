//
// Created by xing on 2022/3/26.
//
#include<algorithm>
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
 * 二叉树中最大路径和
 * */
class Solution {
public:
    int maxSum = INT_MIN;
    int maxGain(TreeNode* node){
        if(node == nullptr) return 0;
        int left = max(maxGain(node->left),0);
        int right = max(maxGain(node->right),0);

        int priceNewPath = node->val + left + right;
        maxSum = max(maxSum,priceNewPath);
        return node->val + max(left,right);
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};
