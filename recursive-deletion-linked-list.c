#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node
{
    int t;
    struct node *child;
}
node;

node *head = NULL;
void destroy(node *head);

int main(void)

{

     node *travel = head;
    for( int i =0 ;i<5;i++)
    {
     node *new = calloc(1,sizeof(node));
     new->t=i;
     if (i ==0)
     {
         head = new ;
         travel = new ;
     }
     else
     {
         travel->child = new;
         travel = new;
      }

    }
     travel = head;
    destroy(travel);
}


void destroy(node* travel)
{

    if (travel == NULL)
    {
    }
    else
    {
    destroy(travel->child);
    free(travel);

    }
}


