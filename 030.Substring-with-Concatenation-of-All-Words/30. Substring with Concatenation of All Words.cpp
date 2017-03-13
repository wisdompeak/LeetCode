class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        unordered_map<string,int>Map;
        unordered_map<string,int>showTime;

        int Target=0;
        vector<int>result;
        
        for (int i=0; i<words.size(); i++)
        {
            if (Map.find(words[i])==Map.end())
                Target++;
            Map[words[i]]++;
        }
        int M=words[0].size();
        
        for (int begin=0; begin<M; begin++ )
        {
            int left=begin;
            int right=left;
      
            for (auto it=showTime.begin(); it!=showTime.end(); it++)
                it->second=0;             
            int count=0;
        
            while (right<s.size())
            {
                
                string temp=s.substr(right,M);
                right+=M;
                
                //cout<<left<<" "<<right<<endl;

                if (Map.find(temp)==Map.end())
                {
                    for (auto it=showTime.begin(); it!=showTime.end(); it++)
                        it->second=0;    
                    count=0;
                    left=right;
                }
                else
                {
                    showTime[temp]++;

                    if (showTime[temp]==Map[temp])
                    {
                        count++;
                        if (count==Target)
                        {
                            result.push_back(left);
                            string temp2=s.substr(left,M);
                            showTime[temp2]--;
                            count--;
                            left+=M;
                        }
                    }
                    else if (showTime[temp]>Map[temp])
                    {
                        while (left<=right && showTime[temp]!=Map[temp])
                        {
                            string temp2 = s.substr(left,M);
                            showTime[temp2]--;
                            if (showTime[temp2]==Map[temp2]-1)
                                count--;
                            left+=M;
                        }
                    }
                }
            }
        }
        
        return result;
        
    }
};
