class Solution {
public:
    bool validDigit(int n, int x) {
        bool found = false;
        while(n >= 10){
            int last_digit;
            last_digit = n % 10;
            if(last_digit == x){
                found = true;
            }
            n = n / 10;
        }
        if(n == x){
            return false;
        }
        else{
            return found;
        }
    }
};