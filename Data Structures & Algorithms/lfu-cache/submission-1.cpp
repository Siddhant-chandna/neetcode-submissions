class LFUCache {
public:
    struct Node{
    public:
        int key;
        int value;
        int freq;
        Node* prev;
        Node* next;
        Node(int k, int v){
            key=k;
            value=v;
            prev=NULL;
            next=NULL;
            freq=1;
        }
    };
    class List{
    public:
        int size;
        Node* head;
        Node* tail;
        List(){
            size=0;
            head=new Node(-1,-1);
            tail=new Node(-1,-1);
            head->next=tail;
            tail->prev=head;
        };
        void deleteNode(Node* oldNode){
            oldNode->prev->next=oldNode->next;
            oldNode->next->prev=oldNode->prev;
            size--;
        }
        void addNode(Node* newNode){
            newNode->next=head->next;
            head->next->prev=newNode;
            head->next=newNode;
            newNode->prev=head;
            size++;
        }
    };
    int cap;
    int minFreq, currSize;
    map<int, Node*> cache;
    map<int, List*> freqList;
    LFUCache(int capacity) {
        cap=capacity;
        currSize=0;
        minFreq=0;
    }

    void update(Node* curr){
        freqList[curr->freq]->deleteNode(curr);
        if(curr->freq==minFreq && freqList[curr->freq]->size==0){
            minFreq++;
        }
        List* l=new List();
        if(freqList.find(curr->freq+1)!=freqList.end()){
            l=freqList[curr->freq+1];
        }
        curr->freq++;
        l->addNode(curr);
        freqList[curr->freq]=l;
    }
    
    int get(int key) {
        if(cache.find(key)==cache.end()) return -1;
        Node* curr=cache[key];
        update(curr);
        return curr->value;
    }
    
    void put(int key, int value) {
        if(cap==0) return;
        if(cache.find(key)!=cache.end()){
            Node* curr=cache[key];
            curr->value=value;
            update(curr);
        }
        else{
            if(currSize>=cap){
                Node* curr=freqList[minFreq]->tail->prev;
                cache.erase(curr->key);
                freqList[minFreq]->deleteNode(curr);
                currSize--;
            }
            Node* newNode=new Node(key, value);
            minFreq=1;
            List* l=new List();
            if(freqList.find(minFreq)!=freqList.end()){
                l=freqList[minFreq];
            }
            l->addNode(newNode);
            freqList[minFreq]=l;
            cache[key]=newNode;
            currSize++;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */