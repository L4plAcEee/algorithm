class Solution {
public:
    // 非字符串解法，核心在于如何在不转换字符串的情况下取到每一个数位的数码。
    // 还有就是取到了数码不要放到数组中比较，这和转字符串没区别。
    bool isPalindrome(int x) {
        // 负数不是回文，个位数一定是回文
        if (x < 0) return false;
        if (x < 10) return true;

        // 1. 确定最高位的权重 a (例如 121 的 a 是 100)
        long long a = 1;
        while (x / a >= 10) a *= 10;

        while (x > 0) {
            int d_a = x / a;    // 提取最高位
            int d_b = x % 10;   // 提取最低位

            if (d_a != d_b) return false;

            // 2. 砍掉最高位：x % a 得到 21
            // 3. 砍掉最低位：(x % a) / 10 得到 2
            x = (x % a) / 10;

            // 4. 因为砍掉了两位，权重 a 也要相应缩小 100 倍
            a /= 100;
        }

        return true;
    }
    bool isPalindrome_inString(int x) {
        string s = to_string(x);
        for (int i = 0, j = s.length() - 1; i < j; ++i, --j){
            if (s[i] != s[j]) return false;
        }
        return true;
    }
};
