//Kaustubh Rai 21BCE0050
#include <bits/stdc++.h>
using namespace std;

class Edge{
public:
    int source;
    int dest;
    int weight;
};

bool compare(Edge e1, Edge e2){
    return e1.weight<e2.weight;
}

int findParent(int v, int *parent){
    if(parent[v]==v){
        return v;
    }
    return findParent(parent[v], parent);
};

void kruskals(Edge *input, int v, int e){
    sort(input, input+e, compare);
    Edge *output = new Edge[v-1];
    int *parent = new int[v];
    for(int i=0; i<v; i++){
        parent[i]=i;
    };
    int count=0;
    int j = 0;

    while(count!=v-1){
        Edge currentEdge = input[j];
        int sourceParent = findParent(currentEdge.source, parent);
        int destParent = findParent(currentEdge.dest, parent);

        if(sourceParent!=destParent){
            output[count]=currentEdge;
            count++;
            parent[sourceParent] = parent[destParent];
        }
        j++;
    }

    for(int i=0; i<v-1; i++){
        if(output[i].source<output[i].dest){
            cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
        }
        else {
            cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;
        }
    }

}

int main() {
    int e;
    int v;

    cin>>v>>e;

    Edge *input = new Edge[e];
    for(int i=0; i<e; ++i){
        cin>>input[i].source;
        cin>>input[i].dest;
        cin>>input[i].weight;

    }
    kruskals(input, v, e);

}