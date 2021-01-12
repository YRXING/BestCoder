//
// Created by xing on 2021/1/12.
//
/*
 * 环形单链表约瑟夫问题
 * 输入环形单链表头节点和报数值m，返回最后生存下来的节点，且这个节点自己组成环形单向链表，其他节点删掉
 */
#include <cstdio>
#include <cstdlib>
struct node{
    int value;
    node* next;
};

/*
 * 普通解法：O(n*m)
 */
node* josephusKill1(node* head, int m){
    if(head == NULL || head->next == head || m<1) return head;

    //找到头节点前一个节点，方便删除操作
    node* last = head;
    while(last->next!=head) last = last->next;

    int count=0;
    while(head !=last){
        if(++count == m){
            last->next = head->next;
            free(head);
            count = 0;
        } else last = last->next;
        head = last->next;
    }
    return head;
}

/*
 * 进阶：O(n)
 * 公式：老编号=（新编号+m-1）%i+1
 */
//根据新编号和老编号关系求出生存节点
int getLive(int i, int m){
    if(i==1) return 1;
    return (getLive(i-1,m)+m-1)%i+1;
}
node* josephusKill2(node* head, int m){
    if(head == NULL || head->next == head || m<1) return head;

    node* cur = head->next;
    int tmp=1;
    while(cur!=head){
        tmp++;
        cur = cur->next;
    }

    //找到生存节点
    tmp = getLive(tmp,m);
    while(--tmp!=0) head = head->next;
    head->next = head;
    return head;
}