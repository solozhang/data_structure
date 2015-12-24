#include<stdio.h>

typedef struct node{
    int key;
    node *next;
}Node;

class Linklist
{
    public:
        Linklist(int head_key=-1);
        void InsertNode(int key);
        void PrintList();
        void DeleteNode();
        int GetNode(int n);
        ~Linklist();
    private:
        Node head;
};

Linklist::Linklist(int head_key)
{
    head.key = head_key;
    head.next = NULL;
    printf("Initialing Linklist\n");
}

void Linklist::InsertNode(int key)
{
    Node *new_node = new Node;
    new_node->key = key;
    new_node->next = NULL;
    Node *pnode = &head;
    while(pnode->next)
        pnode = pnode->next;
    pnode->next = new_node;
    printf("Insert Node %d\n", key);
}

void Linklist::PrintList()
{
    Node *pnode = head.next;
    printf("Linklist is\n");
    while(pnode){
        printf("%d ", pnode->key);
        pnode = pnode->next;
    }
    printf("\n");
}

void Linklist::DeleteNode()
{
    Node *pre_node = &head;
    Node *cur_node = head.next;
    if (cur_node != NULL)
        while(cur_node->next){
            pre_node = cur_node;
            cur_node = cur_node->next;
        }
        delete cur_node;
        pre_node->next = NULL;
        printf("delete the last node\n");
}

int Linklist::GetNode(int n)
{
    Node *pnode = head.next;
    int i = 0;
    while(pnode){
        i++;
        if(i==n)
            break;
        pnode = pnode->next;
    }
    if (pnode != NULL)
        return pnode->key;
    return -999999;
}

Linklist::~Linklist()
{
    Node *cur_node = head.next;
    Node *next_node;
    while(cur_node){
        next_node = cur_node->next;
        delete cur_node;
        cur_node = next_node;
    }
}

int main(void)
{
    int key[] = {1, 2, 3, 4, 5};
    Linklist link;
    for(int i=0; i < sizeof(key)/sizeof(int);i++)
        link.InsertNode(key[i]);
    link.PrintList();
    printf("the %dth is %d\n", 4, link.GetNode(4));
    link.DeleteNode();
    link.PrintList();
    link.DeleteNode();
    link.PrintList();
    printf("the %dth is %d\n", 4, link.GetNode(4));
}
