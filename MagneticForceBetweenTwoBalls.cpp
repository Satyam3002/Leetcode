class Solution {
public:
    bool isAnswer(vector<int>& A, int mid, int m) {
        int initial = 1;
        int prev = A[0];
        for(int i = 1; i < A.size(); i++) {
            if(A[i] - prev >= mid) {
                prev = A[i];
                initial++;
                if(initial == m) {
                    return true;
                }
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int s = 1, n = position.size(), e = position[n-1] - position[0];
        int ans = 0;
        
        while(s <= e) {
            int mid = s + (e - s) / 2;
            
            if(isAnswer(position, mid, m)) {
                ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return ans;
    }
};