class Solution {
   public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string morse[26] = {".-",   "-...", "-.-.", "-..",  ".",    "..-.",
                            "--.",  "....", "..",   ".---", "-.-",  ".-..",
                            "--",   "-.",   "---",  ".--.", "--.-", ".-.",
                            "...",  "-",    "..-",  "...-", ".--",  "-..-",
                            "-.--", "--.."};

        set<string> st;
        for (int i = 0; i < words.size(); i++) {
            string m = "";

            for (int j = 0; j < words[i].length(); j++) {
                m += morse[words[i][j] - 'a'];
            }

            st.insert(m);
        }

        return st.size();
    }
};