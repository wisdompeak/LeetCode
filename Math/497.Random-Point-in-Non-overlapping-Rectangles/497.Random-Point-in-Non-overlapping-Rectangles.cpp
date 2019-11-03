class Solution {
    vector<int>q;
    vector<vector<int>>rects;
public:
    Solution(vector<vector<int>>& rects) 
    {
        int sum = 0;
        for (int i=0; i<rects.size(); i++)
        {
            sum += (rects[i][2]-rects[i][0]+1)*(rects[i][3]-rects[i][1]+1);
            q.push_back(sum);
        }
        this->rects = rects;
    }
    
    vector<int> pick() 
    {
        int idx = rand()%q.back()+1;
        int i = lower_bound(q.begin(),q.end(), idx) - q.begin();
        
        int D1 = rects[i][2]-rects[i][0]+1;
        int D2 = rects[i][3]-rects[i][1]+1;
        int j = rand()%D1;
        int k = rand()%D2;
        return {rects[i][0]+j, rects[i][1]+k};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
