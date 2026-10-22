int maxProduct(int n) {
    char s[15];
    sprintf(s,"%d",n);
    int biggest = 0;
    int second_biggest = 0;

    for (int i = 0 ; s[i] != '\0' ; i++){
        int current_digit = s[i] - '0';

        if(current_digit > biggest){
            second_biggest = biggest;
            biggest = current_digit;
        }
        else if (current_digit > second_biggest){
            second_biggest = current_digit;
        }
    }
    return biggest * second_biggest
    ;
}