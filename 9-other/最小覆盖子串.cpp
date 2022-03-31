//
// Created by xing on 2022/3/29.
//

#include <string>
#include <unordered_map>
using namespace std;
/*
 * 输入：s = "ADOBECODEBANC", t = "ABC"
 * 输出："BANC"
 * 滑动窗口
 * */
class Solution {
public:
    unordered_map<char,int> ori,cnt;
    bool check() {
        for (auto& p : ori) {
            if (cnt[p.first] < p.second) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        for (auto& c : t) {
            ori[c]++;
        }

        int l=0,r=-1;
        int len = INT_MAX,ansL = -1;
        while (r < int(s.size())) {
            //只存窗口里存在t中的字符
            if (ori.find(s[++r])!=ori.end())
                cnt[s[r]]++;

            while (check()&&l<=r) {
                if (r-l+1 < len){
                    len = r-l+1;
                    ansL = l;
                }
                if (ori.find(s[l])!=ori.end())
                    cnt[s[l]]--;
                l++;
            }
        }
        return ansL == -1? "":s.substr(ansL,len);
    }
};