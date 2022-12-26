
 #these are the use for the disconnected graph





#include<iostream>
using namespace std;
#include<queue>
void printBFS(int **edges,int n,int sv,bool* visited){       //Print BFS; sv = starting vertics;
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
}
void PrintDFS(int** edges,int n,int sv,bool* visited){         //Print DFS, sv=stating vertics;
    cout<<sv<<endl;
    visited[sv]=true;
    for(int i=0;i<n;i++){
        if(i==sv){
            continue;
        }
        if(edges[sv][i]==1){
            if(visited[i]){
                continue;
            }
            PrintDFS(edges,n,i,visited);
        }
    }
}
void DFS(int **edges,int n){                                   //these are for Disconnected Graph;
    bool* visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            PrintDFS(edges,n,i,visited);
        }
    }

    delete [] visited;
}
void BFS(int** edges, int n){           
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){                                //these are for disconnected Graph;visited check visit or not
            printBFS(edges,n,i,visited);
        }
    }
    delete [] visited; 
}
    int main(){
    int n,e;                            //n = vertices,and e= edges;
    cin>>n>>e;
    int **edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]= new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int f,s;                                    //first virtics & Second vertics
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    cout<<"DFS"<<endl;
    DFS(edges,n);
    cout<<"BFS"<<endl;
    BFS(edges,n);
    for(int i=0;i<n;i++){
        delete [] edges[i];
    }
    delete [] edges;
}
