### 1601.Maximum-Number-of-Achievable-Transfer-Requests

考虑到requests的总数只有16个，那么任意所有得到满足的请求的组合总数最多也就是2^16种，利用Bit Mask暴力枚举查验都是可行的。查验的方法就是，所有的requests综合效果，是否对于每幢楼而言的净输出和净输入都相等。

本题可以优化的地方就是，我们优先考察含有1-bit多的那些bit mask（令m=requests.size()，则最多m个，其次是m-1，然后递减），如果我们按照这个顺序遇到了第一个查验通过的bit mask，那么对应的1-bit的数目就是答案。

那么如何高效遍历所有含1-bit数目为k的m-bit的bit mask呢？

第一种方法是用C++的next permutation. 比如，我们初始令arr = {0,0,1,1,1}，即将数组的末尾k个元素都设为1. 那么每次运行```next_permuation(arr.begin(), arr.end())```之后就可以得到下一个不同的permutation（即01011, 01101, 01110, 10011, 10101, 10110...），显然所有的permutation包含的1的个数都是相同的。注意，这个函数会自动过滤掉duplicated的排列。

第二种方法是Gosper's Hack。模板如下：
```
int state = (1 << k) - 1;            
while (state < (1 << m))
{
    doSomething(state);

    int c = state & - state;
    int r = state + c;
    state = (((r ^ state) >> 2) / c) | r;
}
```
