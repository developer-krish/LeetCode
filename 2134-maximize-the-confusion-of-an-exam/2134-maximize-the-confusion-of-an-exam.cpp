class Solution {
public:
    int find(string answerKey, char ans, int k)
    {
        int i = 0, j = 0;
        int n = answerKey.size();
        int count = 0;
        int maxLen = 0;
        while(j < n)
        {
            if(answerKey[j] == ans)
               count++;
            while(count > k)
            {
                if(answerKey[i] == ans)
                   count--;
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
    int maxConsecutiveAnswers(string answerKey, int k) 
    {
        return max(find(answerKey, 'T', k), find(answerKey, 'F', k));
    }
};