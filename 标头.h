#pragma once
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<string.h>
#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<cstdio>
typedef struct student
{
	char sno[12] = { '\0' };
	char sname[10] = { '\0' };
	char sex[4] = { '\0' };
	char major[20] = { '\0' };
	struct student* next;
}stdudentlist;
typedef struct Stable
{
	int rows;
	int cols;
	stdudentlist* snode;
}stable;
typedef struct course
{
	char cno[10] = { '\0' };
	char cname[20] = { '\0' };
	int classhours;
	struct course* next;
}courselist;
typedef struct Ctable
{
	int rows;
	int cols;
	courselist* cnode;
}ctable;
typedef struct grade
{
	char sno[12] = { '\0' };
	char cno[10] = { '\0' };
	int score;
	struct grade* next;
}gradelist;
typedef struct Gtable
{
	int rows;
	int cols;
	gradelist* gnode;
}gtable;
typedef struct sgrade
{
	char sno[12] = { '\0' };
	char cno[10] = { '\0' };
	char sname[10] = { '\0' };
	char major[20] = { '\0' };
	char cname[20] = { '\0' };
	int score;
	struct sgrade* next;
}sglist;

void write_student()
{
	FILE* fp;
	fp = fopen("student.txt", "w");
	if (fp == NULL)
	{
		printf("erro!");
		fclose(fp);
		return;
	}
	stdudentlist p;
	p.next = NULL;
	for (int i = 0; i < 10; i++)
	{
		scanf("%s %s %s %s", &p.sno, &p.sname, &p.sex, &p.major);
		fprintf(fp, "%s\t%s\t%s\t%s\n", p.sno, p.sname, p.sex, p.major);
	}
	fclose(fp);
}
void write_course()
{
	FILE* fp;
	fp = fopen("course.txt", "w");
	if (fp == NULL)
	{
		printf("erro!");
		fclose(fp);
		return;
	}
	courselist p;
	p.next = NULL;
	for (int i = 0; i < 3; i++)
	{
		scanf("%s %s %d", &p.cno, &p.cname, &p.classhours);
		fprintf(fp, "%s\t%s\t%-d\n", p.cno, p.cname, p.classhours);
	}
	fclose(fp);
}
void write_grade()
{
	FILE* fp;
	fp = fopen("grade.txt", "w");
	if (fp == NULL)
	{
		printf("erro!");
		fclose(fp);
		return;
	}
	gradelist p;
	p.next = NULL;
	for (int i = 0; i < 30; i++)
	{
		scanf("%s %s %d", &p.sno, &p.cno, &p.score);
		fprintf(fp, "%s\t%s\t%-d\n", p.sno, p.cno, p.score);
	}
	fclose(fp);
}
void write_sgrade(sglist* p)
{
	FILE* fp;
	fp = fopen("studentGrade.txt", "w");
	if (fp == NULL)
	{
		printf("erro!");
		fclose(fp);
		return;
	}
	if (p == NULL)
		return;
	while (p != NULL)
	{
		fprintf(fp, "%s\t%s\t%s\t%s\t%-d\n", p->sno, p->sname, p->major, p->cname, p->score);
		p = p->next;
	}
	fclose(fp);
}
void print_stable(stable* h)
{
	stdudentlist* p = h->snode;
	printf("Sno\tsname\tsex\tmajor\n");
	while (p != NULL)
	{
		printf("%s\t%s\t%s\t%s\n", p->sno, p->sname, p->sex, p->major);
		p = p->next;
	}
}
void print_student(stdudentlist* h)
{
	stdudentlist* p = h;
	printf("Sno\tsname\tsex\tmajor\n");
	while (p != NULL)
	{
		printf("%s\t%s\t%s\t%s\n", p->sno, p->sname, p->sex, p->major);
		p = p->next;
	}
}
void print_ctable(ctable* h)
{
	courselist* p = h->cnode;
	printf("Sno\tcname       classhours\n");
	while (p != NULL)
	{
		printf("%s\t%s      %-d\n", p->cno, p->cname, p->classhours);
		p = p->next;
	}
}
void print_gtable(gtable* h)
{
	gradelist* p = h->gnode;
	printf("Sno\tcno\tscore\n");
	while (p != NULL)
	{
		printf("%s\t%s\t%-d\n", p->sno, p->cno, p->score);
		p = p->next;
	}
}
void print_sgtable(sglist* h)
{
	sglist* p = h;
	printf("Sno\tsname\tmajor\t\tcname       score\n");
	while (p != NULL)
	{
		printf("%s\t%s\t%s\t%s        %-d\n", p->sno, p->sname, p->major, p->cname, p->score);
		p = p->next;
	}
}
void creatstudent(stable*& l)
{
	FILE* fp;
	fp = fopen("student.txt", "r");
	if (fp == NULL)
	{
		return;
	}
	stdudentlist* p, * r = NULL;
	l = (stable*)malloc(sizeof(stable));
	l->snode = NULL;
	l->rows = 10;
	l->cols = 4;
	for (int i = 0; i < l->rows; i++)
	{
		p = (stdudentlist*)malloc(sizeof(stdudentlist));
		fscanf(fp, "%s %s %s %s", &p->sno, &p->sname, &p->sex, &p->major);
		if (l->snode == NULL)
			l->snode = p;
		else
		{
			r->next = p;
		}
		r = p;
	}
	r->next = NULL;
	fclose(fp);
}
void creatcourse(ctable*& s)
{
	FILE* fp;
	fp = fopen("course.txt", "r");
	if (fp == NULL)
	{
		return;
	}
	courselist* p, * r = NULL;
	s = (ctable*)malloc(sizeof(ctable));
	s->cnode = NULL;
	s->rows = 3;
	s->cols = 3;
	for (int i = 0; i < s->rows; i++)
	{
		p = (courselist*)malloc(sizeof(courselist));
		fscanf(fp, "%s %s %d", &p->cno, &p->cname, &p->classhours);
		if (s->cnode == NULL)
			s->cnode = p;
		else
		{
			r->next = p;
		}
		r = p;
	}
	r->next = NULL;
	fclose(fp);
}
void creatgrade(gtable*& s)
{
	FILE* fp;
	fp = fopen("grade.txt", "r");
	if (fp == NULL)
	{
		return;
	}
	gradelist* p, * r = NULL;
	s = (gtable*)malloc(sizeof(gtable));
	s->gnode = NULL;
	s->rows = 30;
	s->cols = 3;
	for (int i = 0; i < s->rows; i++)
	{
		p = (gradelist*)malloc(sizeof(gradelist));
		fscanf(fp, "%s %s %d", &p->sno, &p->cno, &p->score);
		if (s->gnode == NULL)
			s->gnode = p;
		else
		{
			r->next = p;
		}
		r = p;
	}
	r->next = NULL;
	fclose(fp);
}

