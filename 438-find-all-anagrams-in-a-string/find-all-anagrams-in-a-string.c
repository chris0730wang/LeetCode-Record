/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAnagrams(char* s, char* p, int* returnSize) {
	int s_len = strlen(s), p_len = strlen(p);
	int* ret = (int*)malloc(sizeof(int) * s_len);
	*returnSize = 0;
	int* p_table = (int*)calloc(26, sizeof(int));
	for(int i = 0; i < p_len; i++) p_table[p[i] - 'a']++;
	for(int i = 0; i <= s_len - p_len; i++){
		int* tmp_table = (int*)calloc(26, sizeof(int));
		for(int j = 0; j < p_len; j++){
			tmp_table[s[i + j] - 'a']++;
		}
		if(memcmp(tmp_table, p_table, sizeof(int) * 26) == 0) ret[(*returnSize)++] = i;
	}
	return ret;
}