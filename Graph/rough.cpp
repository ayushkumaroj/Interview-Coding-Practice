#include<iostream>
using namespace std;
#include<vector>

void buildAndPrintAdjacencyList(){
    int numberOfVertex;
    cout<<"Enter Number of Vertex: ";
    cin>>numberOfVertex;

    if(numberOfVertex <= 0){
        cout<<"Invalid Input: Vertex cannot be negative or zero";
        return;
    }

    int numberOfEdge;
    cout<<"Enter Number of Edges";
    cin>>numberOfEdge;
    
    if(numberOfEdge < 0){
        cout<<"Invalid Input: Edge cannot be negative";
        return;
    }

    vector<vector<int>>adjacencyMatrix(numberOfVertex, vector<int>(numberOfVertex, 0));

    int sourceVertex;
    int destinationVertex;

    for(int i=0; i<numberOfEdge; i++){
        cout<<"Enter Source Vertex: ";
        cin>>sourceVertex;
        cout<<"Enter Destination Vertex: ";
        cin>>destinationVertex;

        if(sourceVertex < 0 || sourceVertex >= numberOfVertex || destinationVertex < 0 || destinationVertex >= numberOfVertex){
            cout<<"Invalid Edges: Vertex are out of ranges";
            continue;
        }

        adjacencyMatrix[sourceVertex][destinationVertex] = 1;
        adjacencyMatrix[destinationVertex][sourceVertex] = 1;
    }

    if(numberOfEdge == 0){
        cout<<"Graph has no edge: Empty Adjacency Matrix";
    }
    
    cout<<"Printing Adjacency Matrix: "<<endl;
    for(int i=0; i<numberOfVertex; i++){
        for(int j=0; j<numberOfVertex; j++){
            cout<<adjacencyMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    buildAndPrintAdjacencyList();
    return 0;

}