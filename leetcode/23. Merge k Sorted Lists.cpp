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
        // given array of k linked-lists
        // all linked lists are sorted in ascending order
        // merge all the linked-lsits into one sorted linked-list
        // [[ 1, 4, 5], [1, 3, 4], [2, 6]]
        // [1, 1, 2, 3, 4, 4, 5, 6]

        // [[1, 4, 5], [1, 3, 4]]
        // iterate through both linked list simultanously
        // we create a new node
        // on each iteration
        // we check which node is smaller of the current node
        // we will add this our root->next node
        // and then move the small node to next one

        // we'll need to iterate and merge through all the remaining lists
        // we can use divide and conquer
        if(lists.size() == 0) return nullptr;
        return divide(lists, 0, lists.size()-1);
    }

    ListNode* conquer(ListNode* start, ListNode* end){
        ListNode *ans = new ListNode(0);
        ListNode *root = ans;
        while(start && end) {
            if(start->val < end->val) {
                root->next = start;
                start = start->next;
            } else {
                root->next = end;
                end = end->next;
            }
            root = root->next;
        }
        while(start) { 
            root->next = start;
            start = start->next;
            root = root->next;
        }
        while(end) { 
            root->next = end;
            end = end->next;
            root = root->next;
        }
        return ans->next;    
    }

    ListNode* divide(vector<ListNode*>& list, int start, int end){
        int sz = (end - start)+1;
        if(sz == 1) return list[start];
        if(sz == 2) return conquer(list[start], list[end]); 
        int half = sz/2;
        ListNode* left = divide(list, start, start + half-1);
        ListNode* right = divide(list, start + half, end);
        return conquer(left, right);
    }
};