//
// Created by xing on 2022/3/18.
//

#include <string>
#include <vector>
using namespace std;

/*
 * 电话号码的字母组合
输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]

 * 当题目中出现 “所有组合” 等类似字眼时，我们第一感觉就要想到用回溯。
 * */
class Solution {
public:
    void DFS(int i,vector<string>& ans,string& tmp,vector<string>& res){
        if (i==ans.size()){
            res.push_back(tmp);
            return;
        }
        string s = ans[i];
        for (int j = 0; j < s.size(); ++j) {
            tmp+=s[j];
            DFS(i+1,ans,tmp,res);
            tmp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size()==0) return {};
        vector<string> phone={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> res,ans;
        string tmp;
        for (char c : digits){
            ans.push_back(phone[c-'0']);
        }
        DFS(0,ans,tmp,res);
        return res;
    }
};