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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* h=head;
        int n=0;
        while(h!=NULL){
            h=h->next;
            n++;
        }
        int x=n/k;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        h=head;
        ListNode* d=dummy;
        while(h!=NULL && x-->0){
            ListNode* prev=d;
            int y=k;
            ListNode* pTail=h;
            while(h!=NULL && y-->0){
                ListNode* ah=h->next;
                h->next=prev;
                prev=h;
                h=ah;
            }
            pTail->next=h;
            d->next=prev;
            d=pTail;
        }
        return dummy->next;
    }
};
