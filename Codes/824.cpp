class Solution {
public:
    string toGoatLatin(string sentence) {
        vector<string> words;
        string word = "";
        for(int i=0;i<(int)sentence.size();i++){
            if(sentence[i] == ' '){
                if(word.size())words.push_back(word);
                word = "";
                continue;
            }

            word += sentence[i];
        }

        if(word.size())words.push_back(word);

        set<char> s = {'a','e','i','o','u'};

        string ans = "";
        for(int i=0;i<(int)words.size();i++){
            auto w = words[i];
            if(!s.contains(tolower(w[0]))){
                w = words[i].substr(1,words[i].size()-1) + words[i][0];
            }

            w+="ma";
            for(int j=0;j<=i;j++)w+='a';
            if(i)ans+=' ';
            ans+=w;
        }

        return ans;
    }
};
