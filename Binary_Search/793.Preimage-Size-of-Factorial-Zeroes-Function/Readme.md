### 793.Preimage-Size-of-Factorial-Zeroes-Function

此题需要注意，并不是一定存在x使得f(x)=K。比如f(24)=4，但是f(25)=6，因此不存在任何f(x)=5。因此我们可以用二分搜索的方法尝试找到最小的x，满足f(x)==K。如果能找到，那么就直接返回5，这是因为x之后的x+1,x+2,x+3,x+4必定都不含质因数5，而x+5必定会包含新的质因数5从而增加至少一个trailing zero。反之，如果二分搜索找不到，那么就返回0.

如何写f(x)呢？考虑将x!按顺序每5个分一组，就会有一个因数含有一个5；将x!按顺序每25个分一组，就会有一个因数含有两个5；将x!按顺序每125个分一组，就会有一个因数含有三个5。以此类推，可以知道```f(x) = x/5 + x/25 + x/125 + ...```

因为K可以达到1e9，因此由上面的公式可知，二分搜索的上限应该设置为5e9，需要用到long类型。


[Leetcode Link](https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function)