class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        string s2 = '#' + s;
        int len = s2.size();
        vector<bool> possible(len, 0);

        possible[0] = true;

        for (int i = 1; i < len; ++i)
        {
            for (int k = 0; k < i; ++k)
            {
                possible[i] = possible[k] &&
                              dict.find(s2.substr(k + 1, i - k)) != dict.end();
                if (possible[i]) break;
            }
        }

        return possible[len - 1];
    }
};