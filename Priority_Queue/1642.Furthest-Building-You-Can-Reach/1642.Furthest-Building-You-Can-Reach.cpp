class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) 
    {
        multiset<int>Set;
        int count = 0;
        for (int i=1; i<heights.size(); i++)
        {
            if (heights[i]<=heights[i-1])
                continue;

            if (count < ladders)
            {                
                Set.insert(heights[i]-heights[i-1]);
                count++;
            }
            else
            {
                Set.insert(heights[i]-heights[i-1]);
                if (bricks < *Set.begin())
                    return i-1;
                bricks -= *Set.begin();
                Set.erase(Set.begin());                    
            }
        }
        return heights.size()-1;
    }
};
