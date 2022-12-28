
// Coding Problem
// Problem Statement: Get Path - DFS
// Problem Level: MEDIUM
// Problem Description:
// Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
// Find the path using DFS and print the first path that you encountered.
// V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
// E is the number of edges present in graph G.
// Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
// Note : Save the input graph in Adjacency Matrix.
// Input Format :
// Line 1: Two Integers V and E (separated by space)
// Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
// Line (E+2) : Two integers v1 and v2 (separated by space)

// Output Format :
// Path from v1 to v2 in reverse order (separated by space)

// Constraints :
// 2 <= V <= 1000
// 1 <= E <= 1000
// 0 <= v1, v2 <= V-1

// Sample Input 1 :
// 4 4
// 0 1
// 0 3
// 1 2
// 2 3
// 1 3

// Sample Output 1 :
// 3 0 1

// Sample Input 2 :
// 6 3
// 5 3
// 0 1
// 3 4
// 0 3










#include<iostream>
using namespace std;
#include<vector>
bool getPathDFS(int** Graph,bool* visited,int v,int s,int e,vector<int>& res){
    if(s==e){
         res.push_back(s);
         return true;
    }
    visited[s]=1;
    bool ans =0;
    for(int i=0;i<v;i++){
        if(!visited[i] && Graph[s][i]==1){
            ans = getPathDFS(Graph,visited,v,i,e,res);
        }
         if(ans==true){
                res.push_back(s);
                return ans;
            }
    }
    return ans;
}
int main(){
    int v,e;
    cin>>v>>e;
    int **Graph = new int*[v];
    for(int i=0;i<v;i++){ 
        Graph[i] = new int[v];
        for(int j=0;j<v;j++){
            Graph[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int s,e;
        cin>>s>>e;
        Graph[s][e]=1;
        Graph[e][s]=1;
    }
    int v1,v2;
    cin>>v1>>v2;
    vector<int>res;
    bool* visited = new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=0;
    }
    if(getPathDFS(Graph,visited,v,v1,v2,res)){
        for(auto i:res){
            cout<<i<<endl;
        }
    }
    delete [] visited;
    for(int i=0;i<v;i++){
        delete [] Graph[i];
    }
    delete [] Graph;
}
