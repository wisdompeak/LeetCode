class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int,int>Map;
        for (auto interval:intervals)
        {
            Map[interval[0]]+=1;
            Map[interval[1]]-=1;
        }
        
        int sum = 0;
        int ret = 0;
        for (auto& [t,diff]: Map)
        {
            sum += diff;
            ret = max(sum, ret);
        }
        return ret;
    }
};
