
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
 * Created by Mengning,2013/09/20
 * Verified callback and head/next for search by MaLong,2013/09/21
 *
 */
#include <stdlib.h>
#include <stdio.h>

#define SUCCESS 1
#define FAILURE 0

#define MAX 10

/* LinkNode memery any type data 
 * next point the link next
 */

typedef struct LinkNode
{
	void *data;
	struct LinkNode *next;
}LinkNode;

/*LinkTable: Head ->  point the LinkTable head
 *                    Tail    ->  point the linkTable Tail
 *                     cout ->  member the count of linkNode
 */

typedef struct LinkTable
{
	struct LinkNode *Head;
	struct LinkNode *Tail;
	int count;
}LinkTable;

/* CreatLinkTable : initiation the LinkTable 
 *  return type is  LinkTable
 */
LinkTable * CreatLinkTable();

/*
 *InsertNode : Insert node for the LinkTable
 */
int InsertNode(LinkTable *pLink,void *data,int size);

/*
 * SearchNode : Search node from the LinkTable
 */
void* SearchNode(LinkTable *pLink,int (*condition)(void *data));

/*
 *DeleteNode : Delet node from the LinkTable
 */
int DeleteNode(LinkTable *pLink,int (*condition)(void *data));

/*
 *DisplayNode : printf LinkNode
 */
int Display(LinkTable *pLink,int (*display)(void *data));

/*
 *UpdataNode : change node element
 */
int UpdataNode(LinkTable *pLink,int (*condition)(void *data),void *handle(),int size);



LinkTable* CreatLinkTableExt ();

int InsertNodeExt ( LinkTable *Link,void *data,int size , int (*position)() );

void* SearchNodeExt(LinkTable *Link,int (*condition)(void *data),int (*position)());

int DeleteNodeExt ( LinkTable *Link ,int (*position)() ,int (*condition)(void *data) );

int DisplayExt ( LinkTable *Link ,int (*display)(void *data));

int UpdataNodeExt ( LinkTable *Link , int (*position)(),int (*condition)(void *data),void* (*handle)(),int size );