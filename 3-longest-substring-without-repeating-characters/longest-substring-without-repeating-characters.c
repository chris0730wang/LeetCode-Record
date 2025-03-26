int lengthOfLongestSubstring(char* s) {
    int* ht = (int*)malloc(sizeof(int) * 128);
    int start = 0, max = 0;
    for(int i = 0; i < 128; i++) ht[i] = -1;
    for(int i = 0; i < strlen(s); i++){
        if(ht[s[i]] >= start){
            start = ht[s[i]] + 1;
            ht[s[i]] = i;
        }
        else{
            ht[s[i]] = i;
            max = i - start + 1 > max ? i - start + 1 : max;
        }
    }
    return max;
}