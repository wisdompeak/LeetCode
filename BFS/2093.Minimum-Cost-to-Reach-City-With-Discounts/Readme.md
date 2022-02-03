### 2093.Minimum-Cost-to-Reach-City-With-Discounts

本题看上去就像最短路径问题。难点在于，我们在某个位置时，无法知道当前使用折扣的权利是否为最优方案。因此本题的“图”的节点定义应该设计为二元参数 {node, discountsLeft}。在用Dijsktra遍历图的过程中，即使多次来到相同的位置，但是剩余折扣次数的不同的话，应当视为不同的“状态”。所以我们记录答案的数据应该是为二位的：dist[node][discounts]。

在PQ里弹出当前的{curNode, discountsLeft}后，可以扩展加入PQ的“状态”包括两部分，“使用折扣权利”或者“不使用”：
```cpp
for (auto nxt: next[curNode])
{ 
  auto [nxtNode, len] = nxt;
  pq.push(curDist+len, nxtNode, discountsLeft);
  if (discountsLeft >= 1)
    pq.push(curDist+len/2, nxtNode, discountsLeft-1);
}
```
