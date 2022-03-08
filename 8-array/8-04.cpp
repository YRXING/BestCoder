//
// Created by xing on 2022/3/8.
//
#include<vector>
#include<set>
#include <queue>
#include <unordered_map>
using namespace std;
/*
 * 返回前k个高频元素
 * 输入: nums = [1,1,1,2,2,3], k = 2
 * 输出: [1,2]
 * 考察：堆的使用，利用STL priority_queue
 * */
class Solution {
public:
    static bool cmp(pair<int,int>& m,pair<int,int>& n){
        return m.second > n.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> occurrences;
        for (auto& v: nums) {
            occurrences[v]++;
        }
        //pair 第一个元素代表数组的值，第二个元素代表了该值出现的次数
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(&cmp)> q(cmp);
        for (auto& [num,count]:occurrences) {
            if (q.size() == k ){
                if (q.top().second < count) {
                    q.pop();
                    q.emplace(num,count);
                }
            } else {
                //q.push(make_pair(num,count));
                q.emplace(num,count);
            }
        }
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.top().first);
            q.pop();
        }
        return res;
    }
};