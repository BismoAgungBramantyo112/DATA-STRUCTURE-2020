#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define V 5


//case 1
void init(int arr[][V]) {
  int i, j;
  for (i = 0; i < V; i++)
    for (j = 0; j < V; j++)
      arr[i][j] = 0;
}


void addEdge(int arr[][V], int i, int j) {
  arr[i][j] = 1;
  arr[j][i] = 1;
}

void print_AdjMatrix(int arr[][V]) {
  int i, j;
  printf("\nAdjacency Matrix For This Graph\n");
  printf("-----------------------------------\n\n");
  
  for (i =0; i<V ; i++){
  	printf("    %d", i);
  }
  printf("\n");
  printf("--------------------------\n");
  for (i = 0; i < V; i++) {
    printf("%d:  ", i);
    for (j = 0; j < V; j++) {
      printf("%d    ", arr[i][j]);
    }
    printf("\n");
  }
  printf("--------------------------\n");
}

//case 2

struct node {
	
  int vertex;
  struct node* next;
  
};
struct node* createNode(int);

struct Graph {
  int numVertices;
  struct node** adjLists;
};

// membuat node
struct node* create_Node(int v) {
  struct node* new_Node = malloc(sizeof(struct node));
  new_Node->vertex = v;
  new_Node->next = NULL;
  return new_Node;
}

// membuat graph
struct Graph* create_A_Graph(int vertices) {
	
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node*));

  int i;
  for (i = 0; i < vertices; i++)
    graph->adjLists[i] = NULL;

  return graph;
}

// Add edge
void add_Edge(struct Graph* graph, int a, int b) {
	
  // Add edge dari a ke b
  struct node* new_Node = create_Node(a);
  new_Node->next = graph->adjLists[b];
  graph->adjLists[b] = new_Node;

  // Add edge dari b ke a
  new_Node = create_Node(b);
  new_Node->next = graph->adjLists[a];
  graph->adjLists[a] = new_Node;
}

// Print graph
void print_Graph(struct Graph* graph) {
  int v; //vertices
  printf("\n Adjacency List of this Graph\n");
  printf(" -------------------------------\n");
  for (v = 0; v < graph->numVertices; v++) 
  {
    struct node* temp = graph->adjLists[v];
    printf("\n Vertex %d: ", v);
    while (temp != NULL) { 
      printf("%d -> ", temp->vertex);
      temp = temp->next;
      if (temp == NULL){
      	printf("NULL");
	  }
    }
    printf("\n");
  }
}

//case 3;

int count[V];

void count_degree(int a[][V]){
	
	int i, j;
	
	for(i=0; i<V ; i++){
		for(j=0 ; j<V ; j++){
		  if(j < V){
		  if(a[i][j] == 1 && a[j][i] == 1){ //jika di matrix bernilai 1
		  	count[i]++;
		  }
		  else{
		  	count[i] = count[i] + 0;
		  }
	     }
		}
	}
	
	printf("\nDegree of all vertices\n");
	printf("-----------------------\n");
	
	for(i=0 ; i<V ; i++){
		printf("Degree of vertex %d: ", i);
		printf("%d\n", count[i]);
	}
	
	for(i=0 ; i<V ; i++){
		count[i]=0; //variabel count di nol kan disetiap index
	}
	
}

//case 4

struct queue{
  int items[V];
  int front;
  int rear;
};

struct queue* create_Queue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
int isEmpty(struct queue* q);
void print_Queue(struct queue* q);

struct node_BFS{
  int vertex;
  struct node_BFS* next;
};
struct node_BFS* createNode_BFS(int);


struct Graph_BFS{
  int numVertices;
  struct node_BFS** adjLists;
  int* visited;
};

