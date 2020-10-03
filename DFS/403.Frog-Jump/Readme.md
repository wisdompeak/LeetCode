### 403.Frog-Jump

比较直观的想法就是DFS搜索，层层递归下去。设计递归函数 bool DFS(pos,jump)表示当青蛙以jump的跨度跳到pos的石头上时，它能否跳到最后。显然，如果此刻的pos不是最后一块石头的话，那么就继续考察 DFS(pos+jump-1,jump-1), DFS(pos+jump,jump), DFS(pos+jump+1,jump+1)即可。

需要注意的细节：1. 如果pos不是石头的位置，直接返回false，2. 下一步的跨度不能小于等于0，否则就死循环。

以上的算法会LTE。如果思考进一步优化的算法，那显然就是记忆化，把每次搜索过的失败都记录下来。很容易想到，将已经探索过的{pos,jump}共同作为一个key存在一个集合FailureSet里，表明这个状态是失败的，以后DFS过程遇到这个状态就直接返回false。"


[Leetcode Link](https://leetcode.com/problems/frog-jump)
