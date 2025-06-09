int getSum(int a, int b) {
    while (b != 0) {
        unsigned carry = (unsigned)(a & b) << 1; // 進位
        a = a ^ b;  // 不考慮進位的加法
        b = carry;  // 把進位加上去
    }
    return a;
}