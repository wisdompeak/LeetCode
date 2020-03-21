### 399.Evaluate-Division

本题网上有很多提示用图和Floyd算法。本人觉得用图的话，会把所有节点之间的路径都算一遍，没有必要。而且似乎本题用C++实现Floyd有些麻烦，网上的图算法都是用的phyton。所以我这里还是用万能的DFS大法。

基本思想很明确。要算两个节点的a/b，没有现成的数据怎么办，就把所有的中间节点走一遍，查看(a/c,c/b),(a/d,d/b),(a/e,e/b)...如果a/c有现成的，就把锅甩给DFS函数去递归考虑 c/b 怎么算，算出来c/b有解的话，a/b就大功告成。因为题目保证不会有冲突，所以那么多第三方节点c,d,e,...只要成功了一个就行。

首选，为了方便DFS的遍历，需要构造一个检索容易的数据结构。因为a,b,c,d这些字符串比较麻烦。所以用字符串的映射就是很自然的想法：
```cpp
        unordered_map<string, vector<pair<string, double>>> graph; //存储图的数据结构
        for (int i=0; i<equations.size(); i++)
        {
            auto it = equations[i];
            graph[it.first].push_back({it.second,values[i]});
            graph[it.second].push_back({it.first,1.0/values[i]});
        }
        //构造完整的双向图
```
构造DFS函数，包括起点start，终点end，和经过的节点集合visited
```cpp
    double DFS(string start, string end, unordered_set<string>visited)
```
根据上述的思想，在graph[start]遍历所有可以从start到达的第三方节点mid。忽略已经走过的那些节点，剩下的调用DFS(mid,end,visited)来查看mid到end是否走得通就行。
```cpp
        for (auto a:graph[start]) //遍历start所能通向的所有位置
        {
            string mid = a.first;  // 选取一个位置叫mid
            if (visited.find(mid)!=visited.end()) continue;  //如果这个位置已经访问过了，就不要再考虑
            double temp2 = DFS(mid,end,visited); //剩下的就交给DFS去算从mid到end的距离。
            if (temp2!=-1.0)
            {
                temp = a.second*temp2;  //只要从mid到end可行的话，就算找到从start到end的解了（因为题目保证没有其他mid能造成冲突）
                break;
            }
        }
```        


[Leetcode Link](https://leetcode.com/problems/evaluate-division)