/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        unordered_map<Node*, Node*> m;
        Node* curr=head;
        while(curr!=NULL){
            Node* copy=new Node(curr->val);
            m[curr]=copy;
            curr=curr->next;
        } 
        for(auto x:m){
            Node* copy=x.second;
            Node* orig=x.first;
            copy->next=orig->next!=NULL? m[orig->next]:NULL;
            copy->random=orig->random!=NULL? m[orig->random]:NULL;
        }
        return m[head];
    }
};
