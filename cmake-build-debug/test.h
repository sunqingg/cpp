#include "iostream"
using namespace std;

//1、插入
void ListInsert(LinkList& L)
{

    ElemType e;
    int i;
    bool flag;
    cout << "请输入要插入的数据：" << endl;
    cin >> e;
    cout << "请输入要插入的位置：" << endl;
    cin >> i;
    flag = ListInsert(L, i, e);
    if (flag)
        cout << "插入成功!" << endl;
    else
        cout << "位置不对，插入失败！" << endl;
}

//2、删除
void ListDelete(LinkList& L)
{
    ElemType e;
    int i;
    bool flag;
    cout << "请输入要删除数据的位置：" << endl;
    cin >> i;
    flag = ListDelete(L, i, e);
    if (flag)
        cout << "删除成功，删除的数据为：" << e << endl;
    else
        cout << "位置不对，删除失败！" << endl;
}

//3、取值
void GetElem(LinkList L)
{
    ElemType e;
    int i;
    bool flag;
    cout << "请输入要获取数据的位置：" << endl;
    cin >> i;
    flag = GetElem(L, i, e);
    if (flag)
        cout << "获取的数据为：" << e << endl;
    else
        cout << "位置不对，获取数据失败！" << endl;
}

//4、查找
void LocateElem(LinkList L)
{
    ElemType e;
    LNode* p = NULL;
    bool flag;
    cout << "请输入要查找的数据：" << endl;
    cin >> e;
    flag = LocateElem(L, p, e);
    if (flag)
        cout << "查找成功，该数据的地址为：" << p << endl;
    else
        cout << "查找失败！" << endl;
}

//5、判空
void ListEmpty(LinkList L)
{
    if (L->next)
        cout << "链表不为空！" << endl;
    else
        cout << "链表为空！" << endl;
}

//6、求长
void ListLength(LinkList L)
{
    LinkList p = L->next;//p指向第一个结点
    int i = 0;
    while (p)//遍历单链表，统计结点数
    {
        i++;
        p = p->next;
    }
    cout << "链表的长度为：" << i << endl;
}

//7、清空
void ClearList(LinkList& L)
{
    LNode* p, * q;
    p = L->next;
    while (p)//从首元结点开始，依次删除
    {
        q = p->next;
        delete p;
        p = q;
    }
    L->next = NULL;//头结点指针域置空
}

//8、销毁
void DestroyList(LinkList& L)
{
    LNode* p;
    while (L)//从头结点开始依次删除
    {
        p = L;
        L = L->next;
        delete p;
    }
}

//9、打印
void PrintList(LinkList L)
{
    LinkList p = L->next;//p指向第一个结点
    int i = 0;
    while (p)//遍历单链表
    {
        i++;
        cout << "链表第" << i << "个数据为：" << p->data << endl;
        p = p->next;
    }
}

//菜单
void menu()
{
    cout << "***************************************************************************" << endl;
    cout << "***********************************1、插入*********************************" << endl;
    cout << "***********************************2、删除*********************************" << endl;
    cout << "***********************************3、取值*********************************" << endl;
    cout << "***********************************4、查找*********************************" << endl;
    cout << "***********************************5、判空*********************************" << endl;
    cout << "***********************************6、求长*********************************" << endl;
    cout << "***********************************7、清空*********************************" << endl;
    cout << "***********************************8、销毁*********************************" << endl;
    cout << "***********************************9、打印*********************************" << endl;
    cout << "***********************************0、退出*********************************" << endl;
    cout << "***************************************************************************" << endl;
}

int main()
{
    LinkList L;
    InitList(L);
    int select;
    cout << "请先创建单链表：1、前插法！ 2、后插法！" << endl;
    cin >> select;
    switch (select)
    {
        case 1://插入
            CreateList_H(L);
            system("pause");//按任意键继续
            break;
        case 2://删除
            CreateList_R(L);
            system("pause");
            break;
        default:
            cout << "输入有误,创建失败！" << endl;
            system("pause");
            break;
    }
    while (1)
    {
        system("CLS");//清屏操作
        menu();
        cout << "请输入菜单序号：" << endl;
        cin >> select;
        switch (select)
        {
            case 1://插入
                ListInsert(L);
                system("pause");//按任意键继续
                break;
            case 2://删除
                ListDelete(L);
                system("pause");
                break;
            case 3://取值
                GetElem(L);
                system("pause");
                break;
            case 4://查找
                LocateElem(L);
                system("pause");
                break;
            case 5://判断链表是否为空
                ListEmpty(L);
                system("pause");
                break;
            case 6://求单链表的长度
                ListLength(L);
                system("pause");
                break;
            case 7://清空
                ClearList(L);
                system("pause");
                break;
            case 8://销毁
                DestroyList(L);
                system("pause");
                return 0;
                break;
            case 9://打印
                PrintList(L);
                system("pause");
                break;
            case 0:
                cout << "欢迎下次使用!" << endl;//退出
                system("pause");
                return 0;
                break;
            default:
                cout << "菜单序号输入有误！" << endl;
                system("pause");
                break;
        }
    }
    system("pause");
    return 0;
}