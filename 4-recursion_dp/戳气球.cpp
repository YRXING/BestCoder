//
// Created by xing on 2022/4/1.
//

#include <vector>

using namespace std;
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