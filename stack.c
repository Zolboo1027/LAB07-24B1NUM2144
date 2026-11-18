#include "DS.h"
/*
  p-ийн зааж буй Stack-т x утгыг оруулна
 */
void s_push(Stack *p, int x)
{
        Elm *e = (Elm *)malloc(sizeof(Elm));
        if (e==NULL){return;}

        e->x=x;
        e->next=p->top;
        p->top=e;
        p->len++;
}
/*
  p-ийн зааж буй Stack-аас гарах функц
 */
void s_pop(Stack *p)
{
        if(p->top==NULL){return;}

        Elm *temp = p->top;
        p->top = temp->next;

        free(temp);
        p->len--;

}
/*
    p-ийн зааж буй Stack-д байгаа элементүүдийг хэвлэх функц.
    Хамгийн сүүлд орсон элементээс эхлэн дарааллаар, нэг мөрөнд
    нэг л элемент хэвлэнэ.
 */
void s_print(Stack *p)
{
        Elm *cur = p->top;
        while(cur!=NULL){
                printf("%d\n",cur->x);
                cur=cur->next;
        }
}
