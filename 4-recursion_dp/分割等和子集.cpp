//
// Created by xing on 2022/4/13.
//
#include <vector>
#include <numeric>
using namespace std;
/*
 * 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 * 解法：相当于数组中找出一个子集使得和为sum的一半。
 * */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if ( n<2 ) return false;
        int sum = accumulate(nums.begin(),nums.end(),0);
        int maxNum = *max_element(nums.begin(),nums.end());
        if (sum%2==1) return false;

        int target = sum/2;
        if (maxNum>target) return false;
        // dp[i][j]表示[0,i]区间选取若干个整数，是否存在一种方案，和为j
        vector<vector<int>> dp(n,vector<int>(target + 1,0));
        for (int i = 0; i < n; ++i) {
            // 不选取任何整数，和为0，因此存在
            dp[i][0] = 1;
        }
        dp[0][nums[0]] = 1;
        /*
         * 状态转移：
         * 如果j>=nums[i], 可以选，也可以不选 dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]]
         * 如果j<nums[i]，不能选 dp[i][j] = dp[i-1][j]
         * 最终答案 dp[n-1][target]
         * */
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= target; ++j) {
                if (j>=nums[i]) dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n-1][target];

        /*
         * 和背包问题一样，每一行的dp值只和上一行有关，因此可以用一维数组滚动更新
         * dp[j] = dp[j]||dp[j-nums[i]]
         * 需要注意的是，第二层循环需要从大到小来计算
         * */
    }
};