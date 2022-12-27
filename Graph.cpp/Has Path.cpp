// Problem Statement: Has Path 
// Problem Level: MEDIUM
// Problem Description:
// Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), check if there exists any path between them or not. Print true or false.
// V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
// E is the number of edges present in graph G.
// Input Format :
// Line 1: Two Integers V and E (separated by space)
// Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
// Line (E+2) : Two integers v1 and v2 (separated by space)

// Output Format :
// true or false

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
// true

// Sample Input 2 :
// 6 3
// 5 3
// 0 1
// 3 4
// 0 3



#include<iostream>
using namespace std;
bool hashPath(int** edges,int n,bool* visited,int s,int e){
    if(edges[s][e]==1)
        return true;
    visited[s]=true;
    bool res=false;
    for(int i=0;i<e;i++){
        if(i==s){
            continue;
        }
        if(edges[s][i]==1 && !visited[i]){
            res = hashPath(edges,n,visited,i,e);
        }
    if(res==true){
        return true;
    }
    }
    return res;
    
}
int main(){
    int v,e;
    cin>>v>>e;
    int **edges = new int*[v];
    for(int i=0;i<v;i++){
        edges[i]=new int[v];
        for(int j=0;j<v;j++){
            edges[i][j] = 0;
        }
    }
    for(int i = 0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f] = 1;
    }
    bool *visited = new bool[v] ;
    for(int i=0;i<v;i++){
        visited[i] = 0;
    }
    int v1,v2;
    cin>>v1>>v2;
    if(hashPath(edges,v,visited,v1,v2)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
}
