//
// Created by xing on 2022/4/14.
//
#include <vector>
using namespace std;
/*
 * 最大正方形
 * 在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。
 * */
class Solution {
public:
    /*
     * dp[i][j] 表示以i,j结尾所能构造的最大正方形变长
     * if matrix[i][j] == 1; dp[i][j] = min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1;
     * else dp[i][j] = 0;
     * */
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size()==0) return 0;
        int r = matrix.size(),c=matrix[0].size();
        vector<vector<int>> dp(r,vector<int>(c));

        int maxLen = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if ( matrix[i][j]== '1'){
                    if (i==0||j==0)
                        dp[i][j] = 1;
                    else dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])) + 1;

                    maxLen = max(maxLen,dp[i][j]);
                }
            }
        }
        return maxLen*maxLen;
    }
};