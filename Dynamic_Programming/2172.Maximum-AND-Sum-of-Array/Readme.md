### 2172.Maximum-AND-Sum-of-Array

本题看上像二分图匹配问题。左边是一堆数字，右边是一对slots，要求匹配的边权之和最大。但是标准的二分图匹配要求每条边不能有公共边，本题则是允许最多两条边共享一个slot节点。

同以往一样，我们不用KM算法来解决带权最大二分图匹配，我们也不考虑最小费用最大流的做法，这里依然用状态压缩DP。

一般我们有两种方案：1. 遍历slot，用状态来表示nums。2. 遍历nums，用状态来表示slot。

对于第一种方法，我们用二进制数state来表示那些数字已经被配对，于是dp[i][state]表达的是：用完第i个slot、配对了state所表示的数字集时，所得的最大价值。所以核心代码大致会是：
```
 for (int i=0; i<slot.size(); i++)
    for (int state=0; state<(1<<nums.size()); state++)
      for (auto pickedNum: avaiable plans)
        dp[i][state] = dp[i-1][state-pickedNum] + (pickedNum & slot[i]);
```
其中上式里的available plans比较复杂。因为slot里面可以放0个或者1个或者2个数字，所以需要在state所代表的数字集合里面任意挑选0个、1个、2个数字的组合，这个组合的大小可能会有C(18,2)的级别。综上三层循环的总复杂度会是：```9*(2^18)*C(18,2)```，这是1e8数量级的数字，会TLE。

第二种方法，我们用三进制数state来表示所有slots的匹配状态（三进制数的每个bit表示该slot里面已经装了0个、1个或2个数字）。于是dp[i][state]表达的是：用完第i个数字、配对了state所表示的slots时，所得的最大价值。所以核心代码大致会是：
```
 for (int i=0; i<nums.size(); i++)
    for (int state=0; state<pow(3, numSlots); state++)
      for (auto pickedSlot: avaiable plans)
        dp[i][state] = dp[i-1][state-pickedSlot] + (nums[i] & pickedSlot);
```
其中上式里面的avaialbe plans是指，nums[i]对应了state里面的哪一个slot。也就是说，我们需要在state里面挑一个slot，它盛装的数字数目必须大于等于1，这样才能支持dp[i][state]的定义。这个availabe plans的复杂度就是o(numSlot)，把state所代表的每个slot都检查一遍就可以了。综上，三层循环的总复杂度是```18*(3^9)*(9)```，这是3e6数量级的数字，可以接受。

事实上，上述的方法还可以进一步优化，第一层循环是不必要的。我们如果固定了slots的state，那么必然知道此时所有slots里面总共有多少个数字，那么当前所考察的i其实也就知道了。这样时间复杂度就是```(3^9)*(9)```.
