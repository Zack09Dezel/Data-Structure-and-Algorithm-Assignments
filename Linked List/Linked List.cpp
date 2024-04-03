#include <iostream>
using namespace std;

class Node{
    public: 
        int id;
        Node *next;

        Node(){
            next = NULL;
        }

};

class LinkedList{
    public: 
        Node *head, *tail;

        LinkedList(){
            head = tail = NULL;
        }

        //Got backslashed because it outputs the "," before the first element, not after.
        // void outputAll(){
        //     Node *tmp = head;
        //     while(tmp != NULL){
        //         cout << " > " << tmp -> id;
        //         tmp = tmp -> next;
        //     }
        // }

        //This is the updated version of the function.
        void outputAll(){
            Node *tmp = head;
            bool First = true; 

            while(tmp != NULL){
                if (First) {
                    First = false; 
                }else{
                    cout << ", ";
                }
                cout << tmp->id;
                tmp = tmp->next;
            }
        }

        //Got backslashed because it doesn't update the tail in "if (head == NULL)".
        // head->next is pointing to NULL so it will break the link.
        // void insertHead(int data){
        //     Node *node = new Node;
        //     node -> id = data;

        //     if(head == NULL){
        //         Node *tmp = head;
        //         head = node;
        //         head -> next = tmp;
        //     }
        // }

        //This is the updated version of the function.
        void insertHead(int data){
            Node *node = new Node;
            node->id = data;

            if(head == NULL){
                head = node;
                tail = node;
            }else{
                node->next = head;
                head = node;
            }
        }

        void insertTail(int data){
            Node *node = new Node;
            node -> id = data;

            if(head == NULL){
                head = tail = node;
            }else{
                tail -> next = node;
                tail = node;
            }  
        }

        void insertDataAfter(int data, int after){
            if(head == NULL){
                cout << "LinkedList is Empty" << endl;
            }else if(after == tail->id){
                insertTail(data);
            }else{
                Node *tmp = head;
                while(tmp != NULL && tmp->id!=after){
                    tmp = tmp->next;
                }

                if(tmp == NULL){
                    cout << "No data" << endl;
                }else{
                    Node*newNode = new Node();
                    newNode->id = data;
                    
                    newNode->next = tmp->next;
                    tmp->next = newNode;
                }
            }
        }

        void deleteData(int target){
            Node *current = head;
            Node *prev = NULL;

            if(current != NULL && current->id == target){
                head = current->next;
                delete current;
                return;
            }

            while(current != NULL && current->id != target){
                prev = current;
                current = current->next;
            }

            prev->next = current->next;
            delete current;
        }

};

int main() {
    LinkedList *LL = new LinkedList();

    LL->insertHead(1);

    LL->insertTail(2);
    LL->insertTail(3);

    cout << endl;
    cout << "All elements: ";
    LL->outputAll();
    cout << endl;

    LL->insertDataAfter(4, 2);

    cout << "Elements after insertion: ";
    LL->outputAll();
    cout << endl;

    LL->deleteData(2);

    cout << "Elements after deletion: ";
    LL->outputAll();
    cout << endl;

    delete LL;

    return 0;
}
