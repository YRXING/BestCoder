//
// Created by xing on 2022/3/1.
//
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

/*
 * 问：给定序列1-n，不同的BST有多少个
 * */
class Solution {
public:
    /*
     * 遍历每个序号i，将i作为树根，1...i-1为左子树，i+1...n为右子树。然后同样方式递归构建左右子树
     * 序号为i+1...n的BST数量和1...n-i的一样，跟序号无关，只跟长度有关
     * G(n)：长度为n的BST数量
     * G(n) = sum(G(i-1)*G(n-i)) i=[1,n]
     * */
    int numTrees(int n) {
        vector<int> G(n+1,0);
        G[0] = 1;
        G[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <=i ; ++j) {
                G[i] += G[j-1]*G[i-j];
            }
        }
        return G[n];
    }
    /*
     * 本题属于卡塔兰数（catalan number）
     * */
};

/*
 * 问：给定序列1-n，返回不同的BST
 * */
class Solution2 {
public:
    vector<TreeNode*> generateTrees(int start,int end) {
        if (start>end) {
            //vector里面又一个空指针
            return {nullptr};
        }
        vector<TreeNode*> allTrees;
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> left = generateTrees(start,i-1);
            vector<TreeNode*> right= generateTrees(i+1,end);
            for (auto l : left) {
                for (auto r: right){
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    allTrees.push_back(root);
                }
            }
        }
        return allTrees;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (!n) {
            return {};
        }
        return generateTrees(1,n);
    }
};