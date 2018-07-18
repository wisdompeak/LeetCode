### 218.The-Skyline-Problem

#### 解法1:有序容器

此题需要设置一个multiSet记录所有的当前下降沿的高度，则*prev(Set.end(),1)就是这个Set里的最大值。

首先，将所有的edges放入一个数组，按时间顺序排序，然后顺次遍历考虑：如果是上升沿，则在Set里加入对应高度（即添加一个下降沿）；如果是下降沿，则需要在Set里删除对应的高度（即退出当前的下降沿）。

那何时对results进行更新呢？我们在每次处理edge时，不管是加入上升边沿还是退出下降沿之后，都意味着天际线有可能变动。天际线会变成什么呢？答案是此时Set里的最大值！回想一下，Set里装的是所有当前仍未退出的下降沿，说明他们都在当前可以撑起对应的高度。那么Set里的最大值就是当前天际线的最高值。

所以每次查看一个edges，我们都要比较当前的高度（用cur记录）和Set里的最大值进行比较：一旦不同，就用Set里的最大值去加入results，同时也要更新cur。

有一个细节需要注意，在生成edges数组时，如果某一个位置同时有上升沿也有下降沿，如意要先考察上升沿，再考察下降沿。也就是要先加入一个下降沿，再退出可能的下降沿。否则类似[[0,2,3],[2,5,3]]的测试例子就会有问题。

#### 解法2:线段树

此题类似 699. Falling Squares 的方法,采用改造的线段树模型.同样,这里每个区间的tracked表示该区间内的maxHeight.

在设计setTracking(x,y,d)函数时,目标是对区间(x,y)内的高度进行更新.注意,只是对其中那些原有的tracked<d的区间进行更新.
```cpp
        int setStatus(int a, int b, int s)
        {
            if (begin>=b || end<=a)            // 1. [a,b]与这个区间不相交，返回原先的状态
                return status;                        
            if (a<=begin && end<=b && status<=s)            // 2. [a,b]包括了整个区间，并且该区间的status<s,则将该区间抹平
            {
                remove(left);
                remove(right);
                return status = s;
            }         
            if (a<=begin && end<=b && status>s && !left)    // 3. [a,b]包括了整个区间，并且该区间的status>s,且无子树，则整体不更新
            {
                return status;
            }         
            if (!left)                         // 4. 其他情况，需考虑其子树
            {
                int mid = (end-begin)/2+begin;
                left = new SegTree(begin,mid,status);
                right = new SegTree(mid,end,status);
            }            
            int leftStatus = left->setStatus(a,b,s);
            int rightStatus = right->setStatus(a,b,s);
            return status = max(leftStatus,rightStatus);
}
```
注意,本题其实不需要设计getTracking(x,y)
