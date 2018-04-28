#include <stdio.h>
#include "childList.h"


void createList(List_Child &L) {
    /** Arbi 1301174030 **/

    first(L)=NULL;
    last(L)=NULL;
}

address_child allocate(infotype_child x) {
    /** Arbi 1301174030 **/

    address_child P;
    P=new elmlist_child;
    info(P)=x;
    next(P)=NULL;
    prev(P)=NULL;
    return P;
}

void deallocate(address_child &P) {
    /** Arbi 1301174030 **/

    delete P;
}

void insertFirst(List_Child &L, address_child P) {
    /** Arbi 1301174030 **/

    if (first(L)==NULL) {
        first(L)=P;
        last(L)=P;
    } else {
        next(P)=first(L);
        prev(first(L))=P;
        first(L)=P;
    }
}

void insertLastR(List_Child &L, address_child P) {
    /** Arbi 1301174030 **/

    if (first(L)==NULL && last(L)==NULL) {
        insertFirst(L,P);
    } else {
        prev(P)=last(L);
        next(last(L))=P;
        last(L)=P;
    }
}

address_child findElm(List_Child L, int x) {
    /** Arbi 1301174030 **/

    address_child P;
    P = first(L);
    if (first(L) == NULL) {
        return NULL;
    } else {
        while(P != last(L)) {
            if (info(P).ID == x) {
                return P;
            }
            P = next(P);
        }
        if ((P == last(L)) && (info(P).ID == x)) {
            return P;
        } else {
            return NULL;
        }
    }
    return P;
}

address_child findElmName(List_Child L, string x){
    /** Arbi 1301174030 **/

    address_child P;
    P = first(L);
    if (first(L) == NULL) {
        return NULL;
    } else {
        while(P != last(L)) {
            if (info(P).nama_danus == x) {
                return P;
            }
            P = next(P);
        }
        if ((P == last(L)) && (info(P).nama_danus == x)) {
            return P;
        } else {
            return NULL;
        }
    }
    return P;
}

void deleteFirst(List_Child &L, address_child &P) {
    /** Arbi 1301174030 **/

    if (first(L)!=NULL) {
        P= first(L);
        if (first(L)==last(L)) {
            first(L)=NULL;
            last(L)=NULL;
        } else {
            first(L)=next(first(L));
            prev(P)=NULL;
            prev(first(L))=NULL;
            next(P)=NULL;
        }

    }
    deallocate(P);
}

void deleteLast(List_Child &L, address_child &P) {
    /** Arbi 1301174030 **/

    if (first(L)!=NULL) {
        P=last(L);
        last(L)=prev(last(L));
        prev(P)=NULL;
        next(last(L))=NULL;
    }
    deallocate(P);
}

void printInfo(List_Child L) {
    /** Arbi 1301174030 **/

    address_child P = first(L);
    if (first(L)!=NULL) {
        do {
            view_data(info(P));
            P=next(P);
        } while (P!=NULL);
    }
}


void insertAfter(List_Child &L, address_child Prec, address_child P) {
    /** Arbi 1301174030 **/

    if (Prec!=NULL) {
        next(P)=next(Prec);
        prev(P)=Prec;
        prev(next(Prec))=P;
        next(Prec)=P;
    }

}
void deleteAfter(List_Child &L, address_child Prec, address_child &P) {
    /** Arbi 1301174030 **/

    if (Prec!=NULL) {
        next(Prec)=next(P);
        prev(next(P))=Prec;
        next(P)=NULL;
        prev(P)=NULL;
    }
    deallocate(P);
}



void insertAndSort(List_Child &L, address_child P) {
    /** Arbi 1301174030 **/

    bool check=true;
    int x=info(P).ID;
    address_child R=first(L);
    while (R!=NULL) {
        if(info(R).ID==x) {
            check=false;
           cout<<"ID tidak boleh sama, Input Ulang"<<endl;
        }
        R=next(R);
    }

    while (check==true) {
        if (first(L)==NULL) {
            insertFirst(L,P);
        } else if (info(P).ID<=info(first(L)).ID) {
            insertFirst(L,P);
        } else if (info(P).ID>=info(last(L)).ID) {
            insertLastR(L,P);
        } else {
            address_child Q=first(L);
            while (info(P).ID>info(next(Q)).ID) {
                Q=next(Q);
            }
            insertAfter(L,Q,P);
        }
        check=false;
    }
}


void deletebyID(List_Child &L, int x) {
    /** Arbi 1301174030 **/

    address_child Prec, P;
    if(first(L)!=NULL) {
        P=findElm(L,x);
    }
    if (P==NULL) {
        cout<<"ID tidak ditemukan"<<endl;
    }
    address_child last = first(L);
    if (first(L)==P) {
        deleteFirst(L,P);
    } else if (P==last(L)) {
        deleteLast(L,P);
    } else {
        Prec=first(L);
        while (next(Prec)!=P) {
            Prec=next(Prec);
        }
        deleteAfter(L,Prec,P);
    }
}


//====================================================================================

listDanus create_data() {
    /** Arbi 1301174030 **/

    listDanus d;

    cout<<"ID          :  ";
    cin>>d.ID;
    cin.get();
    cout<<"Nama Danus  :  ";
    cin>>d.nama_danus;

    return d;
}

void view_data(listDanus d) {
    /** Arbi 1301174030 **/

    cout<<"ID           : "<<d.ID<<endl;
    cout<<"Nama Danus   : "<<d.nama_danus<<endl;
    cout<<endl;
}


void edit_data(listDanus &d) {
    /** Arbi 1301174030 **/

    cin.get();
    cout<<"Nama Danus   :  ";
    cin>>d.nama_danus;
}
