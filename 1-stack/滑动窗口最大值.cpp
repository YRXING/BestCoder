//
// Created by xing on 2022/3/30.
//
#include <vector>
#include <queue>
using namespace std;
/*
 * 滑动窗口最大值
 * 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
 * 输出：[3,3,5,5,6,7]
 * */
class Solution {
public:
    /*
     * 堆
     * */
    vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
        int n = nums.size();
        // 默认大根堆
        priority_queue<pair<int,int>> q;
        for (int i = 0; i < n; ++i) {
            q.push(make_pair(nums[i],i));
        }
        vector<int> ans = {q.top().first};
        for (int i = k; i < n; ++i) {
            q.emplace(nums[i],i);
            // 如果堆顶元素的索引不在窗口范围内，弹出
            while (q.top().second<= i-k) q.pop();
            ans.push_back(q.top().first);
        }
        return ans;
    }

    /*
     * 单调队列（双端队列）
     * 保持队列的单调递减，新元素如果大于队尾，就可以永久删除队尾了，直到小于队尾
     * 队首保持最大值，同样需要判断队首在不在窗口范围内
     * */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        for (int i = 0; i < k; ++i) {
            while (!q.empty()&&nums[i]>=nums[q.back()]) q.pop_back();
            q.push_back(i);
        }

        vector<int> ans = {nums[q.front()]};
        for (int i = k; i < n; ++i) {
            while (!q.empty()&&nums[i]>=nums[q.back()]) q.pop_back();
            q.push_back(i);
            while (q.front()<=i-k) q.pop_front();
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};
