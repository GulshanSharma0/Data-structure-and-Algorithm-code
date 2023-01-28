
Coding Problem
Problem Statement: Kruskals Algorithm
Problem Level: HARD
Problem Description:
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format -
v1 v2 w

where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)

Output Format :
MST

Constraints :
2 <= V, E <= 10^5

Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8

Sample Output 1 :
1 2 1
0 1 3
0 3 5

  
    #include<iostream>
    #include<vector>
    #include<algorithm>
    using namespace std;
    class edges{
        public:
        int source;
        int dest;
        int weight;
    };
    bool compare(edges a,edges b){
        return a.weight<b.weight;
    }
    int find_path(int v,vector<int>& parent){
        if(parent[v]==v){
            return v;
        }else{
            return find_path(parent[v],parent);
        }
    }
    void kruskals(vector<edges>& input,int n,int e){
        sort(input.begin(),input.end(),compare);
        vector<edges>output(n-1);
        vector<int>parent(n); 
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int i=0;
        int count = 0;
        while(count!=n-1){
            edges currentedge = input[i];
            int sourceparent = find_path(currentedge.source,parent);
            int destparent = find_path(currentedge.dest,parent);
            if(sourceparent!=destparent){
                output[count]=currentedge;
                count++;
                parent[sourceparent]=destparent;
            }
            i++;
        }
        for(int i=0;i<n-1;i++){
            if(output[i].source<output[i].dest)
                cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
            else{
                cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;
            }
        }
    }
    int main(){
    
    int n,e;
    cin>>n>>e;
    vector<edges>edge(n);
    for(int i=0;i<e;i++){
        cin>>edge[i].source>>edge[i].dest>>edge[i].weight;
    }
    kruskals(edge,n,e);
    }
