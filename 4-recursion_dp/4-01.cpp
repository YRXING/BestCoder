//给定数组arr,arr中所有值都为正数且不重复。每个值代表一种面值的货币，每中面值的货币可以使用任意张，
//在给定一个整数aim，代表要找的钱数，求组成aim的最少货币数。

#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;

class Solution {
public:
    //表示[k,len)自由使用面值情况下，找零rest的最少张数
    int dfs(vector<int>& coins, int k, int rest){
        int len = coins.size();
        //递归终止条件：已经没有面值考虑了
        if(k==len) {
            return rest==0?0:-1;
        }
        //最小张数
        int ans = -1;
        //依次尝试使用 i 张coins[k],剩下的交给[k+1,len) rest-i*coins[k]处理
        for (int i = 0; i*coins[k] <= rest; ++i) {
            int next = dfs(coins,k+1,rest-i*coins[k]);
            if (next != -1) {
                //不同的组合中选择最小的结果
                ans = ans==-1? next+i:min(ans,next+i);
            }
        }
        return ans;
    }

    int coinChangeDFS(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        return dfs(coins,0,amount);
    }

    int coinChange(vector<int>& coins, int amount) {
        if (amount==0) return 0;
        int len = coins.size();
        //dp[i][rest]表示[i,len)中兑换rest的最小数目
        vector<vector<int>> dp(len+1,vector<int>(amount+1,-1));
        for (int rest = 1; rest <= amount ; ++rest) {
            dp[len][rest] = -1; //当没有面值却还有零钱时返回-1；
        }
        //dp[i][rest] = min{dp[i+1][rest],dp[i][rest-coins[i]]+1}
        //倒着遍历
        for (int i = len-1; i >=0 ; --i) {
            for (int rest = 0; rest <= amount; ++rest) {
                dp[i][rest] = -1; //初始值为-1
                if (dp[i+1][rest]!=-1) dp[i][rest] = dp[i+1][rest];
                //如果左边位置不越界并且有效
                if (rest-coins[i]>=0&&dp[i][rest-coins[i]]!=-1){
                    if (dp[i][rest]==-1) dp[i][rest]=dp[i][rest-coins[i]]+1;
                    else {
                        // 保证下面和左边的值都有效，才去取最小值
                        dp[i][rest] = min(dp[i][rest],dp[i][rest-coins[i]]+1);
                    }
                }
            }
        }
        return dp[0][amount];
    }
};
