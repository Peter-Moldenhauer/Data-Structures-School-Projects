/*************************************************************************************************
* Author:                       Peter Moldenhauer
* Date Created:                 3/12/17
* Last Modification Date:       3/12/17
* Filename:                     graph.c
* Class:                        CS 261 - Data Structures
* Assignment:                   Assignment 7
*
* Overview:
*   This program implements the Depth First Search (DFS) and Breadth First Search (BFS) graph traversal
*   algorithms with a circular linked-list deque to take two vertices and return 1 if there is a path
*   between the vertices (a sequence of edges connecting them) or 0 otherwise.
*
* Input:
*   When run with tests.c there is no input. When run with main.c it takes the input files: graph1.txt,
*   graph2.txt and graph3.txt.
*
* Output:
*   When run with tests.c, this program outputs a representation of each graph and various messages to
*   the screen that notifies the user if the test cases are passed or failed.
******************************************************************************************************/

#include "graph.h"
#include "deque.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/**
 * Clears isVisited in all nodes in the graph.
 * @param graph
 */
static void clearVisited(Graph* graph)
{
    int i;
    for (i = 0; i < graph->numVertices; ++i)
    {
        graph->vertexSet[i].isVisited = 0;
    }
}

/**
 * Recursive helper function for DfsRecursive. Determines if there is a path
 * from the given vertex to the destination using a recursive depth-first
 * search.
 * @param graph
 * @param vertex
 * @param destination
 * @return 1 if there is a path, 0 otherwise.
 */
static int DfsRecursiveHelper(Graph* graph, Vertex* vertex, Vertex* destination)
{
    vertex->isVisited = 1;
    if (vertex == destination)
    {
        return 1;
    }
    int i;
    for (i = 0; i < vertex->numNeighbors; ++i)
    {
        Vertex* neighbor = vertex->neighbors[i];
        if (!neighbor->isVisited)
        {
            if (DfsRecursiveHelper(graph, neighbor, destination) == 1)
            {
                return 1;
            }
        }
    }
    return 0;
}

/**
 * Determines if an edge (v1, v2) exists.
 * @param v1
 * @param v2
 * @return 1 if the edge exists, 0 otherwise.
 */
static int isAdjacent(Vertex* v1, Vertex* v2)
{
    if (v1 == v2)
    {
        return 1;
    }
    int i;
    for (i = 0; i < v1->numNeighbors; ++i)
    {
        if (v1->neighbors[i] == v2)
        {
            return 1;
        }
    }
    return 0;
}

/**
 * Connects two vertices by adding each other to their neighbors lists.
 * @param v1
 * @param v2
 */
static void createEdge(Vertex* v1, Vertex* v2)
{
    v1->neighbors = realloc(v1->neighbors,
                            sizeof(Vertex*) * (v1->numNeighbors + 1));
    v2->neighbors = realloc(v2->neighbors,
                            sizeof(Vertex*) * (v2->numNeighbors + 1));
    v1->neighbors[v1->numNeighbors] = v2;
    v2->neighbors[v2->numNeighbors] = v1;
    ++(v1->numNeighbors);
    ++(v2->numNeighbors);
}

/**
 * Determines if there is a path from the source to the destination using a
 * recursive depth-first search starting at the source.
 *
 * You can use this function to test the correctness of the others.
 *
 * @param graph
 * @param source
 * @param destination
 * @return 1 if there is a path, 0 otherwise.
 */
int dfsRecursive(Graph* graph, Vertex* source, Vertex* destination)
{
    clearVisited(graph);
    return DfsRecursiveHelper(graph, source, destination);
}

/**
 * Determines if there is a path from the source to the destination using an
 * iterative depth-first search starting at the source.
 *
 * Remember to call clearVisited() before starting the search.
 *
 * @param graph
 * @param source
 * @param destination
 * @return 1 if there is a path, 0 otherwise.
 */
