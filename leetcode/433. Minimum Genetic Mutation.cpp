// 433. Minimum Genetic Mutation
// A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.
// Suppose we need to investigate a mutation from a gene string start to a gene string end where one mutation is defined as one single character changed in the gene string.
// For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
// There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.
// Given the two gene strings start and end and the gene bank bank, return the minimum number of mutations needed to mutate from start to end. If there is no such a mutation, return -1.
// Note that the starting point is assumed to be valid, so it might not be included in the bank.

// Example 1:

// Input: start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
// Output: 1
// Example 2:

// Input: start = "AACCGGTT", end = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
// Output: 2
// Example 3:

// Input: start = "AAAAACCC", end = "AACCCCCC", bank = ["AAAACCCC","AAACCCCC","AACCCCCC"]
// Output: 3
 
// Constraints:

// start.length == 8
// end.length == 8
// 0 <= bank.length <= 10
// bank[i].length == 8
// start, end, and bank[i] consist of only the characters ['A', 'C', 'G', 'T'].


// a gene string,
// 8 - character long
// 'A', 'C', 'G', 'T'
// e.g. AACCGGTT

// one mutation is defined as one single character changed in the gene string

// given
// start gene string &  end gene string
// bank - that records all valid gene mutations

// constraints:
// start.length == 8
// end.length == 8
// 0 <= bank.length <= 10
// bank[i].length == 8

// what we need to find,
// return minimum number of mutations needed to mutate from start to end. 
// return -1 if there is no such a mutation.

// e.g. 1
// start="AAAAACC" end = "AACCCCCC"

// bare solution:
// hash_map[] of bank
// check end is in bank if not return -1

// backtrack(start, end, bank, step):
//     start == end return step
//     if start not in bank return INT_MAX
//     
//     min_step = INT_MAX
//     loop for i to s.length:
//         if s[i] == start[i]: continue;
//         string new_start = start;
//         new_start[i] = s[i]
//         min_step = min(backtrack(start, end, bank, step+1), min_step)
//
//     return min_step

// unordered_map<int, unordered_map<char>>
 
 
class Solution {
public:
    char dna[4] = {'A', 'C', 'G', 'T'};
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> seen({start});
        queue<string> q({start});
        
        int step = 0;
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                string check = q.front();
                q.pop();
                if(check == end) return step;      
                
                for(int k = 0; k < 4; k++){
                    for(int i = 0; i < 8; i++){
                        string new_check = check;
                        new_check[i] = dna[k];
                        if(seen.find(new_check) != seen.end() || 
                           find(bank.begin(), bank.end(), new_check) == bank.end()) continue;
                        q.push(new_check);
                        seen.insert(new_check);
                    }
                }
            }
            step++;            
        }
        
        return -1;
    }
 
};
