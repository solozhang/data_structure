#include<iostream>
using namespace std;

typedef struct Node{int key; struct Node *next;}NODE;
class CNode{
    public:
        CNode();
        ~CNode();
        void InsertList(int k);
        void ReverseList();
        void PrintList();
    private:
        NODE * List;
};
CNode::CNode()
{
    NODE *Head;
    Head = new NODE;
    Head->key = -1;
    Head->next = NULL;
    List = Head;
}
CNode::~CNode()
{ 
    Node * DeleteNode = List;
    Node * WillDeleteNode;
    do{
        
        WillDeleteNode = DeleteNode->next;
        delete DeleteNode;
        DeleteNode = WillDeleteNode;
    }while(DeleteNode!=NULL);
}
void CNode::InsertList(int k)
{
    NODE *NewNode = new NODE;
    NewNode->key = k;
    NewNode->next = List->next;
    List->next = NewNode;
}
void CNode::PrintList()
{
    NODE * PrintNode = List;
    while(PrintNode){
        cout<<"key:"<<PrintNode->key<<" address:"<<PrintNode<<endl;
        PrintNode = PrintNode->next;
    }
}
void CNode::ReverseList()
{
    NODE *Head = List;
    NODE *NextNode = List->next;
    NODE * First, *PreNode, *NowNode;
    if(!NextNode){
        cout<<"List is empty!"<<endl;
    }else{
//        First = List->next;
        NowNode = NextNode;
        NextNode = NextNode->next;
//        First->next = NULL;
        PreNode = NULL;
        while(NowNode){
            NowNode->next = PreNode;
            PreNode = NowNode;
            NowNode = NextNode;
            if(!NowNode)
                break;
            NextNode = NextNode->next;
        }
        List->next = PreNode;
    }
}
int main(void)
{
    NODE *List;
    int a[5] = {1,2,3,4,5};
    CNode ObjList;
    for(int i=0;i<2;i++){
        ObjList.InsertList(a[i]);
    }
    ObjList.PrintList();
    ObjList.ReverseList();
    ObjList.PrintList();
}
