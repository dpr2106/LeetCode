int majorityElement(int* nums, int numsSize) {
    int king = nums[0];
    int health = 1;
    for (int i = 1 ; i < numsSize ; i++){
        if (health == 0){
            king = nums[i];
            health = 1;
        }
        else if (nums[i] == king){
            health++;
        }
        else{
            health--;
        }
    }
    return king;
}