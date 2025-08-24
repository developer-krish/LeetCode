class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string token;
        while (getline(ss, token, ' ')) {
            words.push_back(token);
        }

        if (pattern.size() != words.size()) return false;

        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        for (int i = 0; i < pattern.size(); i++) {
            char ch = pattern[i];
            string word = words[i];

            // If mapping exists, check consistency
            if (charToWord.count(ch) && charToWord[ch] != word) return false;
            if (wordToChar.count(word) && wordToChar[word] != ch) return false;

            // Otherwise, create mapping
            charToWord[ch] = word;
            wordToChar[word] = ch;
        }

        return true;
    }
};
