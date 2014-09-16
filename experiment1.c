/**************************************************************************************************/
/* Copyright (C) 7#1606,SSE@USTC,2014-2015                                                        */
/*                                                                                                */ 
/* FILE NAME             :  experiment1                                                           */
/* PRINCIPAL AUTHOR      :  QuPanpan                                                              */
/* SUBSYSTEM NAME        :  Document                                                              */
/* MODULE NAME           :  menu                                                                  */
/* LANGUAGE              :  C                                                                     */
/* TARGET ENVIRONMENT    :  ANY                                                                   */
/* DATA OF FRIST RELEASE :  2014/09/08                                                            */
/* DESCRIPTION           :  This is the first homework about a menu programm                      */ 
/**************************************************************************************************/
 
/*
 *Revision log:
 *t
 *Created by QuPanpan,2014/09/08
 *
*/

#include <stdio.h>
#include <stdlib.h>

int Help();

#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     10

typedef struct DataNode
{    
    char*   cmd;
    char*   desc;
    int     (*handler) ();
    struct  DataNode *next;    
}tDataNode;

static tDataNode head[]=
{
    {"help","this is a help cmd",Help,&head[1]},
    {"version","menu v1.0",NULL,NULL}
};		
main()
{
    /*cmd line begins*/
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Input a cmd word-> ");
        scanf("%s",cmd);
        tDataNode *p=head;
        while(p!=NULL)
        {
             if(!strcmp(p->cmd,cmd))
            {
                 printf("%s - %s\n",p->cmd,p->desc);
                 if(p->handler != NULL)
                 {
                     p->handler();
                 }
                 break;
            }
            p = p->next; 
        } 
        if(p==NULL)
        {
            printf("The cmd you put is wrong.\n"); 
        }  
    }
}

int Help()
{

    printf("Menu list:\n");
    tDataNode *p=head;
    while(p!=NULL)
    {
        printf("%s - %s\n",p->cmd,p->desc);
        p=p->next;    
    } 
    return 0;
}
