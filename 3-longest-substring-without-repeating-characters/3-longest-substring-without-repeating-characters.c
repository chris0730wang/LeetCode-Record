

int lengthOfLongestSubstring(char * s){
    int *ht = (int*)malloc(sizeof(int)*128);
    for(int i=0; i<128; i++){
        ht[i] = -1;
    }
    int len = strlen(s);
    int substring_start = 0, max = 0;
    for(int i=0; i<len; i++){
        if(ht[s[i]] >= substring_start){
            substring_start = ht[s[i]] + 1;
            ht[s[i]] = i;
        }else{
            ht[s[i]] = i;
            if(i-substring_start+1 > max) max = i-substring_start+1;
        }
    }
    return max;
}