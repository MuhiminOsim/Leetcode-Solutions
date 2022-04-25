class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>> indices;
        for(int i = 1; i < arr.size(); i++) {
            indices[arr[i]].push_back(i);
        }	

        queue<int> q;
        int len = arr.size();
        vector<int> dist(len, -1);
        dist[0] = 0;
        q.push(0);

        while(!q.empty()) {
            int index = q.front();
            q.pop();
            for(int idx : indices[arr[index]]) {
                if(dist[idx]  != -1) continue;
                dist[idx] = 1 + dist[index];
                q.push(idx);
            }
            indices[arr[index]].clear();
            if(index + 1 < arr.size() && dist[index + 1] == -1) {
                dist[index + 1] = 1 + dist[index];
                q.push(index + 1);
            }
            if(index - 1 >= 0 && dist[index - 1] == -1) {
                dist[index - 1] = 1 + dist[index];
                q.push(index - 1);
            }
        }

        return dist[len - 1];
    }

};