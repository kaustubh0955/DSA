//Kaustubh Rai
#include <iostream>
#include <queue>
using namespace std;
void BFS(int vtx, int A[][8], int n){
    queue<int> Q;
    int visited[8] {0};
    cout << vtx << ", " << flush;
    visited[vtx] = 1;
    Q.emplace(vtx);
    while (!Q.empty()){
        int u = Q.front(); 
        Q.pop();
        for (int v=1; v<=n; v++){  
            if (A[u][v] == 1 && visited[v] == 0){  
                cout << v << ", " << flush; 
                visited[v] = 1;
                Q.emplace(v);
            }
        }
    }
    cout << endl;
}
 
int main (){
 
    int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
 
    cout << "Vertex: 1 -> " << flush;
    BFS(1, A, 8);
 
    cout << "Vertex: 4 -> " << flush;
    BFS(4, A, 8);
 
 
    return 0;
}