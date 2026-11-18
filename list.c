#include "DS.h"

/* p-ийн зааж буй List-д x утгыг төгсгөлд хийнэ */
void l_push_back(List *p, int x)
{
	Elm *e = (Elm *)malloc(sizeof(Elm));
        if (e == NULL) return;
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

/* p-ийн зааж буй List-д x утгыг эхэнд хийнэ
   Бүх элементүүд нэг нэг байрлал хойшилно.
 */
void l_push_front(List *p, int x)
{
	      Elm *e = (Elm *)malloc(sizeof(Elm));
        if (e == NULL) return;
        e->x = x;
        e->next = p->head;       
        p->head = e;
        if (p->tail == NULL)        
                p->tail = e;
        p->len++;
}

/*
  p-ийн зааж буй List-д x утгыг pos байрлалд хийнэ
  pos болон түүнээс хойшхи элементүүд нэг байрлал ухарна.
  Тухайн байрлал List-ийн сүүлийн индексээс их бол төгсгөлд орно.
 */
void l_insert(List *p, int x, int pos)
{
	if (pos == 0) {
                l_push_front(p, x);
                return;
        }
        if (pos < 0 || pos >= p->len) {  
                l_push_back(p, x);
                return;
        }

        Elm *e = (Elm *)malloc(sizeof(Elm));
        if (e == NULL) return;
        e->x = x;

        Elm *prev = p->head;         
        for (int i = 0; i < pos - 1; i++)
                prev = prev->next;

        e->next = prev->next;         
        prev->next = e;                 
        p->len++;
}


/*
  p-ийн зааж буй List-н эхлэлээс гаргана.
  List-ийн бүх элементүүд нэг нэг байрлал урагшилна
 */
void l_pop_front(List *p)
{
if (p->head == NULL) return;
        Elm *temp = p->head;
        p->head = temp->next;
        if (p->head == NULL)
                p->tail = NULL;
        free(temp);
        p->len--;
}

/* p-ийн зааж буй List-н төгсгөлөөс гаргана */
void l_pop_back(List *p)
{
	if (p->head == NULL) return;

        if (p->head == p->tail) {       
                free(p->head);
                p->head = NULL;
                p->tail = NULL;
        } else {
                Elm *prev = p->head;    
                while (prev->next != p->tail)
                        prev = prev->next;
                free(p->tail);
                prev->next = NULL;
                p->tail = prev;
        }
        p->len--;
}

/* p-ийн зааж буй List-н pos байрлалаас гаргана.
   pos болон түүнээс хойшхи элементүүд нэг байрлал урагшилна.
   pos байрлалаас гарах боломжгүй бол юу ч хийхгүй.
 */
void l_erase(List *p, int pos)
{
	if (pos < 0 || pos >= p->len)    
                return;
        if (pos == 0) {
                l_pop_front(p);
                return;
        }
        if (pos == p->len - 1) {
                l_pop_back(p);
                return;
        }

        Elm *prev = p->head;            
        for (int i = 0; i < pos - 1; i++)
                prev = prev->next;

        Elm *temp = prev->next;        
        prev->next = temp->next;         
        free(temp);
        p->len--;
}

/*
  p-ийн зааж буй List-н утгуудыг хэвлэнэ.
  Хамгийн эхний элементээс эхлэн дарааллаар, нэг мөрөнд
  нэг л элемент хэвлэнэ.
 */
void l_print(List *p)
{
        Elm *cur = p->head;          
        while (cur != NULL) {        
                printf("%d\n", cur->x);
                cur = cur->next;     
        }
}

/*
  p-ийн зааж буй List-с x тоог хайн олдсон хаягийг буцаана.
  Олдохгүй бол NULL хаяг буцаана.
 */
Elm *l_search(List *p, int x)
{
	Elm *cur = p->head;
        while (cur != NULL) {
                if (cur->x == x)
                        return cur;
                cur = cur->next;
        }
        return NULL;
}
