int cmp(const void *a, const void *b){
    return (*(char*)a - *(char*)b);
}

char * sortVowels(char * s){
    int len = strlen(s);
    char *vowels = (char*)malloc(sizeof(char) * len);
    int *vowelIndices = (int*)malloc(sizeof(int) * len);
    int idx = 0;
    for(int i = 0; i < len; i++){
        if(strchr("aeiouAEIOU", s[i]) != NULL){
            vowels[idx] = s[i];
            vowelIndices[idx] = i;
            idx++;
        }
    }
    qsort(vowels, idx, sizeof(char), cmp);
    for(int i = 0; i < idx; i++){
        s[vowelIndices[i]] = vowels[i];
    }
    return s;
}