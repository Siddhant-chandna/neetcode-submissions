/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || (head->next==NULL)) return NULL;
        ListNode* h=head;
        int m=0;
        while(h!=NULL){
            h=h->next;
            m++;
        }
        int x=m-n+1;
        if(x==1) return head->next;
        int i=1;
        ListNode* prev=head;
        h=head;
        while(prev->next!=NULL){
            if(i==x){
                prev->next=h->next;
            }
            prev=h;
            h=h->next;
            i++;
        }
        return head;
    }
};
