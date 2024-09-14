#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<limits.h>

typedef struct{
    int dist;
    int vertex;
}pq;

typedef struct{
    int size;
    pq *arr;
    int* pos;
}Priority_queue;

int left(int x){
    return 2*x+1;
}

int right(int x){
    return 2*x+2;
}

int parent(int x){
    return (x-1)/2;
}

struct Node{
    int val;
    int wt;
    struct Node* next;
};

struct Graph{
    int n;
    struct Node** vertices;
};

struct Node* createNode(int a,int wt){
    struct Node* newNode=malloc(sizeof(struct Node));
    newNode->val=a;
    newNode->wt=wt;
    newNode->next=NULL;
    return newNode;
}

struct Graph* createGraph(int num){
    struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->n=num;
    graph->vertices=(struct Node**)malloc((graph->n+1)*sizeof(struct Node*));

    for(int i=0;i<=graph->n;i++){
        graph->vertices[i]=NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph,int src,int dest,int wt){
    struct Node* node=createNode(dest,wt);
    node->next=graph->vertices[src];
    graph->vertices[src]=node;

    return;
}

void MinHeapify(Priority_queue* PQ,int index){
    int min=index;
    if(left(index)<PQ->size&&PQ->arr[left(index)].dist<PQ->arr[index].dist){
        min=left(index);
    }
    if(right(index)<PQ->size&&PQ->arr[min].dist>PQ->arr[right(index)].dist){
        min=right(index);
    }

    if(min!=index){
        int temp=PQ->arr[min].dist;
        PQ->arr[min].dist=PQ->arr[index].dist;
        PQ->arr[index].dist=temp;

        temp=PQ->arr[min].vertex;
        PQ->arr[min].vertex=PQ->arr[index].vertex;
        PQ->arr[index].vertex=temp;

        PQ->pos[PQ->arr[index].vertex]=index;
        PQ->pos[PQ->arr[min].vertex]=min;

        MinHeapify(PQ,min);
    }else return;
}

int ExtractMin(Priority_queue* PQ){
    int temp=PQ->arr[0].vertex;
    PQ->arr[0].vertex=PQ->arr[PQ->size-1].vertex;
    PQ->arr[0].dist=PQ->arr[PQ->size-1].dist;
    PQ->pos[temp]=-1;
    PQ->pos[PQ->arr[0].vertex]=0;
    PQ->size--;
    MinHeapify(PQ,0);
    return temp;
}

void Decrease_Key(Priority_queue* PQ,int vertex,int dist){
    if(PQ->pos[vertex]==-1){
        PQ->arr[PQ->size].dist=dist;
        PQ->arr[PQ->size].vertex=vertex;
        PQ->pos[vertex]=PQ->size;
        PQ->size++;
    }

    PQ->arr[PQ->pos[vertex]].dist=dist;
    int index=PQ->pos[vertex];
    while(index>0){
        if(PQ->arr[parent(index)].dist<PQ->arr[index].dist) return;
        else{
            int temp=PQ->arr[parent(index)].dist;
            PQ->arr[parent(index)].dist=PQ->arr[index].dist;
            PQ->arr[index].dist=temp;
            
            temp=PQ->arr[parent(index)].vertex;
            PQ->arr[parent(index)].vertex=PQ->arr[index].vertex;
            PQ->arr[index].vertex=temp;

            PQ->pos[PQ->arr[index].vertex]=index;
            PQ->pos[PQ->arr[parent(index)].vertex]=parent(index);

            index=parent(index);
        }
    }
    return;
}

void InitialisePQ(Priority_queue* PQ,int n){
    PQ->size=0;
    PQ->arr=(pq*)malloc(sizeof(pq)*n);
    PQ->pos=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<=n;i++){
        PQ->arr[i].dist=INT_MAX;
        PQ->pos[i]=-1;
    }
    return;
}

void Dijkstra(struct Graph* graph,int src,int findist[],int parent[]){
    Priority_queue* PQ;
    PQ=(Priority_queue*)malloc(sizeof(Priority_queue));
    InitialisePQ(PQ,graph->n);
    for(int i=0;i<=graph->n;i++){
        findist[i]=INT_MAX;
        parent[i]=-1;
    }
    findist[src]=0;
    Decrease_Key(PQ,src,0);
    while(PQ->size!=0){
        int u=ExtractMin(PQ);
        struct Node* currNode=graph->vertices[u];
        while(currNode!=NULL){
            int w=currNode->val;
            if(findist[w]>findist[u]+currNode->wt){
                findist[w]=findist[u]+currNode->wt;
                parent[w]=u;
                Decrease_Key(PQ,w,findist[w]);
            }
            currNode=currNode->next;
        }
    }
}

void PrintPath(int target,int* parent){
    if(parent[target]==-1){
        printf("%d ",target);
        return;
    }
    PrintPath(parent[target],parent);
    printf("%d ",target);
    return;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    struct Graph* graph=createGraph(n);
    for(int i=0;i<m;i++){
        int src,dest,wt;
        scanf("%d %d %d",&src,&dest,&wt);
        addEdge(graph,src,dest,wt);
    }
    
    int dist[n+1],parent[n+1];
    Dijkstra(graph,1,dist,parent);
    for(int i=1;i<=n;i++){
        printf("%d\n",dist[i]);
        PrintPath(i,parent);
        printf("\n");
    }
}
