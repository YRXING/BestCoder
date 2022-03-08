//
// Created by xing on 2022/2/28.
//
#include <vector>
using namespace std;
/*
 * 求数组中的逆序对
 * */
class BIT {
private:
    vector<int> tree;
    int n;
public:
    BIT(int _n):n(_n),tree(n+1){}

    static  int lowbit(int x) {
        return x & (-x);
    }

    int getSum(int pos) {
        int sum=0;
        for (int i = pos; i >0 ; i-=lowbit(i)) {
            sum+=tree[i];
        }
        return sum;
    }

    void update(int pos,int v) {
        for (int i = pos; i <=n ; i+=lowbit(i)) {
            tree[i]+=v;
        }
    }
};

class Solution {
public:
    /*
     * 离散化树状数组用来求一个序列中左边比它小的数的多少
     * */
    int reversePairs(vector<int>& nums) {
        int len = nums.size();
        vector<int> tmp = nums;
        //离散化
        sort(tmp.begin(),tmp.end());
        //这里时间复杂度为nlog(n)
        for (int& num : nums) {
            //二分查找
            num = lower_bound(tmp.begin(),tmp.end(),num)-tmp.begin()+1;
        }
        BIT bit(len);
        int ans=0;
        //从右往左找比它小的数
        for (int i = len-1; i >=0 ; --i) {
            ans+=bit.getSum(nums[i]-1);
            bit.update(nums[i],1);
        }
        return ans;
    }

    /*
     * 归并排序:用来计算两个有序区间中逆序对的数量
     * 比如[1,3,5] [2,4,6] 数量为2+1=3
     * 即[1,3,5,2,4,6]中有三对逆序对,求解的时候只计算右区间，因为子区间已经有序，不存在逆序对
     * 而且是从小到大排列的，所以只需要计算右边的元素在归并的过程中可能与左边元素产生逆序对的个数
     * */
    int mergeSort(vector<int>& nums, vector<int>& tmp, int l,int r){
        //只有一个元素的两个序列中，不存在逆序对
        if (l>=r) {
            return 0;
        }
        int mid = (l+r)/2;
        //先递归合并左右子区间，在合并整个区间
        int inv_count = mergeSort(nums,tmp,l,mid)+mergeSort(nums,tmp,mid+1,r);
        int i=l,j=mid+1,pos=l;
        while (i<=mid&&j<=r) {
            if (nums[i]<=nums[j]){
                tmp[pos] = nums[i++];
                inv_count+=(j-(mid+1));
            } else {
                tmp[pos] = nums[j++];
            }
        }
        for (int k = i; k <= mid; ++k) {
            tmp[pos++] = nums[k];
            inv_count += (j - (mid + 1));
        }
        for (int k = j; k <= r; ++k) {
            tmp[pos++] = nums[k];
        }
        copy(tmp.begin()+l,tmp.begin()+r+1,nums.begin()+l);
        return inv_count;
    }
    int reversePairs2(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp(n);
        return mergeSort(nums,tmp,0,n-1);
    }
};