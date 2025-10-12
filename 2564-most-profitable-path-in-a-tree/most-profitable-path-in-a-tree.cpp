class Solution {
public:
    vector<vector<int>> adjList;
    unordered_map<int,int> BobMap;
    unordered_map<int,int> AliceMap;
    int aliceincome = INT_MIN;
    int bobincome = INT_MIN;
    // buidling aliceTime map
    void buildAliceTime(int u, int p, int t) {
        AliceMap[u] = t;
        for (int v : adjList[u]) if (v != p) buildAliceTime(v, u, t + 1);
    }

    bool DfsBob(int curr,int time,vector<bool>&visited,int income,vector<int>& amount){
        visited[curr] = true;// marking it true
        BobMap[curr] = time; // making Bob node to time map

        // either alice never visited this node or first visited by bob
        if(!AliceMap.count(curr) || time < AliceMap[curr]){
            income += amount[curr];
        }else if(time == AliceMap[curr]){ // if reached at same time
            income += (amount[curr]/2);
        }

        if(curr == 0){ // when bob reaches his destination 
            bobincome = income;
            return true;
            
        };

        // traversing through all adj nodes 
        for(auto &ngbr: adjList[curr]){
            if(!visited[ngbr]){
                if(DfsBob(ngbr,time+1,visited,income,amount)) return true;
            }
        }
        BobMap.erase(curr);
        return false;
    }
    void DfsAlice(int curr,int time,vector<bool>&visited,int income,vector<int>& amount){
        visited[curr] = true; // mark visited
        
        // similar to bob 
        if(!BobMap.count(curr) || time < BobMap[curr]){
            income += amount[curr];
        }else if(time == BobMap[curr]){
            income += (amount[curr]/2);
        }

        // if we reached leaf node and seeing that current is not consider cause current also has 1
        if(adjList[curr].size() == 1 && curr != 0){
            aliceincome = max(aliceincome,income);
        }

        //traverse
        for(auto &ngbr :adjList[curr]){
            if(!visited[ngbr]){
                DfsAlice(ngbr,time+1,visited,income,amount);
            }
        }
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        adjList.assign(n,{});
        for(auto &it:edges){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }

        buildAliceTime(0, -1, 0);
        vector<bool> visited(n,false);
        int Bincome = 0;
        DfsBob(bob,0,visited,Bincome,amount);

       
        int Aincome = 0;
        visited.assign(n,false);
        DfsAlice(0,0,visited,Aincome,amount);
        cout<<bobincome<<" - "<<aliceincome;
        return aliceincome;

    }
};