class TextEditor {
    stack<char>st1;
    stack<char>st2;
public:
    TextEditor() {
        
    }
    
    void addText(string text) 
    {
        for (auto ch: text)
            st1.push(ch);        
    }
    
    int deleteText(int k) 
    {
        int ret = min(k, (int)st1.size());
        for (int i=0; i<ret; i++)
        {
            st1.pop();
        }
        return ret;
        
    }
    
    string cursorLeft(int k) 
    {
        int t = min(k, (int)st1.size());        
        for (int i=0; i<t; i++)
        {
            st2.push(st1.top());
            st1.pop();
        }
        t = min(10, (int)st1.size());
        string ret;
        for (int i=0; i<t; i++)
        {
            ret.push_back(st1.top());
            st1.pop();
        }
        reverse(ret.begin(), ret.end());        
        for (int i=0; i<ret.size(); i++)
            st1.push(ret[i]);
        return ret;
    }
    
    string cursorRight(int k) 
    {
        int t = min(k, (int)st2.size());        
        for (int i=0; i<t; i++)
        {
            st1.push(st2.top());
            st2.pop();
        }
        t = min(10, (int)st1.size());
        string ret;
        for (int i=0; i<t; i++)
        {
            ret.push_back(st1.top());
            st1.pop();
        }
        reverse(ret.begin(), ret.end());        
        for (int i=0; i<ret.size(); i++)
            st1.push(ret[i]);
        return ret;   
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
