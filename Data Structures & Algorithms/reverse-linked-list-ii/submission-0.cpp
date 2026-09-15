/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 ListNode* h=head;
        int i=1;
        ListNode* dummy=new ListNode(-1);
        while(h!=NULL){
            while(h!=NULL && i>=left && i<=right){
                ListNode* ah=h->next;
                h->next=prev;
                prev=h;
                h=ah;
                i++;
            }
            prev=h;
            h=h->next;
            i++;
        }
        ListNode* lprev=prev;
        while(lprev!=NULL){
            lprev=lprev->next;
        }
        lprev->next=h;
        return head;
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int i=1;
        ListNode* h=head;
        ListNode* prev=NULL;
        while(i<left){
            prev=h;
            h=h->next;
            i++;
        }
        ListNode* prevCopy=prev;
        ListNode* headCopy=h;
        while(i<=right && h!=NULL){
            ListNode* ahead=h->next;
            h->next=prev;
            prev=h;
            h=ahead;
            i++;
        }
        headCopy->next=h;
        if(prevCopy!=NULL) prevCopy->next=prev;
        return prevCopy==NULL?prev:head;
    }
};