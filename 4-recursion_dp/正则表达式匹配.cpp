//
// Created by xing on 2022/3/29.
//
#include <vector>
#include <string>
using namespace std;
/*
 *给你一个字符串s和一个字符规律p，请你来实现一个支持 '.'和'*'的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素

 * if p[j] != '*'
 * s[i]==p[j]||p[j]=='.' dp[i][j]=dp[i-1][j-1]
 * otherwise  dp[i][j] = 0
 * else
 * 如果是*，那么p[j-1]p[j]将作为一个整体去考虑
 * 本质上只会有两种情况：
匹配 s 末尾的一个字符，将该字符扔掉，而该组合还可以继续进行匹配；

不匹配字符，将该组合扔掉，不再进行匹配。
 * s[i]==p[j-1]||p[j-1]=='.'  dp[i][j]=dp[i-1][j]||dp[i][j-2]
 * otherwise  dp[i][j]=dp[i][j-2]
 * */
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        auto matches = [&](int i, int j) {
            if (i == 0) {
                return false;
            }
            if (p[j - 1] == '.') {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        f[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    f[i][j] |= f[i][j - 2];
                    if (matches(i, j - 1)) {
                        f[i][j] |= f[i - 1][j];
                    }
                }
                else {
                    if (matches(i, j)) {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }
        return f[m][n];
    }
};