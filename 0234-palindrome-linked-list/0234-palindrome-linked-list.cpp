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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        // break the chain
        ListNode* temp = head;
        while(temp->next != slow){
            temp = temp->next;
        }
        temp->next = NULL;
        // reverse the second part;
        ListNode* prev = NULL;
        ListNode* curr = slow;
        while(curr != NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        // check;
        ListNode* first = head;
        while(first != NULL){
            if(first->val != prev->val) return false;
            first = first->next;
            prev = prev->next;
        }
        return true;
    }
};