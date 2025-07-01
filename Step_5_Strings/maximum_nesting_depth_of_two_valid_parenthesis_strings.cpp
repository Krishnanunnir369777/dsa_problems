class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
         vector<int> answer;
        int depth = 0;
        for (char c : seq) {
            if (c == '(') {
                depth++;
                answer.push_back(depth % 2); // Alternate groups on opening
            } else {
                answer.push_back(depth % 2); // Same group on closing
                depth--;
            }
        }
        return answer;
        
    }
};