/*
*

Problem Statement: BFS Traversal
Problem Level: MEDIUM
Problem Description:
Given an undirected and disconnected graph G(V, E), print its BFS traversal.
Here you need to consider that you need to print BFS path starting from vertex 0 only.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Note : 1. Take graph input in the adjacency matrix.
2. Handle for Disconnected Graphs as well
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.

Output Format :
BFS Traversal (separated by space)

Constraints :
2 <= V <= 1000
1 <= E <= 1000

Sample Input 1:
4 4
0 1
0 3
1 2
2 3

Sample Output 1:
0 1 3 2

*  
*/

#include<iostream>
using namespace std;
#include<queue>
void printEdges(int **edges,int n,int sv){
    bool *visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    queue<int>pendingvertics;
    pendingvertics.push(sv);
    visited[sv]=true;
    while(!pendingvertics.empty()){
        int currentVertics = pendingvertics.front();
        pendingvertics.pop();
        cout<<currentVertics<<endl;
        for(int i=0;i<n;i++){
            if(i==currentVertics){
                continue;
            }
            if(edges[currentVertics][i]==1 && !visited[i]){
                pendingvertics.push(i);
                visited[i]=true;
            }
        }
    }
    delete [] visited;
}
int main(){
    int n,e;
    cin>>n>>e;
    int** edges= new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    printEdges(edges,n,0);


    for(int i=0;i<n;i++){
        delete [] edges[i];
    }
    delete [] edges;
}
