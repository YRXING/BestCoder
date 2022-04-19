//
// Created by xing on 2022/4/12.
//

#include <vector>

using namespace std;
/*
 * 给定一个非负整数数组 nums ，你最初位于数组的第一个下标 。
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度。
 * 判断你是否能够到达最后一个下标。
 *
 * 输入：nums = [2,3,1,1,4]
 * 输出：true
 * 解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
 * */
class Solution {
public:
    /*
     * 实时维护能够到达的最远位置，如果最远位置大于等于最后一个下标
     * 就代表可以到达
     * */
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int rightMost = 0;
        for (int i = 0; i < n; ++i) {
            if (i<=rightMost) {
                rightMost = max(rightMost,i+nums[i]);
                if (rightMost >= n-1) return true;
            }
        }
        return false;
    }
};