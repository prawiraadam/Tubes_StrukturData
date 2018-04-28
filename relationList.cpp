#include "relationList.h"

void createList(List_relasi &L){
    /** Arbi 1301174030 **/

    first(L) = NULL;
}


address_relasi alokasi(address_child C) {
    /** Arbi 1301174030 **/

    address_relasi P = new elmlist_relasi;
    info(P) = C;
    next(P) = NULL;
    return P;
}


void insertFirst(List_relasi &L, address_relasi P) {
    /** Arbi 1301174030 **/

    if (first(L) == NULL){
        first(L) = P;
        next(P) = P;
    }else{
        next(P) = first(L);
        first(L) = P;
    }
}


void insertAfter(List_relasi &L, address_relasi &Prec, address_relasi P) {
    /** Justisio 1301174597 **/

    next(P) = next(Prec);
    next(Prec) = P;
}


void insertLastR(List_relasi &L, address_relasi P){
    /** Justisio 1301174597 **/

    if (next(first(L)) == first(L)){
        next(first(L)) = P;
        next(P) = first(L);
    }else{
        address_relasi Q = first(L);
        do{
            Q = next(Q);
        }while(next(Q) != first(L));
        next(Q) = P;
        next(P) = first(L);
    }
}


void printInfoR(List_relasi L) {
    /** Arbi 1301174030 **/

    address_relasi P = first(L);
    if (P == NULL){
        cout<<"Child Empty";
    }else{
        do{
            cout<<"->"<<info(info(P)).nama_danus<<endl;
            P = next(P);
        }while (P != first(L));
    }
}


void deleteFirst(List_relasi &L, address_relasi &P){
    /** Justisio 1301174597 **/

    if (next(first(L)) == first(L)){
        P = first(L);
        first(L) = NULL;
    }else{
        address_relasi Q;
        do{
            Q = next(Q);
        }while (next(Q) != first(L));
        P = first(L);
        first(L) = next(first(L));
        next(Q) = first(L);
        next(P) = NULL;
    }
}


void deleteAfter(List_relasi &L, address_relasi Prec, address_relasi &P){
    /** Justisio 1301174597 **/

    if (next(Prec) == first(L)){
        deleteLast(L, P);
    }else{
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }
}


void deleteLast(List_relasi &L, address_relasi &P){
    /** Justisio 1301174597 **/

    address_relasi Q;

    if (next(first(L)) == first(L)){
        deleteFirst(L, P);
    }else{
        do{
            Q = next(Q);
        }while (next(next(Q)) != first(L));
        P = next(Q);
        next(Q) = first(L);
        next(P) = NULL;
    }
}

void deleteRelation(List_relasi &LR, address_child C) {
    /** Justisio 1301174597 **/

    address_relasi R = findElmR(LR, C);
    if (R != NULL) {
        if (R == first(LR)) {
            deleteFirst(LR, R);
        } else if (next(R) == NULL) {
            deleteLast(LR, R);
        } else {
            address_relasi Prec = first(LR);
            while (Prec != R){
                Prec = next(Prec);
            }
            deleteAfter(LR, Prec, R);
        }
    }
}

address_relasi findElmR(List_relasi L, address_child C) {
    /** Arbi 1301174030 **/

    if (first(L) == NULL){
        cout<<"No Child"<<endl;
    }else{
        address_relasi P = first(L);
        while (P != NULL){
            if (info(P) == C){
                return P;
            }
            P = next(P);
        }
        return NULL;
    }
}
