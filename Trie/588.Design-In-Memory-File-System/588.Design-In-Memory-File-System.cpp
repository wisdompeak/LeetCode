class FileSystem {
    class TrieNode
    {
        public:
        map<string,TrieNode*>Map;
        bool isFile;
    };
    TrieNode* root;
    unordered_map<string,string>FileContents;
    
public:
    FileSystem() 
    {
        root=new TrieNode();
    }
    
    vector<string> ls(string path) 
    {
        TrieNode* node=root;
        string str;
        for (int i=1; i<path.size(); i++)
        {
            int i0=i;
            while (i<path.size() && path[i]!='/')
                i++;
            str=path.substr(i0,i-i0);
            node=node->Map[str];
        }
        
        if (node->isFile)
            return {str};
        else
        {
            vector<string>results;
            for (auto a:node->Map)
                results.push_back(a.first);
            return results;
        }
    }
    
    void mkdir(string path) 
    {
        TrieNode* node=root;
        for (int i=1; i<path.size(); i++)
        {
            int i0=i;
            while (i<path.size() && path[i]!='/')
                i++;
            string str=path.substr(i0,i-i0);
            if (node->Map.find(str)==node->Map.end())
                node->Map[str]=new TrieNode();                        
            node=node->Map[str];
        }
    }
    
    void addContentToFile(string filePath, string content) 
    {
        TrieNode* node=root;
        for (int i=1; i<filePath.size(); i++)
        {
            int i0=i;
            while (i<filePath.size() && filePath[i]!='/')
                i++;
            string str=filePath.substr(i0,i-i0);
            if (node->Map.find(str)==node->Map.end())
                node->Map[str]=new TrieNode();                        
            node=node->Map[str];
        }
        node->isFile=1;
        FileContents[filePath]+=content;
    }
    
    string readContentFromFile(string filePath) 
    {
        return FileContents[filePath];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem obj = new FileSystem();
 * vector<string> param_1 = obj.ls(path);
 * obj.mkdir(path);
 * obj.addContentToFile(filePath,content);
 * string param_4 = obj.readContentFromFile(filePath);
 */
