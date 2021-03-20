class CustomStack {
   public:
    int currsize, maxsize;
    vector<int> st;

    CustomStack(int maxSize) {
        currsize = 0;
        maxsize = maxSize;
    }

    void push(int x) {
        if (currsize < maxsize) {
            st.push_back(x);
            currsize++;
        }
    }

    int pop() {
        if (currsize == 0) return -1;
        int k = st[--currsize];
        st.pop_back();
        return k;
    }

    void increment(int k, int val) {
        for (int i = 0; i < min(k, currsize); i++) st[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */