//
// Created by xing on 2021/1/19.
//

/*
 * 换钱的方法数：给定数组，里面存面值，每种可以使用任意张，再给一个整数aim
 * 代表要找的钱数，求换钱有多少种方法
 */
#include <cstdio>

/*
 * 暴力递归
 */
int process1(int *arr,int n,int index,int rest){
    if(index == n) return rest==0?1:0;
    if(rest<=0) return rest==0?1:0; //剪枝，可省略此步
    //方法数量
    int count=0;
    //当前面值
    int coin = arr[index];
    //一张张尝试
    for(int i=0;coin*i<=rest;i++){
        count+=process1(arr,n,index+1,rest-coin*i);
    }
    return count;
}
int coins1(int *arr, int aim,int n){
    if(arr==NULL || aim<0) return 0;
    return process1(arr,n,0,aim);
}

/*
 * 记忆化搜索：把每一个递归过程记录下来，避免重复计算
 * map[i][j]表示process(i,aim)的结果 0表示未计算过，-1表示计算过但值为0
 */
int process2(int *arr,int n,int index,int rest,int **map){
    int count=0;
    if(index==n) count = rest==0?1:0;
    else {
        int coin = arr[index];
        int mapValue = 0;
        for (int i = 0; coin * i <= rest; i++) {
            mapValue = map[i + 1][rest - coin * i];
            if (mapValue != 0)
                count += mapValue == -1 ? 0 : mapValue;
            else count += process2(arr, n, index + 1, rest - coin * i, map);

        }
    }
    map[index][rest] = count==0?-1:count;
    return count;
}

int coins2(int *arr,int n,int aim){
    if(arr==NULL || aim<0) return 0;
    int **map = new int*[n+1];
    for(int i=0;i<n+1;i++){
        map[i] = new int[aim+1];
    }
    return process2(arr,n,0,aim,map);
}

/*
 * 动态规划
 */
