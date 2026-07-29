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
        ListNode* prev=nullptr;
        ListNode* curr=head;
        ListNode* next;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(!head)   return true;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prevnode=nullptr;
        while(fast!=nullptr && fast->next!=nullptr){
            prevnode=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* left=head;
        ListNode* right=reverse(slow);
        while(right!=nullptr){
            if(left->val!=right->val)   return false;
            left=left->next;
            right=right->next;
        }
        return true;
    }
};
