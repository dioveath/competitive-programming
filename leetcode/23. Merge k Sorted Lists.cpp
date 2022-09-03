// 23. Merge k Sorted Lists
// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
// Merge all the linked-lists into one sorted linked-list and return it.

// Example 1:

// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6
// Example 2:

// Input: lists = []
// Output: []
// Example 3:

// Input: lists = [[]]
// Output: []
 

// Constraints:

// k == lists.length
// 0 <= k <= 104
// 0 <= lists[i].length <= 500
// -104 <= lists[i][j] <= 104
// lists[i] is sorted in ascending order.
// The sum of lists[i].length will not exceed 104.


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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = nullptr;
        ListNode* curr = nullptr;
        while(lists.size()){
            int idx = 0;
            if(!lists[idx]) {
                lists.erase(lists.begin() + idx);
                continue;
            }

            for(int i = 1; i < lists.size(); i++){
                if(lists[i] && lists[idx]->val > lists[i]->val) {
                    idx = i;
                }
            }
                        
            if(!curr) curr = lists[idx];
            else { 
                curr->next = lists[idx];
                curr = curr->next;
            }
            if(!res) res = curr;

            if(lists[idx]) lists[idx] = lists[idx]->next;
            if(lists[idx] == nullptr) lists.erase(lists.begin() + idx);
        }
        
        return res;
    }
};
