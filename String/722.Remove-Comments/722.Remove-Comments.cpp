class Solution {
public:
    vector<string> removeComments(vector<string>& source) 
    {
        vector<string>result;
        bool comment=false;
        string s;
        
        for (int i=0; i<source.size(); i++)
        {
            for (int j=0; j<source[i].size(); j++)
            {
                if (!comment && j+1<source[i].size() && source[i].substr(j,2)=="//")
                    break;
                else if (!comment && j+1<source[i].size() && source[i].substr(j,2)=="/*")
                {
                    comment=true;
                    j++;
                }
                else if (comment && j+1<source[i].size() && source[i].substr(j,2)=="*/")
                {
                    comment=false;
                    j++;
                }
                else if (!comment)
                {
                    s.push_back(source[i][j]);
                }
                    
            }
            
            if (!comment && s.size()>0)
            {
                result.push_back(s);
                s.clear();
            }
                
        }
        
        return result;
    }
};
