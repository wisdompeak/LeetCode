class Solution {
    int result;
public:
    int findMinStep(string board, string hand) 
    {
        result = INT_MAX;
        unordered_map<char,int>Hand;
        for (auto x:hand) Hand[x]++;
        
        DFS(board,Hand,0);
        if (result==INT_MAX) return -1;
        else return result;
    }
    
    void DFS(string board, unordered_map<char,int>&Hand, int curCount)
    {
        
        if (board=="")
        {
            result = min(result,curCount);
            return;
        }
        if (curCount>=result) return;
            
        for (auto elem: Hand)
        {
            
            if (elem.second==0) continue;
            char c = elem.first;
            
            Hand[c]--;
                        
            for (int i=0; i<board.size(); i++)
            {
                if (board[i]!=c) continue;
                if (i>0 && board[i]==board[i-1]) continue;
                
                string newBoard = board;
                newBoard.insert(i,1,c);
                
                newBoard = clean(newBoard);
                DFS(newBoard, Hand, curCount+1);
            }
            
            Hand[c]++;
            
        }
    }
    
    string clean(string s)
    {
        string t="";
        while (1)
        {
            t = "";
            for (int i=0; i<s.size(); i++)
            {
                int i0=i;
                while (i<s.size() && s[i]==s[i0]) i++;
                if (i-i0<3)
                    t = t+s.substr(i0,i-i0);
                i--;
            }
            if (t==s) return t;
            s = t;
        }
        
        return s;
    }
};
