### 440.K-th-Smallest-in-Lexicographical-Order

本题初看和```386.Lexicographical-Numbers```非常相似，但解法大不相同．在386题中，因为需要将按照字典序从小到大所有的元素打印出来，所以可以用构造法把这些数都找出来．但本题中，如果Ｋ很大，要将从１到Ｋ个的字典序元素都生成是很费时的．

此题可以用递归的思路来拆解每个digit，逐步将k化小。我们先考察所有以1开头的数字`1xx..xx`，它们必然在字典序里是最靠前的一拨。如果它们的个数count1小于k，那么就意味着答案的首数字必然不会是1，我们就可以`k-=count1`。我们再考察所有以2开头的数字`2xx..xx`，同理此时它们必然在字典序里是最靠前的一拨。如果它们的个数count1大于k，说明我们的答案的首数字必然就是2！

接下来我们同理，处理第二位数字。我们先考察所有以20开头的数字`20xx..xx`，如果它们的个数count20小于k，那么就意味着答案的首两位数字必然不会是20，我们就可以`k-=count20`。我们再考察所有以21开头的数字`21xx..xx`，同理此时它们必然在字典序里是最靠前的一拨。如果它们的个数count21小于k，说明答案的首两位数字必然不会是21，我们继续`k-=count21`。直至我们发现`22xx..xx`的个数count22大于k，说明最终答案的首二位数字就是22.

所以我们可以重复调用主函数`FindKthNumberBeginWith(prefix, k)`，表示求以prefix为前缀的第k个字典序排列的元素。如果k为0，就输出prefix本身。

代码的流程大致如下：
```cpp
int FindKthNumberBeginWith(prefix,k)
{
    if (k==0) return prefix;
    
    for i=0 to 9
    {
        count = TotalNumbersBeginWith(prefix+[i], n);
        if (count<k)
            k -= count;
        else 
            return FindKthNumberBeginWith(prefix+[i],k-1)
    }
}
```

此外我们需要辅助函数`TotalNumbersBeginWith(prefix, n)`，计算所有以prefix为前缀的、不大于n的元素的数量。对此，我们只需要枚举前缀后面还需要加几位即可。加一位，就有`0~9`这些可能；加两位，就有`00~99`这些可能；直至位数加长到m，发现`prefix+999...999`超过了n，那么就不再尝试加长了。


[Leetcode Link](https://leetcode.com/problems/k-th-smallest-in-lexicographical-order)
