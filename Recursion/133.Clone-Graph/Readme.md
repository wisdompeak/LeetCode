### 133.Clone-Graph  
对于图的copy，必用Map建立原图和新图之间节点的对应。

#### DFS 
DFS时，递归函数作用于原图root所有的邻接节点adjacent。如果邻接节点adjacent已经存在于Map的映射里（说明已经访问过），则只需建立root和adjacent各自对应的两个节点在新图里的邻里关系。否则，邻接节点adjacent不存在于Map的映射里，说明它未曾被考虑过，则需要先在新图里建立一个adjacent的对应节点，再建立邻里关系。

#### BFS 
BFS一般都是用队列。对于队首的原图节点root，查看其所有邻接节点adjacent。如果adjacent在Map中没有建立其映射关系，则将adjacent入列，并且新建adjacent在新图中的对应节点，并建立在新图中的邻里关系。反之，邻接节点adjacent存在于Map的映射里，说明它已经被考虑过，则只需要建立root和adjacent对应节点的邻里关系，不需要入列任何节点。


[Leetcode Link](https://leetcode.com/problems/clone-graph)