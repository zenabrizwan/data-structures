 #include<iostream>
using namespace std;

class doublylinkedlist;


class node{

    friend doublylinkedlist;
    int data;
    node *next;
    node *prev;

};

class doublylinkedlist{
private:
    node *head;

public:

    doublylinkedlist(){
    head=nullptr;                //constructor of class
    }


     bool insertatend(int val){

    node *temp=head;
    while(temp!=nullptr){
                                    //now temp has reached the last node
        temp=temp->next;
    }
    node *n=new node;
    n->data=val;                 // a new node is made and the value is stored in there
    n->next=nullptr;
    n->prev=temp;                 //the new node is attached to the last node

    return 1;
    }

    bool insertatstart(int val){


    node *n=new node;                     //a new node is made and the value is placed there
    n->data=val;
    n->next=head;                         //the next of the new node is given the address of head becomes the 2nd node now
    n->prev=nullptr;

    return 1;
    }


    void display(){
    node *temp=head;                          //a newptr is created pting at head

    while(temp=nullptr){
        cout<<temp->data;
        temp=temp->next;                    //temp is moved to the last node and the values are displayed side by side
        cout<<endl;

    }

    }

    bool deletespecificvalue(int sv){
    node *temp=head;
    int counter=1;                              //new ptr is created and given the address of head

    while(counter!=sv && temp->next!=nullptr){

        temp=temp->next;
        counter++;                              //move to the index where the value is stored

    }
    if(temp->next!=nullptr){
    temp->prev->next=temp->next;              //once we reach that value, we pt the previous node's
    temp->next->prev=temp->prev;              // next at the next node and vice versa and then delete temp
    }
    delete temp;
    }

    bool deleteatstart(){
        if(head==nullptr){
            return 0;
        }
        else{
    node *n=head;            //storing the value of head in another pointer and thenpointing head to the next node and then
    head=head->next;         //deleting the actual value of head in n
    head->prev=nullptr;
    delete n;
        }
    return 1;
    }

    bool deleteatend(){
    node *temp=head;                     //created a ptr and moved it forward then deleted the last node and put
                                        //nullptr in the secondlast node
    while(temp->next!=nullptr){
        temp=temp->next;

    }
    temp->prev->next=nullptr;
    delete temp;
    return 1;

    }
    bool sortedinsert(int val){
        node *temp=head;
    if (head==0){
        return 0;
    }
    else{
            while(temp->next!=nullptr){
                if(temp->data<=val){
                    temp=temp->next;
                }                                          //until node data is lesser than the value to be inserted
                else{                                      //we move the temp ptr forward, then when it reaches a value greater,
                    node *n=new node;                    //we attach a new node with the value between like we did in inserspecicvalue
                    n->data=val;                         //function
                    temp->next=n->prev;
                    n->next=temp->next->prev;
                }

            }


    }
     return 1;
    }

    node *search(int val){
    node *temp;
    int counter=0;
    while(temp->next!=nullptr){
    if(temp->data==val){                                //moved the new ptr forward till the index is reavhed then fit the new
        cout<<"value found at "<<counter<<" index";      //node with the value inserted between
    }
    else{
        temp=temp->next;
        counter++;
    }
    }

    }
    ~doublylinkedlist(){
    while(head!=nullptr){
            node *temp=head;
        head=head->next;
        delete head;                      //destructor
    delete temp;
    }

    }
};



int main()
{
    int x;
doublylinkedlist L1;
 cout << "enter values to insert at start" << endl;
    for (int i = 0; i < 3; i++) {

        cin >>x;
        L1.insertatstart(x);
    }

    cout << "enter elements to insert at end" << endl;
    for (int i = 0; i < 3; i++) {

        cin >>x;
        L1.insertatend(x);
    }
    int y;
    cout<<"enter value for sorted insert";
    cin>>y;
L1.sortedinsert(y);
int z;
cout<<"enter specific value to be deleted";
cin>>z;
L1.deletespecificvalue(z);
L1.deleteatstart();
L1.deleteatend();
L1.display();


return 0;

}
