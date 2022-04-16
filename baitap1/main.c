#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Cau truc nhan vien
typedef struct
{
    char id[50];
    char ho_ten[50];
    char chuc_vu[50];
    int so_dien_thoai;
} nhanvien;

//Cau truc node
typedef struct NODE
{
    nhanvien data;
    struct NODE *next;
} node;

//Cau truc danh sach
typedef struct
{
    node *pHead;
    node *pTail;
} list;

//Khoi tao danh sach
void khoiTaoList(list *l)
{
    l->pHead = l->pTail = NULL;
}

//Khoi tao 1 node
node * createNode(nhanvien *nv)
{
    node *p= (node *)malloc(sizeof(node));
    p->data = *nv;
    p->next = NULL;
    return p;
}

//Them node vao danh sach
void addTail(list *l,node *p)
{
    if(l->pHead == NULL)
    {
        l->pHead = l->pTail = p;
        return;
    }
    l->pTail->next = p;
    l->pTail = p;
}

//Khoi tao ham nhap thong tin nhan vien va them nhan vien vao cuoi danh sach
void createNhanVien(list *l)
{
    nhanvien *nv = (nhanvien *)malloc(sizeof(nhanvien));
    printf("\nNhap id nhan vien: ");
    fflush(stdin);
    gets(nv->id);
    printf("\nNhap ho va ten nhan vien: ");
    fflush(stdin);
    gets(nv->ho_ten);
    printf("\nNhap chuc vu cua nhan vien: ");
    fflush(stdin);
    gets(nv->chuc_vu);
    printf("\nNhap sdt nhan vien: ");
    scanf("%d",&nv->so_dien_thoai);
    addTail(l,createNode(nv));
    free(nv);
}


//Ham hien thi danh sach
void outputLIST(list *l)
{
    printf("%-10s%-25s%-20s%-15s\n","ID","Ho ten","Chuc vu","So dien thoai");
    node *p = l->pHead;
    while(p != NULL)
    {
        printf("%-10s%-25s%-20s%-15d\n",p->data.id,p->data.ho_ten,p->data.chuc_vu,p->data.so_dien_thoai);
        p = p->next;
    }
}

//Ham xoa nhan vien theo ma id

void removeHead(list *l,node *p)
{
    l->pHead = p->next;
    free(p);
}
void removeTail(list *l,node *p)
{
    node *q = l->pTail;
    p->next = NULL;
    l->pTail = p;
    free(q);
}
void removeBatKy(list *l,node *p)
{
    node *k = p->next;
    p->next = p->next->next;
    free(k);
}

void removeID(list *l,char id[])
{
    node *p = l->pHead;
    if(strcmp(l ->pHead->data.id,id) == 0)
    {
        removeHead(l,p);
        return;
    }
    while(p!=NULL)
    {
        if(strcmp(p->next->data.id,id) == 0)
        {
            if(p->next == l->pTail)
            {
                removeTail(l,p);
                return;
            }
            removeBatKy(l,p);
            break;
        }
        p = p->next;
    }

}

//Menu
void menu1()
{
    printf("\n==============================================================================");
    printf("\n||            1. Tao danh sach nhanh vien                                   ||");
    printf("\n||            2. Hien thi danh sach nhan vien                               ||");
    printf("\n||            3. Xoa nhan vien                                              ||");
    printf("\n||            4. Ket thuc                                                   ||");
    printf("\n==============================================================================");
}



int a()
{
    list *l = (list *)malloc(sizeof(list));
    khoiTaoList(l);
    do
    {
        menu1();
        int luachon;
        printf("\nLua chon cua ban: ");
        scanf("%d",&luachon);
        switch(luachon)
        {
        case 1:
        {
            createNhanVien(l);
            break;
        }
        case 2:
        {
            outputLIST(l);
            break;
        }
        case 3:
        {
            printf("\nNhap id nhan vien ban muon xoa: ");
            char id[20];
            fflush(stdin);
            gets(id);
            removeID(l,id);
            break;
        }
        case 4:
        {
            return 0;
        }
        default:
        {
            printf("Nhap sai vui long nhap lai!!");
        }
        }

    }
    while(1);

    return 0;
}
