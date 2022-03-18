//
// Created by xing on 2022/3/18.
//

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
/*
 * 单词拆分
输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
 * */
class Solution {
public:
    /*
     * DFS遍历每一种可能
     * s[0:i]在字典里&&DFS(s[i+1:len])
     * 这种方法数量大时会超时
     * */
    bool DFS(int start, string s, unordered_map<string,bool>& mp) {
        int len = s.size();
        if (start == len) {
            return true;
        }
        for (int i = start+1; i < len; ++i) {
            string prefix = s.substr(start,i-start);
            if (mp[prefix]&&DFS(i,s,mp)){
                return true;
            }
        }
        return false;
    }

    /*
     * 记忆化搜索
     * 把递归的状态存到数组里，遇到相同递归问题直接返回结果
     * */
    bool DFS(int start,string s,unordered_map<string,bool>& mp,unordered_map<int,bool>& mem){
        int len = s.size();
        if (start == len) {
            return true;
        }
        if (mem.find(start)!=mem.end()) {
            return mem[start];
        }
        for (int i = start+1; i < len; ++i) {
            string prefix = s.substr(start,i-start);
            if (mp[prefix]&&DFS(i,s,mp)){
                mem[i] = true;
                return true;
            }
        }
        mem[start] = false;
        return false;
    }

    bool wordBreak2(string s, vector<string>& wordDict) {
        unordered_map<string,bool> hash;
        for (string& s: wordDict) {
            hash[s] = true;
        }
        unordered_map<int,bool>mem;
        return DFS(0,s,hash,mem);
    }

    /*
     * 动态规划
     * dp[i]表示前i个字符s[0:i-1]能否被拆分成字典里面的单词。
     * dp[i] = dp[j]&&check(s[j..i-1]) j==0..i-1
     * */
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool> hash;
        for (string& s: wordDict) {
            hash[s] = true;
        }

        vector<int> dp(s.size()+1);
        dp[0] = 1;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j]&&hash[s.substr(j,i-j)]){
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};