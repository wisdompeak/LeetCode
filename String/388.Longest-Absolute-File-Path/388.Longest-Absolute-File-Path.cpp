class Solution {
    static bool cmp(string a, string b)
    {
        return a.size()>b.size();
    }
public:
    int lengthLongestPath(string input) 
    {
                
        vector<string>temp;
        int i=0;    
                
        while (i<input.size())
        {
            int i0=i;
            while (i<input.size() && input[i]!='\n')
                i++;
            temp.push_back(input.substr(i0,i-i0));
            i=i+1;
        }
        
        vector<string>files;
        
        vector<vector<string>>dirs;
        for (int i=0; i<temp.size(); i++)
        {
            string str=temp[i];
            int j=0;
            int count=0;
            while (j<str.size() && str[j]=='\t')
            {
                count++;
                j++;
            }
            str = str.substr(j);
            if (dirs.size()<count+1)
                dirs.push_back({str});
            else
                dirs[count].push_back(str);
                        
            bool flag=0;
            for (int j=0; j<str.size(); j++)
            {
                if (str[j]=='.')
                {
                    flag=1;
                    break;
                }
            }
            
            if (flag==1)
            {
                string filename;
                for (int j=0; j<=count; j++)
                {
                    filename+=dirs[j].back();
                    filename+='/';
                }
                filename.pop_back();    
                files.push_back(filename);
            }                
        }
        
        if (files.size()==0)
            return 0;
        else
        {
            sort(files.begin(),files.end(),cmp);
            return files[0].size();
        }
        
    }
};
