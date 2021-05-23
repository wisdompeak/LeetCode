### 943.Find-the-Shortest-Superstring

这是一道难度较高的题。首先注意题目中的substring是连续的，和subsequence的概念不一样。

其次，我们要能敏锐地将它看出，其本质是一道TSP的问题。举个例子，假如说有三个字符串A,B,C，那么最终答案只可能是类似ABC,ACB,BAC,BCA,CAB,CBA这几种可能性的一种（其中ABC表示将ABC三个字符串顺序相连，两两相接的部分有overlap的话就共享）。于是我们发现，这个题目就是让我们找一条最短路径，能包含所有的节点A,B,C。例如在上面的这个例子中，ABC,ACB,BAC,BCA,CAB,CBA的路径长度可能是互不相同的，我们要找出最短的。

慢着，路径ABC代表什么意思呢？它代表ABC三个字串连接起来（再利用公有部分）的长度。不难发现一个很好的性质，ABC的长度其实就是A的长度+（A到B的长度）+（B到C的长度）。其中A到B的长度，表示从字串A增加多少个字符能够变成以B为结尾的字串。例如A=abc,B=bcd,C=cde，那么ABC就代表了abcde，并且肯定是包含了A，B，C三个子串的superstring；其中A到B的长度是1，B到C的长度也是1.

所以，我们可以预处理得到题目中任意两个字串（节点）之间的距离graph[i][j]。现在已知任意节点之间的路径距离，我们要找出一条最短的路径，能包含所有的节点（起始点可以自由选择），这就是典型的旅行商（TSP）问题。

TSP问题最经典的解法是结合了DP的思想。我们设计状态方程dp[set][last],其中set表示已经访问过的节点的集合，last表示这些已经访问过的点集里面最后一个访问到的那个节点。我们认为{set,last}表示了一种“状态”，dp[set][last]就是到达这种状态时的最短路径长度。为什么要用两个指标来定义“状态”，这是因为仅仅根据set作为状态的话，不能往后续作为扩展。

举个例子，我们已经考察完了set4={1,2,3,4}，得到了当前最优解dp[set4]，那么我们想访问5号节点怎么办呢？显然我们不知道如何从已知的dp[set4]往待求的dp[set5]传递。但是如果我们额外知道最后一个节点的信息，那么转移方程就好办了：
```
dp[set5] = min{dp[set4][1]+graph[1][5], dp[set4][2]+graph[2][5], ... , dp[set4][4]+graph[4][5]}
```
可见dp[set][last]是一个很好的状态，便于我们做状态转移。

当然，如果用一个真正的“集合”作为dp的下表，显然实现上很不方便。TSP有个非常成熟的解决方案，就是用整形的32位bit值为来代表节点集合的状态。第k个bit位的数值是1，那么就说明了集合中包含第k个节点；反之就没有包含。例如3=binary(0011)表示包含了节点1和0的集合状态。对于大多数小规模的TSP问题而言，一个32位的整形就可以足够表示节点集合的状态了。

在程序中，我们用mask代表记载集合状态的整数，bit表示最后一个节点是哪个。于是有一个比较公式化的算法用来不断更新dp[mask][bit]：
```
for (int mask=0; mask<2^N; mask++)
  for (int bit=0; bit<N; bit++)
  {      
        pmask = mask删去bit节点;
        for (int i=0; i<N; i++)
        {
          dp[mask][bit] = min_{i}(dp[pmask][i]+graph[i][bit]);
          (where bit is contained in mask, and i is contained in pmask)
          update parent[mask][bit] if necessary;
        }
  }
```
其中比较精妙的point在于第一行的大循环：```for (int mask=0; mask<2^N; mask++)```，这样的循环顺序恰好保证了内循环中的```dp[pmask][i]```永远是已经在之前更新过了的（即已经赋值过的）。原因简而言之，是因为pmask永远是mask的一个子集，因此我们在更新dp[mask]时，dp[pmask]总是已经ready了。

以上的代码循环结束之后，最终的答案存在dp[2^N-1][bit]之中。其中2^N-1表示所有的点都已经被访问并装在集合里面了，而我们需要遍历bit（也就是考察以哪个点结尾），能够得到最短的总路径。

以上的dp存储的只是最短路径的长度。那么怎么回溯构建整个路径呢？我们只需要给每个状态[mask][bit]再添加一个parent的记录，即k=parent[mask][bit]表示的是：最优的dp[mask][bit]是通过dp[pmask][k]+graph[k][bit]得到的。于是我们就能够往上回溯一步了，下一步就递归来考察状态{pmask,k}。于是顺着parent的记录，我们最终能够到达全集合set0的状态.




[Leetcode Link](https://leetcode.com/problems/find-the-shortest-superstring)
