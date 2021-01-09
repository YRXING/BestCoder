//
// Created by xing on 2021/1/9.
//

//给顶一个整形矩阵，请按照顺时针转圈方式打印它
#include <cstdio>
using namespace std;

//打印自矩阵外围
void printEdge(int** mtx, int topRow, int topCol, int downRow, int downCol){
    int curRow = topRow;
    int curCol = topCol;
    while(curCol!=downCol){
        printf("%d ",mtx[curRow][curCol]);
        curCol++;
    }
    //向下转
    while(curRow!=downRow){
        printf("%d ",mtx[curRow][curCol]);
        curRow++;
    }
    //向左转
    while(curCol!= topCol){
        printf("%d ",mtx[curRow][curCol]);
        curCol--;
    }
    //向上转
    while(curRow!=topRow){
        printf("%d ",mtx[curRow][curCol]);
        curRow--;
    }

    //特殊情况处理
    if(topRow==downRow&&topCol==downCol) printf("%d ",mtx[topRow][topCol]);
}

void spiralOrderPrint(int** mtx,int row, int col){
    //l是
    int topRow = 0,topCol = 0;
    int downRow = row-1,downCol = col-1;
    //左上角坐标和右下角坐标能夹出一个子矩阵，把外层打印出来
    while(topRow <= downRow && topCol <= downCol){
        printEdge(mtx, topRow++, topCol++, downRow--, downCol--);
    }
}


int main()
{
    int** mtx = new int*[4];
    for(int i=0;i<4;i++){
        mtx[i] = new int[4];
    }
    int count=1;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++) {
            mtx[i][j] = count++;
            printf("%d ",mtx[i][j]);
        }

    printf("\n");
    spiralOrderPrint(mtx,3,3);
    return 0;
}
