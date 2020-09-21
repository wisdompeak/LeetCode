
int numNodes;
int visited[numNodes];
vector<vector<int>> next;

main()
{
  // prepare next; // next[i][j]: there is a directional path i->j

  // dfs 判断有环
  for (int i=0; i<numNodes; i++)
  {            
      if (dfs(i)==false) return false;            
  }
  return true;

  // bfs 判断有环
  return bfs();
}

bool dfs(int cur)
{
    if (visited[cur]==1) return true;

    visited[cur] = 2;
    for (int next: next[cur])
    {
        if (visited[next]==1) continue;
        if (visited[next]==2) return false;
        if (dfs(next)==false)  return false;
    }
    visited[cur] = 1;
    return true;
}



bool bfs() 
{        
    queue<int>q;
    int count = 0;

    vector<int>InDegree(numNodes,0);
    for (int i=0; i<numNodes; i++)
    	for (int j: next[i])
    		InDegree[j]++;

    for (int i=0; i<numNodes; i++)
    {
        if (InDegree[i]==0) 
        {
            q.push(i);
            count++;
        }
    }
                
    while (!q.empty())
    {
        int curCourse = q.front();
        q.pop();
        for (auto child: next[curCourse])
        {
            InDegree[child]--;
            if (InDegree[child]==0)
            {
                q.push(child);
                count++;
            }                    
        }
    }        
    
    return count==numNodes;        
}
