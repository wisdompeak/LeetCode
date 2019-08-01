class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) 
    {
        stack<pair<int,int>>Stack;
        vector<int>results(n,0);
        
        for (auto s: logs)
        {
            int pos1 = s.find(":",0);
            int pos2 = s.find(":",pos1+1);
            int id = stoi(s.substr(0,pos1));
            bool flag = s.substr(pos1+1,pos2-pos1-1)=="start"? true:false;
            int timeStamp = stoi(s.substr(pos2+1));
            
            if (flag)
                Stack.push({id,timeStamp});
            else
            {
                int start = Stack.top().second;
                int duration = timeStamp - start + 1;
                results[id] += duration;
                Stack.pop();
                
                if (!Stack.empty())
                {
                    int prevId = Stack.top().first;
                    results[prevId] -= duration;
                }
            }            
        }
        
        return results;
    }
};
