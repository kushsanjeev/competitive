#include <iostream>
#include <limits>
#define infinity std::numeric_limits<int>::max()



void Warshall(int **Adj_Matrix, int vertices){

int i,j,k;

for(k = 0; k < vertices; k++)
    for(i = 0; i < vertices; i++)
        for(j = 0; j < vertices; j++)
            if(Adj_Matrix[i][k] != infinity && Adj_Matrix[j][k] != infinity && Adj_Matrix[i][j] > (Adj_Matrix[i][k] + Adj_Matrix[k][j]))
                   Adj_Matrix[i][j] = Adj_Matrix[i][k]+Adj_Matrix[k][j];       
}

int main(){


int i,j,NumofVertices;
int **Adj_Matrix;
int *Cost_Row;

std::cout<<"Enter the number of vertices: ";
std::cin>>NumofVertices;

Adj_Matrix = new int*[NumofVertices];

for(i = 0;i < NumofVertices; i++){
    Adj_Matrix[i] = new int[NumofVertices];
}

std::cout<<"Enter the adjacency matrix"<<std::endl;
    for(i = 0; i < NumofVertices; i++){
        for(j = 0; j < NumofVertices; j++){
            std::cin>> Adj_Matrix[i][j];
            if (Adj_Matrix[i][j] == 0 && i != j)
            {
                Adj_Matrix[i][j] = infinity;
            }
    }
}

Warshall(Adj_Matrix,NumofVertices);
for(i = 0; i < NumofVertices; i++){
    for(j = 0; j < NumofVertices; j++){
            std::cout<<"Shortest path between "<<i<<" and "<<j<<" is : ";
            if(Adj_Matrix[i][j]==infinity)
                    std::cout<<"INF"<<std::endl;
            else
                    std::cout<<Adj_Matrix[i][j]<<std::endl;
    }
}

return 0;

}