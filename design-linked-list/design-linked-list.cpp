class MyLinkedList {
public:
    struct Node {
        int data;
        Node *next;
        Node(int a) {
            data = a;
            next = NULL;
        }
    };
    
    Node *root = NULL;
    int size = 0;
	
    /** Initialize your data structure here. */
    MyLinkedList() {
        
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(size <= index) return -1;
        Node *curr = root;
        while(index-- && curr) {
            curr = curr -> next;
        }
        return curr -> data;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *curr = new Node(val);
        curr -> next = root;
        root = curr;
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if(root == NULL) root = new Node(val);
        else {
            Node *curr = root;
            while(curr -> next) curr = curr -> next;
            curr -> next = new Node(val);
        }
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index == size) addAtTail(val);
        else if(index == 0) addAtHead(val);
        else if(index < size) {
            Node *curr = root;
            while(index != 1) {
                curr = curr -> next;
                index--;
            }
            Node *temp = curr -> next;
            curr -> next = new Node(val);
            curr -> next -> next = temp;
            size++;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index < size) {
            if(index == 0) {
				Node *temp = root;
				root = root -> next;
				delete(temp);
			} else {
                Node *curr = root;
                while(index != 1) {
                    curr = curr -> next;
                    index--;
                }
                Node *temp = curr -> next;
                curr -> next = curr -> next -> next;
                delete(temp);
            }
            size--;
        }
    }
};