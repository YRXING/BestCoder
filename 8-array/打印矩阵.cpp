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
    int topRow = 0,topCol = 0;//左上角坐标
    int downRow = row-1,downCol = col-1;//右下角坐标

    //左上角坐标和右下角坐标能夹出一个子矩阵，把外层打印出来
    while(topRow <= downRow && topCol <= downCol){
        printEdge(mtx, topRow++, topCol++, downRow--, downCol--);
    }
}



