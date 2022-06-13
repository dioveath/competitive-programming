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
        return addTwoWithCarry(l1, l2, 0);
    }
    
    ListNode* addTwoWithCarry(ListNode* l1, ListNode* l2, int carry){
        if(l1 == nullptr && l2 == nullptr) {
            if(carry)                 
                return new ListNode(carry);
            return nullptr;
        }
        int l1Val = l1 != nullptr ? l1->val : 0;
        int l2Val = l2 != nullptr ? l2->val : 0;
        
        int sum = l1Val + l2Val + carry;
        int newVal = sum % 10;
        int newCarry = sum/10;
        
        return new ListNode(newVal, addTwoWithCarry(l1 != nullptr ? l1->next : nullptr, l2 != nullptr ? l2->next : nullptr, newCarry));
    }
};



