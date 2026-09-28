
class Solution {
public:
    int maxVowels(string s, int k) {

        int vowel = 0;
        int maxvowel = 0;

        for(int i = 0; i < k; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
               s[i] == 'o' || s[i] == 'u'){
                vowel++;
            }
        }

        maxvowel = vowel;

        for(int i = k; i < s.length(); i++){

            if(s[i-k] == 'a' || s[i-k] == 'e' || s[i-k] == 'i' ||
               s[i-k] == 'o' || s[i-k] == 'u'){
                vowel--;
            }

            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
               s[i] == 'o' || s[i] == 'u'){
                vowel++;
            }

            maxvowel = max(maxvowel, vowel);
        }

        return maxvowel;
    }
};


