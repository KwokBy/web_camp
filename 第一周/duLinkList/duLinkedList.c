#include "C:\Users\kwok\Desktop\�ƿ�3-������-��ҵ���ͣ�ѵ��Ӫ��С�飩-��һ��\��ҵ\�����ͷ�ļ�\head\duLinkedlist.h"
#include<stdio.h>
#include<stdlib.h> 
/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
	(*L)->next = NULL;
	if ((*L)->next == NULL)
		return SUCCESS;
	else
		return ERROR;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
	DuLinkedList p = (*L)->next;
	while (p)
	{
		DuLinkedList q = p;
		p = p->next;
		free(q);
	}
	(*L)->next = NULL;
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
	if (p == NULL || q == NULL)
		return ERROR;
	DuLinkedList h = p->prior;
	h->next = q;
	q->prior = h;
	q->next = p;
	p->prior = q;
	return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	if (p == NULL || q == NULL)
		return ERROR;
	DuLinkedList h = p->next;
	p->next = q;
	q->prior = p;
	q->next = h;
	if(h!=NULL)
	h->prior = q;
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
	if (p->next != NULL)
	{
		DuLinkedList q = p->next;
		*e = q->data;
		p->next = q->next;
		if(q->next!=NULL)
		q->next->prior = p;
		free(q);
		return SUCCESS;
	}
	else
	{
		return ERROR;
	}
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
 void Visit(ElemType e) {
	printf("%d   ", e);
}
void TraverseList_DuL(DuLinkedList L, void (*Visit)(ElemType e)) {
	DuLinkedList p = L->next;
	printf("�������ݮ� :");
	if (p == NULL)
		printf("����Ϊ��!");
	while (p)
	{
		Visit(p->data);
		p = p->next;
	}
	printf("\n");
}

/**
*	@name			:Status Append(LinkedList *L)
*	@description	:Append the list
*	@param			:*L(the head node)
*	@return			:Status
*  @notice		    :None
*/
Status Append(DuLinkedList *L)
{
	DuLinkedList p = (*L);
	int len = 0;  //�ڵ���� 
	int i = 0;
	int val; //�ڵ�ֵ 
	printf("�������Ӽ����ڵ� len = ");
	char n[20];
	scanf("%s", n);
	getchar();
	while (n[0]<'0' || n[0]>'9')
	{
		printf("\n����Ƿ���������\n");
		scanf("%s", n);
		getchar();
	}
	while (n[i] >= '0'&&n[i] <= '9')
	{
		len = (len * 10 + (int)n[i] - 48);
		i++;
	}
	for (i = 0; i < len; ++i)
	{
		printf("�������%d���ڵ��ֵ:  ", i + 1);
		InputError(&val);

		DuLinkedList q = (DuLinkedList)malloc(sizeof(DuLNode));
		q->data = val;
		p->next = q;
		q->prior = p;
		q->next = NULL;
		p = q;
	}
	return SUCCESS;
}
/**
*	@name			:void userInterFace(void)
*	@description	:Select the action you want to perform
*	@param			:Node
*	@return			:Node
*  @notice		    :None
*/
void UserInterFace(void) {
	 printf("******_my list_*******\n");
     printf(" -----------------------");
	 printf("\n |ѡ��Ҫ���еĲ���:\t|\n |1.��������\t\t|\n |2.��������\t\t|\n |3.ɾ������\t\t|\n |4.��������\t|\n" ) ;

}
/**
*	@name			:int count(DuLinkedList L)
*	@description	:Count the node
*	@param			: L(the head node)
*	@return			:n
*  @notice		    :None
*/
int Count(DuLinkedList L)
{
	int n = 0;
	DuLinkedList p;
	for (p = L->next; p != NULL; p = p->next)
		n++;
	return n;
}
/**
*	@name			:void select(int n)
*	@description	:Select the action you want to perform
*	@param			:n
*	@return			:Node
*  @notice		    :None
*/
void Select(DuLinkedList *L)
{
	char n[20];
	printf("\n������������Ĳ���:");
	scanf("%s", n);
	getchar();
	while (n[0]<'1' || n[0]>'4')
	{
		printf("\n����Ƿ������������룺n");
		scanf("%s", n);
		getchar();
	}
	void *pFun;
	pFun = &Visit;
	system("cls");
	switch ((int)n[0] - 48)
	{
	case 1:
	{
		DestroyList_DuL(L);
		printf("���ٳɹ�\n");
		break;
	}
	case 2:
	{
		TraverseList_DuL(*L, pFun);
		printf("�������������Ľڵ�����");
		DuLinkedList q = (DuLinkedList)malloc(sizeof(DuLNode));
		InputError(&q->data);
		if ((*L)->next == NULL)
		{
			printf("����Ϊ�գ��Զ������׸�λ��\n");
			(*L)->next = q;
			q->next = NULL;
		}
		else
		{
			//���λ�� 
			int pos, i = 0;
			DuLinkedList p = (*L);
			printf("��������ĸ�λ��:");
			InputError(&pos);
			while (pos<1 || pos>Count(*L))
			{
				printf("�����������������:\n");
				InputError(&pos);
			}
			printf("����ѡ��ǰ�廹�Ǻ�壨1.ǰ��/2.��壩");
			InputError(&i);
			while (i != 1 && i != 2)
			{
				printf("����������������룺");
				InputError(&i);
			}
			while (pos--)
			{
				p = p->next;
			}
			if (i == 1)
			{
				if (InsertBeforeList_DuL(p, q))
					printf("����ɹ���\n");
				else
					printf("����ʧ�ƣ�\n");
			}
			else
			{
				if (InsertAfterList_DuL(p, q))
					printf("����ɹ���\n");
				else
					printf("����ʧ�ƣ�\n");
			}
		}
		TraverseList_DuL(*L, pFun);
		break;
	}
	case 3:
	{
		int pos, val;
		DuLinkedList p = (*L);
		printf("����ɾ���ĸ�λ��:");
		InputError(&pos);
		while (pos<0 || pos>Count(*L))
		{
			printf("�����������������:\n");
			InputError(&pos);
		}
		while (--pos)
		{
			p = p->next;
		}
		if (DeleteList_DuL(p, &val))
			printf("����ɾ���ɹ���ɾ���ڵ�Ϊ��\n", val);
		else
			printf("ɾ��ʧ��!\n");
		break;
	}
	case 4:
	{
		TraverseList_DuL(*L, pFun);
		break;
	}
	}
}
/**
*	@name		:void Visit(ElemType e)
*	@description:visit the node and get the data
*	@param		:e
*	@return     :None
*	@notice		:None
*/


void InputError(int *val)
{
	char n[20];
	int i = 0;
	*val = 0;
	scanf("%s", n);
	getchar();
	while (n[0]<'0' || n[0]>'9')
	{
		printf("\n����������������룡\n");
		scanf("%s", n);
		getchar();
	}
	while (n[i] >= '0'&&n[i] <= '9')
	{
		*val = (*val * 10 + (int)n[i] - 48);
		i++;
	}
}
