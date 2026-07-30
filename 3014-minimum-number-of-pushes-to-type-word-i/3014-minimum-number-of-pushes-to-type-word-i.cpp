class Solution {
public:
    int minimumPushes(string word) {
        int count = word.length();
        int i = 1;
        int push = 0;
        while(count > 0){
            push += min(8,count)*i;
            count-=8;
            i++;
        }
        return push;
        
    }
};