

int countMatches(char *** items, int itemsSize, int* itemsColSize, char * ruleKey, char * ruleValue){
    int res = 0, key = 0;
    if(strcmp("type", ruleKey) == 0) key = 0;
    else if(strcmp("color", ruleKey) == 0) key = 1;
    else if(strcmp("name", ruleKey) == 0) key = 2;
    for(int i=0; i<itemsSize; i++){
        if(strcmp(ruleValue, *(items[i]+key)) == 0) res++;
    }
    return res;
}