#include <iostream>

using namespace std;
struct Node
{
    int data;
    Node *left; // все меньшие
    Node *right; // все большие
};

class tree{
private:
    Node *head;
    int length;
    int hight;
public:
    tree() // конструктор класса без параметров
    {
        head = NULL;
        length = 0;
        hight = 0;
    }

    void addNode(int d){
        length++;
        if(head == NULL)  {
            head = new Node;
            head->data = d;
            head->left = NULL;
            head->right = NULL;
        }
        else
        {
            Node *nd = head;
            while (nd != NULL ){
                if(d > nd->data) {
                    if(nd->right == NULL) {
                        nd->right = new Node;
                        nd->right->data = d;
                        nd->right->left = NULL;
                        nd->right->right = NULL;
                        break;
                    } else {
                        nd = nd->right;
                    }
                } else {
                    if(nd->left == NULL) {
                        nd->left = new Node;
                        nd->left->data = d;
                        nd->left->left = NULL;
                        nd->left->right = NULL;
                        break;
                    } else {
                        nd = nd->left;
                    }
                }
            }
        }
    }

    void poisk(int z){
        Node *nd = head;
        while(nd != NULL && z != nd->data){
            if(z > nd->data)
                nd = nd->right;
            else
                nd = nd->left;
        }

        if(nd == NULL)
            cout << "no" << endl;
        else
            cout << "yes" << endl;
    }

    void LLL() {
        cout << length << " " << hight << endl;
    }

    void prefix(Node* tree) {
        if (tree != NULL)
        {
            cout << tree->data;
            prefix(tree->left);
            prefix(tree->right);
        }
    }

    void infix(Node* tree) {
        if (tree != NULL)
        {
            infix(tree->left);
            cout << tree->data;
            infix(tree->right);

        }
    }

    void postfix(Node* tree) {
        if (tree != NULL)
        {
            postfix(tree->left);
            postfix(tree->right);
            cout << tree->data;
        }
    }
};

int main()
{
    tree A;
    int n, a;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        A.addNode(a);
    }

    return 0;
}
