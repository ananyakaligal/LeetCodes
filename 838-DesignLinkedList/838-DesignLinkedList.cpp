// Last updated: 9/16/2025, 12:04:57 AM
class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(int v) : val(v), next(nullptr) {}
    };
    
    Node* head;
    int size;

public:
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node* curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        Node* node = new Node(val);
        node->next = head;
        head = node;
        size++;
    }
    
    void addAtTail(int val) {
        Node* node = new Node(val);
        if (!head) {
            head = node;
        } else {
            Node* curr = head;
            while (curr->next) curr = curr->next;
            curr->next = node;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        Node* curr = head;
        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }
        Node* node = new Node(val);
        node->next = curr->next;
        curr->next = node;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        if (index == 0) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        } else {
            Node* curr = head;
            for (int i = 0; i < index - 1; i++) {
                curr = curr->next;
            }
            Node* tmp = curr->next;
            curr->next = curr->next->next;
            delete tmp;
        }
        size--;
    }
};
