class Solution {
public:
    vector<int> fallingSquares(vector<pair<int, int>>& positions) 
    {
        map<int,int>Map;
        
        Map[0]=0;
        Map[INT_MAX]=0;
        
        vector<int>results;
        int cur=0;
        
        for (auto p:positions)
        {
            int left=p.first;
            int right=p.first+p.second-1;
            int h=p.second;
            int maxH=0;
            
            auto ptri = Map.lower_bound(left);
            auto ptrj = Map.upper_bound(right);
            
            int temp = prev(ptrj,1)->second;
            
            auto ptr = ptri->first==left? ptri:prev(ptri,1);
            while (ptr!=ptrj)            
            {
                maxH=max(maxH, ptr->second);
                ptr = next(ptr,1);
            }
            if (ptri!=ptrj)
                Map.erase(ptri,ptrj);
                            
            Map[left] = maxH+h;
            Map[right+1] = temp;            
            cur = max(cur, maxH+h);
            
            results.push_back(cur);    
        }
        
        return results;
        
    }
};
