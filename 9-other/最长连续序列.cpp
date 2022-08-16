//
// Created by xing on 2022/4/20.
//
#include <vector>
#include <unordered_set>

using namespace std;
/*
 * 最长连续序列
 * 输入：nums = [100,4,200,1,3,2]
 * 输出：4
 * 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
 * */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (int& num : nums) {
            num_set.insert(num);
        }

        int longestStreak = 0;
        for (const int& num : num_set) {
            // 如果存在前驱，直接跳过，否则求最大长度
            if (!num_set.count(num-1)){
                int currentNum = num;
                int currentStreak = 1;

                // 判断num+1是否存在，累加长度
                while(num_set.count(currentNum+1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak,currentStreak);
            }
        }

        return longestStreak;
    }
};