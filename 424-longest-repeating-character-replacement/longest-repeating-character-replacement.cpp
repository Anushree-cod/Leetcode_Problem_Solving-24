class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
         int n = s.length();
        int maxlen = 0;
        int maxfreq = 0;
        unordered_map<char, int> mp;
        while( r < n){
            mp[s[r]]++;
            maxfreq = max(maxfreq, mp[s[r]]);
            int len = r - l + 1;
            int replacement = len - maxfreq;

            if(replacement > k){
                mp[s[l]]--;
                if(mp[s[l]] == 0)
                mp.erase(s[l]);
            l++;
            }
            len = r - l + 1;
            maxlen = max(maxlen , len);
            r++;
        }
        return maxlen;
    }
};