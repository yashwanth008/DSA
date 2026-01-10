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
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* nxt = nullptr,*prev = nullptr;
        while(curr != NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newl1 = reverse(l1);
        ListNode* newl2 = reverse(l2);
        int carry = 0;
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        while(newl1 != NULL || newl2 != NULL || carry){
            int sum = 0;
            if(newl1 != NULL){
                sum+=newl1->val;
                newl1 = newl1->next;
            }
            if(newl2 != NULL){
                sum+=newl2->val;
                newl2 = newl2->next;
            }
            sum+=carry;
            carry = sum/10;
            ListNode* res = new ListNode(sum%10);
            temp->next = res;
            temp = temp->next;
        }
        ListNode* testing = reverse(dummy->next);
        return testing;
    }
};