### 798.Smallest-Rotation-with-Highest-Score

我们考虑某一个数的entry A[i]和它对应的index i,我们假设```A[i]<=i```.此时根据规则我们知道A[i]对应的得分是1.

我们可以知道，每做一次rotate，A[i]对应的index就会减1.所以我们可以知道当转过```i-A[i]+1```次之后，此时的index就会变成A[i]-1,就会导致A[i]大于它那时的index，导致分数变成0.

我们重新想象，在初始状态下（此时```index=i```还不变），如果将数组转过```i+1```次，那么index会从i变成0再突变成N-1.根据题目的条件，N-1必然大于等于A[i]，因此这个时候必然是会经历分数从0到1的变化。

所以总结一下，对于初始状态```A[i]<=i```的情况，经历过```i-A[i]+1```次rotate之后会经历分数从1变0，而经历过```i+1```次rotate之后会经历分数从0变1.所以我们设立一个数组change，其中change[k]表示在第k个rotate之后分数的变化。于是我们就有
```
change[i-A[i]+1] -= 1;
change[i+1] += 1;
```

那么如果初始状态```A[i]>i```的情况怎么处理呢？上述的第一个式子里面的索引会变成了负数。其实根据wrap up的性质，我们不难猜到，只需要改成（i-A[i]+1+N）%N即可。而第二个式子是永远成立的，这从索引的表达式是一直合法的就可以看出。

所以无论是否```A[i]<=i```，我们都可以用统一的公式：
```
change[(i-A[i]+1+N)%N] -= 1;
change[i+1] += 1;
```
就可以处理所有A[i]，计算相应在何时会导致分数的跳变（加1或者减1）。

最后只要在change里面找到最大值对应的index即可（也就是对应ratate了多少次）。


[Leetcode Link](https://leetcode.com/problems/smallest-rotation-with-highest-score)