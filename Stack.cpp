#include <iostream>
using namespace std;

class Stack{
public:
    int size = 0, top = -1; 
    char *items;

    Stack(int capacity){ 
        size = capacity;
        items = new char[size];
    }

    void push(char item){
        if(top == size-1){
            cout<<"Stack is full, unable to push more elements"<<endl;
        }else{
            top++;
            items[top] = item;
        }
    }

    char pop(){
        char item;
        if(top == -1){
            cout<<"Stack is empty, no element to pop"<<endl;
        }else{
            item = items[top];
            cout << "Element Popped: " << item << endl; //For better visualization 
            top--; 
        }
        return item;
    }
};

int main(){

    Stack bag(5);

    bag.push('A'); 
    bag.push('B'); 
    bag.push('C'); 
    bag.push('D');

    while(bag.top != -1){
        bag.pop();
    }

    return 0;
}
