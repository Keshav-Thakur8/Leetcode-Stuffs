class Node {
public:
    int value;
    Node* next;
    Node(int val) {
        this->value = val;
        next = NULL;
    }
};

class MyLinkedList {
public:
    int size = 0;
    Node* head = new Node(0);
    MyLinkedList() {
        
    }
    
    int get(int index) {
        if(index >= size) {
            return -1;
        }
        Node* temp = head;
        for(int i=0 ; i<index ; i++) {
            temp = temp->next;
        }
        return temp->value;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if(index > size) {
            return;
        }
        Node* curr = head;
        Node* newNode = new Node(val);
        if(index == 0) {
            newNode->next = head;
            head = newNode;
        }
        else {
            for(int i=0 ; i<index-1 ; i++) {
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
        }
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= size || index < 0) {
            return;
        }
        if(index == 0) {
            Node* newNode = head->next;
            delete head;
            head = newNode;
        }
        else {
            Node* curr = head;
            for(int i=0 ; i<index-1 ; i++) {
                curr = curr->next;
            }
            Node* newNode = curr->next->next;
            delete curr->next;
            curr->next = newNode;
        }
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */