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


/*
 * 戳气球，使获得金币最多
输入：nums = [3,1,5,8]
输出：167
解释：
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
 * */
class Solution {
public:
    /*
     * 动态规划
     * dp[i][j]表示区间(i,j)等得到的最多硬币数
     * i<j-1 dp[i][j] = max val[i]*val[k]*val[j] + dp[i][k]+dp[k][j] (k=i+1....j-1)
     * i>=j-1 dp[i][j] = 0;
     * 最终答案 dp[0][n+1];
     * */
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+2,vector<int>(n+2));
        vector<int> val(n+2);
        // 真实的值在1-n中，0和n+1为边界
        val[0] = val[n+1] = 1;
        for (int i = 1; i <= n; ++i) {
            val[i] = nums[i-1];
        }

        for (int i = n-1; i >= 0 ; --i) {
            for (int j = i+2; j <= n+1; ++j) {
                for (int k = i+1; k <= j-1; ++k) {
                    int sum = val[i]*val[k]*val[j];
                    sum+=dp[i][k]+dp[k][j];
                    dp[i][j] = max(sum,dp[i][j]);
                }
            }
        }
        return dp[0][n+1];
    }

    /*
     * 还可以用递归solve(i,j)表示将开区间 (i,j)(i,j) 内的位置全部填满气球能够得到的最多硬币数。
     * */
};

int main(){

    return 0;
}