int dfsIterative(Graph* graph, Vertex* source, Vertex* destination)
{
    // FIXME: Implement

    // Since we are going to be using a "stack" we need to pushFront to the deque
    // and popFront of the deque to mimic the stack functionality

    assert(graph != NULL);
    struct Deque *deque = dequeNew();
    clearVisited(graph); // call clearVisited before starting the search

    // Add source to the stack
    dequePushFront(deque, source);

    // while stack is not empty
    while(dequeIsEmpty(deque) != 1){
        // Get the most recent vertex from the stack
        Vertex* vertex = dequeFront(deque);
        // Mark this vertex as reachable
        vertex->isVisited = 1;
        // Pop this most recent vertex from the stack
        dequePopFront(deque);

        // For all the neighbors of this vertex, if a neighbor is NOT in reachable (isVisited) then push to the stack
        int i;
        for(i = 0; i < vertex->numNeighbors; i++){
            if(!vertex->neighbors[i]->isVisited){
                dequePushFront(deque, vertex->neighbors[i]);
            }
        }

        // if destination is reached (isVisited) then return 1
        if(vertex == destination)
            return 1;
    }

    dequeDelete(deque);
    // if destination was not reached then return 0
    return 0;
}

/**
 * Determines if there is a path from the source to the destination using an
 * iterative breadth-first search starting at the source.
 *
 * Remember to call clearVisited() before starting the search.
 *
 * @param graph
 * @param source
 * @param destination
 * @return 1 if there is a path, 0 otherwise.
 */
int bfsIterative(Graph* graph, Vertex* source, Vertex* destination)
{
    // FIXME: Implement

    // Since we are going to be using a "queue" we need to pushFront to the deque
    // and popBack of the deque to mimic the queue functionality

    assert(graph != NULL);
    struct Deque *deque = dequeNew();
    clearVisited(graph); // call clearVisited before starting the search

    // Add source to the queue
    dequePushFront(deque, source);

    // while queue is not empty
    while(dequeIsEmpty(deque) != 1){
        // Get the first vertex in the queue
        Vertex* vertex = dequeBack(deque);
        // Mark this vertex as reachable
        vertex->isVisited = 1;
        // Pop this vertex from the queue
        dequePopBack(deque);

        // For all the neighbors of this vertex, if a neighbor is NOT in reachable (isVisited) then push to the queue
        int i;
        for(i = 0; i < vertex->numNeighbors; i++){
            if(!vertex->neighbors[i]->isVisited){
                dequePushFront(deque, vertex->neighbors[i]);
            }
        }

        // if destination is reached (isVisited) then return 1
        if(vertex == destination)
            return 1;
    }

    dequeDelete(deque);
    // if destination was not reached then return 0
    return 0;
}

typedef struct Edge Edge;

struct Edge
{
    int i;
    int j;
};

/**
 * Generates a set of random unique edges of size numEdges sampled from the
 * set of all possible edges.
 * @param numVertices
 * @param numEdges
 * @return An array of numEdges edges.
 */
Edge* randomEdges(int numVertices, int numEdges)
{
    assert(numVertices > 0);
    int maxEdges = numVertices * (numVertices - 1) / 2;
    assert(numEdges >= 0);
    assert(numEdges <= maxEdges);

    // Generate all possible edges
    Edge* edges = malloc(sizeof(Edge) * maxEdges);
    int k = 0;
    int i;
    int j;
    for (i = 0; i < numVertices; ++i)
    {
        for (j = i + 1; j < numVertices; ++j)
        {
            edges[k].i = i;
            edges[k].j = j;
            ++k;
        }
    }

    // Shuffle edges
    for (i = maxEdges - 1; i > 0; --i)
    {
        int j = rand() % (i + 1);
        Edge temp = edges[i];
        edges[i] = edges[j];
        edges[j] = temp;
    }

    // Take only the number of edges needed
    edges = realloc(edges, sizeof(Edge) * numEdges);
    return edges;
}

