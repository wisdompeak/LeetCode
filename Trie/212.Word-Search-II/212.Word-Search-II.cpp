class Solution {
    class TrieNode
    {
        public:
        TrieNode* next[26];
        bool isEnd;
        TrieNode()
        {
            for (int i=0; i<26; i++)
                next[i]=NULL;
            isEnd=false;
        }
    };
    TrieNode* root;
    set<string>Set;
    int M;
    int N;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        root=new TrieNode();
        
        for (int i=0; i<words.size(); i++)
            build(words[i]);
                
        M=board.size();
        N=board[0].size();            
        auto visited=vector<vector<int>>(M,vector<int>(N,0));
        
        string word;
        for (int i=0; i<M; i++)
         for (int j=0; j<N; j++)
         {             
             visited[i][j]=1;
             DFS(i,j,root,word,visited,board);
             visited[i][j]=0;
         }
        
        vector<string>results(Set.begin(),Set.end());
        return results;
    }
    
    void build(string word)
    {
        TrieNode* node=root;
        for (int i=0; i<word.size(); i++)
        {
            char ch=word[i];
            if (node->next[ch-'a']==NULL)
                node->next[ch-'a']=new TrieNode();
            node=node->next[ch-'a'];
        }
        node->isEnd=true;
    }
    
    void DFS(int i, int j, TrieNode* node, string word, vector<vector<int>>&visited, vector<vector<char>>& board)
    {
        if (node->next[board[i][j]-'a']==NULL) return;
        
        node = node->next[board[i][j]-'a'];
        word += board[i][j];
        
        if (node->isEnd==true) Set.insert(word);
        
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};        
        
        for (int k=0; k<4; k++)
        {
            int x=i+dir[k].first;
            int y=j+dir[k].second;
            if (x<0||x>=M||y<0||y>=N) continue;
            if (visited[x][y]==1) continue;
            
            visited[x][y]=1;
            DFS(x,y,node,word,visited,board);
            visited[x][y]=0;                            
        }        
    }
};
