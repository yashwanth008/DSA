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
    // ListNode* reverse(ListNode* head){
    //     ListNode* curr = head;
    //     ListNode* nxt = nullptr,*prev = nullptr;
    //     while(curr != NULL){
    //         nxt = curr->next;
    //         curr->next = prev;
    //         prev = curr;
    //         curr = nxt;
    //     }
    //     return prev;
    // }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // sol 1 second best sol 
    //     ListNode* newl1 = reverse(l1);
    //     ListNode* newl2 = reverse(l2);
    //     int carry = 0;
    //     ListNode* dummy = new ListNode();
    //     ListNode* temp = dummy;
    //     while(newl1 != NULL || newl2 != NULL || carry){
    //         int sum = 0;
    //         if(newl1 != NULL){
    //             sum+=newl1->val;
    //             newl1 = newl1->next;
    //         }
    //         if(newl2 != NULL){
    //             sum+=newl2->val;
    //             newl2 = newl2->next;
    //         }
    //         sum+=carry;
    //         carry = sum/10;
    //         ListNode* res = new ListNode(sum%10);
    //         temp->next = res;
    //         temp = temp->next;
    //     }
    //     ListNode* testing = reverse(dummy->next);
    //     return testing;
    // }

    //sol 2 least one
    // stack<int> s1;
    // stack<int> s2;
    // ListNode* temp1 = l1;
    // ListNode* temp2 = l2;

    // while(temp1 != NULL){
    //     s1.push(temp1->val);
    //     temp1 = temp1->next;
    // }
   

    // while(temp2 != NULL){
    //     s2.push(temp2->val);
    //     temp2 = temp2->next;
    // }
   

    // int carry = 0;
    // ListNode* dummy = new ListNode();
    // ListNode* temp = dummy;
    // stack<int>res;
    // while(!s1.empty() || !s2.empty() || carry){
    //     int sum = 0;
    //     if(!s1.empty()){
    //         sum+=s1.top();
    //         cout<<s1.top()<<" ";
    //         s1.pop();
    //     }
    //     if(!s2.empty()){
    //         sum+=s2.top();
    //         s2.pop();
    //     }

    //     sum+=carry;
    //     carry = sum/10;
    //     res.push(sum%10);
    // }
    // while(!res.empty()){
        
    //     ListNode* rest = new ListNode(res.top());
    //     temp->next = rest;
    //     temp = temp->next;
    //     res.pop();
    // }
    // return dummy->next;
    // }

    // sol3 using 2 stacks beats a lot of %
    stack<int> s1,s2;

    while(l1){
        s1.push(l1->val);
        l1 = l1->next;
    }
   
    while(l2){
        s2.push(l2->val);
        l2 = l2->next;
    }
   
    int carry = 0;
    ListNode* head = nullptr;
    while(!s1.empty() || !s2.empty() || carry){
        int sum = carry;
        if(!s1.empty()){
            sum+=s1.top();
            cout<<s1.top()<<" ";
            s1.pop();
        }
        if(!s2.empty()){
            sum+=s2.top();
            s2.pop();
        }
        carry = sum/10;
        ListNode* rest = new ListNode(sum%10);
        rest->next = head;
        head = rest;
    }
    return head;
    }

};