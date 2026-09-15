class LRUCache {
    struct Node{
        int key, value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(NULL), next(NULL){}
    };
public:
    unordered_map<int,Node*> m;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    int cap;
    LRUCache(int capacity) {
        head->next=tail;
        tail->prev=head;
        cap=capacity;
    }
    
    void addNode(Node* newNode){
        Node* temp=head->next;
        newNode->next=temp;
        newNode->prev=head;
        head->next=newNode;
        temp->prev=newNode;
    }

    void deleteNode(Node* oldNode){
        Node* prevNode=oldNode->prev;
        Node* nextNode=oldNode->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }

    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        Node* resNode=m[key];
        int res=resNode->value;
        m.erase(key);
        deleteNode(resNode);
        addNode(resNode);
        m[key]=head->next;
        return res;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            Node* existing=m[key];
            m.erase(key);
            deleteNode(existing);
        }
        if(m.size()==cap){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        m[key]=head->next;
    }
};
