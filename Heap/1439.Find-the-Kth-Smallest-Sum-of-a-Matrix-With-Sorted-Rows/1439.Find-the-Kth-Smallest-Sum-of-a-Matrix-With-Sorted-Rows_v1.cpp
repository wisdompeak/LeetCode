class Solution {    
public:
    int kthSmallest(vector<vector<int>>& mat, int k) 
    {
        int m = mat.size();
        int n = mat[0].size();

        vector<int>temp({0});
        vector<int>temp2;
        for (int i=0; i<m; i++)
        {
            temp2.clear();
            for (int j: temp)
                for (int k: mat[i])
                    temp2.push_back(j+k);
            sort(temp2.begin(), temp2.end());
            temp2.resize(min((int)temp2.size(),k));
            swap(temp, temp2);
        }
        return temp[k-1];      
    }        
};
