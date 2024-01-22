### 2382.Maximum-Segment-Sum-After-Removals

我们用一个有序Map来维护当前存在的segments，其中key是起点，val是终点。另外我们在用一个有序的multiset来维护当前存在的segment sum。

每次我们考虑一个分割点t，根据题意，它必然存在一个segment里。可以用upper_bound在Map里找到这个segment，记做[start,end]。我们只需要将这个segment从Map中移出，并将对应的segment sum从Set里移出。再将新生成的两个新区间（如果存在的话）和各自的区间和放入Map和Set里即可。每次query之后，可以从Set里直接读出当前的最大值。
