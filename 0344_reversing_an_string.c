void reverseString(char* s, int sSize) {
    for(int i = 0; i < sSize / 2; i++){
        int temp = s[i];
        s[i] = s[sSize - i - 1];
        s[sSize - i - 1] = temp;
    } 
}


//much more similar or we can say same to the reversing of an array of numbers also.