// BFS algorithm
void bfs(struct Graph_BFS* graph, int startVertex) {
  struct queue* q = create_Queue();

  graph->visited[startVertex] = 1;
  enqueue(q, startVertex);

  while (!isEmpty(q)) {
    print_Queue(q);
    int currentVertex = dequeue(q);
    printf("\n                            Visited %d\n", currentVertex);

    struct node_BFS* temp = graph->adjLists[currentVertex];

    while (temp) {
      int adjVertex = temp->vertex;

      if (graph->visited[adjVertex] == 0) {
        graph->visited[adjVertex] = 1;
        enqueue(q, adjVertex);
      }
      temp = temp->next;
    }
  }
}

// Creating a node
struct node_BFS* createNode_BFS(int v) {
  struct node_BFS* new_Node = malloc(sizeof(struct node_BFS));
  new_Node->vertex = v;
  new_Node->next = NULL;
  return new_Node;
}

// Creating a graph
struct Graph_BFS* createGraph(int vertices) {
  struct Graph_BFS* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node*));
  graph->visited = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }

  return graph;
}

// Add edge
void addEdge_BFS(struct Graph_BFS* graph, int src, int dest) {
  // Add edge from src to dest
  struct node_BFS* new_Node = createNode_BFS(dest);
  new_Node->next = graph->adjLists[src];
  graph->adjLists[src] = new_Node;

  // Add edge from dest to src
  new_Node = createNode_BFS(src);
  new_Node->next = graph->adjLists[dest];
  graph->adjLists[dest] = new_Node;
}

// Create a queue
struct queue* create_Queue() {
  struct queue* q = malloc(sizeof(struct queue));
  q->front = -1;
  q->rear = -1;
  return q;
}

// Check if the queue is empty
int isEmpty(struct queue* q) {
  if (q->rear == -1)
    return 1;
  else
    return 0;
}

// Adding elements into queue
void enqueue(struct queue* q, int value) {
  if (q->rear == V - 1)
    printf("\nQueue is Full\n");
  else {
    if (q->front == -1)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
  }
}

// Removing elements from queue
int dequeue(struct queue* q) {
  int item;
  if (isEmpty(q)) {
    printf("Queue is empty");
    item = -1;
  } else {
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
      q->front = q->rear = -1;
    }
  }
  return item;
}

// Print the queue
void print_Queue(struct queue* q) {
	
  int i = q->front;

  if (isEmpty(q)) {
    printf("Queue is empty");
  } else {
    printf("\nQueue contains ");
    for (i = q->front; i < q->rear + 1; i++) {
      printf("%d ", q->items[i]);
    }
  }
}

//case 5

struct node_DFS{
  int vertex;
  struct node_DFS* next;
};

struct node_DFS* createNode_DFS(int v);

struct Graph_DFS{
  int numVertices;
  int* visited;
  struct node_DFS** adjLists;
};

// DFS algo
void DFS(struct Graph_DFS* graph, int vertex) {
  struct node_DFS* adjList = graph->adjLists[vertex];
  struct node_DFS* temp = adjList;

  graph->visited[vertex] = 1;
  printf("Visited %d \n", vertex);

  while (temp != NULL) {
    int connectedVertex = temp->vertex;

    if (graph->visited[connectedVertex] == 0) {
      DFS(graph, connectedVertex);
    }
    temp = temp->next;
  }
}

// Create a node
struct node_DFS* createNode_DFS(int v) {
  struct node_DFS* new_Node = malloc(sizeof(struct node));
  new_Node->vertex = v;
  new_Node->next = NULL;
  return new_Node;
}

// Create graph
struct Graph_DFS* createGraph_DFS(int vertices) {
  struct Graph_DFS* graph = malloc(sizeof(struct Graph_DFS));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node_DFS*));

  graph->visited = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }
  return graph;
}

// Add edge
void addEdge_DFS(struct Graph_DFS* graph, int src, int dest) {
  // Add edge from src to dest
  struct node_DFS* new_Node = createNode_DFS(dest);
  new_Node->next = graph->adjLists[src];
  graph->adjLists[src] = new_Node;

  // Add edge from dest to src
  new_Node = createNode_DFS(src);
  new_Node->next = graph->adjLists[dest];
  graph->adjLists[dest] = new_Node;
}


