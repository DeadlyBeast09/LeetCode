class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        string ans = "";
        int minLen = INT_MAX;
        
        int i = 0, j = 0;           // Window pointers
        int countOnes = 0;           // Count of 1's in current window
        
        while (j < n) {
            // Step 1: Include s[j] in window
            if (s[j] == '1') {
                countOnes++;
            }
            
            // Step 2: If countOnes >= k, try to shrink window
            while (countOnes >= k && i <= j) {
                // Step 3: If we have exactly k ones, this is a beautiful substring
                if (countOnes == k) {
                    int currLen = j - i + 1;
                    string currSub = s.substr(i, currLen);
                    
                    // Step 4: Update answer based on length and lexicographical order
                    if (currLen < minLen) {
                        minLen = currLen;
                        ans = currSub;
                    }
                    else if (currLen == minLen && currSub < ans) {
                        ans = currSub;
                    }
                }
                
                // Step 5: Remove s[i] from window (shrink from left)
                if (s[i] == '1') {
                    countOnes--;
                }
                i++;
            }
            
            // Step 6: Expand window from right
            j++;
        }
        
        return ans;
    }
};