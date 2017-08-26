class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) 
    {
        stack<pair<int,int>>Stack;
        unordered_map<int,int>Map;
        
        for (int i=0; i<logs.size(); i++)
        {
            string s=logs[i];
            int j=0;
            while (s[j]!=':')
                j++;
            int id=stoi(s.substr(0,j));
            j++;
            
            int flag;
            if (s[j]=='s')
                flag=0;
            else
                flag=1;
            
            j=s.size()-1;
            while (s[j]!=':')
                j--;
            int time=stoi(s.substr(j+1));
            if (flag==1)
                time++;
                        
            if (flag==0)
            {
                Stack.push({id,time});
            }
            else
            {
                int t=time-Stack.top().second;
                Map[id]+=t;
                Stack.pop();
                if (!Stack.empty())
                {                    
                    Map[Stack.top().first]-=t;
                }
            }
        }
        
        vector<int>results(n,0);
        for (auto a:Map)
        {
            results[a.first]=a.second;
        }
        return results;
    }
};
