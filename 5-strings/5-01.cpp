//
// Created by xing on 2021/1/13.
//
#include <cstdio>
#include <algorithm>
using namespace std;
/*
 * 给定一个字符类型数组，请在单词间做逆序调整。
 * i'm a student.--->student. a i'm
 * 思路：整体逆序,每个单词再逆序
 */
void rotateWord(char str[]){
    int len  = strlen(str);
    if(str == NULL || len == 0) return;
    reverse(str,str+len);//整体逆序
    int l = -1;
    int r = -1; //单词的左右下标
    //遇到空格或结尾 被视为一个逻辑单词
    for(int i=0;i<len;i++){
        if(str[i] != ' '){
            l = i==0 || str[i-1] ==' '?i:l; //单词开头要么为0；要么前面为空格,其他情况不变
            r = i==len-1 || str[i+1] == ' ' ?i:r; //单词结尾要么为整个字符串结尾;要么后面为空格
        }
        if( l!=-1 && r!=-1){
            reverse(str+l,str+r+1);//reverse反转区间为[start,stop)
            l=r=-1;
        }
    }
}
/*
 * 补充问题：给定一个字符串和一个整数size，把字符串左移size长度。
 * 比如"ABCDE" size=3 ---> "DEABC"
 */

/*
 * 整体逆序+局部逆序
 */
void rotate(char str[],int size){
    int len = strlen(str);
    if(str == NULL || size<=0 || size>=len) return;
    //先整体后局部 先局部后整体都可以,但要注意局部分割是不一样的
    reverse(str,str+size);
    reverse(str+size,str+len);
    reverse(str,str+len);
}

/*int main(){
    char str[50];
    gets(str);
    //rotateWord(str);
    rotate(str,3);
    printf("%s",str);
    return 0;

}*/
