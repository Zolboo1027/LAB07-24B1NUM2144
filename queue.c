#include "DS.h"

/* p-ийн зааж буй Queue-д x утгыг хийнэ */
void q_push(Queue *p, int x)
{
        Elm *e = (Elm *)malloc(sizeof(Elm));
        if(e==NULL){return;}

        e->x = x;
        e->next = NULL;

        if (p->tail == NULL) {       
                p->head = e;
                p->tail = e;
        } else {                  
                p->tail->next = e;  
                p->tail = e;        
        }
        p->len++;
}

/* p-ийн зааж буй Queue-с гаргана */
void q_pop(Queue *p)
{
        if (p->head == NULL)       
                return;

        Elm *temp = p->head;         
        p->head = temp->next;        
        if (p->head == NULL)          
                p->tail = NULL;       
        free(temp);
        p->len--;
}

/*
  p-ийн зааж буй Queue-н утгуудыг хэвлэнэ.
  Хамгийн эхний элементээс эхлэн дарааллаар, нэг мөрөнд
  нэг л элемент хэвлэнэ.
 */
void q_print(Queue *p)
{
        Elm *cur = p->head;
        while (cur != NULL) {
                printf("%d\n", cur->x);
                cur = cur->next;
        }
}
