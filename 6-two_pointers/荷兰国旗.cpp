//
// Created by xing on 2022/4/15.
//
#include <vector>
using namespace std;
/*
 * 荷兰国旗问题
 * 输入：nums = [2,0,2,1,1,0]
 * 输出：[0,0,1,1,2,2]
 * */
class Solution {
public:
    /*
     * 单指针
     * 需要两次遍历，第一次把所有的0交换到头部
     * 第二次把所有的1交换到头部
     * */
    void sortColors1(vector<int>& nums) {
        int n = nums.size();
        int ptr = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i]==0) {
                swap(nums[i],nums[ptr]);
                ptr++;
            }
        }
        for (int i = ptr; i < n; ++i) {
            if (nums[i] == 1){
                swap(nums[i],nums[ptr]);
                ptr++;
            }
        }
    }

    /*
     * 双指针
     * 用p0交换0，p1交换1，只需要一次遍历
     * 如果找到了1，与nums[p1]交换，p1++
     * 如果找到了0，与nums[p0]交换，
     * 如果p0<p1，证明此时1被换到了nums[i],还需要把nums[i]和nums[p1]交换,最后p0++,p1++
     * */
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0=0,p1=0;
        for (int i = 0; i < n; ++i) {
            if (nums[i]==1) {
                swap(nums[i],nums[p1]);
                p1++;
            } else if (nums[i]==0) {
                swap(nums[i],nums[p0]);
                if (p0<p1) {
                    swap(nums[i],nums[p1]);
                }
                p0++;
                p1++;
            }
        }
    }
};