#ifndef RELATIONLIST_H_INCLUDED
#define RELATIONLIST_H_INCLUDED

#define next(P) P->next
#define info(P) P->info

#include <iostream>
#include "childList.h"

using namespace std;


/** NAMA  : JUSTISIO YAN PRAWIRA ADAM
*   NIM   : 1301174597
*   KELAS : IF 41 - 08
**/

typedef struct elmlist_relasi *address_relasi;

struct elmlist_relasi{
    address_relasi next;
    address_child info;
};

struct List_relasi{
    address_relasi first;
};

void createList(List_relasi &L);
void insertFirst(List_relasi &L, address_relasi P);
void insertLastR(List_relasi &L, address_relasi P);
void insertAfter(List_relasi &L, address_relasi Prec, address_relasi P);
void deleteFirst(List_relasi &L, address_relasi &P);
void deleteLast(List_relasi &L, address_relasi &P);
void deleteAfter(List_relasi &L, address_relasi Prec, address_relasi &P);
void deleteRelation(List_relasi &LR, address_child C);

void printInfoR(List_relasi L);
address_relasi alokasi(address_child C);
address_relasi findElmR(List_relasi L, address_child C);


#endif // RELATIONLIST_H_INCLUDED
