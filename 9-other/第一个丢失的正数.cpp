//
// Created by xing on 2022/3/18.
//
#include <vector>
using namespace std;

/*
 * 对于一个长度为 N 的数组，其中没有出现的最小正整数只能在 [1, N+1] 中
1. 我们将数组中所有小于等于 0 的数修改为 N+1；

2. 我们遍历数组中的每一个数 x，它可能已经被打了标记，因此原本对应的数为 |x|。如果 |x| in [1, N]
 那么我们给数组中的第 |x| - 1 个位置的数添加一个负号。

3. 在遍历完成之后，如果数组中的每一个数都是负数，那么答案是 N+1，否则答案是第一个正数的位置加 1。

 * */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            if (nums[i]<=0) nums[i] = len+1;
        }
        for (int i = 0; i < len; ++i) {
            int num = abs(nums[i]);
            if ( num <= len) nums[num-1] = -abs(nums[num-1]);
        }
        for (int i = 0; i < len; ++i) {
            if (nums[i]>0) return i+1;
        }
        return len+1;
    }
};

