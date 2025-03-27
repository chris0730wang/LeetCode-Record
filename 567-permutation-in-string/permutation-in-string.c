bool checkempty(int* ht){
    // for(int i = 0; i< 26; i++){
    //     printf("%d\n", ht[i]);
    // }
    for(int i = 0; i < 26; i++){
        if(ht[i] > 0) return false;
    }
    return true;
}

bool checkInclusion(char* s1, char* s2) {
    int* ht = (int*)calloc(26, sizeof(int));
    int* ini = (int*)calloc(26, sizeof(int));
    for(int i = 0; i < strlen(s1); i++){
        ht[s1[i] - 'a']++;
        ini[s1[i] - 'a']++;
    }
    for(int i = 0; i < strlen(s2); i++) {
        int l = i;
        if(ht[s2[l] - 'a'] != 0){
            ht[s2[l] - 'a']--;
            int r = l + 1;
            while(r < strlen(s2)){
                if(ht[s2[r] - 'a'] != 0){
                    ht[s2[r] - 'a']--;
                    r++;
                }
                else{
                    break;
                }
            }
            if(checkempty(ht)) return true;
            else {
                memcpy(ht, ini, sizeof(int) * 26);
            }
        }
    }
    return false;
}
    

    
