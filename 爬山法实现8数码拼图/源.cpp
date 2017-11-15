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
//char path[M]; // ���Ž�  
//STATUS begin, end = { 1,2,3,4,5,6,7,8,0,2,2 }; // ��ʼ����ֹ״̬  
//int maxDepth = 0; // ��ȱ߽�  
//int diff(const STATUS &cur) // ��������  
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
//	{ // OK�ҵ�����:)  
//		path[depth] = '/0';
//		return true;
//	}
//	if (depth + h > maxDepth) return false; // ��֦  
//	STATUS nxt; // ��һ״̬  
//	for (int i = 0; i<4; i++)
//	{
//		if (dirCode[i] == preDir) continue; // �ص��ϴ�״̬,��֦  
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
////�ö�ά���鴢��ڵ�����
//int manHattan()
//{
//
//}
////�Ź���״̬
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
typedef struct grade NODE;  //typedefΪC���ԵĹؼ��֣�������Ϊһ���������Ͷ���һ�������֡�
							//ʹ��typedefĿ��һ����������һ���Ǹ�����һ���׼���������ȷ�������֣�    //grade��NODE��Ч
							//��һ���Ǽ�һЩ�Ƚϸ��ӵ�����������
struct grade *create();   //��������
void insert(NODE *head, NODE *pnew, int i);   //��������
void pdelete(NODE *head, int i);   //ɾ���б�
void display(NODE *head);   //�������
void Pfree(NODE *head);    //��������

int main(int argc, char *argv[]) {
	struct grade *head, *pnew;
	head = create();
	if (head == NULL)
		return 0;
	printf("�������������");
	display(head);
	pnew = (NODE *)malloc(sizeof(NODE));
	if (pnew == NULL) {
		printf("����ʧ�ܣ�");
		return 0;
	}
	pnew->score = 88;
	insert(head, pnew, 3);   //���½ڵ����ڵ�3�ĺ���
	printf("����������");
	display(head);
	pdelete(head, 3);   //ɾ���ڵ�3
	printf("ɾ���������");
	display(head);
	Pfree(head);
	return 0;
}

struct grade *create() {
	NODE *head, *tail, *pnew;
	int score;
	head = (NODE *)malloc(sizeof(NODE));  //����ͷ�ڵ㡣
	if (head == NULL) { //����ʧ�ܷ���
		printf("����ʧ�ܣ�");
		return NULL;
	}
	head->next = NULL;  //ͷ�ڵ�ָ������NULL
	tail = head;  // ��ʼʱβָ��ָ��ͷ�ڵ�
	printf("����ѧ���ɼ���");
	while (1) { //��������
		scanf("%d", &score);
		if (score<0) //�ɼ�Ϊ�����˳�ѭ��
			break;
		pnew = (NODE *)malloc(sizeof(NODE));  //�����½ڵ�
		if (pnew == NULL) { //����ʧ�ܷ���
			printf("����ʧ�ܣ�");
			return NULL;
		}
		pnew->score = score;  //�½ڵ�������������ĳɼ�
		pnew->next = NULL;   //�½ڵ�ָ������NULL
		tail->next = pnew;  //�½ڵ���뵽��β
		tail = pnew;   //Ϊָ��ָ��ǰ��β�ڵ�
	}
	return head;  //���ش��������ͷָ��
}

void insert(NODE *head, NODE *pnew, int i) {
	NODE *p; //��ǰָ��
	int j;

	p = head;
	for (j = 0; j<i&&p != NULL; j++) //pָ��Ҫ����ĵ�i���ڵ�
		p = p->next;

	if (p == NULL) { //�ڵ�i������
		printf("�����Ľڵ㲻���ڣ�");
		return;
	}

	pnew->next = p->next;   //����ڵ��ָ����ָ���i���ڵ�ĺ�̽ڵ�
	p->next = pnew;    //���i���ڵ��ָ����ָ�������½ڵ�
}

void pdelete(NODE *head, int i) {
	NODE *p, *q;
	int j;
	if (i == 0) //ɾ������ͷָ�룬����
		return;
	p = head;
	for (j = 1; j<i&&p->next != NULL; j++)
		p = p->next;  //��pָ��Ҫɾ���ĵ�i���ڵ��ǰ���ڵ�
	if (p->next == NULL) { //���������еĽڵ㲻����
		printf("�����ڣ�");
		return;
	}
	q = p->next;  //qָ���ɾ���Ľڵ�
	p->next = q->next;  //ɾ���ڵ�i��Ҳ��д��p->next=p->next->next
	free(q);   //�ͷŽڵ�i���ڴ浥Ԫ
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
	while (p->next != NULL) { //ÿ��ɾ��ͷ�ڵ�ĺ�̽ڵ�
		q = p->next;
		p->next = q->next;
		free(q);
	}
	free(head);   //���ɾ��ͷ�ڵ�
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
