//
// Created by xing on 2022/2/27.
//
/*
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * n = "(" + 【i=p时所有括号的排列组合】 + ")" + 【i=q时所有括号的排列组合】，其中 p+q=n-1
 * 剩下的n-1组括号要么在新增加"（）"的里面，要么在外面（右侧）
 * 为什么不会在左侧？
 * 因为整个结构是对称的，比如p=0,q=n-1，如果q在左侧刚好对应p=n-1,q=0的情况
 * 所以只需要把p从0-n-1遍历完就可以了
 * */
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n==0) return {""};
        vector<vector<string>> dp(n+1);
        dp[0] = {""};
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                for (string p : dp[j]) {
                    for (string q : dp[i-j-1]) {
                        dp[i].push_back("("+p+")"+q);
                    }
                }
            }
        }

        return dp[n];
    }
};