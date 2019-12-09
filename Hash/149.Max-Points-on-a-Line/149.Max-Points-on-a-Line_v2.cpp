class Solution {
public:
    int maxPoints(vector<vector<int>>& points) 
    {
        int ret = 0;
            
        for (int i=0; i<points.size(); i++)
        {
            map<pair<int,int>, int>count;
            int verticle = 0;
            int same = 0;
            
            for (int j=0; j<points.size(); j++)
            {
                if (i==j)  continue;
                if (points[i]==points[j])
                {
                    same++;
                    continue;
                }
                
                int dy = points[j][1]-points[i][1];
                int dx = points[j][0]-points[i][0];
                
                if (dx==0)
                {
                    verticle ++;
                    continue;
                }
                
                int a = dy/gcd(dy,dx);
                int b = dx/gcd(dy,dx);
                
                count[make_pair(a,b)] ++;
            }
            
            ret = max(ret, same + 1);
            ret = max(ret, verticle + same +1 );
            for (auto x: count)
                ret = max(ret, x.second + same + 1);
        }
        
        return ret;
    }
};
