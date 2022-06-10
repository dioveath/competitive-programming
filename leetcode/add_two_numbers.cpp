/// ou are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order, and each of their nodes contains a single digit.
// Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 
// 2, 4, 3
// 5, 6, 4

// 7, 0, 8


addTwoNumbers(ListNode l1, ListNode l2, carry)

return new ListNode(l1 ->val + l2->val, addTwoNumbers(l1->next, l2->next));

// Example 1:


// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.
// Example 2:

// Input: l1 = [0], l2 = [0]
// Output: [0]
// Example 3:

// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]
 

// Constraints:

// The number of nodes in each linked list is in the range [1, 100].
// 0 <= Node.val <= 9
// It is guaranteed that the list represents a number that does not have leading zeros.


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      return add(l1, l2, 0);
    }
    
    ListNode* add(ListNode* l1, ListNode* l2, int carry){
        if(l1 == nullptr && l2 == nullptr) return nullptr;
        int newValue = 0;
        if(l1 == nullptr)
            newValue = ((l2->val + carry)); 
        else if(l2 == nullptr)
            newValue = ((l1->val + carry)); 
        else 
            newValue = ((l1->val + l2->val + carry));
        
        ListNode* l3 = new ListNode(newValue % 10);
        
        if(l2->next == nullptr && l1->next == nullptr) return l3;
        if(l2->next == nullptr)
            l3->next = add(l1->next,  new ListNode(0 + (l1->val + l2->val) > 9 ? 1 : 0), carry);
        if(l1->next == nullptr)
            l3->next = add(l2->next, new ListNode(0 + (l1->val + l2->val) > 9 ? 1 : 0), carry);
        if(l2->next != nullptr && l1->next != nullptr) 
            l3->next = add(l1->next, l2->next, (newValue) / 10);
        return l3;        
    }
};


