//
// Created by xing on 2022/1/4.
//

#include <vector>
using namespace std;
/*
 * 盛水最多的容器
 * 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点(i,ai) 。
 * 在坐标内画 n 条垂直线，垂直线 i的两个端点分别为(i,ai) 和 (i, 0) 。
 * 找出其中的两条线，使得它们与x轴共同构成的容器可以容纳最多的水。
解决方法：双指针
 * */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int area=0;
        while (i<=j){
            int now = (j-i)*min(height[i],height[j]);
            if(now>area) {
                area = now;
            }
            height[i]>height[j]?j--:i++;
        }
        return area;
    }
};