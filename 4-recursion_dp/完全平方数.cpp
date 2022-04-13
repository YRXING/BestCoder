//
// Created by xing on 2022/4/12.
//

#include <vector>

using namespace std;
/*
 * 给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
 * */
class Solution {
public:
    /*
     * 动态规划
     * dp[n] = 1 + Min(dp[n-j*j]) j=1,2,3...sqrt(n)
     * */
    int numSquares(int n) {
        vector<int> dp(n+1);
        for (int i = 1; i <= n; ++i) {
            int minn = INT_MAX;
            for (int j = 1; j*j <= i; ++j) {
                minn = min(minn,dp[i-j*j]);
            }
            dp[i] = 1+minn;
        }
        return dp[n];
    }

    /*
     * 四平方和定理：任意一个正整数都可以被表示为至多四个正整数的平方和
     * 当 n = 4^k*(8m+7)时，直接返回4
     * 当 n = k^k 返回1
     * 当 n = a^a + b^b 返回2 枚举a，判断n-a^a是否是完全平方数
     * 排除法 返回3
     * */

    // 判断是否为完全平方数
    bool isPerfectSquare(int x) {
        int y = sqrt(x);
        return y * y == x;
    }

    // 判断是否能表示为 4^k*(8m+7)
    bool checkAnswer4(int x) {
        while (x % 4 == 0) {
            x /= 4;
        }
        return x % 8 == 7;
    }

    int numSquares2(int n) {
        if (isPerfectSquare(n)) {
            return 1;
        }
        if (checkAnswer4(n)) {
            return 4;
        }
        for (int i = 1; i * i <= n; i++) {
            int j = n - i * i;
            if (isPerfectSquare(j)) {
                return 2;
            }
        }
        return 3;
    }
};
