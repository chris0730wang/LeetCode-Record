int maxVowels(char* s, int k) {
    int left = 0, right = k - 1;
    int len = strlen(s);
    int sum = 0, res;
    for(int i = 0; i <= right; i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
            sum++;
        }
    }
    res = sum;
    while(right + 1 < len){
        char next = s[right+1], first = s[left];
        if(next == 'a' || next == 'e' || next == 'i' || next == 'o' || next == 'u'){
            sum++;
        }
        if(first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u'){
            sum--;
        }
        right++;
        left++;
        res = sum > res ? sum : res;
    }
    return res;
}