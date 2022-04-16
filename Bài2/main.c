#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char sbd[20];
    char full_name[100];
    float diem_toan;
    float diem_ly;
    float diem_anh;
    float tong_diem;
} sinhvien;

typedef struct NODE
{
    sinhvien data;
    struct NODE *next;
} node;

typedef struct
{
    node *pHead;
    node *pTail;
} list;

void createList(list *l)
{
    l->pHead = l->pTail = NULL;
}

node *createNode(sinhvien sv)
{
    node *p = (node *)malloc(sizeof(node));
    p->data = sv;
    p->next = NULL;
    return p;
}

void addList(list *l,node *p)
{
    if(l->pHead == NULL)
    {
        l->pHead = l->pTail = p;
        return;
    }
    l->pTail->next = p;
    l->pTail = p;
}


void inputData(list *l)
{
    sinhvien sv;
    printf("\nNhap so bao danh cua sinh vien : ");
    fflush(stdin);
    gets(sv.sbd);
    printf("\nNhap ho va ten cua sinh vien : ");
    fflush(stdin);
    gets(sv.full_name);
    printf("\nNhap diem toan : ");
    scanf("%f",&sv.diem_toan);
    printf("\nNhap diem ly : ");
    scanf("%f",&sv.diem_ly);
    printf("\nNhap diem anh : ");
    scanf("%f",&sv.diem_anh);
    sv.tong_diem = sv.diem_anh + sv.diem_ly + sv.diem_toan;
    addList(l,createNode(sv));
    printf("\nThem thanh cong nhan phim bat ky de tiep tuc!\n");
}

void outputData(list *l)
{
    int i=1;
    int d=-15;
    int y=2;
    node *p = l->pHead;
    printf("%-5s%-10s%-25s%-15s%-15s%-15s%-5s\n","STT","SBD","Ho ten","Diem Toan","Diem Ly","Diem TA","Tong");
    while(p!= NULL)
    {
        printf("%-5d%-10s%-25s%*.*f%*.*f%*.*f%*.*f\n",i++,p->data.sbd,p->data.full_name,d,y,p->data.diem_toan,
                                        d,y,p->data.diem_ly,d,y,p->data.diem_anh,d,y,p->data.tong_diem);
        p = p->next;
    }
}

void swap(sinhvien *sv1,sinhvien *sv2)
{
    sinhvien sv3 = *sv1;
    *sv1 = *sv2;
    *sv2 = sv3;
}

void sapxepToan(list *l)
{
    for(node *p = l->pHead;p != NULL ;p = p->next)
    {
        for(node *k = p->next;k != NULL;k = k->next)
        {
            if(p->data.diem_toan > k->data.diem_toan)
            {
                swap(&p->data,&k->data);
            }
        }
    }
}
void sapxepLy(list *l)
{
    for(node *p = l->pHead;p != NULL ;p = p->next)
    {
        for(node *k = p->next;k != NULL;k = k->next)
        {
            if(p->data.diem_ly > k->data.diem_ly)
            {
                swap(&p->data,&k->data);
            }
        }
    }
}
void sapxepAnh(list *l)
{
    for(node *p = l->pHead;p != NULL;p = p->next)
    {
        for(node *k = p->next;k != NULL;k = k->next)
        {
            if(p->data.diem_anh > k->data.diem_anh)
            {
                swap(&p->data,&k->data);
            }
        }
    }
}
void sapxepTong(list *l)
{
    for(node *p = l->pHead;p != NULL;p = p->next)
    {
        for(node *k = p->next;k != NULL;k = k->next)
        {
            if(p->data.tong_diem > k->data.tong_diem)
            {
                swap(&p->data,&k->data);
            }
        }
    }
}

void menu()
{
    printf("\n================================MENU=================================");
    printf("\n||                    1. Tao danh sach thi sinh                    ||");
    printf("\n||                    2. Hien thi danh sach thi sinh               ||");
    printf("\n||                    3. Sap sep diem thi                          ||");
    printf("\n||                    4. Ket thuc                                  ||");
    printf("\n=====================================================================");
}

void menu2()
{
    printf("\n================================MENU 2=================================");
    printf("\n||                    1.Sap xep theo diem Toan                       ||");
    printf("\n||                    2.Sap xep theo diem Ly                         ||");
    printf("\n||                    3.Sap xep theo diem Anh                        ||");
    printf("\n||                    4.Sap xep theo diem Tong                       ||");
    printf("\n=======================================================================");
}

int main()
{
    list *l = (list *)malloc(sizeof(list));
    createList(l);
    do
    {
        system("cls");
        int luachon = 0;
        menu();
        printf("\nLua chon cua ban: ");
        scanf("%d",&luachon);
        switch(luachon)
        {
        case 1:
        {
            system("cls");
            inputData(l);
            system("PAUSE");
            break;
        }
        case 2:
        {
            system("cls");
            outputData(l);
            system("PAUSE");
            break;
        }
        case 3:
        {
            system("cls");
            menu2();
            int select;
            printf("\nLua chon cua ban: ");
            scanf("%d",&select);
            if(select == 1)
            {
                sapxepToan(l);
            }
            if(select == 2)
            {
                sapxepLy(l);
            }
            if(select == 3)
            {
                sapxepAnh(l);
            }
            if(select == 4)
            {
                sapxepTong(l);
            }
            printf("\nDanh sach sau khi sap xep: \n");
            outputData(l);
            system("PAUSE");
            break;
        }
        case 4:
        {
            return 0;
        }
        default:
        {
            printf("\nNhap sai vui long nhap lai!");
            break;
        }
        }
    }
    while(1);

    return 0;
}
