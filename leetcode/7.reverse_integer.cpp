// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
// Example 1:

// Input: x = 123
// Output: 321
// Example 2:

// Input: x = -123
// Output: -321
// Example 3:

// Input: x = 120
// Output: 21
 

// Constraints:

// -231 <= x <= 231 - 1


class Solution {
public:
    int reverse(int x) {
        int reverse_int = 0;
        bool is_neg = false;
        if(x < 0) is_neg = true;
        x = abs(x);
        
        int count = 0;
        for(int y = x; y; y/=10) count++;
        
        if(count >= 10 && (x % 10) > 2) return 0;
        
        while(x){
            int temp = (x % 10) * pow(10, --count);
            if(INT_MAX - temp < reverse_int) return 0;     
            x /= 10;
            reverse_int += temp;
        }
        return reverse_int * (is_neg ? -1 : 1);
    }
};


