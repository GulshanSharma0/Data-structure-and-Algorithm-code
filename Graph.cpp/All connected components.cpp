// Coding Problem
// Problem Statement: All connected components
// Problem Level: MEDIUM
// Problem Description:
// Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
// V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
// E is the number of edges present in graph G.
// You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
// Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
// Input Format :
// Line 1: Two Integers V and E (separated by space)
// Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.

// Output Format :
// Different components in new line

// Constraints :
// 2 <= V <= 1000
// 1 <= E <= 1000

// Sample Input 1:
// 4 2
// 0 1
// 2 3

// Sample Output 1:
// 0 1 
// 2 3

// Sample Input 2:
// 4 3
// 0 1
// 1 3 
// 0 3

// Sample Output 2:
// 0 1 3 
// 2


#include<iostream>
using namespace std;
void DFS(int** Graph,int v,bool* visited,int index){
    cout<<index<<" ";
    visited[index]=1;
    for(int i=0;i<v;i++){
        if((!visited[i]) && Graph[index][i]==1){
            DFS(Graph,v,visited,i);
        }
    }
}
void AllConnected_Components(int** Graph,int v,bool* visited){
    for(int i=0;i<v;i++){
        if(!visited[i]){
            DFS(Graph,v,visited,i);
            cout<<endl;
        }
    }
}
int main(){ 
    int v,e;
    cin>>v>>e;
    int** Graph=new int*[v];
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
    bool *visited=new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=0;
    }
 
    AllConnected_Components(Graph,v,visited);
    
    delete [] visited;
    for(int i=0;i<v;i++){
        delete [] Graph[i];
    }
    delete [] Graph;
}
