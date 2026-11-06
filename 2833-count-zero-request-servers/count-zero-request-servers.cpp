
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {

        int m = logs.size();
        int q = queries.size();

        sort(logs.begin(), logs.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        vector<pair<int,int>> sortedQueries;

        for(int i = 0; i < q; i++) {
            sortedQueries.push_back({queries[i], i});
        }

        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> ans(q, 0);
        unordered_map<int,int> mp;

        int i = 0, j = 0;
        int active = 0;

        for(auto it : sortedQueries) {

            int start = it.first - x;
            int end = it.first;
            int idx = it.second;

            while(j < m && logs[j][1] <= end) {
                int server = logs[j][0];

                if(mp[server] == 0) {
                    active++;
                }

                mp[server]++;
                j++;
            }

            while(i < j && logs[i][1] < start) {
                int server = logs[i][0];

                mp[server]--;

                if(mp[server] == 0) {
                    active--;
                }

                i++;
            }

            ans[idx] = n - active;
        }

        return ans;
    }
};
