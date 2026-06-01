//zadacha 1: vnesuvame brojki od tastatura i tie se sortiraat vo niza, po sekoe vnesuvanje na eden element (vo nieden moment nizata da ne bide nesortirana, znachi vo sekoj moment da imame sortirana lista)

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int value;
    Node *next;
    Node(int val) : value(val), next(nullptr){}
};

struct LinkedList{
    Node *head = nullptr;
    LinkedList() : head(nullptr){}
};

void sorted_list(LinkedList& l, int value){
    Node *newNode = new Node(value);
    if(l.head == nullptr || l.head->value >= value){
        newNode->next = l.head;
        l.head = newNode;
        return;
    }

    Node *current = l.head;
    while(current->next != nullptr && current->next->value < value){
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void printList(const LinkedList& l){
    Node *current = l.head;
    while(current != nullptr){
        cout<<current->value<<" ";
        current = current->next;
    }
    cout<<"\n";
}

int main(){
    LinkedList l;
    int n, val;
    cin>>n;
    while(n--){
        cin>>val;
        sorted_list(l, val);
    }
    printList(l);
    return 0;
}

//zadacha 2: imame dve listi, da gi spoime i finalnata lista da e sortirana, bez duplikati
    //a) moze vnesenite listi da se vekje sortirani zasebno
    //b) moze vnesenite listi da ne se sortirani ushte pri vnesot
//zadacha 3: da napravime bubble sort i insertion sort za listata shto kje ja vneseme
//note: zad. 2 i 3 moze da se spojat vo edna, ne smee da se pravat kopii od listata, mora site promeni vo sekoj moment da se vrz originalnata niza

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int value;
    Node* next;
    Node(int val) : value(val), next(nullptr){}
};

struct List{
    Node* head;
    List() : head(nullptr){}

    void insertList(int val){
        Node* newNode = new Node(val);
        if (!head){
            head = newNode;
        }
        else{
            Node* temp = head;
            while(temp->next){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void print(){
        Node* temp = head;
        while(temp){
            cout<< temp->value <<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    void combine(List& vtoraLista){
        Node* tmp1 = head;
        Node* tmp2 = vtoraLista.head;
        List combinedList;

        while(tmp1 && tmp2){
            if(tmp1->value < tmp2->value){
                if(!combinedList.sodrzi(tmp1->value)){
                    combinedList.insertList(tmp1->value);
                }
                tmp1 = tmp1->next;
            }
            else if(tmp1->value > tmp2->value){
                if(!combinedList.sodrzi(tmp2->value)){
                    combinedList.insertList(tmp2->value);
                }
                tmp2 = tmp2->next;
            }
            else{
                if(!combinedList.sodrzi(tmp1->value)){
                    combinedList.insertList(tmp1->value);
                }
                tmp1 = tmp1->next;
                tmp2 = tmp2->next;
            }
        }

        while(tmp1){
            if(!combinedList.sodrzi(tmp1->value)){
                combinedList.insertList(tmp1->value);
            }
            tmp1 = tmp1->next;
        }

        while(tmp2){
            if(!combinedList.sodrzi(tmp2->value)){
                combinedList.insertList(tmp2->value);
            }
            tmp2 = tmp2->next;
        }

        head = combinedList.head;
    }

    bool sodrzi(int val){
        Node* temp = head;
        while(temp){
            if(temp->value == val){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void sortList(){ //bubble sort
        if(!head || !head->next){
            return;
        }
        bool swapped;
        do{
            swapped = false;
            Node* temp = head;
            while(temp && temp->next){
                if(temp->value > temp->next->value){
                    int tempvalue = temp->value;
                    temp->value = temp->next->value;
                    temp->next->value = tempvalue;
                    swapped = true;
                }
                temp = temp->next;
            }
        }
        while(swapped);
    }
};

int main() {
    List list1;
    List list2;
    int n,m;
    cin>>n;
    while(n--){
        int a;
        cin>>a;
        list1.insertList(a);
    }
    cin>>m;
    while(m--){
        int a;
        cin>>a;
        list2.insertList(a);
    }
    list1.combine(list2);
    list1.sortList();
    list1.print();
    return 0;
}

//zadacha 4: implementacija na dvojna lista: ADD - stava na kraj po default, ako e specificirana dr poz., togash na taa, REMOVE - se trga cel node (so delete), SEARCH - funkcii
