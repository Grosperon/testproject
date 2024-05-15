#include <iostream>

using namespace std;
struct Node
{
    int data;
    Node *left;//все меньшие
    Node *right;//все большие
};

class tree{
private:
    Node *head;
    int length;
    int hight;
public:
    tree() //конструктор класса без параметров
    {
        head = NULL;
        length = 0;
        hight = 0;
    }

    void addNode(int d){
        length ++;//количество ячеек
        if(head == NULL)  {
            head->data = d;
            head->left = NULL;
            head->right = NULL;  //если создаем первый узел
            }
        else
        {
            Node *nd = new Node;
            nd = head;
            while (nd != NULL ){
            if(d>nd->data) nd = nd->right;
            else nd = nd->left;
            }
            nd->data = d;
            nd->left = NULL;
            nd->right = NULL;
        }
}



    void poisk(int z){
        Node *nd = new Node;
        nd = head;
        while(z != nd->data){
            if(nd->left == NULL && nd->right == NULL) {
                cout<<"no"<<endl;
                break; }
            else
            if(z>nd->data) nd = nd->right;
            else nd = nd->left;
            if(z == nd->data) cout<<"yes"<<endl;
            }
    }
    void LLL(){cout<<length<<" "<<hight<<endl;}//количество чисел в дереве
//    void printList()//вывод списка
//    {
//        Node *c = head;
//
//        while(c != NULL)
//        {
//            cout << c->data<<" ";
//            c = c->next;
//        }
//        cout<< endl;
//    }
    void prefix(){ //префикснаня форма обхода дерева
    if( tree != NULL )
    {
        cout<< tree -> data;
        prefix(tree -> left);
        prefix(tree -> right);
        }


    }
    void infix(){
    if(tree != NULL)
    {
        infix(tree -> left);
        cout<< tree -> data;
        infix(tree -> right);

        }

    }
    void postfix() {
    if(tree != NULL)
    {
        postfix(tree -> left);
        postfix(tree -> right);
        cout<< tree -> data;
    }

        };
int main()
{
    tree A;
    int n;
    cin>>n;
    for(int i =0; i<n; i++){
        int a;
        cin>>a;
        cout<<1;
        A.addNode(a);
        }


}