int main() {
	
	int parameter = 1;
	int menu = 0;
	int adjMatrix[V][V]; //matrix untuk case 1
	struct Graph* graph = create_A_Graph(V); //inisiasi case 2
	struct Graph_BFS* graph_BFS = createGraph(V); //inisiasi graph untuk case 4
	struct Graph_DFS* graph_DFS = createGraph_DFS(V);
	
	while (parameter == 1){
	
	printf("GRAPH REPRESENTATION AND TRASVERSAL\n");
	printf("-------------------------------------\n\n\n");
	printf("        1   ---   2\n");
	printf("         \\       / \\   \n");
	printf("          4 --- 3 -- 0 \n\n");
	printf("1. Show Adjancency Matrix\n");
	printf("2. Show Adjacency List\n");
	printf("3. Show Degree of all vertices\n");
	printf("4. Show BFS Traversal from vertex 0\n");
	printf("5. show DFS Traversal from vertex 0\n");
	printf("6. Exit\n\n");
	printf(">> Input Choice: ");
	scanf("%d", & menu);
	
	switch(menu){
		
		case 1:
			
		    init(adjMatrix);
            addEdge(adjMatrix, 0, 3);
            addEdge(adjMatrix, 1, 2);
            addEdge(adjMatrix, 1, 4);
            addEdge(adjMatrix, 2, 3);
            addEdge(adjMatrix, 2, 4);
            addEdge(adjMatrix, 3, 4);

            print_AdjMatrix(adjMatrix);
            getchar();
            getchar();
            system("cls");
            

		break;
		
		case 2: 
		    //input edge di soal (konstan)
		    
            add_Edge(graph, 4, 2);
			add_Edge(graph, 4, 3);
            add_Edge(graph, 4, 1);
			add_Edge(graph, 3, 2);
			add_Edge(graph, 2, 1);
            add_Edge(graph, 0, 3);
            
            print_Graph(graph);
            getchar();
            getchar();
            system("cls");
            
		break;
		
		case 3:
			init(adjMatrix);
            addEdge(adjMatrix, 0, 3);
            addEdge(adjMatrix, 1, 2);
            addEdge(adjMatrix, 1, 4);
            addEdge(adjMatrix, 2, 3);
            addEdge(adjMatrix, 2, 4);
            addEdge(adjMatrix, 3, 4);
            
            count_degree(adjMatrix);
            getchar();
            getchar();
            system("cls");
			break;
			
		case 4:
			
            addEdge_BFS(graph_BFS, 4, 2);
			addEdge_BFS(graph_BFS, 4, 3);
            addEdge_BFS(graph_BFS, 4, 1);
			addEdge_BFS(graph_BFS, 3, 2);
			addEdge_BFS(graph_BFS, 2, 1);
            addEdge_BFS(graph_BFS, 0, 3);
            
            printf("\n\n  BFS Traversal\n");
            printf("  --------------\n");
            bfs(graph_BFS, 0);
            getchar();
            getchar();
            system("cls");
			break;
			
		case 5:
			
			addEdge_DFS(graph_DFS, 0, 3);
			addEdge_DFS(graph_DFS, 1, 2);
			addEdge_DFS(graph_DFS, 2, 3);
			addEdge_DFS(graph_DFS, 4, 2);
      addEdge_DFS(graph_DFS, 4, 3);
			addEdge_DFS(graph_DFS, 4, 1);
            
            printf("\nDFS Traversal\n");
            printf("--------------\n\n");
            DFS(graph_DFS, 0);
            getchar();
            getchar();
            system("cls");
			break;
		case 6:
			printf("\n-----Programm Closed Thank you-----\n");
			parameter = 0;
			break;
		default:
			system("cls");
			break;
	}



}
}
