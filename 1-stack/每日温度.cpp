//
// Created by xing on 2022/3/18.
//
#include <vector>
#include <stack>
using namespace std;

/*
 * answer[i] 是指在第 i 天之后，才会有更高的温度。如果气温在这之后都不会升高，请在该位置用 0 来代替。
输入: temperatures = [73,74,75,71,69,72,76,73]
输出: [1,1,4,2,1,1,0,0]

单调栈：栈里面存下标，这样即可以计数，也可以比较。
单调栈解题过程：
1、如果当前元素大于栈顶元素，弹栈，直到栈顶元素大于当前元素
 处理完后（可以是计数，也可以是直接输出栈顶），将当前元素入栈
2、如果当前元素小于栈顶，直接入栈
 * */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        vector<int> res(temperatures.size());
        for (int i = temperatures.size()-1; i >=0 ; --i) {
            int t = temperatures[i];
            if (!stk.empty()&&t<temperatures[stk.top()]){
                stk.push(i);
                res[i] = 1;
            } else {
                while (!stk.empty() && temperatures[stk.top()] <= t) {
                    stk.pop();
                }
                if (stk.empty()) res[i] = 0;
                else res[i]= stk.top()-i;
                stk.push(i);
            }

        }
        return res;
    }
};