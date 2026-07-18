class Solution {
public:

    string encode(vector<string>& strs) {
        string s="";
        for(auto x:strs){
            s+=to_string(x.size())+"#"+x;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#')
                j++;
            int len = stoi(s.substr(i, j - i));
            strs.push_back(s.substr(j + 1, len));
            i = j + 1 + len;
        }
        return strs;
    }
};
