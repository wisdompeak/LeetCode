### 2096.Step-By-Step-Directions-From-a-Binary-Tree-Node-to-Another

本题和以往求LCA的题目不同。以往的LCA只需要求得LCA的节点本身，而这道题需要设计到路径打印。因此我们就老老实实地用递归的方法，把从root到q或者q的路径先记录出来，然后再比较得到LCA的位置。

此题中我们需要记录从root到p（或者q）一路上的操作（L或者R）。假设两条路径dirs1和dirs2在第k个节点位置分叉（也就是LCA的位置）。根据题意，我们就将dirs1[k:]全部搞成“U”（因为从p到LCA一路都是up），再拼接上dirs2[k:]这段路径即可。
