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
    void reorderList(ListNode* head) {
        ListNode* h=head;
        int n=0;
        while(h!=NULL){
            n++;
            h=h->next;
        }
        h=head;
        int i=0;
        ListNode* prev1=NULL;
        while(i<(n+1)/2){
            prev1=h;
            h=h->next;
            i++;
        }
        prev1->next=NULL;
        ListNode* prev=NULL;
        while(h!=NULL){
            ListNode* ah=h->next;
            h->next=prev;
            prev=h;
            h=ah;
        }
        ListNode* h1=head;
        ListNode* h2=prev;
        while(h1!=NULL && h2!=NULL){
            ListNode* ah1=h1->next;
            ListNode* ah2=h2->next;
            h1->next=h2;
            h2->next=ah1;
            h1=ah1;
            h2=ah2;
        }
    }
};
