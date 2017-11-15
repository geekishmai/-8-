//#include <iostream>  
//#include <cmath>  
//#include <cstdlib>  
//#include <cstdio>  
//#include <cstring>  
//using namespace std;
//const unsigned int M = 1001;
//int dir[4][2] = {
//	1, 0, // Down  
//	-1, 0, // Up  
//	0,-1, // Left  
//	0, 1 // Right  
//};
//typedef struct STATUS {
//	int arr[3][3];
//	int r, c;
//}STATUS;
//char dirCode[] = { "dulr" };
//char rDirCode[] = { "udrl" };
//char path[M]; // 最优解  
//STATUS begin, end = { 1,2,3,4,5,6,7,8,0,2,2 }; // 起始和终止状态  
//int maxDepth = 0; // 深度边界  
//int diff(const STATUS &cur) // 启发函数  
//{
//	int i, j, k, m, ans = 0;
//	for (i = 0; i <= 2; i++)
//		for (j = 0; j <= 2; j++)
//		{
//			if (cur.arr[i][j] != 0)
//			{
//				for (k = 0; k <= 2; k++)
//					for (m = 0; m <= 2; m++)
//					{
//						if (cur.arr[i][j] == end.arr[k][m])
//						{
//							ans += abs(i - k) + abs(j - m);
//							break;
//						}
//					}
//			}
//		}
//	return ans;
//}
//bool dfs(STATUS &cur, int depth, int h, char preDir)
//{
//	if (memcmp(&cur, &end, sizeof(STATUS)) == 0)
//	{ // OK找到解了:)  
//		path[depth] = '/0';
//		return true;
//	}
//	if (depth + h > maxDepth) return false; // 剪枝  
//	STATUS nxt; // 下一状态  
//	for (int i = 0; i<4; i++)
//	{
//		if (dirCode[i] == preDir) continue; // 回到上次状态,剪枝  
//		nxt = cur;
//		nxt.r = cur.r + dir[i][0];
//		nxt.c = cur.c + dir[i][1];
//		if (!(nxt.r >= 0 && nxt.r < 3 && nxt.c >= 0 && nxt.c < 3))
//			continue;
//		int nxth = h;
//		int preLen, Len, desNum = cur.arr[nxt.r][nxt.c], desR = (desNum - 1) / 3, desC = (desNum - 1) % 3;
//		preLen = abs(nxt.r - desR) + abs(nxt.c - desC);
//		Len = abs(cur.r - desR) + abs(cur.c - desC);
//		nxth = h - preLen + Len;
//		swap(nxt.arr[cur.r][cur.c], nxt.arr[nxt.r][nxt.c]);
//		path[depth] = dirCode[i];
//		if (dfs(nxt, depth + 1, nxth, rDirCode[i]))
//			return true;
//	}
//	return false;
//}
//int IDAstar()
//{
//	int nh = diff(begin);
//	maxDepth = nh;
//	while (!dfs(begin, 0, nh, '/0'))
//		maxDepth++;
//	return maxDepth;
//}
//void Input()
//{
//	char ch;
//	int i, j;
//	for (i = 0; i < 3; i++) {
//		for (j = 0; j < 3; j++) {
//			do {
//				scanf("%c", &ch);
//			} while (!((ch >= '1' && ch <= '8') || (ch == 'x')))
//				;
//			if (ch == 'x') {
//				begin.arr[i][j] = 0;
//				begin.r = i;
//				begin.c = j;
//			}
//			else
//				begin.arr[i][j] = ch - '0';
//		}
//	}
//}
//bool IsSolvable(const STATUS &cur)
//{
//	int i, j, k = 0, s = 0;
//	int a[8];
//	for (i = 0; i < 3; i++) {
//		for (j = 0; j < 3; j++) {
//			if (cur.arr[i][j] == 0) continue;
//			a[k++] = cur.arr[i][j];
//		}
//	}
//	for (i = 0; i < 8; i++) {
//		for (j = i + 1; j < 8; j++) {
//			if (a[j] < a[i])
//				s++;
//		}
//	}
//	return (s % 2 == 0);
//}
//int main()
//{
//	Input();
//	if (IsSolvable(begin)) {
//		IDAstar();
//		printf("%s/n", path);
//	}
//	else
//		printf("unsolvable/n");
//	return 0;
//}


