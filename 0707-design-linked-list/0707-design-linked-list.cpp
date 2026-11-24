class MyLinkedList {
public:
    struct ListNode{
        int val;
        ListNode *next;
    };
    ListNode* head = NULL;
    MyLinkedList() {}
    
    int get(int index) {
        if(head == NULL) return -1;
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL){
            if(count == index) return temp->val;
            temp = temp->next;
            count++;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        ListNode* newnode = new ListNode();
        newnode->val = val;
        newnode->next = head;
        head = newnode;
    }
    
    void addAtTail(int val) {
        ListNode* newnode = new ListNode();
        newnode->val = val;
        newnode->next = NULL;
        if(head == NULL) {
            head = newnode;
            return;
        }
        ListNode *temp = head;
        while(temp->next != NULL) temp = temp->next;
        temp->next = newnode;
    }
    
    void addAtIndex(int index, int val) {
        if(index == 0){
            addAtHead(val);
            return;
        }
        int count = 0;
        ListNode* temp = head;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        if(index > count) return;
        ListNode* newnode = new ListNode();
        newnode->val = val;
        newnode->next = NULL;
        ListNode* curr = head;
        for(int i = 0; i < index-1; i++){
            curr = curr->next;
        }

        newnode->next = curr->next;
        curr->next = newnode;
    }
    
    void deleteAtIndex(int index) {
        if(head == NULL) return;
        if(index == 0){
            if(head->next == NULL){
                head = NULL;
            }
            else{
                ListNode* temp = head;
                head = head->next;
                temp->next = NULL;
            }
            return;
        }
        int count = -1;
        ListNode* temp1 = head;
        while(temp1 != NULL){
            count++;
            temp1 = temp1->next;
        }
        if(index > count) return;
        int count1 = 0;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(count1 < index){
            count1++;
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next = NULL;
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