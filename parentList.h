#ifndef PARENTLIST_H_INCLUDED
#define PARENTLIST_H_INCLUDED

#include "relationList.h"
#include <iostream>

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
#define relasi(P) P->relasi

using namespace std;

/** NAMA  : JUSTISIO YAN PRAWIRA ADAM
*   NIM   : 1301174597
*   KELAS : IF 41 - 08
**/

struct listUKM {
    int idUKM;
    string namaUKM;
};

typedef listUKM infotype_parent;
typedef struct elmlist_parent *address_parent;


struct elmlist_parent{
    infotype_parent info;
    address_parent next;
    List_relasi relasi;
};

struct List_Parent{
    address_parent first;
};


//------------------------------------------------------------------------------------------------//
void createList(List_Parent &L);
address_parent allocate(infotype_parent x);
void deallocate(address_parent &P);

void insertFirst(List_Parent &L, address_parent P);
void insertLast(List_Parent &L, address_parent P);
void deleteFirst(List_Parent &L, address_parent &P);
void deleteLast(List_Parent &L, address_parent &P);
void insertAfter (List_Parent &L, address_parent Prec, address_parent P);
void deleteAfter(List_Parent &L, address_parent Prec, address_parent &P);
void deleteParent(List_Parent &LP, address_parent P);

address_parent findByID(List_Parent L, int x);
void printInfo(List_Parent L);

void insertAndSort(List_Parent &L, address_parent P);
//====================================================

listUKM createData();
void view_data(listUKM P);
void edit_data(listUKM P);
#endif // PARENTLIST_H_INCLUDED
