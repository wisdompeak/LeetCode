### 1697.Checking-Existence-of-Edge-Length-Limited-Paths

我们考虑一下如果只有一个query的话我们会怎么做？显然，我们只要考虑所有权重小于limit的那些edges，看看这些edges能否把query的两个node连接在一起。这是一个典型的Union Find的解法，时间复杂度近似为o(E).

但是本题有多个queries，如果对于每个query都独立解决的话，时间复杂度大致是o(QE)，这样来看是会TLE的。

解决方案很简单。我们优先解决limit低的query，因为它所能用到的edge数目更少，我们只需要查看少量的edges看它是否能够成query两点的连通图。然后我们再解决limit较高的query，此时只需要在已经构建的图里面再添加若干个新edge即可（因为放宽了对权重的要求），再判断query的两点是否联通...可见，如果我们将所有的queries按照limit从小到大排列进行处理，那么相应地我们只需要按照权重从小到大地添加边就行了。在构建联通图的过程中，每条边只需要处理一遍。

所以本题的时间复杂度可以近似认为是o(ElogE)，瓶颈在于对所有edges的排序。
