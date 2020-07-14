### 1483.Kth-Ancestor-of-a-Tree-Node
假设parent[node][0]标记了每个node的1代祖先，所以如果想知道node的7代祖先，可以将```node=parent[node][0]```执行7次。

假设我们额外知道每个node的2代祖先，记做p[node][1]，那么我们对node的7代祖先只要做4次操作：（7=2^0+2^1+2^1+2^1）
```
node = parent[node][0], node = p[node][1], node = p[node][1], node = p[node][1]
```
假设我们额外知道每个node的4代祖先，记做p[node][2]，那么我们对node的7代祖先只要做3次操作：（7=2^0+2^1+2^2）
```
node = p[node][0], node = p[node][1], node = p[node][2]
```
由此可知，如果我们预先知道每个node的2^i代祖先parent[node][i]，那么我们就能减少query的次数。这样能减少多少呢？对于node的k代祖先，只需要将k做二进制分解，有多少个为1的bit，就做多少次query。考虑到k<=5\*10^4，最多只需要20次query，就能够实现查询任意k代祖先。
```cpp
        for (int i=0; i<20; i++)
        {
            if ((k>>i)&1)
            {
                node = p[node][i];
                if (node == -1) break;
            }                
        }
        return node;
```
接下来我们考虑如何构建p[node][j].

我们知道node的4代祖先p[node][2]，可以通过两次2代祖先的query来实现，即```node=p[node][1], node=p[node][1]```。于是我们可以发现，如果知道了p[node][j-1]，就可以推出p[node][j]。即```p[node][j] = p[p[node][j-1]][j-1]```。所以我们设置两层循环，外循环从小到大确定j，内循环设置node，就可以设置所有的p[node][j]了。

这种思想叫做binary lifting.
