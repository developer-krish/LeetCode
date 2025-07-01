class Solution {
public:
    int possibleStringCount(string word) 
    {
        int n = word.size();
        int length = n;
        for(int i = 1 ; i < n ; i++)
        {
            if(word[i - 1] != word[i])
               length--;
        }
        return length;

    }
};