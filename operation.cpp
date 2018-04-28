#include "operation.h"
#include <conio.h>

void deleteChild(List_Parent &LP, List_Child &LC, address_child C) {
    /** Justisio 1301174597 **/

    int id;
    cout<<"Input ID to delete : ";
    cin>>id;
    C = findElm(LC, id);
    cout<<info(C).nama_danus;
    if(C != NULL) {
        address_parent P = first(LP);
        do {
            disconnect(P, C);
            P = next(P);
        } while(P != first(LP));
        if(C == first(LC)) {
            deleteFirst(LC, C);
        } else if(C == last(LC)) {
            deleteLast(LC, C);
        } else {
            address_child prec = prev(C);
            deleteAfter(LC,prec,C);
        }
    }
}

void connect(List_Parent LP, List_Child LC){
    /** Justisio 1301174597 **/

    int id;

    cout<<"Input ID UKM : ";
    cin>>id;
    address_parent P = findByID(LP, id);

    cout<<"Input ID Danusan : ";
    cin>>id;
    address_child C = findElm(LC, id);

    if (P != NULL && C != NULL){
        address_relasi R = alokasi(C);
        insertFirst(relasi(P), R);
        cout<<"Connected"<<endl;
    }else{
        cout<<"Node not found"<<endl;
    }
}


bool isConnected(List_Parent LP, List_Child LC){
    /** Justisio 1301174597 **/

    int idtoFind;

    cout<<"Input id UKM to find : ";
    cin>>idtoFind;
    address_parent P = findByID(LP, idtoFind);

    cout<<"Input id danus to find : ";
    cin>>idtoFind;
    address_child C = findElm(LC, idtoFind);

    if(P != NULL && C != NULL){
        address_relasi R = findElmR(relasi(P), C);
        if (R == NULL){
            return false;
        }else{
            return true;
        }
    }else{
        cout<<"Not Found"<<endl;
    }
}


void disconnect(address_parent P, address_child C){
    /** Justisio 1301174597 **/

    int id;
    List_Parent LP;
    List_Child LC;
    List_relasi LR;

    cout<<"Input ID UKM : ";
    cin>>id;
    P = findByID(LP, id);

    cout<<"Input ID Danusan : ";
    cin>>id;
    C = findElm(LC, id);
    if (P != NULL && C != NULL){
        address_relasi R = findElmR(relasi(P), C);
        if (R != NULL){
            deleteRelation(LR, C);
            delete C;
        }else{
            cout<<"No connection exist"<<endl;
        }
    }else{
        cout<<"One not found"<<endl;
    }
}


void printAll(List_Parent LP, List_Child LC){
    /** Arbi 1301174030 **/

    address_parent P = first(LP);
    if (first(LP) != NULL){
        do{
            view_data(info(P));
                printInfoR(relasi(P));
                cout<<endl;
            P = next(P);
        }while (P != first(LP));
    }else if (first(LC) != NULL){
        printInfo(LC);
        cout<<endl;
    }else{
        cout<<"Both list empty";
    }

}


void printChildofParent(List_Parent LP, List_relasi LR){
    /** Arbi 1301174030 **/

    int idtoFind;
    cout<<"Masukkan ID : ";
    cin>>idtoFind;
    address_parent P = findByID(LP, idtoFind);
    if (P != NULL){
            cout<<info(P).namaUKM<<endl;;
            printInfoR(relasi(P));
    }else{
        cout<<"Parent not found";
    }
}

/** CASE FUNCTIONALITY **/

void bestUKM(List_Parent LP){
    /** Justisio 1301174597 **/

    address_parent most = first(LP);
    address_parent P = first(LP);
    int max;
    int count;
    do{
        max = 0;
        count = 0;
        address_relasi R = first(relasi(P));
        while(R != NULL){
            count++;
            R = next(R);
        }
        if (count > max){
            max = count;
            most = P;
        }
        P = next(P);
    }while (P != first(LP));

    cout<<"Most Diligent UKM goes to : "<<info(most).namaUKM<<endl;
    cout<<"With "<<max<<" variants of danusan"<<endl;
}


void bestDanusan(List_Parent LP, List_Child LC){
    /** Justisio 1301174597 **/

    int max = 0;
    int count = 0;
    bool check;

    address_child C = first(LC);
    address_child most = first(LC);
    address_parent P = first(LP);

    while (C != NULL){
        do{
            check = isConnected(LP, LC);
            if(check == true){
                count++;
            }
            P = next(P);
        }while (P != first(LP));
        if (count > max){
            max = count;
            most = C;
        }
        C = next(C);
    }
    cout<<"Most popular danusan goes to : "<<info(most).nama_danus<<endl;
    cout<<"With "<<max<<" Resellers"<<endl;
}


void Preset(List_Parent &LP, List_Child &LC){
    /** Arbi 1301174030 **/

    address_child C;
    address_parent P;
    address_relasi R;

    infotype_parent iP;
    infotype_child iC;

    /**insert Parents**/
    iP.idUKM = 1;
    iP.namaUKM = "FOTOGRAFI";
    P = allocate(iP);
    insertAndSort(LP, P);

    iP.idUKM = 4;
    iP.namaUKM = "ASTACALA";
    P = allocate(iP);
    insertAndSort(LP, P);

    iP.idUKM = 2;
    iP.namaUKM = "SES";
    P = allocate(iP);
    insertAndSort(LP, P);

    iP.idUKM = 3;
    iP.namaUKM = "RIVERSIDE";
    P = allocate(iP);
    insertAndSort(LP, P);

    iP.idUKM = 5;
    iP.namaUKM = "SEARCH";
    P = allocate(iP);
    insertAndSort(LP, P);

    cout<<"Success Insert Parent"<<endl;


    /**insert Child**/
    iC.ID = 1;
    iC.nama_danus = "RISOL";
    C = allocate(iC);
    insertAndSort(LC, C);

    iC.ID = 3;
    iC.nama_danus = "MARTABAK";
    C = allocate(iC);
    insertAndSort(LC, C);

    iC.ID = 5;
    iC.nama_danus = "BOLU";
    C = allocate(iC);
    insertAndSort(LC, C);

    iC.ID = 2;
    iC.nama_danus = "TEMPURA";
    C = allocate(iC);
    insertAndSort(LC, C);

    iC.ID = 4;
    iC.nama_danus = "JCO";
    C = allocate(iC);
    insertAndSort(LC, C);

    cout<<"Success insert child"<<endl;

//    /** Hubungkan **/
//    P = findByID(LP, 4);
//    C = findElm(LC, 2);
//    R = alokasi(C);
//    insertLastR(relasi(P), R);

//    P = findByID(LP, 1);
//    C = findElm(LC, 2);
//    R = alokasi(C);
//    insertLastR(relasi(P), R);
//
//    P = findByID(LP, 3);
//    C = findElm(LC, 4);
//    R = alokasi(C);
//    insertLastR(relasi(P), R);
}

