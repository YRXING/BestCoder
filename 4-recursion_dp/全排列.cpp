//
// Created by xing on 2022/2/11.
//
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include <iostream>
#include <cmath>
using namespace std;
/*
 * 深度优先搜索和回溯算法都是递归搜索树，本质是一样的，是一种暴力搜索所有可能解的方法
 *
 * 区别就是回溯算法会维护一些状态变量，当递归搜索树退回的时候需要将这些状态变量重置，
 * 而深度优先搜索没有重置状态变量的操作。
 *
 * 剪枝只是一种提高算法效率的操作：提前结束递归过程，并不是什么具体的算法
 *
 * 动态规划只需要我们评估最优解是什么，有递归和递推两种写法，递归写法也就是记忆话搜索
 *
 * */

/*
 * 全排列（包含重复的序列）
输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]
 * */
class Solution {
public:
    vector<int> chosed;
    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> result;
        vector<int> temp;
        chosed.resize(len);
        dfs(result,temp,nums,0,len);
        return result;
    }

    void dfs(vector<vector<int>>& result, vector<int>& temp, vector<int>& nums,int depth,int len){
        if(depth == len) {
            //这个方法效率高一点，c++11才有
            result.emplace_back(temp);
            return;
        }
        for (int i = 0; i < len; ++i) {
            if (!chosed[i]) {
                temp.push_back(nums[i]);
                chosed[i] = 1;
                dfs(result,temp,nums,depth+1,len);
                //恢复现场
                chosed[i] = 0;
                temp.pop_back();
            }
        }
    }


    void dfsUniq(vector<vector<int>>& result, vector<int>& temp, vector<int>& nums,int depth,int len){
        if(depth == len) {
            //这个方法效率高一点，c++11才有
            result.emplace_back(temp);
            return;
        }

        int visHash[21]={0};

        for (int i = 0; i < len; ++i) {
            //-10 <= nums[i] <= 10
            if (!chosed[i]) {
                if (!visHash[nums[i]+10]) {
                    temp.push_back(nums[i]);
                    chosed[i] = 1;
                    //表示这个位置已经填过nums[i]了
                    visHash[nums[i]+10]=1;
                    dfsUniq(result,temp,nums,depth+1,len);
                    //恢复现场
                    chosed[i] = 0;
                    temp.pop_back();
                } else{ //如果没有被选择过，但是这个位置已经填过相同的数了,不用递归了
                    continue;
                }
            }
        }
    }

    /*
 * 首先寻找不降序列a[i]，[i+1,n)为下降序列
 * [i+1,n)中从后向前查找第一个大于a[i]的数字a[j]
 * 交换a[i],a[j],利用双指针反转[i+1,n)中的元素即可
 * */
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i>=0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) {
                j--;
            }

            swap(nums[i], nums[j]);
        }
        reverse(nums.begin()+i+1,nums.end());
    }
};
