//
// Created by xing on 2021/3/3.
//

//判断一个表达式是否等于给定值（没有括号运算符）
#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>
#include <cctype>
#include <string>
using namespace std;

/*
 * 中缀表达式转化为后缀表达式
 */
string infixToPostfix(string &infixExp){
    string Postfix;
    stack<char> tmp; //运算符栈
    for(int i= 0; i<infixExp.size();i++){
        char c = infixExp[i];
        //如果是数字，直接加入后缀表达式
        if(isdigit(c)) Postfix+=c;
            //如果是运算符，判断优先级
        else{
            //优先级高的，直接入栈，因为没有比乘除还高的运算符，可以直接入栈
            if(tmp.empty()||c=='x'||c=='/') tmp.push(c);
                //如果是加减的话需要和栈顶相比较
            else{
                //如果是乘除，说明优先级低，出栈后加入到后缀表达式
                while(tmp.top()=='x'||tmp.top()=='/'){
                    Postfix+=tmp.top();
                    tmp.pop();
                }
                //如果不是，入栈
                tmp.push(c);
            }
        }
    }
    //待处理序列为空，结算运算符栈
    while(!tmp.empty()){
        Postfix+=tmp.top();
        tmp.pop();
    }
    return Postfix;
}

int value(int a,int b,char op){
    switch (op) {
        case '+': return a+b;
        case '-': return a-b;
        case 'x': return a*b;
        case '/': return a/b;
    }
    return 0;
}
/*
 * 后缀表达式求值
 */
int judge(string infixExp,int dest){
    string postfixExp = infixToPostfix(infixExp);
    stack<int> v;
    for(int i=0;i<postfixExp.size();i++){
        //如果是数字直接进栈
        if(isdigit(postfixExp[i])) v.push(postfixExp[i]-'0');
        else{
            int a = v.top();
            v.pop();
            int b = v.top();
            v.pop();
            v.push(value(a,b,postfixExp[i]));
        }
    }
    if(v.top()==dest) return 1;
    else return 0;
}

/*
int main(){
    string infix = "5+4x5x5";
    cout<< infixToPostfix(infix)<<endl;
    printf("%d",judge(infix,24));
}*/
