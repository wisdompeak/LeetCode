### 029.Divide-Two-Integers

本题的基本思想就是将divisor不断用左移的方法乘以2来逼近dividend，然后将dividend减去倍乘之后的divisor，再重复这个过程直至被除数小于除数。记录这个过程中divisor“倍乘”的总次数，即为答案。

核心代码就那么几行 (a为被除数，b为除数）：
```cpp
        int res=0;
        while (a>=b)
        {
            c = b;
            count=1;
            while ((c<<1)<=a)
            {
                c=c<<1;
                count=count<<1;
            }
            res+=count;
            a = a-c;
        }
```        

其他需要注意的细节：
1. 注意可能的负号。提前将被除数和除数取绝对值，符号最后留给商。
2. 对于整形取绝对值，常设的陷阱就是对于INT_MIN，取反之后就会溢出。为了处理起来简单，把变量统统转换为long long类型。
3. Overflow的意思就是结果>INT_MAX


[Leetcode Link](https://leetcode.com/problems/divide-two-integers)