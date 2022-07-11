class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        vector<int> nList;
        
        while(x){
            // if(x < 10) return true;
            
            int digit = x % 10;
            int frontDigit = x / 10;
            x /= 10;
            // if(digit != frontDigit) return false;
            nList.push_back(digit);
        }
        
        for(int i = 0; i < nList.size(); i++){
            if((nList.size() / 2) % 2 == 1 && i == (nList.size()/2)) return true;             
            if(nList[i] != nList[nList.size() - 1 - i])
                return false;
        }
        return true;
    }
};
