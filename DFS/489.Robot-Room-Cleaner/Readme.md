### 489.Robot-Room-Cleaner

比较常规的DFS，但是题目却很有趣，而且对于考察回溯的概念要求很高．

基本的流程是：

(1) 每新探索(DFS)一个格子，先判断是否曾经来过，曾经来过的话什么都不用做，return．注意，这里是指＂新探索＂一个格子．如果确定不是新探索，而是在回溯的过程中到了这个地方，不适用于这个规则．

如果这是一个新格子，就clean()，并且标记已经来过．然后依次向四个方向探索：

(2) 首先向当前方向继续探索：步骤是：move, DFS（递归的过程，新探索下一个格子）, turnRight, turnRight, move, turnRight, turnRight．后面这五步是一个必要的回溯过程，保证回到了探索之前的状态．

(３) 然后turnRight,找到下一个方向，重复(２)的过程．

(４) 然后turnRight,找到下一个方向，重复(２)的过程．

(５) 然后turnRight,找到下一个方向，重复(２)的过程．

完整结束了这个格子的探索．


[Leetcode Link](https://leetcode.com/problems/robot-room-cleaner)