class Solution {
public:
    char kthCharacter(int k) 
    {
        string str = "a";
        while(str.length() < k)
        {
            int n = str.length();
            for(int i = 0 ; i < n && str.length() < k ; i++)
            {
                char nextChar = str[i] + 1;
                if(nextChar <= 'z')
                   str += nextChar;

                   
            }
        }
        return str[k - 1];

    }
};