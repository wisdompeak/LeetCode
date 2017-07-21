class Solution {
    
    unordered_map<string, vector<pair<string, double>>> graph; //存储图的数据结构
    
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) 
    {
        vector<double>results;
        
        for (int i=0; i<equations.size(); i++)
        {
            auto it = equations[i];
            graph[it.first].push_back({it.second,values[i]});
            graph[it.second].push_back({it.first,1.0/values[i]});
        }
        //构造完整的双向图
        
        for (int i=0; i<queries.size(); i++) //遍历所有的query
        {
            auto it = queries[i];
            if (graph.find(it.first)==graph.end() || graph.find(it.second)==graph.end())
                results.push_back(-1.0);  //提前处理：图中不存在的点
            else if (it.first==it.second)
                results.push_back(1.0);   //提前处理：起讫位置相同的情况
            else
            {
                unordered_set<string>visited;
                double temp = DFS(it.first,it.second,visited); //剩下的都扔给DFS
                results.push_back(temp);
            }
        }
        return results;
    }
    
    double DFS(string start, string end, unordered_set<string>visited)
    {
        if (start==end) return 1.0;
        
        visited.insert(start);
        double temp = -1.0;
        
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
        
        return temp;
    }
};
