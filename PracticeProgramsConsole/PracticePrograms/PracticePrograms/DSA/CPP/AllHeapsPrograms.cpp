#include<bits/stdc++.h>
using namespace std;
bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        int curr,left,right;
        for (int i = 0; i < (n / 2) ; i++) {
            // Check left child
            if (arr[i] < arr[2 * i + 1]) {
                return false;
            }
            // Check right child
            if (arr[i] < arr[2 * i + 2]) {
                return false;
            }
        }
        return true;
    }
//
int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        //  {diff, {row, col}}
        // max heap
        priority_queue<pair<int,pair<int,int>>> pq;
        
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m,-1e9));
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        
        // direction of row and column
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if(row==n-1 and col==m-1) return (-1)*diff;
            // 4 directions up, right, down, left
            for(int i{0};i<4;i++)
            {
                int newr = row + dr[i];
                int newc = col + dc[i];
                if(newr>=0 and newc>=0 and newr<n and newc < m)
                {
                    int newEffort = min((-1)*abs(heights[row][col]-heights[newr][newc]), diff);
                    if(newEffort > dist[newr][newc])
                    {
                        dist[newr][newc] = newEffort;
                        pq.push({dist[newr][newc], {newr,newc}});
                    }
                }
            }
        }
        return 0;
    }

int main()
{
	return 0;
}