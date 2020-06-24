#pragma once
#include"БъЭЗ.h"
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<string.h>
#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<cstdio>
typedef struct
{
	sglist* front;
	sglist* fear;
}linkqunode;
void initqueue(linkqunode*& q)
{
	q = (linkqunode*)malloc(sizeof(linkqunode));
	q->front = q->fear = NULL;
}
void destroyqueer(linkqunode*& q)
{
	sglist* pre = q->front, * p=NULL;
	if (pre != NULL)
	{
		p - pre->next;
		while (p!=NULL)
		{
			free(pre);
			pre = p;
			p = p->next;
		}
		free(pre);
	}
	free(q);
}
bool queueempty(linkqunode* q)
{
	return(q->fear == NULL);
}
void enqueue(linkqunode*& q, sglist* g)
{
	sglist* p;
	p = (sglist*)malloc(sizeof(sglist));
	strcpy(p->cname,g->cname);
	strcpy(p->cno,g->cno);
	strcpy(p->major,g->major);
	strcpy(p->sname,g->sname);
	strcpy(p->sno,g->sno);
	p->score = g->score;
	p->next = NULL;
	if (q->fear == NULL)
		q->front = q->fear = p;
	else
	{
		q->fear->next = p;
		q->fear = p;
	}
}
bool dequeue(linkqunode*& q, sglist*&e)
{
	sglist* t;
	if (q->fear == NULL)
		return false;
	t = q->front;
	if (q->front == q->fear)
		q->front = q->fear;
	else
	{
		q->front = q->front->next;
	}
	e = t;
	e->next = NULL;
	free(t);
	return true;
}
