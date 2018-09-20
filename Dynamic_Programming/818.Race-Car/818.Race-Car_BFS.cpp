class Solution {
public:
    int racecar(int target) 
    {
        queue<pair<int,int>>q;
        q.push({0,1});           
        set<pair<int,int>>visited;
        visited.insert({0,1});
        
        int count = 0;
        while (!q.empty())
        {
            int len = q.size();
            count++;                        
            
            for (int k=0; k<len; k++)
            {
                int pos = q.front().first;
                int speed = q.front().second;
                q.pop();
            
                int speed_r = speed>0? -1:1;
                if (visited.find({pos,speed_r})==visited.end())
                {
                    visited.insert({pos,speed_r});
                    q.push({pos,speed_r});
                }
            
                int pos_a = pos+speed;
                int speed_a = speed*2;
                if (pos_a==target) return count;
                if (abs(pos_a-target)>target) continue;
                if (visited.find({pos_a,speed_a})==visited.end())
                {
                    visited.insert({pos_a,speed_a});
                    q.push({pos_a,speed_a});
                }                
            }            
        }
        return -1;
    }
};
