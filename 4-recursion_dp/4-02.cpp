//
// Created by xing on 2021/1/10.
//
/*
 * 假设有排成一行的N个位置，记为1~N，开始时机器人在M位置，机器人可以往左或者往右走
 * 如果机器人在1位置，那么下一步机器人只能走到2位置，如果机器人在N位置，那么下一步机器人只能走到N-1位置。
 * 规定机器人只能走k步，最终能来到P位置的方法有多少种。
 */
#include <cstdio>

using namespace std;

/*
 * N：位置1~N
 * cur：当前位置
 * rest：剩余步数
 * P：最终位置
 */
int walk(int N, int cur, int rest, int P){
    //没有步数，递归终止，判断当前位置是否在最终位置，累加count
    if(rest == 0) return cur==P?1:0;
    //两种特殊情况处理
    if(cur==1) return walk(N,2,rest-1,P);
    if(cur==N) return walk(N,N-1,rest-1,P);

    //一般情况就向左，向右走，情况数量相加
    return walk(N,cur+1,rest-1,P)+walk(N,cur-1,rest-1,P);
}

//暴力递归
int ways1(int N, int M, int K, int P){
    //判断参数合法性
    if(N<2 || K<1 || M<1 || M>N || P<1 || P>N) return 0;
    return walk(N,M,K,P);
}

//动态规划
/*
 * 状态方程：dp[rest][cur]表示当前位置剩余步数有多少种方法
 * 状态转移方程：dp[rest][cur] = dp[rest-1][cur-1] + dp[rest-1][cur+1]
 * 特殊情况不再累述
 */
int ways2(int N, int M, int K, int P){
    if(N<2 || K<1 || M<1 || M>N || P<1 || P>N) return 0;
    //初始化动态二维数组
    int **dp = new int*[K+1];
    for(int i=0;i<K+1;i++){
        dp[i] = new int[N+1];
    }
    dp[0][P]=1;

    for(int i=1;i<=K;i++){
        for(int j=1;j<=N;j++){
            if(j==1) dp[i][j] = dp[i-1][2];
            else if(j==N) dp[i][j]=dp[i-1][N-1];
            else dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
        }
    }

    return dp[K][M];
}

/*
 * 动态规划+空间压缩(滚动更新)
 * 二维的动态规划每一行的值都依赖于上一行，最终状态在最后一行。所以可以设置一维数组来滚动更新。
 */
int ways3(int N, int M, int K, int P){
    if(N<2 || K<1 || M<1 || M>N || P<1 || P>N) return 0;

    int *dp = new int[N+1];
    dp[P]=1; //初始相当于第一行dp[0][P]

    //滚动更新只要注意未更新的状态不要被覆盖掉
    for(int i=1;i<=K;i++){
        int leftUp = dp[1]; //左上角的值
        for(int j=1;j<=N;j++){
            int tmp = dp[j];
            if(j==1) dp[j] = dp[2];
            else if(j==N) dp[j] = leftUp;
            else dp[j] = leftUp + dp[j+1];
            leftUp = tmp;
        }
    }

    return dp[M];
}

/*int main(){
    printf("%d\n",ways1(3,1,3,3));
    printf("%d\n",ways2(7,4,9,5));
    printf("%d\n",ways3(7,4,9,5));
    return 0;
}*/
