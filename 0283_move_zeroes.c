// 283. Move Zeroes
// Logic: Two Pointers approach (in-place modification).
// 1. Use a 'for' loop to scan the array. If a number is non-zero, move it to the 'insertpos' 
//    and increment 'insertpos'. This packs all non-zero numbers to the front.
// 2. Use a 'while' loop starting from 'insertpos' to the end of the array, filling 
//    the remaining spaces with 0s. 
// Time Complexity: O(N) | Space Complexity: O(1)

void moveZeroes(int* nums, int numsSize) {
    int insertpos = 0;
    for (int i = 0; i < numsSize;i++){
        if(nums[i] != 0){
            nums[insertpos] = nums[i];
            insertpos++;
        }
    }
    while (insertpos < numsSize) {
        nums[insertpos] = 0;
        insertpos++;
    }
}