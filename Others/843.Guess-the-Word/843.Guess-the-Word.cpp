class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) 
    {
        for (int i=0; i<10; i++)
        {
            srand(1);
            int r = rand() % wordlist.size();
            string x = wordlist[r];
            int count = master.guess(x);
            if (count==6) return;
            
            vector<string>temp;
            for (auto s:wordlist)
            {
                if (s==x) continue;
                if (sameCount(s,x)==count) temp.push_back(s);
            }
            wordlist = temp;
        }
    }
    
    int sameCount(string A, string B)
    {
        int count=0;
        for (int i=0; i<6; i++)
            if (A[i]==B[i]) count++;
        return count;
    }
};
