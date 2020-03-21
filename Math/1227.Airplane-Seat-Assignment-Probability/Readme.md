### 1227.Airplane-Seat-Assignment-Probability

第k个人登机的时候，第1到第k-1个人已经登机了。除了第一个人的位置未知，其他第2到第k-1个人的位置肯定是已经被占据了（either被本人占据，or被乱坐的人占据）。此时未占据的位置有n-(k-1)个，另外还有一个座位是不知道主人的（它的主人肯定不是编号2到k-1的乘客）。所以这n-k+2个位置，只有一份的概率是k号乘客的位置。所以第k个乘客能坐到自己的位置的概率就是```(n-k+1)/(n-k+2)```

当n=k时，上面的公式就是1/2.


[Leetcode Link](https://leetcode.com/problems/airplane-seat-assignment-probability)