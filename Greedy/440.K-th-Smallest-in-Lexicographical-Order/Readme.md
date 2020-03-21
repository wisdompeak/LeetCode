### 440.K-th-Smallest-in-Lexicographical-Order

本题初看和```386.Lexicographical-Numbers```非常相似，但解法大不相同．在３８６题中，因为需要将按照字典序从小到大所有的元素打印出来，所以可以用构造法把这些数都找出来．但本题中，如果Ｋ很大，要将从１到Ｋ个的字典序元素都生成是很费时的．

此题的解法很巧妙．举个例子，假设n=23456,k=10000，我们期待的结果是Ｒ．我们如何找到Ｒ呢？我们肯定会先尝试Ｒ的第一个数字是否会是１．此时，一个快速的筛选准则是：考察所有小于ｎ的１ｘｘｘｘ（ｘ的个数随意），可以计算总共有几个这样的数，我们假设是Ｍ．我们应该发现，这Ｍ个数其实就是字典序里的前Ｍ个（因为首元素是１，字典序最小）．如果Ｍ<k的话，那么我们就不用考虑所有的1xxxx，只需要从２xxxx开始寻找第k-M个字典序的数．如果M>k的话，我们就确定了首元素必须是１，进而考虑第二个数字，也是从１的可能性考虑起－－我们发现，这就是在递归重复之前的步骤．

代码的流程大致如下：
```cpp
int FindKthNumberBeginWith(prefix,k)
{
    if (k==0) return prefix;
    
    for i=0 to 9
    {
        count = TotalNumbersBeginWith(prefix+[i]);
        if (count<k)
            k -= count;
        else 
            return FindKthNumberBeginWith(prefix+[i],k-1)
    }
}
```


[Leetcode Link](https://leetcode.com/problems/k-th-smallest-in-lexicographical-order)