#include "../head/linkedList.h"
#include<stdio.h>
#include<stdlib.h> 
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
	(*L)->next = NULL;
	if ((*L)->next == NULL)
		return	SUCCESS;
	else
		return ERROR;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	LinkedList p;
	p = (*L)->next;
	while (p)
	{
		LinkedList q = p;
		p = p->next;
		free(q);
	}
	(*L)->next = NULL;
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
		q->next = p->next;
		p->next = q;
		return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
	if(!p){
		printf("����Ϊ�ղ���ɾ��\n");
		return ERROR;
	} 
    if (p->next != NULL)
	{
		LinkedList q = p->next;
		*e = q->data;
		p->next = q->next;
		free(q);
		return SUCCESS;
	}
	else
	{
		return ERROR;
	}
}

/**
*	@name		:void visit(ElemType e)
*	@description:visit the node and get the data
*	@param		:e
*	@return     :None
*	@notice		:None
*/
void Visit(ElemType e) {
	printf("%d   ", e);
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit 
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*Visit)(ElemType e)) {
	LinkedList p = L->next;
	printf("�������� :");
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
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e 
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	LinkedList p;
	for (p=L->next; p != NULL; p = p->next)
	{
		if (e == p->data)
			return SUCCESS;
	}
	return ERROR;
} 

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list 
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
	if ((*L)->next == NULL)
		return ERROR;
	LinkedList p, q;
	p = (*L)->next;
	q = p->next;
	p->next = NULL;
	while (q)
	{
		LinkedList s = q->next;
		q->next = p;
		p = q;
		q = s;
	}
	(*L)->next = p;
	return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	LinkedList p, q;
	p = L->next;
	if (p == NULL)
		return ERROR;
	q = L->next->next;
	while (q)
	{
		if (p == q)
			return SUCCESS;
		else
		{
			p = p->next;
			q = q->next->next;
		}
	}
	return ERROR;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish 
 */
LNode* ReverseEvenList(LinkedList *L) {
	LinkedList p, q, r;
	int i = 0;
	r = (*L);
	while (r->next != NULL && r->next->next != NULL)
	{
		p = r->next;

		q = p->next;
		p->next = q->next;
		q->next = r->next;
		r->next = q;
		r = p;
		if (r->next == NULL || (r->next != NULL && r->next->next == NULL))
			return *L;
	}
	return *L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish 
 */
LNode* FindMidNode(LinkedList *L) {
	LinkedList p=(*L), q=(*L);
	while (q&&q->next!=NULL)
	{
		p = p->next;
		q = q->next->next;
	}
	return p;
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
     printf("\n |ѡ��Ҫ���еĲ���:\t|\n |1.��������\t\t|\n |2.Ƕ������\t\t|\n |3.ɾ������\t\t|\n |4.��������\t|\n |5.��Ѱ����\t\t|\n |6.��ת����\t\t|\n |7.�ж��Ƿ�ɻ�\t\t|\n |7.��ת����\t\t|\n |8.���м�ڵ�\t\t|\n |9.��תż���ڵ�\t|\n "); 
}

/**
*	@name			:int count(LinkedList L)
*	@description	:Count the node
*	@param			: L(the head node)
*	@return			:n
*  @notice		    :None
*/
int Count(LinkedList L)
{
	int n = 0;
	LinkedList p;
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
void Select(LinkedList *L)
{
	char n[20];
	printf("\n������������Ĳ���:");
	scanf("%s", n);
	getchar();
	while (n[0]<'0'||n[0]>'10')
	{
		printf("\n����������������룺\n");
		scanf("%s", n);
		getchar();
	}
	void *pFun;
	pFun = &Visit;
	system("cls");
	switch ((int)n[0]-48)
	{ 
	case 1:
	{
		DestroyList(L);
		printf("��������ɹ���\n");
		break;
	}
	case 2:
	{
		TraverseList(*L, pFun);
		printf("�������������Ľڵ����ݣ�");
		LinkedList q = (LinkedList)malloc(sizeof(LNode));
		InputError(&q->data);
		if ((*L)->next == NULL)
		{
			printf("����Ϊ�գ��Զ������׸�λ��\n");
			(*L)->next = q;
			q->next = NULL;
		}
		else
		{
			//���û���������ĸ�λ��,i��¼��ǰ�ڵ�λ��
			int pos, i = 0;
			LinkedList p = (*L);
			printf("��������ĸ�λ��:");
			InputError(&pos);
			while (pos<0 || pos>Count(*L))
			{
				printf("�����������������:\n");
				InputError(&pos);
			}

			while (pos--)
			{
				p = p->next;
			}
			if (InsertList(p, q))
				printf("����ɹ���\n");
			else
				printf("����ʧ��!\n");
		}
		TraverseList(*L, pFun);
		break;
	}
	case 3:
	{
		TraverseList(*L, pFun);
		int pos, i = 0, val;
		LinkedList p = (*L);
		if (Count(*L))
		{
			printf("����ɾ���Ǹ��ڵ�?:");
			InputError(&pos);
			while (pos < 0 || pos>Count(*L))
			{
				printf("����������������룺");
				InputError(&pos);
			}
		}
		else
		{
			printf("����Ϊ��!\n");
			break;
		}
		while (--pos)
			p = p->next;
		if (DeleteList(p, &val))
		{
			printf("����ɾ���ɹ���ɾ���Ľڵ�ֵΪ %d.\n", val);
		}
		else
			printf("ɾ��ʧ��!\n");
		break;
	case 4:
		TraverseList(*L, pFun);
		break;
	}
	case 5:
	{
		int i;
		printf("���������ҵ�ֵ:");
		InputError(&i);
		if (SearchList(*L, i))
			printf("�ҵ���!\n");
		else
			printf("�Ҳ����ýڵ�!\n");
		break;
	}
	case 6:
	{
		if (ReverseList(L))
			printf("��ת�ɹ�!\n");
		else
			printf("��תʧ��!\n");
		break;
	}
	case 7:
	{
		if (IsLoopList(*L))
			printf("�ǣ�����һ��ѭ������!\n");
		else
			printf("��!������һ��ѭ������\n");
		break;
	}
	case 8:
	{
		LinkedList p;
		p=FindMidNode(L);
		printf("�м�ֵΪ�� %d\n\n", p->data);
		break;
	}
	case 9:
	{
		ReverseEvenList(L);
		break;
	}
	}
}

void InputError(int *val)
{
	char n[20];
	int i=0;
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
/**
*	@name			:Status Append(LinkedList *L)
*	@description	:Append the list
*	@param			:*L(the head node)
*	@return			:Status
*  @notice		    :None
*/
Status Append(LinkedList *L)
{
	LinkedList p = (*L);
	int len=0;  //���������Ч�ڵ�ĸ���
	int i=0;
	int val; //������ʱ����û�����Ľ���ֵ
	printf("�������ӵĽڵ����: len = ");
	char n[20];
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
		len =(len*10+(int)n[i] - 48);
		i++;
	}
	for (i = 0; i < len; ++i)
	{
		printf("�������%d���ڵ��ֵ: ", i + 1);
		InputError(&val);
		LinkedList q = (LinkedList)malloc(sizeof(LNode));
		q->data = val;
		p->next = q;
		q->next = NULL;
		p = q;
	}
	return SUCCESS;
}
