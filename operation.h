#ifndef OPERATION_H_INCLUDED
#define OPERATION_H_INCLUDED

#include "parentList.h"
#include "childList.h"
#include "relationList.h"

void deleteChild(List_Parent &LP, List_Child &LC, address_child C);

void connect(List_Parent LP, List_Child LC);
bool isConnected(List_Parent LP, List_Child LC);
void disconnect(address_parent P, address_child C);
void printAll(List_Parent LP, List_Child LC);
void printChildofParent(List_Parent LP, List_relasi LR);

void bestDanusan(List_Parent LP, List_Child LC);
void bestUKM(List_Parent LP);

void Preset(List_Parent &LP, List_Child &LC);

#endif // OPERATION_H_INCLUDED
