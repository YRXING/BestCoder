//
// Created by xing on 2022/4/22.
//
#include <vector>
using namespace std;
class Solution {
public:
    /*
     * 左右乘积列表
     * res[i] = L[i]*R[i]
     * L[i] = nums[0]*...*nums[i-1]
     * R[i] = nums[i+1]*...*nums[len-1]
     * */
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> L(len,0),R(len,0);
        vector<int> res(len);
        L[0] = 1;
        for (int i = 1; i < len; ++i) {
            L[i] = L[i-1]*nums[i-1];
        }
        R[len-1] = 1;
        for (int i = len-2; i >=0 ; --i) {
            R[i] = R[i+1]*nums[i+1];
        }
        for (int i = 0; i < len; ++i) {
            res[i] = L[i]*R[i];
        }
        return res;
    }

    /*
     * 优化：先把输出数组当作 L 数组来计算，然后再动态构造 R 数组得到结果。
     * */
    vector<int> productExceptSelf2(vector<int>& nums) {
        int length = nums.size();
        vector<int> answer(length);

        // answer[i] 表示索引 i 左侧所有元素的乘积
        // 因为索引为 '0' 的元素左侧没有元素， 所以 answer[0] = 1
        answer[0] = 1;
        for (int i = 1; i < length; i++) {
            answer[i] = nums[i - 1] * answer[i - 1];
        }

        // R 为右侧所有元素的乘积
        // 刚开始右边没有元素，所以 R = 1
        int R = 1;
        for (int i = length - 1; i >= 0; i--) {
            // 对于索引 i，左边的乘积为 answer[i]，右边的乘积为 R
            answer[i] = answer[i] * R;
            // R 需要包含右边所有的乘积，所以计算下一个结果时需要将当前值乘到 R 上
            R *= nums[i];
        }
        return answer;
    }
};