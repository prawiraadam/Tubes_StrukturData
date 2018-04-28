#include <iostream>
#include <stdlib.h>
#include <conio.h>

#include "parentList.h"
#include "childList.h"
#include "relationList.h"
#include "operation.h"

using namespace std;

List_Parent LP;
List_Child LC;
List_relasi LR;
int idtoFind;

void mainMenu(){
    address_parent P;
    infotype_parent iP;

    address_child C;
    infotype_child iC;

    address_relasi R;

    int choice;
    bool check;
    do {
        system("cls");
        cout<<"-------------------- MAIN MENU --------------------"<<endl;
        cout<<"1. Insert UKM "<<endl;
        cout<<"2. find and delete UKM "<<endl;
        cout<<"3. View All UKM "<<endl;
        cout<<"---------------------------------------------------"<<endl;
        cout<<"4. Insert Danusan "<<endl;
        cout<<"5. Find and Delete Danusan "<<endl;
        cout<<"6. View all Danusan "<<endl;
        cout<<"---------------------------------------------------"<<endl;
        cout<<"7. Connect "<<endl;
        cout<<"8. Check Connection "<<endl;
        cout<<"9. Disconnect "<<endl;
        cout<<"10. Print All "<<endl;
        cout<<"11. Print Child of a Parent "<<endl;
        cout<<"12. Most Popular Danusan "<<endl;
        cout<<"13. Most diligent UKM "<<endl;
        cout<<"99. Insert Data Preset "<<endl;
        cout<<"0. exit "<<endl;
        cout<<"----------------------------------------------------"<<endl;
        cout<<"Input choice: ";
        cin>>choice;
        switch(choice){
            case 0:
                cout<<"Thank you for using our program"<<endl;
                cout<<"Press <enter> to exit"<<endl;
                break;
            case 1:
                system("cls");
                iP = createData();
                P = allocate(iP);
                insertAndSort(LP, P);
                break;
            case 2:
                deleteParent(LP, P);
                break;
            case 3:
                printInfo(LP);
                getch();
                break;
            case 4:
                iC = create_data();
                C = allocate(iC);
                insertAndSort(LC, C);
                break;
            case 5:
                deleteChild(LP, LC, C);
                break;
            case 6:
                printInfo(LC);
                getch();
                break;
            case 7:
                connect(LP, LC);
                getch();
                break;
            case 8:
                check = isConnected(LP, LC);
                if (check == true){
                    cout<<"connected"<<endl;
                }else{
                    cout<<"Not connected"<<endl;
                }
                getch();
                break;
            case 9:
                disconnect(P, C);
                break;
            case 10:
                printAll(LP, LC);
                getch();
                break;
            case 11:
                printChildofParent(LP, LR);
                getch();
                break;
            case 12:
                bestDanusan(LP, LC);
                getch();
                break;
            case 13:
                bestUKM(LP);
                getch();
                break;
            case 99:
                Preset(LP, LC);
                getch();
                break;

        }
    }while(choice != 0);
}

int main()
{
    createList(LP);
    createList(LC);
    createList(LR);
    mainMenu();
    return 0;
}
