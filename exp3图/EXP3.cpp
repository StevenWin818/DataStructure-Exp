#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
const int max_n = 100;
bool vi[max_n];
int num[max_n] = { 0 };
queue<int>q;
typedef struct ArcNode
{
	char adjvex;//�û���ָ��Ķ����λ�� 
	struct ArcNode *nextarc;//ָ����һ������ָ�� 
}ArcNode; //���� 
typedef struct VNode
{
	char data;//������Ϣ 
	ArcNode *firstarc;//ָ���һ�������ö���Ļ���ָ�� 
}VNode/*ͷ���*/,AdjList[max_n]; 
typedef struct
{ 
	AdjList vertices;
	int vexnum,arcnum;//�����ʵ�������ߵ�ʵ����
}AlGraph;
int locat(AlGraph g, char v) {
    for (int i = 0; i < g.vexnum; i++) {
        if (g.vertices[i].data == v)
            return i;
    }
}
void creatGraph(AlGraph& g) {
    ArcNode* p1;
    ArcNode* p2;
    printf("������ͼ�Ķ�������ͱߵ�������\n");
    cin >> g.vexnum >> g.arcnum;
    printf("�����붥�����Ϣ��\n"); 
    for (int i = 0; i < g.vexnum; i++) {
    	cin >> g.vertices[i].data;
        g.vertices[i].firstarc = NULL;
    }
    char v1, v2;
    printf("�����뻡��������������\n");
    for (int j = 0; g.arcnum > j; j++) {
    	cin >> v1 >> v2;
        char a = locat(g, v1);//v1��λ�� 
        char b = locat(g, v2);//v2��λ�� 
        p1 = new ArcNode;
        p2 = new ArcNode;
        p1->adjvex = b;
        p1->nextarc = g.vertices[a].firstarc;
        g.vertices[a].firstarc = p1;
        
        p2->adjvex = a;
        p2->nextarc = g.vertices[b].firstarc;
        g.vertices[b].firstarc = p2;
        num[a] =num[a] + 1;//�ȼ�һ 
        num[b] =num[b] + 1;
    }
}
void dfs(AlGraph g, int v) {
	printf("%c",g.vertices[v].data);
    vi[v] = true;
    ArcNode* p;
    p = g.vertices[v].firstarc;
    while (p != NULL) {
        int w = p->adjvex;
        if (!vi[w])
            dfs(g, w);
        p = p->nextarc;
    }
}
void bfs(AlGraph g, int v) {
	printf("%c",g.vertices[v].data);
    vi[v] = true;
    q.push(v);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ArcNode* p;
        p = g.vertices[u].firstarc;
        while (p != NULL) {
            if (!vi[p->adjvex]) {
                cout << g.vertices[p->adjvex].data;
                vi[p->adjvex] = true;
                q.push(p->adjvex);
            }
            p = p->nextarc;
        }
    }
}
int main() {
    AlGraph g;
    creatGraph(g);
    int n = 0;
	for(         )//�������
    	printf("��%c�Ķ�Ϊ��%d\n",g.vertices[n].data,num[n]);
    printf("�������������\n");
    dfs(g, 0);
    for (        )//�������
    {
        vi[i] = false;
    }
    printf("\n�������������\n"); 
    bfs(g, 0);
    return 0;
}
