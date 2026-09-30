class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256];
        fill(hash, hash+256,-1);
        int l = 0;
        int r = 0;
        int maxlen = 0;

        while(r < s.length()){
            if(hash[s[r]] != -1){
                if(hash[s[r]] >= l){
                    l = hash[s[r]] + 1;
                }
            }
            hash[s[r]] = r;
            maxlen = max(maxlen, r-l+1);
            r++;
        }
     return maxlen; 
    }
};