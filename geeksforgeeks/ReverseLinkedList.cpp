#include <bits/stdc++.h>
//ko dùng mảng phụ / ds phụ
using namespace std;
struct Node
{
    int data;
    Node *pNext;
};
struct List
{
    Node *pHead, *pTail;
};

void Init(List &l) //khởi tạo list
{
    l.pHead = l.pTail = NULL;
}

Node* GetNode(int data) //tạo 1 Node
{
    Node *p = new Node;
    if(p == NULL) return NULL;
    p->data = data;
    p->pNext = NULL;
    return p;
}
void AddTail(List &l, Node* x)
{
    if(l.pHead == NULL)
    {
        l.pHead = l.pTail = x;
    }
    else
    {
       l.pTail->pNext = x;
       l.pTail = x;
    }
}
void InPut(List &l) // tuong đương thêm node cuối ds
{
    // khởi tạo 1 list rồi làm gì thì làm
    Init(l);

    int n, data;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> data;

        //đóng gói data vào 1 node => tạo 1 Node
        Node *q;
        q = GetNode(data);
        AddTail(l, q);
    }
}

void DaoNguocDSLK(List &l, int h, int k)
{
    if(h >= k || l.pHead == NULL) return;
    int dd = 0;
    Node *p = l.pHead;
    int m = k / 2 + 1;
    Node *first, *last;
    while(h <= m)
    {
        Node *prev = p;
        for ( ; prev; prev = prev->pNext)
        {
            dd++;
            if (dd == h) 
            {
                first = prev;
                p = prev->pNext;
            }
            else if (dd == k)
            {
                last = prev;
                swap(first->data, last->data);
                break;
            }
        }
        dd = h;
        h++;
        k--;
    }
}


void OutPut(List l)
{
    for (Node *p = l.pHead; p; p = p->pNext)
        cout << p->data << " ";
}
int main()
{
    List l;
    InPut(l);
    int h, k;
    cin >> h >> k;
    DaoNguocDSLK(l, h, k);
    OutPut(l);
    return 0;
}