class Solution {
public:
    bool canAliceWin(int n) {
        int x = 10, moves = 0;
        while (n >= x) {
            n -= x;
            x--;
            moves++;
        }
        return moves % 2 == 1;
    }
};