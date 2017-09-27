### 200.Number-of-Islands
#### BFS的模板
```cpp
for (int i=0; i<N; i++)  // 遍历所有元素
{
       if (Yes) {q.push(i);}  // 符合条件的话，加入新元素至空队列
       while (!q.empty()) 
      {
            x = q.front();   //队首弹出一个元素
            q.pop();
            x1 = adjacent(x); // 每出列一个元素，则入列其相邻元素
            if (visited(x1)==0) 
                 q.push(x1);
      }
}
```

#### DFS的模板
```cpp
for (int i=0; i<N; i++)  // 遍历所有元素
{
      if (No) continue  // 不符合条件的话忽略
      visited[i]=1;
      explore(grid, visited, i); 
}

void explore(grid, visited, i)
{
    for (int k=0; k<4; k++)
    {
        int m = ... //寻找相邻元素
        if (Yes)    //满足条件的话，就从m开始递归
        {
           visited[m]=1;
           explore(grid, visited, m);           
        }
    }
}
```

