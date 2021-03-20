class Solution {
   public:
    int boats(vector<int>& people, int s, int e, int l) {
        if (s > e) {
            return 0;
        }

        if (s == e) {
            return 1;
        }

        if (people[s] + people[e] <= l) {
            return 1 + boats(people, s + 1, e - 1, l);
        }
        return 1 + boats(people, s, e - 1, l);
    }
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        return boats(people, 0, people.size() - 1, limit);
    }
};