void sort_student(stable*& l)
{
	stdudentlist* cur, * end, * next, * pre, * temp, * head;
	head = (stdudentlist*)malloc(sizeof(stdudentlist));
	head->next = l->snode;
	end = NULL;
	while (head->next->next != end)
	{
		pre = head;
		cur = pre->next;
		next = cur->next;
		while (next != end)
		{
			if (strcmp(cur->sno, next->sno) > 0)
			{
				cur->next = next->next;
				pre->next = next;
				next->next = cur;
				temp = next;
				next = cur;
				cur = temp;
			}
			pre = pre->next;
			cur = cur->next;
			next = next->next;
		}
		end = cur;
	}
	l->snode = head->next;
	free(head);
	pre = NULL; cur = NULL; next = NULL; end = NULL; temp = NULL; head = NULL;
}
void sort_course(ctable*& l)
{
	courselist* cur, * end, * next, * pre, * temp, * head;
	head = (courselist*)malloc(sizeof(courselist));
	head->next = l->cnode;
	end = NULL;
	while (head->next->next != end)
	{
		pre = head;
		cur = pre->next;
		next = cur->next;
		while (next != end)
		{
			if (strcmp(cur->cno, next->cno) > 0)
			{
				cur->next = next->next;
				pre->next = next;
				next->next = cur;
				temp = next;
				next = cur;
				cur = temp;
			}
			pre = pre->next;
			cur = cur->next;
			next = next->next;
		}
		end = cur;
	}
	l->cnode = head->next;
	free(head);
	pre = NULL; cur = NULL; next = NULL; end = NULL; temp = NULL; head = NULL;
}
void sort_grade(gtable*& l)
{
	gradelist* cur, * end, * next, * pre, * temp, * head;
	head = (gradelist*)malloc(sizeof(gradelist));
	head->next = l->gnode;
	end = NULL;
	while (head->next->next != end)
	{
		pre = head;
		cur = pre->next;
		next = cur->next;
		while (next != end)
		{
			if (strcmp(cur->sno, next->sno) > 0)
			{
				cur->next = next->next;
				pre->next = next;
				next->next = cur;
				temp = next;
				next = cur;
				cur = temp;
			}
			if (strcmp(cur->sno, next->sno) == 0)
			{
				if (strcmp(cur->cno, next->cno) > 0)
				{
					cur->next = next->next;
					pre->next = next;
					next->next = cur;
					temp = next;
					next = cur;
					cur = temp;
				}
			}
			pre = pre->next;
			cur = cur->next;
			next = next->next;
		}
		end = cur;
	}
	l->gnode = head->next;
	free(head);
	pre = NULL; cur = NULL; next = NULL; end = NULL; temp = NULL; head = NULL;
}
void sort_sgrade(sglist*& l)
{
	sglist* cur, * end, * next, * pre, * temp, * head;
	head = (sglist*)malloc(sizeof(sglist));
	head->next = l;
	end = NULL;
	while (head->next->next != end)
	{
		pre = head;
		cur = pre->next;
		next = cur->next;
		while (next != end)
		{
			if (cur->score < next->score)
			{
				cur->next = next->next;
				pre->next = next;
				next->next = cur;
				temp = next;
				next = cur;
				cur = temp;
			}
			pre = pre->next;
			cur = cur->next;
			next = next->next;
		}
		end = cur;
	}
	l = head->next;
	free(head);
	pre = NULL; cur = NULL; next = NULL; end = NULL; temp = NULL; head = NULL;
}
void search_grade_A(sglist* sg, sglist*& p, char a[])
{
	sglist* s = NULL, * end = NULL, * l = sg;
	p = (sglist*)malloc(sizeof(sglist));
	p = NULL;
	while (l != NULL)
	{
		if (strcmp(l->cno, a) == 0)
		{
			s = (sglist*)malloc(sizeof(sglist));
			strcpy(s->cname, l->cname);
			strcpy(s->sname, l->sname);
			strcpy(s->sno, l->sno);
			strcpy(s->cno, l->cno);
			strcpy(s->major, l->major);
			s->score = l->score;
			if (p == NULL)
				p = s;
			else
			{
				end->next = s;
			}
			end = s;
		}
		l = l->next;
	}
	if (s == NULL)
	{
		printf("There is no such date!");
		return;
	}
	end->next = NULL;
	l = NULL;
}
void serch_fail(sglist* sg, sglist*& p, char a[])
{
	sglist* end = NULL, * s, * l = sg;
	p = (sglist*)malloc(sizeof(sglist));
	p = NULL;
	while (l != NULL)
	{
		if (strcmp(l->cno, a) == 0)
		{
			if (l->score < 60)
			{
				s = (sglist*)malloc(sizeof(sglist));
				strcpy(s->cname, l->cname);
				strcpy(s->sname, l->sname);
				strcpy(s->sno, l->sno);
				strcpy(s->major, l->major);
				strcpy(s->cno, l->cno);
				s->score = l->score;
				if (p == NULL)
					p = s;
				else
				{
					end->next = s;
				}
				end = s;
			}
		}
		l = l->next;
	}
	if (p == NULL)
	{
		printf("There is no student fail!");
		return;
	}
	end->next = NULL;
	l = NULL;
}
void destroy_student(stable*& l)
{
	stdudentlist* pre = l->snode, * p = pre->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
	free(l);
}
void destroy_course(ctable*& l)
{
	courselist* pre = l->cnode, * p = pre->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
	free(l);
}
void destroy_grade(gtable*& l)
{
	gradelist* pre = l->gnode, * p = pre->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
	free(l);
}
void destroy_sglist(sglist*& l)
{
	sglist* pre = l, * p = pre->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
}