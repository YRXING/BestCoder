//
// Created by xing on 2022/3/18.
//
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0),next(nullptr){}
    ListNode(int x): val(x),next(nullptr){}
    ListNode(int x, ListNode* next): val(x),next(next){}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b){
        if (!a||!b) return a?a:b;
        ListNode head,*tail=&head;
        while (a&&b){
            if (a->val<b->val) {
                tail->next = a;
                a = a->next;
            } else{
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        tail->next = a?a:b;
        return head.next;
    }
    ListNode* merge(int start,int end,vector<ListNode*>& lists){
        if (start>end) return nullptr;
        if (start == end) return lists[start];
        int mid = (start+end)/2;
        return mergeTwoLists(merge(start,mid,lists),merge(mid+1,end,lists));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        return merge(0,len-1,lists);
    }
};