int decode(char s){
	if(s == 'I') return 1;
	else if (s == 'V') return 5;
	else if (s == 'X') return 10;
	else if (s == 'L') return 50;
	else if (s == 'C') return 100;
	else if (s == 'D') return 500;
	else if (s == 'M') return 1000;
	else return 0;
}

int romanToInt(char* s) {
	int ret = 0, temp = 0;
    for(int i = 0; i < strlen(s); i++){
        if(i == strlen(s) - 1){
            ret += decode(s[i]);
            break;
        }
		if(decode(s[i + 1]) > decode(s[i])){
			temp = decode(s[i + 1]) - decode(s[i]);
			ret += temp;
			i++;
			temp = 0;
			continue;
		}
		ret += decode(s[i]);
	}
	return ret;
}