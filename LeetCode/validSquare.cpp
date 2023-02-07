class Solution {
public:

    int d(vector<int>p1, vector<int> p2)
    {
        return (p1[0] - p2[0]) *(p1[0] - p2[0]) + ((p1[1] - p2[1]) *(p1[1] - p2[1])); 
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> s;
        s.insert(d(p1,p2));
        s.insert(d(p1,p3));
        s.insert(d(p1,p4));
        s.insert(d(p2,p3));
        s.insert(d(p2,p4));
        s.insert(d(p3,p4));

        return !s.count(0) && s.size() == 2;
    }
};