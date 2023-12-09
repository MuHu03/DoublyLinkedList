#include <iostream>
using namespace std;
class node {
    friend class doublyLinkedList;
    node *prev;
    int info;
    node *next;
};
class doublyLinkedList{
private:
    node *first;
public:
    doublyLinkedList(){
        first=NULL;
    }
    int empty(){
        if(first==NULL){
            return 1;
        } else {
            return 0;
        }
    }
    node* createNode(int x){
        node *newNode=new node;
        if (newNode==NULL){
            cout<<"there is a problem in creating new node";
        } else {
            newNode->prev = NULL;
            newNode->info = x;
            newNode->next = NULL;
            return newNode;
        }
    }
    void insert(int x){
        node *newNode= createNode(x);
        if (empty()){
            first=newNode;
        } else {
            node *temp=first;
            while (temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->prev=temp;
        }
    }
    void addToBeginning(int x){
        node *newNode= createNode(x);
        newNode->next=first;
        first->prev=newNode;
        first=newNode;
    }
    node* search(int x){
        //If you need to access a specific node, you can use this function
        if (empty()){
            cout<<"link list is empty"<<endl;
        } else {
            node *temp=first;
            while (temp != NULL && temp->info!=x){
                temp=temp->next;
            }
            if (temp==NULL){
                cout<<"The desired node was not found"<<endl;
            } else{
                return temp;
            }
        }
    }
    void deleteLastNode(){
        if (empty()) {
            cout << "List is empty" << endl;
        } else {
            node* temp = first;
            while (temp->next!=NULL){
                temp=temp->next;
            }
            temp->prev->next=NULL;
            delete temp;
        }
    }
    void deleteNode(char ch){
        switch (ch) {
            case 'l':deleteLastNode();
                break;
            case 'e':
                node *foundedNode;
                cout<<"Enter the information of the node you needed to delete : "<<endl;
                int x;
                cin>>x;
                foundedNode=search(x);
                if (foundedNode==first){
                    delete foundedNode;
                } else {
                    foundedNode->prev->next=foundedNode->next;
                    foundedNode->next->prev=foundedNode->prev;
                    delete foundedNode;
                    cout<<x<<"was deleted"<<endl;
                }
                break;
            default:
                cout<<"you enter wrong char try again: "<<endl;
                char a;
                cin>>a;
                deleteNode(a);
                break;
        }
    }
    void merging(doublyLinkedList sublist){
        node *temp1=first;
        node *temp2=sublist.first;
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
        temp1->next=temp2;
        temp2->prev=temp1;
    }
    void insertAfter(int info , int x){
        node *foundedNode=search(info);
        node *newNode= createNode(x);
        newNode->next=foundedNode->next;
        newNode->prev=foundedNode;
        foundedNode->next->prev=newNode;
        foundedNode->next=newNode;
    }
    void print(){
        node *temp=first;
        int i=1;
        while (temp!=NULL){
            cout<<i<<" th node is : "<<temp->info<<endl;
            temp = temp->next;
            i++;
        }
    }
    ~doublyLinkedList(){};

};

int main() {
    doublyLinkedList li1,li2;
    for (int i = 1; i <=3 ; ++i)
        li1.insert(i);
    cout<<"this is your first link list : "<<endl;
    li1.print();
    cout<<"==========================="<<endl;
    cout<<"insert 255 after 2 "<<endl;
    li1.insertAfter(2,255);
    li1.print();
    cout<<"==========================="<<endl;
    cout<<"delete last node : "<<endl;
    li1.deleteLastNode();
    li1.print();
    cout<<"==========================="<<endl;
    cout<<"add 235 to the beginning : "<<endl;
    li1.addToBeginning(235);
    li1.print();
//    cout<<"==========================="<<endl;
//    cout<<"if you want to delete last node enter l and if you want to delete espesific info enter e : ";
//    char x;
//    cin>>x;
//    li1.deleteNode(x);
    cout<<"==========================="<<endl;
    cout<<"merge"<<endl;
    for(int j=10;j<=30;j=j+10)
        li2.insert(j);
    li1.merging(li2);
    li1.print();


    return 0;
}
