class Solution {
public:
    int aliceIncome;
    unordered_map<int,int> BobMap; // bobs node and time taken to reach that node data
    vector<vector<int>> adjList;
    bool DfsBob(int curr,int time,vector<bool>&visited){
        visited[curr] = true;
        BobMap[curr] = time;

        if(curr == 0){ return true; } // reached the target node; and will return true only if
        // reached the node 0

        // explore the ngbr
        for(auto &ngbr:adjList[curr]){
            if(!visited[ngbr]){
                if(DfsBob(ngbr,time+1,visited)) return true;
            }
        }
        //if didnt reach node 0 then backtrack so earse that node 
        BobMap.erase(curr);
        return false;
    }
    // dfs of alice to reach a leaf node which can fetch her the most income;
    void DfsAlice(int curr,int time,int income,vector<bool>&visited,vector<int>&amount){
        visited[curr] = true;

        // check if bob never reached this node or if reached alice reached first
        if(BobMap.find(curr) == BobMap.end() || time < BobMap[curr]){
            income += amount[curr];
        }else if(time == BobMap[curr]){ // both reached at same time
            income += (amount[curr]/2);
        }

        // if leaf node is found then update the AliceIncome 
        if(adjList[curr].size() == 1 && curr != 0){
            aliceIncome = max(aliceIncome,income);
        }

        //else traverse the adjlist
        for(auto &ngbr:adjList[curr]){
            if(!visited[ngbr]){
                DfsAlice(ngbr,time+1,income,visited,amount);
            }
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size(); // nodes 0 to n-1
        aliceIncome = INT_MIN;
        // created adjList
        adjList.assign(n, {});
        for(auto &it: edges){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        // visited table
        vector<bool> visited(n,false);
        // dfs for bob to traverse and reach Node 0
        int time = 0;
        DfsBob(bob,time,visited); // start node of bob, time taken for bob, visited array
        // dfs for alice to get max amount
        int income = 0;
        visited.assign(n,false);
        DfsAlice(0,0,income,visited,amount);
        return aliceIncome;

    }
};