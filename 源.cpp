#include"标头.h"
#include"queue.h"
#include"zhan.h"
void reverser_order(stable* l,sqstack*&q,stdudentlist*&s)
{
	s = (stdudentlist*)malloc(sizeof(stdudentlist));
	s = NULL;
	stdudentlist*end=NULL,*r,*p;
	p = l->snode;
	while (p!=NULL)
	{
		push(q, p);
		p = p->next;
	}
	while (!stackempty(q))
	{
		r= (stdudentlist*)malloc(sizeof(stdudentlist));
		if (pop(q, r)) {
			if (s == NULL)
			{
				s = r;
			}
			else
			{
				end->next = r;
			}
			end = r;
		}
	}
}
void creatsg(stable*& s, ctable*& c, gtable*& g, sglist*& l)
{
	sort_grade(g);
	sort_course(c);
	sort_student(s);
	gradelist* gg = g->gnode;
	courselist* cc = c->cnode;
	stdudentlist* ss = s->snode;
	sglist* p, * end = NULL;
	l = NULL;
	while(gg!=NULL)
	{
		p = (sglist*)malloc(sizeof(sglist));
		p->score = gg->score;
		strcpy(p->sno, gg->sno);
		strcpy(p->cno, gg->cno);
		strcpy(p->sname, ss->sname);
		strcpy(p->major, ss->major);
		strcpy(p->cname, cc->cname);
		if (l == NULL)
			l = p;
		else
		{
			end->next = p;
		}
		cc = cc->next;
		ss = ss->next;
		if (cc == NULL)
			cc = c->cnode;
		if (ss == NULL)
			ss = s->snode;
		gg = gg->next;
		end = p;
	}
	end->next = NULL;
}
void trans_to_queue(sglist* sg,linkqunode*&l)
{
	initqueue(l);
	sglist* end;
	end = sg;
	while (end != NULL)
	{
		enqueue(l, end);
		end = end->next;
	}
}

int main()
{
	printf("*******************************************\n");
	printf("欢迎来到学生成绩管理系统！\n");
	printf("现在先按照系统要求进行系统的初始化，输入目标数据\n");
	stable* l;
	FILE* fp;
	printf("Please enter the imformation of students:\n");
	write_student();
	creatstudent(l);
	sort_student(l);
	print_stable(l);
	printf("\n");


	ctable* c;
	printf("Please enter the imformation of courses:\n");
	write_course();
	creatcourse(c);
	sort_course(c);
	print_ctable(c);
	printf("\n");


	gtable* g;
	printf("Please enter the imformation of grades:\n");
	write_grade();
	creatgrade(g);
	sort_grade(g);
	print_gtable(g);
	printf("\n");
	while (1) {
		printf("*******************************************\n");
		printf("1、查询全部学生各课程成绩并输出\n");
		printf("2、查询指定课程数据并输出\n");
		printf("3、查询指定课程不及格学生数据并输出\n");
		printf("4、逆序输出学生信息\n");
		printf("5、退出\n");
		printf("请输入你的选择（纯数字）：\n");
		int u;
		if (scanf("%d", &u) != 1)
			printf("请按要求输入!");
		if (u == 5)
			break;
		switch (u)
		{
		case 1: {
			sglist* sg;
			creatsg(l, c, g, sg);
			sort_sgrade(sg);
			write_sgrade(sg);
			print_sgtable(sg);
			printf("\n");
		}; break;
		case 2: {
			sglist* sg;
			creatsg(l, c, g, sg);
			sort_sgrade(sg);

			sglist* search_A;
			char A[4] = { '\0' };
			printf("the course imformation you want to search:\n");
			scanf("%s", &A);
			search_grade_A(sg, search_A, A);
			if (search_A != NULL)
				print_sgtable(search_A);
			printf("\n");
		}; break;
		case 3:
		{
			sglist* sg;
			creatsg(l, c, g, sg);
			sort_sgrade(sg);

			sglist* search_60;
			char fail[10] = { '\0' };
			printf("Please enter the cno you want to search:\n");
			scanf("%s", &fail);
			printf("these are the fial student:\n");
			serch_fail(sg, search_60, fail);
			if (search_60 != NULL)
				print_sgtable(search_60);
			printf("\n");
		}; break;
		case 4:
		{
			stdudentlist* std;
			sqstack* q;
			initstack(q);
			reverser_order(l, q, std);
			print_student(std);
			printf("\n");
			destraystack(q); q = NULL;
		}
		}
	}
	sglist* sg;
	creatsg(l, c, g, sg);
	sort_sgrade(sg);

	linkqunode* i;
	trans_to_queue(sg, i);

	destroy_course(c); c = NULL;
	destroy_grade(g); g = NULL;
	destroy_sglist(sg); sg = NULL;
	destroyqueer(i); i = NULL;
	destroy_student(l); l = NULL;

	system("pause");
	
}