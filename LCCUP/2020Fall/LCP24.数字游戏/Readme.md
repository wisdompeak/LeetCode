### LCP24.数字游戏

令一个新的序列```nums[i] = nums[i] - i```，那么本题就转化为了对于任意区间[0:i]，求将该区间内所有元素都变equal的最少操作步数。根据LC 462的结论，这个equal value就是所有元素的中位数。

我们再根据LC 295的算法，用multiset的迭代器操作，可以动态地得到data stream medium。相应地总操作步骤的更新也可以高效地计算。

1. 如果当前区间元素数目是偶数，加入进来的新元素X大于等于medium，即 OOMOOOX，那么我们需要将medium右移。对于原先的元素而言，有3个元素需要增大delta，3个元素需要减小delta，最终效果是彼此抵消。其中的```detla = abs(medium- new medium)```

2. 如果当前区间元素数目是偶数，加入进来的新元素X小于medium，即 XOOMOOO，那么我们不需要将medium移动。对于原先的元素而言，他们已经进行的操作不用变动。

3. 如果当前区间元素数目是奇数，加入进来的新元素X大于等于medium，即 OOMOOX，那么我们不需要将medium移动。对于原先的元素而言，他们已经进行的操作不用变动。

4. 如果当前区间元素数目是奇数，加入进来的新元素X小于medium，即 XOOMOO，那么我们需要将medium左移。对于原先的元素而言，有3个元素需要增大delta，2个元素需要减小delta，最终效果是多操作一个delta。其中的```detla = abs(medium- new medium)```

别忘了，总操作步数还要再加上新元素的```abs(new medium - nums[i])```.


