class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) 
    {
        int ret = 0;
        int n = answerKey.size();
        
        int flip = 0;        
        int j = 0;
        for (int i=0; i<n; i++)
        {
            while (j<n && (answerKey[j]=='T' || flip<k))
            {
                if (answerKey[j]!='T')
                    flip++;
                j++;                    
            }
            ret = max(ret, j-i);
            if (answerKey[i]=='F')
                flip--;
        }
        
        flip = 0;        
        j = 0;
        for (int i=0; i<n; i++)
        {
            while (j<n && (answerKey[j]=='F' || flip<k))
            {
                if (answerKey[j]!='F')
                    flip++;
                j++;                    
            }
            ret = max(ret, j-i);
            if (answerKey[i]=='T')
                flip--;
        }
        
        return ret;
    }
};
