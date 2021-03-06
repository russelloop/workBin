// 实验一：设计一个程序实现线性表上并操作。
// e1list.cpp : 定义控制台应用程序的入口点。
// 

#include "p1list.h"

/* 此函数用于初始化一个保持增序的线性表L
 * L的初值是通过键盘按照递增的次序一个自然数一个自然数输入的。
 */
void InitList(List &L) {
    int i=0,d;
    L.elem[0]=GUARD;
    printf("输入某线性表各个元素的值(自然数)，%d表示输入结束！\n", GUARD);
    do {
        scanf("%d", &d);
        if (d!=GUARD) {
            if (i!=0 && d < L.elem[i-1]) 
                printf("\n这里要初始化一个保持增序的线性表，请输入一个不小于的%d自然数",L.elem[i]);
            else L.elem[i++]=d;
        }
        if (i==MAXLEN) printf("\n该线性表长度达到最大值\n");
    }while ((d!=GUARD)&&(i<MAXLEN));
    L.length=i;
}

/* 此函数用于初始化一个线性表L
 * L的初值是通过键盘一个自然数一个自然数输入的。
 */
void InitList0(List &L) {
    int i=0,d;
    L.elem[0]=GUARD;
    printf("输入某线性表各个元素的值(自然数)，%d表示输入结束！\n", GUARD);
    do {
        scanf("%d", &d);
        if (d!=GUARD) L.elem[i++]=d;
        if (i==MAXLEN) printf("\n该线性表长度达到最大值\n");
    }while ((d!=GUARD)&&(i<MAXLEN));
    L.length=i;
}

void printList(List L){
    int i;
    printf("线性表[%d]: \n", L.length);
    for (i=0;i<L.length;i++) printf("%d ", L.elem[i]);
    printf("\n");
}

void createTwoLists(List &La, List &Lb) {
    printf("\n创建两个线性表--注意输入的两表的总长度不要超过%d\n",MAXLEN);
    InitList(La);
    printf("\n初始化线性表Lb，其长度不超过%d。超出部分被截断！\n", MAXLEN-La.length);
    InitList(Lb);
    if (La.length + Lb.length > MAXLEN) Lb.length=MAXLEN-La.length;
}


/*TBD1* 将Lb归并到La表，形成新表Lc
 *TBD1* 要求Lc保持有序，允许出现重复元素
 *TBD1*/
void MergeList(List La, List Lb, List &Lc) {
    int i, j, k;
    i = j = k = 0;

    while(i < La.length && j < Lb.length){
        if(La.elem[i] < Lb.elem[j]){
            Lc.elem[k++] = La.elem[i++];
        }
        else{
            Lc.elem[k++] = Lb.elem[j++];
        }
    }

    while(i < La.length){
        Lc.elem[k++] = La.elem[i++];
    }
    while(j < Lb.length){
        Lc.elem[k++] = Lb.elem[j++];
    }

    Lc.length = k;
}

/*TBD2* 线性La和Lb分别表示两个集合，求新集合La＝La U Lb（ U"并"操作）
 *TBD2* 注意集合里不允许出现重复元素
 *TBD2*/
void Union(List &La, List Lb) {
    int i = La.length;
    int j = 0;
    while(j <= Lb.length){
        La.elem[i++] = Lb.elem[j++];
    }
    La.length += Lb.length; 
}

/*TBD3* 将线性表L逆转
 *TBD3* 要求使用最少的附加空间，空间复杂度为O(1)。
 *TBD3*/
void ReverseList(List &L) {
    int temp;
    int i, j;
    int n = L.length - 1;
    for(i = 0; i <= n; i++){
            temp = L.elem[n];
        for(j = n - 1; j>= i; j--){
            L.elem[j + 1] = L.elem[j];
        }
            L.elem[i] = temp;
    }
}

/*TBD4* 从一给定的顺序表L中删除元素值在x和y之间的所有元素(x<= y)
 *TBD4* 要求以较高的效率实现，空间复杂度为O(1)。
 *TBD4*/
void deleteall(List &L, int x, int y) {
    int n = L.length - 1;
    int i = 0;
    int j;
    while(i <= n) {
        if (L.elem[i] >= x && L.elem[i] <= y){
            for(j = i; j <= n; j++) {
                L.elem[j] = L.elem[j + 1];
            }
            L.length -= 1;
        }
        else
            i++;
    }
}


int main(int argc, char* argv[])
{
    mainlottery();
    //List La;
    //InitList(La);
    //printList(La);
    //InitList(Lb);
    //printList(Lb);
    //MergeList(La, Lb, Lc);
    //Union(La, Lb);
    //ReverseList(La);
    //deleteall(La, 3, 5);
    //printList(La);

    printf("\n键入任意字符程序退出 ......"); getchar();
    return 0;
}