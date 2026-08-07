int mostFrequentEven(int* nums, int numsSize) {
    int checklist[100001] = {0};
    for (int i = 0 ; i < numsSize ; i++){
        if(nums[i] % 2 == 0){
            checklist[nums[i]]++;
        }
    }
    int highest_score = 0;
    int winning_number = -1;
    for(int i = 0 ; i <= 100000 ; i+=2){
        if (checklist[i] > highest_score){
            highest_score = checklist[i];
            winning_number = i;
        }
    }
    return winning_number;
}