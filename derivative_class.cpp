#include<stdio.h>
#include<stdlib.h>
#include"Deq_List_One.h"

Deq_List_One *kek;

int main(void)
{
    kek = new Deq_List_One();
    kek->Append(0);
    kek->Append(1);
    kek->Append(2);
    kek->Append(3);
    kek->Print();
}
