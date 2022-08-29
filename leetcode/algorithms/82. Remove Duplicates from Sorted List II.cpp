// 82. Remove Duplicates from Sorted List II
// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

// Example 1:

// Input: head = [1,2,3,3,4,4,5]
// Output: [1,2,5]
// Example 2:


// Input: head = [1,1,1,2,3]
// Output: [2,3]
 

// Constraints:

// The number of nodes in the list is in the range [0, 300].
// -100 <= Node.val <= 100
// The list is guaranteed to be sorted in ascending order.

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode* ans = nullptr, *prev = nullptr;
        while(head){
            ListNode* dup_node = nullptr;
            if(head && head->next && 
               head->val == head->next->val)
                dup_node = head;
            
            while(dup_node && head && 
                  head->val == dup_node->val) head = head->next;
            
            if(dup_node) {
                if(prev) prev->next = head;
            } else if(head) { 
                if(!ans) ans = head;
                prev = head;
                head = head->next; 
            }

        }
        return ans;
    }
};
