//
// Created by xing on 2021/4/1.
//

//幸运袋子，判断袋子中有多少子集号码sum>pro
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n, a[1003];

//dfs设计成void dfs(int &cur,long long sum,long long pro,int &count)时候统计数量不对
//可能传参原因？dfs(++cur,sum,pro,count)，换种传参没问题
void dfs(int cur,long long sum,long long pro,int &count){
    if(cur>=n) return;
    //选中
    sum +=a[cur];
    pro *=a[cur];
    if(sum>pro)
        //这个数满足
        dfs(cur+1,sum,pro,++count);
    else if(a[cur]==1)//如果等于1，还有机会，但是递归时候count不能再加1了
        dfs(cur+1,sum,pro,count);
    else return; //不满足，剪枝

    //复原后递归
    sum -= a[cur];
    pro /= a[cur];
    //相同的数处理流程是一样的，结果也是一样的，所以可以通过去重来提高效率
    for(;a[cur] == a[cur+1]&&cur<n-1;cur++);
    dfs(cur+1,sum,pro,count);
}
