

char * defangIPaddr(char * address){
    int len = strlen(address);
    char *re = (char*)malloc(24);
    char *out = re;
    while (*address) {
        if (*address == '.') {
            *out++ = '[';
            *out++ = '.';
            *out++ = ']';
            *address++;
        } else {
            *out++ = *address++;
        }
    }
    *out = '\0';
    return re;
}