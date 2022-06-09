class TextEditor {
    list<char>t;
    list<char>::iterator iter;
public:
    TextEditor() {
        t.push_back('#');
        iter = t.begin();
    }
    
    void addText(string text) 
    {
        for (auto ch: text)
        {
            t.insert(iter, ch);
        }            
    }
    
    int deleteText(int k) 
    {
        int ret = 0;
        while (iter!=t.begin() && k>0)
        {
            auto iter2 = prev(iter);
            t.erase(iter2);
            k--;
            ret++;
        }        
        return ret;
    }
    
    string cursorLeft(int k) 
    {
        while (iter!=t.begin() && k>0)
        {
            iter = prev(iter);
            k--;
        }
        int p = 10;
        while (iter!=t.begin() && p>0)
        {
            iter = prev(iter);
            p--;
        }
        string ret;
        for (int i=0; i<10-p; i++)
        {
            ret.push_back(*iter);
            iter = next(iter);                
        }
        return ret;            
    }
    
    string cursorRight(int k) 
    {
        while (*iter!='#' && k>0)
        {
            iter = next(iter);
            k--;
        }
        int p = 10;
        while (iter!=t.begin() && p>0)
        {
            iter = prev(iter);
            p--;
        }
        string ret;
        for (int i=0; i<10-p; i++)
        {
            ret.push_back(*iter);
            iter = next(iter);                
        }
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
