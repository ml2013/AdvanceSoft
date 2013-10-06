
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

#define MAX 10

/* 
 *CreatLinkTable : initiation the LinkTable 
 *  return type is  LinkTable
 */
LinkTable * CreatLinkTable()
{
	LinkTable *pLink=(LinkTable *)malloc(sizeof(LinkTable));
	if(pLink == NULL)
	{
		return FAILURE;
	}
	pLink->Head=NULL;
	pLink->Tail=NULL;
	pLink->count=0;
	return pLink;
}

/*
 *InsertNode : Insert node for the LinkTable
 */
int InsertNode(LinkTable *pLink,void *data,int size)
{
	LinkNode *pnode=(LinkNode *)malloc(sizeof(LinkNode));
	if(pLink == NULL || data == NULL)
	{
		return FAILURE;
	}
	pnode->data = (void *)malloc(size);
	memcpy(pnode->data,data,size);
	pnode->next=NULL;

	if(pLink->count == 0 )
	{
		pLink->Head = pnode;
		pLink->Tail = pnode;
		pLink->count += 1;
	}
	else
	{
		pLink->Tail->next=pnode;
		pLink->Tail=pnode;
		pLink->count += 1;
	}
	return SUCCESS;
}
/*
 * SearchNode : Search node from the LinkTable
 */
void* SearchNode(LinkTable *pLink,int (*condition)(void *data))
{
	LinkNode *tmp=pLink->Head;
	if(pLink == NULL )
	{
		return FAILURE;
	}
	while(tmp != NULL)
	{
		if(condition(tmp->data) != 0)
		{
			return tmp->data;
		}
		tmp=tmp->next;
	}
	printf("\nthis Informantio is not exits!");
	return FAILURE;
}

/*
 *DeleteNode : Delet node from the LinkTable
 */
int DeleteNode(LinkTable *pLink,int (*condition)(void *data))
{
	LinkNode *tmp=pLink->Head;
	if(pLink->count == 0)
	{
		printf("this Link is empty!");
		return FAILURE;
	}
	if(condition(tmp->data) == 1)
	{
		pLink->Head=tmp->next;
		pLink->count -= 1;
		if(pLink->count == 0)
		{
			pLink->Tail=NULL;
			pLink->Head=NULL;
		}
		return SUCCESS;
	}
	else
	{
		while(tmp->next != pLink->Tail->next)
		{
			if(condition(tmp->next->data) == 1)
			{
				tmp->next=tmp->next->next;
				free (tmp->next);
				pLink->count -= 1;
				if(pLink->count == 0)
				{
					printf("you delete the last Node !");
					pLink->Tail = NULL;
					pLink->Head=NULL;
				}
				return SUCCESS;
			}
			tmp=tmp->next;
		}
	}
	printf("\nERROR! ");
	return FAILURE;
}

/*
 *DisplayNode : printf LinkNode
 */
int Display(LinkTable *pLink,int (*display)(void *data))
{
	LinkNode *tmp=pLink->Head;
	if(pLink == NULL )
	{
		printf("this Link is empty");
		return FAILURE;
	}

	while(tmp != pLink->Tail->next)
	{
		display(tmp->data);
		tmp=tmp->next;
	}
	return SUCCESS;
}
/*
 *UpdataNode : change node element
 */
int UpdataNode(LinkTable *pLink,int (*condition)(void *data),void* (*handle)(),int size)
{
	LinkNode *tmp=pLink->Head;
	if(pLink == NULL)
		return FAILURE;
	
	while(tmp != NULL)
	{
		if(condition(tmp->data) == 1)
		{
			tmp->data=malloc(size);
			tmp->data=handle();
			return SUCCESS;
		}
		tmp=tmp->next;
	}
	printf("\nthis information is not exist!");
	return	FAILURE;
}