//#include"stdio.h"
//#include"stdlib.h"
//#define up 0;
//#define down 1;
//#define left 2;
//#define right 3;
////用二维数组储存节点数据
//int manHattan()
//{
//
//}
////九宫格状态
//typedef struct status
//{
//	int arr[3][3];
//	int r, c;
//};


#include <stdio.h>
#include <stdlib.h>

struct grade {
	int score;
	struct grade *next;
};
typedef struct grade NODE;  //typedef为C语言的关键字，作用是为一种数据类型定义一个新名字。
							//使用typedef目的一般有两个，一个是给变量一个易记且意义明确的新名字，    //grade和NODE等效
							//另一个是简化一些比较复杂的类型声明。
struct grade *create();   //创建链表
void insert(NODE *head, NODE *pnew, int i);   //插入链表
void pdelete(NODE *head, int i);   //删除列表
void display(NODE *head);   //输出链表
void Pfree(NODE *head);    //销毁链表

int main(int argc, char *argv[]) {
	struct grade *head, *pnew;
	head = create();
	if (head == NULL)
		return 0;
	printf("输出创建的链表：");
	display(head);
	pnew = (NODE *)malloc(sizeof(NODE));
	if (pnew == NULL) {
		printf("创建失败！");
		return 0;
	}
	pnew->score = 88;
	insert(head, pnew, 3);   //将新节点插入节点3的后面
	printf("插入后的链表：");
	display(head);
	pdelete(head, 3);   //删除节点3
	printf("删除后的链表：");
	display(head);
	Pfree(head);
	return 0;
}

struct grade *create() {
	NODE *head, *tail, *pnew;
	int score;
	head = (NODE *)malloc(sizeof(NODE));  //创建头节点。
	if (head == NULL) { //创建失败返回
		printf("创建失败！");
		return NULL;
	}
	head->next = NULL;  //头节点指针域置NULL
	tail = head;  // 开始时尾指针指向头节点
	printf("输入学生成绩：");
	while (1) { //创建链表
		scanf("%d", &score);
		if (score<0) //成绩为负是退出循环
			break;
		pnew = (NODE *)malloc(sizeof(NODE));  //创建新节点
		if (pnew == NULL) { //创建失败返回
			printf("创建失败！");
			return NULL;
		}
		pnew->score = score;  //新节点数据域存放输入的成绩
		pnew->next = NULL;   //新节点指针域置NULL
		tail->next = pnew;  //新节点插入到表尾
		tail = pnew;   //为指针指向当前的尾节点
	}
	return head;  //返回创建链表的头指针
}

void insert(NODE *head, NODE *pnew, int i) {
	NODE *p; //当前指针
	int j;

	p = head;
	for (j = 0; j<i&&p != NULL; j++) //p指向要插入的第i个节点
		p = p->next;

	if (p == NULL) { //节点i不存在
		printf("与插入的节点不存在！");
		return;
	}

	pnew->next = p->next;   //插入节点的指针域指向第i个节点的后继节点
	p->next = pnew;    //犟第i个节点的指针域指向插入的新节点
}

void pdelete(NODE *head, int i) {
	NODE *p, *q;
	int j;
	if (i == 0) //删除的是头指针，返回
		return;
	p = head;
	for (j = 1; j<i&&p->next != NULL; j++)
		p = p->next;  //将p指向要删除的第i个节点的前驱节点
	if (p->next == NULL) { //表明链表中的节点不存在
		printf("不存在！");
		return;
	}
	q = p->next;  //q指向待删除的节点
	p->next = q->next;  //删除节点i，也可写成p->next=p->next->next
	free(q);   //释放节点i的内存单元
}
void display(NODE *head) {
	NODE *p;
	for (p = head->next; p != NULL; p = p->next)
		printf("%d ", p->score);
	printf("\n");
}
void pfree(NODE *head) {
	NODE *p, *q;

	p = head;
	while (p->next != NULL) { //每次删除头节点的后继节点
		q = p->next;
		p->next = q->next;
		free(q);
	}
	free(head);   //最后删除头节点
}
void Pfree(NODE *head) {
	NODE *p, *q;
	p = head;
	while (p->next != NULL) {
		q = p->next;
		p->next = q->next;
		free(q);
	}
	free(p);
}
