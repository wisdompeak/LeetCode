class Solution {
public:
    int lengthLongestPath(string input) 
    {
        vector<string>files;
        for (int i=0; i<input.size(); i++)
        {
            int i0=i;
            while (i<input.size() && input[i]!='\n')
                i++;
            files.push_back(input.substr(i0,i-i0));
        }
                
        vector<string>dir;
        int result = 0;
        
        for (string str:files)
        {
            int k=0;
            while (k<str.size() && str[k]=='\t')
                k++;
                  
            if (dir.size()<=k) dir.resize(k+1);      
            dir[k] = str.substr(k);
                        
            if (dir[k].find(".")!=-1)
            {
                int count = 0;
                for (int i=0; i<=k; i++)
                    count+=dir[i].size();
                count+=k;
                
                result = max(count,result);
            }
        }
        
        return result;
        
    }
};