/**
 * Given a number of vertices and a number of edges, generates a graph
 * connecting random pairs of vertices. The edges are unique, and thus their is
 * a maximum number of edges allowed in proportion to the number of vertices.
 * numEdges must be in the interval [0, numVertices * (numVertices + 1) / 2].
 * @param numVertices
 * @param numEdges
 * @return
 */
Graph* randomGraph(int numVertices, int numEdges)
{
    assert(numVertices > 0);
    assert(numEdges >= 0);
    assert(numEdges <= numVertices * (numVertices - 1) / 2);

    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;
    graph->vertexSet = malloc(sizeof(Vertex) * numVertices);

    // Initialize vertices
    int i;
    for (i = 0; i < graph->numVertices; ++i)
    {
        Vertex* vertex = &graph->vertexSet[i];
        vertex->label = i;
        vertex->isVisited = 0;
        vertex->numNeighbors = 0;
        vertex->neighbors = NULL;
    }

    // Randomly connect vertices
    Edge* edges = randomEdges(numVertices, numEdges);
    for (i = 0; i < numEdges; ++i)
    {
        Vertex* v1 = &graph->vertexSet[edges[i].i];
        Vertex* v2 = &graph->vertexSet[edges[i].j];
        createEdge(v1, v2);
    }
    free(edges);

    return graph;
}

/**
 * Loads a graph from the given file. The file's first line must be the number
 * of vertices in the graph and each consecutive line must be a list of numbers
 * separated by spaces. The first number is the next vertex and the following
 * numbers are its neighbors.
 * @param fileName
 * @return
 */
Graph* loadGraph(const char* fileName)
{
    FILE* file = fopen(fileName, "r");
    char buffer[512];

    // Get the number of vertices
    fgets(buffer, sizeof buffer, file);
    int numVertices = (int) strtol(buffer, NULL, 10);
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->numEdges = 0;

    // Initialize vertices
    graph->vertexSet = malloc(sizeof(Vertex) * numVertices);
    int i;
    for (i = 0; i < numVertices; ++i)
    {
        Vertex* vertex = &graph->vertexSet[i];
        vertex->isVisited = 0;
        vertex->label = i;
        vertex->neighbors = NULL;
        vertex->numNeighbors = 0;
    }

    // Create edges
    while (fgets(buffer, sizeof buffer, file) != NULL)
    {
        char* begin = buffer;
        char* end = NULL;

        // Get vertex
        int i = (int) strtol(begin, &end, 10);
        Vertex* vertex = &graph->vertexSet[i];
        begin = end;

        // Create edges
        for (i = (int) strtol(begin, &end, 10);
            end != begin;
            i = (int) strtol(begin, &end, 10))
        {
            Vertex* neighbor = &graph->vertexSet[i];
            if (!isAdjacent(vertex, neighbor))
            {
                createEdge(vertex, neighbor);
                ++(graph->numEdges);
            }
            begin = end;
        }
    }
    fclose(file);

    return graph;
}

/**
 * Frees all memory allocated for a graph and the graph itself.
 * @param graph
 */
void freeGraph(Graph* graph)
{
    int i;
    for (i = 0; i < graph->numVertices; ++i)
    {
        free(graph->vertexSet[i].neighbors);
    }
    free(graph->vertexSet);
    free(graph);
}

/**
 * Prints the vertex count, edge count, and adjacency list for each vertex.
 * @param graph
 */
void printGraph(Graph* graph)
{
    printf("Vertex count: %d\n", graph->numVertices);
    printf("Edge count: %d\n", graph->numEdges);
    int i;
    int j;
    for (i = 0; i < graph->numVertices; ++i)
    {
        Vertex* vertex = &graph->vertexSet[i];
        printf("%d :", vertex->label);
        for (j = 0; j < vertex->numNeighbors; ++j)
        {
            printf(" %d", vertex->neighbors[j]->label);
        }
        printf("\n");
    }
}
