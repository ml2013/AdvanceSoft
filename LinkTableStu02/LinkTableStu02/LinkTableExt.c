#include "LinkTable.h"

LinkTable * CreatLinkTableExt ()
{
	LinkTable *Link=malloc(sizeof(LinkTable)*MAX );
	int i=0;
	for ( i=0 ; i<MAX ; i++ )
	{
		Link[ i ].Head=NULL;
		Link[ i ].Tail=NULL;
		Link[ i ].count=0;
	}
	return Link;
}

int InsertNodeExt ( LinkTable *Link , void *data , int size,int (*position)() )
{
	int id=position();

	InsertNode ((Link+id),data,size) ;
	
}

void *SearchNodeExt ( LinkTable *Link ,int (*condition)(void *data),int (*position)() )
{
	int id=position();
	return SearchNode ( (Link+id) ,condition);
}

int DeleteNodeExt ( LinkTable *Link ,int (*position)() ,int (*condition)(void *data) )
{
	int id=position();
	DeleteNode ( (Link+id) ,condition);
}

int DisplayExt ( LinkTable *Link ,int (*display)(void *data))
{
	int i=0;
	for ( i=0 ; i<MAX ; i++ )
	{
		Display ( (Link+i),display);
	}
}

int UpdataNodeExt ( LinkTable *Link , int (*position)(),int (*condition)(void *data),void *(*handle)(),int size )
{
	int id=position();
	UpdataNode ( (Link+id),condition,handle,size);
}