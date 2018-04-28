#ifndef CHILDLIST_H_INCLUDED
#define CHILDLIST_H_INCLUDED

#include <iostream>

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info

using namespace std;

struct listDanus {
    int ID;
    string nama_danus;
};

typedef struct listDanus infotype_child;
typedef struct elmlist_child *address_child;

struct elmlist_child{
    infotype_child info;
    address_child next;
    address_child prev;
};

struct List_Child{
    address_child first;
    address_child last;
};

//==========================================================//

void createList(List_Child &L);
address_child allocate(infotype_child x);
void deallocate(address_child &P);

void insertFirst(List_Child &L, address_child P);
void insertLastR(List_Child &L, address_child P);
void deleteFirst(List_Child &L, address_child &P);
void deleteLast(List_Child &L, address_child &P);
void insertAfter(List_Child &L, address_child Prec, address_child P);
void deleteAfter(List_Child &L, address_child Prec, address_child &P);

address_child findElm(List_Child L, int x);
void printInfo(List_Child L);
address_child findElmName(List_Child L, string x);

void insertAndSort(List_Child &L, address_child P);
void deletebyID(List_Child &L, infotype_child x);

listDanus create_data();
void view_data(listDanus d);
void edit_data(listDanus &d);

#endif // DOUBLELIST_H_INCLUDED
