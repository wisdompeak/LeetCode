### 638.Shopping-Offers

虽然常规的DFS也能通过，但理论上需要用记忆化来避免已经探索过的路径。

记忆化的方式比较直接，但需要将needs转化为一个string这样能使用HashMap来存储对应的最优策略。

对于一个状态（给出needs的需求），遍历每一种valid offer之后就将needs降级用DFS处理；尝试所有valid offer之后就可以存储这个状态的最优策略到Map里了。

需要注意的细节：
1. 有些offer是不合算的，可以提前从special里排除掉；
2. 对于一个needs的需求，如果没有任何offer可以适用，则可以直接根据price计算出这个状态的策略。


[Leetcode Link](https://leetcode.com/problems/shopping-offers)