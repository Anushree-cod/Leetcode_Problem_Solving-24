class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        int left = 0;
        int a = 0; int b = 0; int c =0;

        for(int right = 0; right <n; right++){
            if(s[right] == 'a') a++;
            if(s[right] == 'b') b++;
            if(s[right] == 'c') c++;

            while(a > 0 && b > 0 && c > 0){
                ans += n - right;

                if(s[left] == 'a') a--;
                if(s[left] == 'b') b--;
                if(s[left] == 'c') c--;

                left++;
            }
        }
        return ans;
    }
};