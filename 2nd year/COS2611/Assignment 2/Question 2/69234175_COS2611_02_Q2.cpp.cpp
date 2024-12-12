//Jaymeen Patel
//69234175
#include <iostream>
#include <vector>
#include <climits>
#include <fstream>

using namespace std;

const int INF = INT_MAX; // got this from blackboxai

class msTreeType
{
public:
    void createSpanningGraph(const string &filename);
    void minimalSpanning(int sVertex);
    msTreeType(int size = 0);
    ~msTreeType();

protected:
    int source;
    double **weights;
    int *edges;
    double *edgeWeights;
    int gSize = 0;
    vector<vector<int>> vertexPaths;
};

void msTreeType::createSpanningGraph(const string &filename)
{
    ifstream inputFile(filename);
    if (!inputFile)
    {
        cout << "Error opening the file." << endl;
        return;
    }

    int numVertices, numEdges;
    inputFile >> numVertices >> numEdges;

    weights = new double *[numVertices];
    for (int i = 0; i < numVertices; ++i)
    {
        weights[i] = new double[numVertices];
    }

    for (int i = 0; i < numVertices; ++i)
    {
        for (int j = 0; j < numVertices; ++j)
        {
            weights[i][j] = INF;
        }
    }

    edges = new int[numVertices];
    edgeWeights = new double[numVertices];

    for (int i = 0; i < numEdges; ++i)
    {
        int u, v;
        double weight;
        inputFile >> u >> v >> weight;
        weights[u][v] = weight;
        weights[v][u] = weight;
    }

    gSize = numVertices;

    inputFile.close();
}

//Used blackboxai to help with below function and modify the original from the textbook to output the minimum spanning path
//and read the data from the text file and output the edges and vertices
void msTreeType::minimalSpanning(int sVertex)
{
    source = sVertex;
    bool *mstv = new bool[gSize];
    vector<vector<int>> paths(gSize);

    for (int j = 0; j < gSize; j++)
    {
        mstv[j] = false;
        edges[j] = source;
        edgeWeights[j] = weights[source][j];
    }

    mstv[source] = true;
    edgeWeights[source] = 0;

    cout << "Minimum Spanning Tree using Prim's Algorithm:" << endl;
    cout << "Edges Weight" << endl;

    for (int i = 0; i < gSize - 1; i++)
    {
        double minWeight = INF;
        int startVertex = -1;
        int endVertex = -1;

        for (int j = 0; j < gSize; j++)
        {
            if (mstv[j])
            {
                for (int k = 0; k < gSize; k++)
                {
                    if (!mstv[k] && weights[j][k] < minWeight)
                    {
                        endVertex = k;
                        startVertex = j;
                        minWeight = weights[j][k];
                    }
                }
            }
        }

        mstv[endVertex] = true;
        edges[endVertex] = startVertex;
        edgeWeights[endVertex] = minWeight;

        // Store the path from the source to the current vertex
        int currentVertex = endVertex;
        while (currentVertex != source)
        {
            paths[endVertex].push_back(currentVertex);
            currentVertex = edges[currentVertex];
        }
        paths[endVertex].push_back(source);

        // Print the edge and path
        if (edges[endVertex] != endVertex)
        {
            cout << "(" << edges[endVertex] << ", " << endVertex << ") " << edgeWeights[endVertex] << " Path: ";
            for (int vertex : paths[endVertex])
            {
                cout << vertex << " <- ";
            }
            cout << endVertex << endl;
        }
    }

    delete[] mstv;
}



msTreeType::msTreeType(int size) : gSize(0)
{
    weights = new double *[size];
    for (int i = 0; i < size; i++)
        weights[i] = new double[size];
    edges = new int[size];
    edgeWeights = new double[size];
}

msTreeType::~msTreeType()
{
    for (int i = 0; i < gSize; i++)
    delete[] weights[i];
    delete[] weights;
    delete[] edges;
    delete[] edgeWeights;
}

int main()
{
    string filename = "datatest2.txt";


    msTreeType myTree;
    myTree.createSpanningGraph(filename);

    int startingVertex = 0;
    myTree.minimalSpanning(startingVertex);

    return 0;
}

