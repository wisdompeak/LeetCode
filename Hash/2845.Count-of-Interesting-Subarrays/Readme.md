### 2845.Count-of-Interesting-Subarrays

看到subarray就想到前缀数组之差。

```
[X X X X X] l X X r
```

对于以r为结尾的前缀数组，假设其cnt对于M的取模是kk，那么想要得到以r为结尾、且`cnt%M=k`的subarray，我们只需要查看在r之前有多少前缀数组里的`cnt%M=k-kk`。每一个这样的前缀数组，都对应了一个l与r能够组成符合条件的subarray。
