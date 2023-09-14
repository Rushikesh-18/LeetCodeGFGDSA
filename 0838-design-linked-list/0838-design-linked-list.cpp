class Node {
    public: 
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        next = NULL;
    }
};
class MyLinkedList {
public:
    int size = 0;
    Node* head = NULL;
    Node* tail = NULL;
    MyLinkedList() {}
    int get(int index) {
        if(index >= size)
            return -1;
        Node* temp = head;
        for(int i=0; i<index; ++i)
            temp = temp->next;
        
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node* nnode = new Node(val);
        nnode->next = head;
        head = nnode;
        if(size==0)
            tail = nnode;
        size++;
    }
    
    void addAtTail(int val) {
        if(size ==0) {
            addAtHead(val);
            return;
        }
        Node* nnode = new Node(val);
        tail->next = nnode;
        tail = nnode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>size)
            return;
        else if(index == size)
            addAtTail(val);
        else if(index==0)
            addAtHead(val);
        else {
            Node* temp =head;
            Node* nnode = new Node(val);
            for(int i=0; i<index-1; ++i) {
                temp = temp->next;
            }
            nnode->next = temp->next;
            temp->next = nnode;
            size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index>=size)
            return;
        else if(index == size-1) {
           
            if(index==0){
                head==NULL;
                tail==NULL;
            }
            else {
                Node* temp = head;
                while(temp->next!=tail) {
                    temp= temp->next;
                }
                tail = temp;
                temp->next = NULL;
            }
           
        }
        else if(index==0) {
            Node* temp = head;
            head = head->next;
            temp =NULL;
        }
        else {
            Node* temp = head;
            for(int i=0; i<index-1;++i) {
                temp = temp->next;
            }
            Node* t = temp->next;
            temp->next = temp->next->next;
            t->next = NULL;
            
        }
        size--;
    }
};