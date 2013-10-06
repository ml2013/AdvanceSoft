
/********************************************************************/
/* Copyright (C) SSE-USTC, 2013-2014                                */
/*                                                                  */
/*  FILE NAME             :  testlinktabe.c                         */
/*  PRINCIPAL AUTHOR      :  MaLong                               */
/*  SUBSYSTEM NAME        :  LinkTable                              */
/*  MODULE NAME           :  LinkTable                              */
/*  LANGUAGE              :  C                                      */
/*  TARGET ENVIRONMENT    :  ANY                                    */
/*  DATE OF FIRST RELEASE :  2013/09/20                             */
/*  DESCRIPTION           :  test of Link Table                     */
/********************************************************************/

/*
 * Revision log:
 *
 * Created by MaLong,2013/09/20
 * Verified callback and head/next for search by MaLong,2013/09/21
 *
 */
#include "LinkTable.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define SUCCESS 1
#define FAILURE 0

typedef struct student 
{
	int id;
	char name[20];
}tstudent;

int key;
int real_id;

int display(void *data)
{
	if(data == NULL)
		return FAILURE;
	else
	{
		tstudent *node=(tstudent *)(data);
		printf("\nid = %d, name = %s",node->id,node->name) ;
		return SUCCESS;
	}
}

int condition(void *data)
{
	tstudent *node=(tstudent *)(data);
	if(node->id == key)
		return SUCCESS;
	else
		return FAILURE;
}

void* handle()
{
	tstudent *node=(tstudent *)malloc(sizeof(tstudent));
	printf("please input the new id:");
	scanf("%d",&node->id);
	printf("please input the new name:");
	scanf("%s",node->name);
	return node;
}

int position()
{
	return real_id%MAX;
}


void print()
{
	printf("#################################################################\n");
	printf("                    WELCOME TO USER  THIS SYSTEM                 \n");
	printf("         FUNCTION A:Insert Node for the LINK, INPUT     I        \n");
	printf("         FUNCTION B:Search Node for the LINK, INPUT     S        \n");
	printf("         FUNCTION C:Delete Node for the LINK, INPUT     D        \n");
	printf("         FUNCTION D:Change Node for the LINK, INPUT     C        \n");
	printf("         FUNCTION E:Display Node for the LINK, INPUT    P        \n");
	printf("         FUNCTION F:User Other Version , INPUT O       \n");
	printf("         FUNCTION G:Quit This System  , INPUT Q       \n");
	printf("#################################################################\n");
}

int version ()
{
	LinkTable *Link=CreatLinkTableExt();
	tstudent student;

	clock_t start,end;
	double cost;

	char chose;
	int i=0;

	for(i=0;i<1000000;i++)
	{
		student.id=i;
		real_id=i;
		strcpy(student.name,"aaadfadfad");
		InsertNodeExt(Link,&student,sizeof(tstudent),position);
	}
	printf("                    V2.0                 \n");
	print();	
	
	while(1)
	{
		printf("\nplease input you want  to user function !");
		scanf(" %c",&chose);
		if(islower(chose))
		{
			chose=chose-('a'-'A');
		}
		switch(chose)
		{
		case 'I' :	
			{
				printf("please input id:  ");
				scanf("%d",&student.id);
				real_id=student.id;
				printf("please input name:   ");
				scanf("%s",&student.name);
				InsertNodeExt(Link,&student,sizeof(tstudent),position);
			}
				break;
		case 'D':
			{
				printf("\nplease input you want to Delete id:");
				scanf("%d",&key);
				real_id=key;
				if(DeleteNodeExt(Link,position,condition))
				{
					printf(" \t  SUCCESS ");
				}
				else
					printf("\t   ERROR");
			}
				break;
		case 'S':
			{
				printf("\nplease input you want to search id:");
				scanf("%d",&key);
				real_id=key;

				start=clock();

				if(display(SearchNodeExt(Link,condition,position)))
				{

					end=clock();
					cost = (double )(end-start )/CLOCKS_PER_SEC;
					printf(" \t  Search use time :%lf",cost);
				}
				else
					printf("\t   ERROR");
			}
			break;
		case 'C':
			{
				printf("\nplease input you want to Change id:");
				scanf("%d",&key);
				real_id=key;
				printf("%d",sizeof(tstudent));
				UpdataNodeExt(Link,position,condition,handle,sizeof(tstudent));
			}
			break;
		case 'P':
			{
				if( DisplayExt( Link,display) )
				{
					printf("\nSUCCESS");
				}
				else
				{
					printf("ERROR!");
				}
			}
				break;
		case 'Q' :
			return 0;
		}
	}
}

int main()
{
	LinkTable *Link=CreatLinkTable();
	tstudent student;
	char chose;
	int i=0;

	clock_t start,end;
	double cost;
	
	for(i=0;i<1000000;i++)
	{
		student.id=i;
		strcpy(student.name,"aaadfadfad");
		InsertNode(Link,&student,sizeof(tstudent));
	}
	print();
	
	while(1)
	{
		printf("\nplease input you want  to user function !");
		scanf(" %c",&chose);
		if(islower(chose))
		{
			chose=chose-('a'-'A');
		}
		switch(chose)
		{
		case 'I' :	
			{
				printf("please input id:  ");
				scanf("%d",&student.id);
				printf("please input name:   ");
				scanf("%s",&student.name);
				InsertNode(Link,&student,sizeof(tstudent));
			}
				break;
		case 'D':
			{
				printf("\nplease input you want to Delete id:");
				scanf("%d",&key);
				if(DeleteNode(Link,condition))
				{
					printf(" \t  SUCCESS ");
				}
				else
					printf("\t   ERROR");
			}
				break;
		case 'S':
			{
				printf("\nplease input you want to search id:");
				scanf("%d",&key);
				start=clock();
				if(display(SearchNode(Link,condition)))
				{
					end=clock();
					cost = (double )(end-start )/CLOCKS_PER_SEC;
					printf(" \t use time is  %lf  ",cost);
				}
				else
					printf("\t   ERROR");
			}
			break;
		case 'C':
			{
				printf("\nplease input you want to Change id:");
				scanf("%d",&key);
				printf("%d",sizeof(tstudent));
				UpdataNode(Link,condition,handle,sizeof(tstudent));
			}
			break;
		case 'P':
			{
				if( Display(Link,display) )
				{
					printf("\nSUCCESS");
				}
				else
				{
					printf("ERROR!");
				}
			}
				break;
		case 'O' :
			version();
			break;
		}
	}
		
}





