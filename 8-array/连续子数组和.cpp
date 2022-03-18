//
// Created by xing on 2022/1/4.
//

#include <vector>
#include <unordered_map>
using namespace std;
/*
 * 给你一个整数数组 nums 和一个整数k ，编写一个函数来判断该数组是否含有同时满足下述条件的连续子数组：

    子数组大小 至少为 2 ，且
    子数组元素总和为 k 的倍数。
    如果存在，返回 true ；否则，返回 false 。

    解决办法： 前缀和+哈希表
    同余定理：如果两个整数m、n满足n-m能被k整除，那么n和m对k同余

    即 ( pre(j) - pre (i) ) % k == 0 则 pre(j) % k == pre(i) % k
    这样哈希表里只需要存放前缀和的余数和相应的索引即可，然后判断哈希表中是否有相同的余数
    有就意味着存在i，j使得pre[j]-pre[i]是k的倍数
 */
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int s = nums.size();
        if(s < 2) return false;
        unordered_map<int,int> map;
        map[0] = -1;
        int remainder=0; //余数
        for(int i=0;i<s;i++){
            remainder = (remainder+nums[i])%k;
            // 如果已经有相同的余数，判断下标的差是否大于2
            if(map.count(remainder)) {
                int preIndex = map[remainder];
                if(i - preIndex>=2) return true;
            } else {
                map[remainder] = i;
            }
        }
        return false;
    }
};

