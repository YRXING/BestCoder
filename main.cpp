
#include <cstdio>
using namespace std;

unsigned int a[100][100]={};
unsigned int visit[100][100]={};
int minstp=-1; //表示没有路径
int w,h;
void dfs(int x,int y,int step){
    //如果越界并且被访问过，直接返回
    if(x==w||y==h||x==-1||y==-1||visit[x][y]== true) return;
    //标记
    visit[x][y] = true;
    int value = a[x][y];
    if(x==0||y==0){
        if(minstp==-1) minstp=step;
        else minstp = step<minstp?step:minstp; //到达公路进行优化
    }else{
        if(a[x+1][y]<=value) dfs(x+1,y,++step);
        if(a[x-1][y]<=value) dfs(x-1,y,++step);
        if(a[x][y-1]<=value) dfs(x,y-1,++step);
        if(a[x][y+1]<=value) dfs(x,y+1,++step);
    }
}
int main(){
    scanf("%d%d",&w,&h);
    int x,y;
    scanf("%d%d",&x,&y);
    for(int i=0;i<w;i++)
        for(int j=0;j<h;j++)
            scanf("%d",&a[i][j]);
    dfs(2,2,0);
    if(minstp==-1) printf("-1 -1 -1");
    else printf("\nminstp:%d",minstp);
    return 0;
}