// Coding Problem
// Problem Statement: Is Connected ?
// Problem Level: MEDIUM
// Problem Description:
// Given an undirected graph G(V,E), check if the graph G is connected graph or not.
// V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
// E is the number of edges present in graph G.
// Input Format :
// Line 1: Two Integers V and E (separated by space)
// Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
// Output Format :
// "true" or "false"
// Constraints :
// 2 <= V <= 1000
// 1 <= E <= 1000
// Sample Input 1:
// 4 4
// 0 1
// 0 3
// 1 2
// 2 3
// Sample Output 1:
// true

// Sample Input 2:
// 4 3
// 0 1
// 1 3 
// 0 3

// Sample Output 2:
// false
// Sample Output 2 Explanation
// The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn’t any path from vertices 0,1,3 to vertex 2.



#include<iostream>
using namespace std;
#include<queue>
void isConnected(int** edges,int n,int sv,bool* visited){
    //cout<<sv<<endl;
    visited[sv]=true;
    for(int i=0;i<n;i++){
        if(i==sv){
            continue;
        }
        if(edges[sv][i]==1){
            if(visited[i]){
                continue;
            }
            isConnected(edges,n,i,visited);
        }
    }
}

// void isConnected(int **edges,int n,int sv,bool *visited){
//     queue<int>pendingvertics;
//     pendingvertics.push(sv);
//     visited[sv]=true;
//     while(!pendingvertics.empty()){
//         int currentVertics = pendingvertics.front();
//         pendingvertics.pop();
//         //cout<<currentVertics<<endl;
//         for(int i=0;i<n;i++){
//             // if(i==currentVertics){
//             //     continue;
//             // }
//             if(edges[currentVertics][i]==1 && !visited[i]){
//                 pendingvertics.push(i);
//                 visited[i]=true;
//             }
//         }
//     }
// }
int main(){
    int v,e;
    cin>>v>>e;
    int **Graph=new int*[v];
    for(int i=0;i<v;i++){
        Graph[i]=new int[v];
        for(int j=0;j<v;j++){
            Graph[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        Graph[f][s]=1;
        Graph[s][f]=1;
    }
    bool* visited =new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    isConnected(Graph,v,0,visited);
    bool ans=true;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            cout<<"false"<<endl;
            ans=false;
            break;
        }
    }
    if(ans==1){ 
        cout<<"true"<<endl;
    }
    for(int i=0;i<v;i++){
        delete [] Graph[i];
    }
    delete [] Graph;
    delete [] visited;
    
}
