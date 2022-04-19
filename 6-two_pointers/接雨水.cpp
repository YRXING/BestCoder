//
// Created by xing on 2022/2/18.
//
#include<vector>
#include <stack>
using namespace std;
/*
 * 接雨水
 * */
class Solution {
public:
    /*
     * 暴力
     * 当前位置能接到的雨水为：max(min(max_left,max_right) - height[i],0)
     * 时间复杂度为n2，可能会超时
     * */
    int trap1(vector<int>& height) {
        int ans=0;
        int size = height.size();
        for (int i = 1; i < size-1; ++i) {
            int max_left=0,max_right=0;
            for (int j = i; j >=0 ; --j) {
                max_left = max(max_left,height[j]);
            }
            for (int j = i; j < size; ++j) {
                max_right = max(max_right,height[j]);
            }

            ans += max(min(max_left,max_right) - height[i],0);
        }
        return ans;
    }

    /*
     * 每个位置的left_max,right_max存储到数组中，来减少时间复杂度
     * */
    int trap2(vector<int>& height) {
        int ans=0;
        int size = height.size();
        vector<int> left_max(size), right_max(size);
        //初始化边界值
        left_max[0] = height[0];
        right_max[size-1] = height[size-1];
        for (int i = 1; i < size; ++i) {
            left_max[i] = max(height[i],left_max[i-1]);
        }
        for (int i = size-2; i >=0; --i) {
            right_max[i] = max(height[i],right_max[i+1]);
        }

        for (int i = 1; i < size-1; ++i) {
            ans+=max(min(left_max[i],right_max[i]) - height[i],0);
        }
        return ans;
    }

    /*
     * 双指针
     * 对于位置left而言，它左边最大值一定是left_max，右边最大值“>=”right_max，
     * 这时候，如果left_max<right_max成立，那么它就知道自己能存多少水了。
     * 无论右边将来会不会出现更大的right_max，都不影响这个结果。
     * 所以当left_max<right_max时，我们就希望去处理left下标，反之，我们希望去处理right下标。
     * 时间复杂度n，空间复杂度1
     * */
    int trap(vector<int>& height) {
        int left=0,right=height.size()-1;
        int ans=0;
        int left_max=0,right_max=0;
        while (left <= right) {
            if (left_max<right_max) {
                height[left] >= left_max?(left_max = height[left]):ans+=left_max-height[left];
                left++;
            } else {
                height[right] >= right_max?(right_max = height[right]):ans+=right_max-height[right];
                right--;
            }
        }
        return ans;
    }

};