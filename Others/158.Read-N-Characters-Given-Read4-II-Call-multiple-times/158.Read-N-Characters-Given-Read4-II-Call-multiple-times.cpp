// Forward declaration of the read4 API.
int read4(char *readBuf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    char ReadBuf[4];
    int i = 0;  // read buf pointer
    int count = 0;  // read buf counter
    
    int read(char *buf, int n) 
    {
        int j;
        for (j=0; j<n; j++)
        {
            if (count==0)
            {
                count = read4(ReadBuf);
                i = 0;
                if (count==0) break;
            }
            buf[j] = ReadBuf[i];
            i++;
            count--;
        }
        
        return j;        
    }
};
