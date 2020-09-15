#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
 
// 간선 구조체
// src = 시작점, dest = 도착점, weight = 가중치
struct Edge
{
    int src, dest, weight;
};
 
// 그래프 구조체
// V :: 정점의 수 E :: 간선의 수
// edge :: 포인터 형식으로 서로 다른 정점을 연결하기 위해 존재
struct Graph
{
    int V, E;
 
    struct Edge* edge;
};
 
// V와 E를 통해 정점과 간선의 수를 가진 그래프를 생성한다.
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
 
    graph->V = V;
    graph->E = E;
 
    graph->edge = (struct Edge*) malloc(graph->E * sizeof(struct Edge));
 
    return graph;
}
 
// 결과를 출력하기 위한 함수
void printArr(int dist[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
        dist[i] == INT_MAX ? printf("%d \t\tINF\n", i) : printf("%d \t\t %d\n", i, dist[i]);
}
 
// src에서 모든 다른 정점까지의 최단 거리를 찾아주는 BellmanFord 함수이다.
// 음의 가중치 까지 적용이 가능하다.
void BellmanFord(struct Graph* graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    int *dist = (int*)malloc(sizeof(int)*V); // int dist[V+1]과 같다.
 
                                             // 모든 최단 거리를 무한대로 지정해주고, 시작점(src)만 0으로 초기화 한다.
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
 
    // 벨만 포드 알고리즘
    for (int i = 1; i <= V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            // 정점u가(시작점이) 무한대가 아니고, 
            // 시작점까지의 최단 거리 + 가중치가 도착점의 가중치 
            // 보다 작을 때 업데이트 해준다.
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
 
    // 음의 가중치 때문에 무한히 최단 경로가 작아지는 것이 있다면
    // 탐색하여 알려준다.
    for (int i = 0; i < E; i++)
    {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        // if문에서 현재위치 최단거리 + 가중치가 계속해서 더 작아질 경우
        // 음의 사이클이 있다고 판단한다.
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            printf("Graph contains negative weight cycle\n");
    }
 
    printArr(dist, V);
 
    return;
}
 
 
int main()
{
    int V = 5;  // 정점의 수
    int E = 9;  // 간선의 수
    struct Graph* graph = createGraph(V, E);
 
    // 그래프 정보를 입력해준다.
    graph->edge[0].src = 0; // 0에서 
    graph->edge[0].dest = 2; // 2로 가는 간선의
    graph->edge[0].weight = 1; // 가중치는 1로 정한다.
 
    graph->edge[1].src = 0;
    graph->edge[1].dest = 3;
    graph->edge[1].weight = 5;
 
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = -2;
 
    graph->edge[3].src = 2;
    graph->edge[3].dest = 1;
    graph->edge[3].weight = 4;
 
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;
 
    graph->edge[5].src = 3;
    graph->edge[5].dest = 0;
    graph->edge[5].weight = -1;
 
    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = 3;
 
    graph->edge[7].src = 4;
    graph->edge[7].dest = 0;
    graph->edge[7].weight = 1;
 
    graph->edge[8].src = 4;
    graph->edge[8].dest = 2;
    graph->edge[8].weight = -1;
 
    BellmanFord(graph, 0);
 
    return 0;
}
