char* stoneGameIII(int* stoneValue, int stoneValueSize) {
    int n = stoneValueSize;
    int* dp = (int*)malloc((n + 1) * sizeof(int));
    dp[n] = 0;
    for (int i = n - 1 ; i >= 0 ; i--){
        dp[i] = INT_MIN;
        int stones_taken_score = 0;
        for (int k = 0 ;k < 3 && (i + k) < n ; k++){
            stones_taken_score += stoneValue[i + k];
            int score_diff = stones_taken_score - dp[i + k + 1];
            if (score_diff > dp[i]){
                dp[i] = score_diff;
            }
        }
    }
    int alice_advantage = dp[0];
    if (alice_advantage > 0){
        return "Alice";
    }
    else if (alice_advantage < 0){
        return "Bob";
    }
    else {
        return "Tie";
    }
}