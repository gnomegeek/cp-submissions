class Solution {
   public:
    int calculate(string s) {
        stack<int> st;
        int curr = 0;
        char op = '+';
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') continue;

            if (s[i] >= '0' and s[i] <= '9') {
                curr = curr * 10 + (s[i] - '0');
            } else {
                if (op == '+')
                    st.push(curr);
                else if (op == '-')
                    st.push(-curr);
                else if (op == '*') {
                    int left = st.top();
                    st.pop();
                    st.push(left * curr);
                } else if (op == '/') {
                    int left = st.top();
                    st.pop();
                    st.push(left / curr);
                }
                op = s[i];
                curr = 0;
            }
        }

        if (op == '*') {
            int left = st.top();
            st.pop();
            st.push(left * curr);
        } else if (op == '/') {
            int left = st.top();
            st.pop();
            st.push(left / curr);
        }

        if (op == '+')
            st.push(curr);
        else if (op == '-')
            st.push(-curr);

        int res = 0;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        return res;
    }
};