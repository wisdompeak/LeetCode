### 794.Valid-Tic-Tac-Toe-State

此题乍看会觉得是DFS或BFS,从一个空棋盘开始进行搜索,查看是否能够搜索到需要的状态.其实有更巧妙的解法.

首先,对于一个棋盘状态,X的数目只可能比O的数目多1,或者两者相等.除此之外的可以排除.

其次,当X的数目比O的数目多1时,说明最后一步是X落子,那么O不可能此时在盘面上获胜.故如果发现win('O')就返回false

类似的,当X的数目与O的数目相等时,说明最后一步是O落子,那么X不可能此时在盘面上获胜.故如果发现win('X')就返回false

至于其他情况,不管两边棋子怎么摆放,都是可能的.


[Leetcode Link](https://leetcode.com/problems/valid-tic-tac-toe-state)