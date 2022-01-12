#### [7. 整数反转](https://leetcode-cn.com/problems/reverse-integer/)

注意边界条件

```C++
class Solution {
public:
    int reverse(int x) {
        int result=0, digit;
        while(x != 0) 
        {
            if(result < INT_MIN / 10 || result > INT_MAX / 10) 
                return 0;
            digit = x % 10;
            x /= 10;
            result = result * 10 + digit;
        }
        return result;
    }
};
```

#### [9. 回文数](https://leetcode-cn.com/problems/palindrome-number/)

设置列表保存各位数字

```C++
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        vector<int> list;
        while(x != 0)
        {
            list.push_back(x % 10);
            x /= 10;
        }
        int lenth = list.size();
        for(int i=0; i<lenth/2; i++)
        {
            if(list[i] != list[lenth - i - 1])
                return false;
        }
        return true;
    }
};
```

#### [479. 最大回文数乘积(*)](https://leetcode-cn.com/problems/largest-palindrome-product/)

丑陋穷举法

```C++
class Solution {
public:
    int largestPalindrome(int n) {
        switch(n)
        {
            case 1:return 9;
            case 2:return 987;
            case 3:return 123;
            case 4:return 597;
            case 5:return 677;
            case 6:return 1218;
            case 7:return 877;
            case 8:return 475;
            default:return 0;
        }
    }
};
```

#### [564. 寻找最近的回文数(*)](https://leetcode-cn.com/problems/find-the-closest-palindrome/)

```java
public class Solution {
    public String mirroring(String s) {
        String x = s.substring(0, (s.length()) / 2);
        return x + (s.length() % 2 == 1 ? s.charAt(s.length() / 2) : "") + new StringBuilder(x).reverse().toString();
    }
    public String nearestPalindromic(String n) {
        if (n.equals("1"))
            return "0";

        String a = mirroring(n);
        long diff1 = Long.MAX_VALUE;
        diff1 = Math.abs(Long.parseLong(n) - Long.parseLong(a));
        if (diff1 == 0)
            diff1 = Long.MAX_VALUE;

        StringBuilder s = new StringBuilder(n);
        int i = (s.length() - 1) / 2;
        while (i >= 0 && s.charAt(i) == '0') {
            s.replace(i, i + 1, "9");
            i--;
        }
        if (i == 0 && s.charAt(i) == '1') {
            s.delete(0, 1);
            int mid = (s.length() - 1) / 2;
            s.replace(mid, mid + 1, "9");
        } else
            s.replace(i, i + 1, "" + (char)(s.charAt(i) - 1));
        String b = mirroring(s.toString());
        long diff2 = Math.abs(Long.parseLong(n) - Long.parseLong(b));


        s = new StringBuilder(n);
        i = (s.length() - 1) / 2;
        while (i >= 0 && s.charAt(i) == '9') {
            s.replace(i, i + 1, "0");
            i--;
        }
        if (i < 0) {
            s.insert(0, "1");
        } else
            s.replace(i, i + 1, "" + (char)(s.charAt(i) + 1));
        String c = mirroring(s.toString());
        long diff3 = Math.abs(Long.parseLong(n) - Long.parseLong(c));

        if (diff2 <= diff1 && diff2 <= diff3)
            return b;
        if (diff1 <= diff3 && diff1 <= diff2)
            return a;
        else
            return c;
    }
}
```

#### [231. 2 的幂](https://leetcode-cn.com/problems/power-of-two/)

注意到操作`n & (n-1)`是将`n`二进制最低位的1移除。

```C++
class Solution {
    public boolean isPowerOfTwo(int n) {
        return (n > 0) && (n & (n-1)) == 0;
    }
}
```

#### [342. 4的幂](https://leetcode-cn.com/problems/power-of-four/)

同上题类似，首先是2的幂，然后1的位置要在奇数位，可以使用`0xA = 1010b`或者`0x5 = 0101b`来进行校验

