//
// Created by xing on 2022/4/1.
//
#include <stack>
#include <string>
#include <vector>
using namespace std;
/*
 * 给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
 * 输入：s = "(()"
 * 输出：2
 *
 * 切入点：所有有效的括号都是以')'结尾
 * */
class Solution {
public:
    /*
     * 动态规划
     * s[i]=‘)’ 且 s[i - 1] = ‘(’,也就是字符串形如 “……()”
     * dp[i] = dp[i-2] + 2
     *
     * s[i] = ‘)’ 且 s[i−1]=‘)’，也就是字符串形如 “……))”
     * 如果dp[i-1-dp[i-1]] = '(' 那么dp[i] = dp[i-1]+dp[i-dp[i-1]-2] + 2
     * */
    int longestValidParentheses1(string s) {
        int maxans=0,n=s.length();
        vector<int> dp(n,0);
        for (int i = 1; i < n; ++i) {
            if (s[i]==')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i - 2 >= 0) ? dp[i - 2] + 2 : 2;
                }else if (s[i-1] == ')'&&i-1-dp[i-1]>=0&&dp[i-1-dp[i-1]] == '(') {
                    dp[i] = dp[i-1]+(i-2-dp[i-1]>=0?dp[i-dp[i-1]-2]+2:2);
                }
            }
            maxans = max(maxans,dp[i]);
        }
        return maxans;
    }

    /*
     * 栈：栈底始终存最后一个未被匹配的')'下标，来表示边界，其他存'('下标等待匹配。
     * */
    int longestValidParentheses2(string s) {
        int maxans=0;
        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i]=='(') {
                stk.push(i);
            } else {
                stk.pop();
                // 更新最后一个未被匹配的')'
                if (stk.empty()) stk.push(i);
                    // 匹配成功，计算长度
                else maxans = max(maxans,i-stk.top());
            }
        }
        return maxans;
    }

    /*
     * 双指针+正向逆向遍历
     * 遇到'('，left+1，')'，right+1。当left=right时候，计算长度。当right>left时候，两者设为0
     * 这样会漏掉一种情况，就是遍历的时候左括号的数量始终大于右括号的数量，即 (() ，这种时候最长有效括号是求不出来的。
     * 解决办法是反向遍历一边即可，判断条件相反。
     * */
    int longgestValidParentheses(string s){
        int left=0,right=0,maxlength=0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i]=='(') left++;
            else right++;
            if (left==right) maxlength = max(maxlength,2*right);
            else if (right > left) left = right = 0;
        }

        left = right = 0;
        for (int i = s.length()-1; i >= 0; --i) {
            if (s[i]=='(') left++;
            else right++;
            if (left==right) maxlength = max(maxlength,2*left);
            else if (left > right) left = right = 0;
        }

        return maxlength;
    }

};