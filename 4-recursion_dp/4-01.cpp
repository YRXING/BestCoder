//给定数组arr,arr中所有值都为正数且不重复。每个值代表一种面值的货币，每中面值的货币可以使用任意张，
//在给定一个整数aim，代表要找的钱数，求组成aim的最少货币数。

#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;

//arr[i..len-1]中找rest
int process(int arr[],int len,int i,int rest){
    if(i==len) return rest==0?0:-1; //剩余待找的钱数不是零，证明找不开，返回-1
    int res = -1;//没有找到有效解，初始为-1

    //不断尝试k张面值arr[i]，不断优化res的最小张数
    for(int k=0;k*arr[i]<=rest;k++){
        //使用k张arr[i],剩下的钱为rest-k*arr[i],交给剩下面值arr[i+1...len-1]
        int next = process(arr,len,i+1,rest-k*arr[i]);
        if(next != -1) res=res==-1 ? next+k : min(res,next+k); //不断优化res值
    }
    return res;
}

int minCoins(int arr[],int len,int aim){
    if(len==0||aim<0) return -1;
    return process(arr,len,0,aim);

}

int main() {
    int arr[3]={5,3,2};
    printf("%d",minCoins(arr,2,2));
    return 0;
}
