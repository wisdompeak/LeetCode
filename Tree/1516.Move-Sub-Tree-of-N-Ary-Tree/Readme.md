### 1516.Move-Sub-Tree-of-N-Ary-Tree

这道题的复杂之处在于需要考虑不同的情景，有不同的操作策略。

1. p是root。需要的操作：q与其父节点断开；p接为q的子节点；答案返回q。

2. p是q的子树里的节点。需要的操作：p与其父节点断开；将p子树接在q的子节点；答案返回root。

3. q是p的子树里的节点。需要的操作：q与其父节点断开；将p子树与其父节点断开，改换为q子树；将p子树接在q的子节点；答案返回root。

4. p和q没有直属关系。需要的操作：p与其父节点断开；将p子树接在q的子节点；答案返回root。

要正确判断这四种情景，需要设计一个函数```Node* findParent(Node* root, Node* node)```，表示从root出发，试图寻找node的parent，找不到则返回NULL。情境2对应的是```findParent(q,p)!=NULL```，情境3对应的是```findParent(p,q)!=NULL```.

另外，设计一个函数```void disconnectOrReplace(Node* parent, Node* child, Node* node)```能够极大方便操作，它的作用是find child under parent, and replace it with node。如果node是NULL的话，就从parent里删除这个child。
    
