### 1970.Last-Day-Where-You-Can-Still-Cross

此题和```LC 803.Bricks-Falling-When-Hit```的做法很相似，就是“时光倒流”+并查集。

我们首先考察最终的状态，将所有是陆地、且互相邻接的格子进行Union。再一步步地往前倒推，每一步都会有一个新格子从水变成陆地，它与邻接的陆地就可以进行Union。此时查看是否有任意两个第一行与最后一行的格子被Union起来了，是的话就意味着有一条从top到bottom的通路。

我们发现，每一个回合里都要检查任意两个top和bottom格子是否已经union，这个二层循环效率很低。解决的方法是，我们预先将所有的第一行的格子与一个虚拟的“top”进行union，将所有的最后一行的格子与一个虚拟的“bottom”进行union。这样每个回合的check，只要看top和bottom这两个格子是否被union起来了。
