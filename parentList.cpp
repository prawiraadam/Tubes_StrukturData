#include "parentList.h"
#include <stdio.h>

/** NAMA  : JUSTISIO YAN PRAWIRA ADAM
*   NIM   : 1301174597
*   KELAS : IF 41 - 08
**/

void createList(List_Parent &L){
    /** Justisio 1301174597 **/

    first(L) = NULL;
}

address_parent allocate(infotype_parent x){
    /** Justisio 1301174597 **/

    address_parent P;

    P = new elmlist_parent;
    info(P) = x;
    next(P) = NULL;
    createList(relasi(P));
    return P;
}

void deallocate(address_parent &P){
    /** Justisio 1301174597 **/
    delete P;
}

void insertFirst(List_Parent &L, address_parent P){
    /** Justisio 1301174597 **/

    if (first(L) == NULL){
        first(L) = P;
        next(first(L)) = P;
    }
    else{
        address_parent Q = first(L);
        while (next(Q) != first(L)){
            Q = next(Q);
        }
        next(P) = first(L);
        first(L) = P;
        next(Q) = first(L);
    }

}

void insertLast(List_Parent &L, address_parent P){
    /** Justisio 1301174597 **/

    if (first(L) == NULL){
        insertFirst(L, P);
    }else{
        address_parent Q = first(L);
        do{
            Q = next(Q);
        }while(next(Q) != first(L));
        next(P) = first(L);
        next(Q) = P;
    }
}

void deleteFirst(List_Parent &L, address_parent &P){
    /** Justisio 1301174597 **/

    if (first(L) == NULL){
        cout<<"LIST EMPTY!"<<endl;
    }
    else if (next(first(L)) == first(L)){
        P = first(L);
        next(P) = NULL;
        first(L) = NULL;
    }
    else{
        address_parent Q = first(L);
        do{
            Q = next(Q);
        }while(next(Q) != first(L));
        P = first(L);
        first(L) = next(first(L));
        next(P) = NULL;
        next(Q) = first(L);
    }
    delete P;
}

void deleteLast(List_Parent &L, address_parent &P){
    /** Justisio 1301174597 **/

    if (first(L) == NULL){
        cout<<"LIST EMPTY!"<<endl;
    }
    else if (next(first(L)) == first(L)){
        P = first(L);
        first(L) = NULL;
    }
    else{
        address_parent Q = first(L);
        do{
            Q = next(Q);
        }while(next(next(Q)) != first(L));
        P = next(Q);
        next(P) = NULL;
        next(Q) = first(L);
    }
    delete P;
}

address_parent findByID(List_Parent L, int x){
    /** Justisio 1301174597 **/

    address_parent P = first(L);
    if (P != NULL){
        do{
        if (x == info(P).idUKM){
            return P;
        }
        P = next(P);
        }while (P != first(L));
    }

    return NULL;
}

address_parent findElmName(List_Parent L, string x){
    /** Justisio 1301174597 **/

    address_parent P = first(L);
    if (P != NULL){
        do{
        if (x == info(P).namaUKM){
            return P;
        }
        P = next(P);
        }while (P != first(L));
    }

    return NULL;
}

void insertAfter(List_Parent &L, address_parent Prec, address_parent P){
    /** Justisio 1301174597 **/

    if (next(Prec) ==  first(L)){
        insertLast(L, P);
    }else{
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void deleteAfter(List_Parent &L, address_parent Prec, address_parent &P){
    /** Justisio 1301174597 **/

    if (next(Prec) == first(L)){
        deleteFirst(L, P);
    }else{
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }
}

void printInfo(List_Parent L){
    /** Justisio 1301174597 **/

    address_parent P = first(L);
    if (P == NULL){
        cout<<"List empty"<<endl;
    }else{
        do{
            view_data(info(P));
            P = next(P);
        }while (P != first(L));
    }
}

//=============================================================================================//

void insertAndSort(List_Parent &L, address_parent P){
    /** Justisio 1301174597 **/

    address_parent Q = findByID(L, info(P).idUKM);

    if (Q != NULL){
        cout<<"Duplicate"<<endl;
    }else{
        address_parent R = first(L);

        if (first(L) == NULL){
            insertFirst(L,P);
        }else{
            do{
                R = next(R);
            }while(next(R) != first(L));

            if (info(P).idUKM < info(first(L)).idUKM){
                insertFirst(L,P);
            }
            else if((info(P).idUKM > info(R).idUKM)){
                insertLast(L, P);
            }else{
                address_parent Prec = NULL;
                R = first(L);
                while (info(P).idUKM > info(R).idUKM){
                    Prec = R;
                    R = next(R);
                }
                insertAfter(L, Prec, P);
            }
        }
    }
}


void deleteParent(List_Parent &LP, address_parent P) {
    /** Justisio 1301174597 **/

    address_relasi R;
    while(first(relasi(P))!=NULL) {
        deleteFirst(relasi(P), R);
    }
    if (P == first(LP)) {
        deleteFirst(LP, P);
    } else if(next(P) == first(LP)) {
        deleteLast(LP, P);
    } else {
        address_parent Prec = first(LP);
        while (Prec != P){
            Prec = next(Prec);
        }
        deleteAfter(LP, Prec, P);
    }
}

//==========================================================================================================


listUKM createData(){
    /** Justisio 1301174597 **/

    listUKM P;

    cout<<"===== Pakai huruf KAPITAL ! ====="<<endl;

    cout<<"Masukkan ID          : ";
    cin>>P.idUKM;
    cout<<"Masukkan nama UKM    : ";
    cin>>P.namaUKM;
    cout<<endl;
    // ===========================
    return P;
}

void view_data(listUKM P){
    /** Justisio 1301174597 **/

    cout<<"["<<P.idUKM<<"]"<<P.namaUKM<<endl;
}

void edit_data(listUKM P){
    /** Justisio 1301174597 **/

    cout<<"Input ID         : ";
    cin>>P.idUKM;
    cout<<"Edit Nama UKM    : ";
    cin>>P.namaUKM;
    cout<<endl;
}
