### 1059.All-Paths-from-Source-Lead-to-Destination

此题的本质是用DFS来检查图内是否有环。模板如下：
```cpp
    bool dfs(int cur)
    {
        visited[cur] = 2;
        for (int next: graph[cur])
        {
            if (visited[next]==1) continue;
            if (visited[next]==2) return false;
            if (dfs(next)==false)  return false;
        }
        visited[cur] = 1;
        return true;
    }
```

另外，如果DFS到了端点节点，还要检查是否是destination。
