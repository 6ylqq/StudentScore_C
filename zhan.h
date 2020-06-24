#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<string.h>
#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<cstdio>
#define M 1000
typedef struct
{
	stdudentlist *date[M];
	int top;
}sqstack;
void initstack(sqstack*& s)
{
	s = (sqstack*)malloc(sizeof(sqstack));
	s->top = -1;
}
void destraystack(sqstack*& s)
{
	free(s);
}
bool stackempty(sqstack* s)
{
	return(s->top == -1);
}
bool push(sqstack * &s, stdudentlist *e)
{
	if (s->top == M - 1)
		return false;
	s->top++;
	stdudentlist* p;
	p = (stdudentlist*)malloc(sizeof(stdudentlist));
	strcpy(p->major, e->major);
	strcpy(p->sex, e->sex);
	strcpy(p->sname, e->sname);
	strcpy(p->sno, e->sno);
	s->date[s->top] = p;
	p->next = NULL;
	return true;
}
bool pop(sqstack * &s, stdudentlist*& e)
{
	if (s->top == -1)
		return false;
	e = s->date[s->top];
	s->top--;
	return true;
}
bool gettop(sqstack * s, stdudentlist*& e)
{
	if (s->top == -1)
		return false;
	e = s->date[s->top];
	return true;
}