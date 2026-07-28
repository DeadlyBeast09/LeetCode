class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> count(26, 0);

        for (char ch : s) {
            count[ch - 'a']++;
        }

        string left = "";
        char mid = '\0';

        for (int i = 0; i < 26; i++) {
            left += string(count[i] / 2, char('a' + i));

            if (count[i] % 2 == 1) {
                mid = char('a' + i);
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (mid != '\0')
            return left + mid + right;

        return left + right;
    }
};