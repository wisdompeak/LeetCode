class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) 
    {
        int k0 = s.size() - k;
        int count = 0;
        for (auto ch: s)
            if (ch==letter) count++;
        int k1 = count - repetition;
        
        int count0 = 0; //the total number of letters deleted
        int count1 = 0; // the total number of "letter" deleted
        
        stack<int>Stack;
        for (int i=0; i<s.size(); i++)
        {            
            while (!Stack.empty() && s[i]<Stack.top() && count0<k0 && (Stack.top()!=letter|| (Stack.top()==letter && count1<k1)))
            {
                if (Stack.top() == letter)
                    count1++;
                count0++;
                Stack.pop();
            }
            Stack.push(s[i]);            
        }
        
        string result;
        while (!Stack.empty())
        {
            result += Stack.top();
            Stack.pop();
        }
        
        string ans;
        for (int i=0; i<result.size(); i++)
        {
            if (count0==k0 || (result[i]==letter && count1==k1))
                ans.push_back(result[i]);
            else
            {
                count0++;
                if (result[i]==letter)
                    count1++;
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
