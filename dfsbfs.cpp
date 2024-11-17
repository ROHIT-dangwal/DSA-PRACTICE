#include <iostream>
#include <cstdlib>
using namespace std;

class Graph
{
private:
    int **adjMatrix;
    int vertices;

public:
    Graph(int v)
    {
        vertices = v;
        adjMatrix = new int *[vertices];
        for (int i = 0; i < vertices; i++)
        {
            adjMatrix[i] = new int[vertices];
            for (int j = 0; j < vertices; j++)
            {
                adjMatrix[i][j] = 0; // Initialize all edges to 0 (no edge)
            }
        }
    }

    void addEdge(int u, int v)
    {
        adjMatrix[u][v] = 1; // For undirected graph
        adjMatrix[v][u] = 1; // For undirected graph
    }

    void DFS(int start)
    {
        bool *visited = new bool[vertices];
        for (int i = 0; i < vertices; i++)
        {
            visited[i] = false;
        }

        DFSUtil(start, visited);
        cout << endl;

        delete[] visited;
    }

    void DFSUtil(int v, bool *visited)
    {
        visited[v] = true;
        cout << v << " ";

        for (int i = 0; i < vertices; i++)
        {
            if (adjMatrix[v][i] == 1 && !visited[i])
            {
                DFSUtil(i, visited);
            }
        }
    }

    void BFS(int start)
    {
        bool *visited = new bool[vertices];
        for (int i = 0; i < vertices; i++)
        {
            visited[i] = false;
        }

        int *queue = new int[vertices];
        int front = 0, rear = 0;

        visited[start] = true;
        queue[rear++] = start;

        while (front < rear)
        {
            int node = queue[front++];
            cout << node << " ";

            for (int i = 0; i < vertices; i++)
            {
                if (adjMatrix[node][i] == 1 && !visited[i])
                {
                    visited[i] = true;
                    queue[rear++] = i;
                }
            }
        }
        cout << endl;

        delete[] visited;
        delete[] queue;
    }

    void displayGraph()
    {
        for (int i = 0; i < vertices; i++)
        {
            cout << "Vertex " << i << ": ";
            for (int j = 0; j < vertices; j++)
            {
                if (adjMatrix[i][j] == 1)
                {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }

    ~Graph()
    {
        for (int i = 0; i < vertices; i++)
        {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }
};

int main()
{
    int v, e, u, w, start;

    cout << "Enter the number of vertices: ";
    cin >> v;
    Graph g(v);

    cout << "Enter the number of edges: ";
    cin >> e;

    cout << "Enter the edges (u, v):\n";
    for (int i = 0; i < e; i++)
    {
        cin >> u >> w;
        g.addEdge(u, w);
    }

    cout << "Enter the starting vertex for traversal: ";
    cin >> start;

    cout << "\nDepth-First Search (DFS): ";
    g.DFS(start);

    cout << "Breadth-First Search (BFS): ";
    g.BFS(start);

    return 0;
}