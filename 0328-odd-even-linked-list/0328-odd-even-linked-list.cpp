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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* dummyEven = new ListNode(-1);
        ListNode* dummyOdd = new ListNode(-1);
        ListNode* tempEven = dummyEven;
        ListNode* tempOdd = dummyOdd;
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL){
            if(count%2 == 0){
                tempEven->next = temp;
                tempEven = tempEven->next;
            }
            else{
                tempOdd->next = temp;
                tempOdd = tempOdd->next;
            }
            temp = temp->next;
            count++;
        }
        tempEven->next = dummyOdd->next;
        tempOdd->next = NULL;
        return dummyEven->next;
    }
};