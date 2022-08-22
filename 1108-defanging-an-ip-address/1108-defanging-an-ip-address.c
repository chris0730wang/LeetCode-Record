

char * defangIPaddr(char * address){
    char *res = malloc(24);
    char *out = res;
    while(*address){
        if(*address == '.'){
            *out++ = '[';
            *out++ = '.';
            *out++ = ']';
            address++;
        }else{
            *out++ = *address++;
        }
    }
    *out = '\0';
    return res;
}