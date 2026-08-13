class Solution {
public:
    bool isPalindrome(string s) {
        
        int l=0; int h = s.size()-1;
        while(l <= h) {
            while(!((s[l] >=48 && s[l] <=57) || (s[l] >=65 && s[l] <=90) || (s[l] >=97 && s[l] <=122)) && l<h) l++;
            while(!((s[h] >=48 && s[h] <=57) || (s[h] >=65 && s[h] <=90) || (s[h] >=97 && s[h] <=122)) && l<h) h--;
            if(h < l) return true;
            if(s[h] >=97) s[h]= s[h]-32;
            if(s[l] >=97) s[l] = s[l]-32;
            if((s[l] == s[h])) {
                l++; h--; continue;
            };
            return false;
        }

        return true;
    }
};
