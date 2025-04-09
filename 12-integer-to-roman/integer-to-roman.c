char* intToRoman(int num) {
    // 對應的羅馬符號與值
    int values[] =    {1000, 900, 500, 400, 100,  90,  50, 40, 10, 9, 5, 4, 1};
    char* symbols[] = {"M",  "CM","D", "CD","C", "XC","L","XL","X","IX","V","IV","I"};

    // 最多需要 20 字元，保證夠用
    char* result = (char*)malloc(20);
    result[0] = '\0'; // 清空字串

    for (int i = 0; i < 13 && num > 0; i++) {
        while (num >= values[i]) {
            strcat(result, symbols[i]);  // 加入羅馬字元
            num -= values[i];            // 減去數值
        }
    }

    return result;
}