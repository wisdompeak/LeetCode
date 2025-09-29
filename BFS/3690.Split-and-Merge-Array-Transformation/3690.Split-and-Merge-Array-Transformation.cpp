class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        if (nums1==nums2) return 0;
        int n = nums1.size();
        set<vector<int>>visited;
        visited.insert(nums1);
        
        queue<vector<int>>q;                
        q.push(nums1);
        int step = 0;

        while (!q.empty()) {
            int len = q.size();
            step++;
            while (len--) {
                auto cur = q.front();
                q.pop();                

                for (int L = 0; L < n; L++) 
                    for (int R = L; R<n; R++) {
                        vector<int>sub(cur.begin()+L, cur.begin()+R+1);
                        vector<int>rem;
                        rem.insert(rem.end(), cur.begin(), cur.begin()+L);
                        rem.insert(rem.end(), cur.begin()+R+1, cur.end());

                        for (int pos = 0; pos<=rem.size(); pos++) {
                            vector<int>nxt;
                            nxt.insert(nxt.end(), rem.begin(), rem.begin()+pos);
                            nxt.insert(nxt.end(), sub.begin(), sub.end());
                            nxt.insert(nxt.end(), rem.begin()+pos, rem.end());
                            
                            if (visited.find(nxt)!=visited.end()) continue;
                            visited.insert(nxt);
                            if (nxt==nums2) return step;
                            q.push(move(nxt));
                        }
                    }
            }
        }

        return -1;
        
    }
};