```C++
class Solution {
public:
    bool isPowerOfFour(int n) {
        return (n > 0) && (n & (n-1)) == 0 && (n & 0x55555555) != 0;
    }
};
```

#### [326. 3 的幂](https://leetcode-cn.com/problems/power-of-three/)

```C++
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0)
            return false;
        while(n != 1)
        {
            if(n % 3 != 0)
                return false;
            n /= 3;
        }
        return true;
    }
};
```

#### [504. 七进制数](https://leetcode-cn.com/problems/base-7/)

```C++
class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0)
            return "0";
        string result = "";
        bool negflag = (num < 0) ? true : false;
        num = abs(num);
        while(num > 0)
        { 
            result += num % 7 + '0';
            num /= 7;
        }
        if(negflag)
            result += '-';
        reverse(result.begin(), result.end());
        return result;
    }
};
```

#### [263. 丑数](https://leetcode-cn.com/problems/ugly-number/)

当`n<=0`时不是丑数

否则，当n不为1时，判断其除以2、3、5的余数，若为零则除之，不断循环。如果都不是，则n不是丑数

```C++
class Solution {
public:
    bool isUgly(int n) {
        if(n <= 0)
            return false;
        while(n != 1)
        {
            if(n % 5 == 0)
                n /= 5;
            else if(n % 3 == 0)
                n /= 3;
            else if(n % 2 == 0)
                n /= 2;
            else
                return false;
        }
        return true;
    }
};
```

#### [190. 颠倒二进制位](https://leetcode-cn.com/problems/reverse-bits/)

逐位添加即可

```C++
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i=0; i<31; i++)
        {
            if((n & 1) != 0)
                result |= 1;
            n = n >> 1;
            result = result << 1;
        }
        if((n & 1) != 0)
            result |= 1;
        return result;
    }
};
```

#### [191. 位1的个数](https://leetcode-cn.com/problems/number-of-1-bits/)

* 逐位检查
* 使用`n&(n-1)`不断去除一个1，直到原数没有1为止

```C++
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while(n != 0)
        {
            if((n & 1) != 0)
                result++;
            n = n >> 1;
        }
        return result;
    }
};
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while (n) {
            n &= n - 1;
            ret++;
        }
        return ret;
    }
};
```

#### [476. 数字的补数](https://leetcode-cn.com/problems/number-complement/)

假设`num`至少需要`k`位表示，则令$mask=2^{k+1}-1$，即连续`k`个1，再减去`num`即可

```C++
class Solution {
public:
    int findComplement(int num) {
        uint32_t mask = 1;
        while(mask <= num)
            mask = mask << 1;
        return mask - num - 1;
    }   
};
```

#### [461. 汉明距离](https://leetcode-cn.com/problems/hamming-distance/)

先异或，然后同Q191类似计算1的个数，为了节省空间可以使用输入的x，y作为变量使用

```C++
class Solution {
public:
    int hammingDistance(int x, int y) {
        x ^= y;
        y = 0;
        while(x)
        {
            x = x & (x - 1);
            y++;
        }
        return y;
    }
};
```

#### [477. 汉明距离总和](https://leetcode-cn.com/problems/total-hamming-distance/)

对数组中每个数的第`k`位，假设有`n`个0，则有`lenth-n`个1，在这一位上的汉明距离之和为`n*(lenth-n)`

```C++
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int result=0, lenth=nums.size();
        uint32_t mask = 1;
        vector<int> count(32, 0);
        for(int i=0; i<32; i++)
        {
            for(int j=0; j<lenth; j++)
                if(nums[j] & mask)
                    count[i]++;
            mask = mask << 1;
        }
        for(int i=0; i<32; i++)
            result += count[i] * (lenth - count[i]);
        return result;
    }
};
```

#### [693. 交替位二进制数](https://leetcode-cn.com/problems/binary-number-with-alternating-bits/)

```C++
class Solution {
public:
    bool hasAlternatingBits(int n) {
        uint32_t temp = n ^ (n >> 1);
        return (temp & (temp + 1)) == 0;
    }
};
```

