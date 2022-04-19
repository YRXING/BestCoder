//
// Created by xing on 2022/4/19.
//
#include <vector>
#include <stack>
using namespace std;
/*
 * 最大出栈字典序
 * 输入
5
2 1 5 3 4
输出
5 4 3 1 2
 * */
class Solution {
public:
    /*
     * 思路：
     * 用一个数组rmax[i]表示第 i 项到第 n 项的数的最大值。
     * 若栈为空，直接压入当前元素
     * 若栈顶元素比rmax[i]大，栈顶出栈，直到栈顶元素比rmax[i]小
     * 若栈顶元素比rmax[i]小，nums[i]入栈
     * */
    vector<int> maxOutStackSequence(vector<int>& nums) {
        int n = nums.size();
        vector<int> rmax(n,0);
        stack<int> s;
        vector<int> res;
        //初始化
        rmax[n-1] = nums[n-1];
        //逆着求 rmax[i]
        for (int i = n-2; i >=0 ; --i) {
            rmax[i] = max(rmax[i+1],nums[i]);
        }

        for (int i = 0; i < n; ++i) {
            while (!s.empty()&&s.top() > rmax[i]){
                res.push_back(s.top());
                s.pop();
            }
            s.push(nums[i]);
        }

        while (!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
};