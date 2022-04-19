#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include <iostream>
#include <cmath>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <string>
#include <bit>
#include <list>
#include <numeric>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solutiona {
public:
    /*
     * 暴力 n2时间复杂度
     * */
    int largestRectangleArea1(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        // 枚举左边界
        for (int left = 0; left < n; ++left) {
            int minHeight = INT_MAX;
            // 枚举右边界
            for (int right = left; right < n; ++right) {
                // 确定高度
                minHeight = min(minHeight, heights[right]);
                // 计算面积
                ans = max(ans, (right - left + 1) * minHeight);
            }
        }
        return ans;
    }

    /*
     * 对于每一根柱子，所能围成的最大面积，是左边最后一个不小于它的柱子和右边最后一个不小于它的柱子围起来的面积
     * are = height[i]*(right-left)
     * 因为一旦遇到比它小的柱子，面积就不是由它决定了，而是由小柱子决定的
     * 对于每根柱子，可以暴力搜索找到左右边界，也可以使用单调栈
     *
     * */
    int largestRectangleArea(vector<int>& heights) {

    }
};



int main(){

    return 0;
}