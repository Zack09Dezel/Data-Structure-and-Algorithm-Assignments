#include <iostream>
using namespace std;

class Queue{
private:
    int capacity, *items, frontIndex, rearIndex, itemCount;
public:
    Queue(int queueCapacity){
        capacity = queueCapacity;
        items = new int[capacity];
        frontIndex = 0;
        rearIndex = -1;
        itemCount = 0;
    }
    void enqueue(int value){
        if(full()){
            cout << "Queue is full. Unable to enqueue.\n";
            return;
        }
        rearIndex = (rearIndex + 1) % capacity;
        items[rearIndex] = value;
        itemCount++;
    }
    void dequeue(){
        if(empty()){
            cout << "Queue is empty. Unable to dequeue.\n";
            return;
        }
        frontIndex = (frontIndex + 1) % capacity;
        itemCount--;
    }
    int front(){
        if(empty()){
            cout << "Queue is empty. No front element.\n";
            return 0;
        }
        return items[frontIndex];
    }
    bool empty(){
        return (itemCount == 0);
    }
    bool full(){
        return (itemCount == capacity);
    }
    int size(){
        return itemCount;
    }
};

int main(){
    Queue myQueue(5);
    
    myQueue.enqueue(15);
    myQueue.enqueue(25); 
    myQueue.enqueue(35);

    cout<<"Front element: "<<myQueue.front()<<endl;

    myQueue.dequeue();
    cout<<"Front element post-dequeuing: "<<myQueue.front()<<endl;

    myQueue.enqueue(45), myQueue.enqueue(55);

    cout <<"Queue size: "<<myQueue.size()<<endl;

    while(!myQueue.empty()){
        cout<<"Dequeued: "<< myQueue.front()<<endl;
        myQueue.dequeue();
    }

    cout<<"Queue size after dequeuing all the elements: "<<myQueue.size()<<endl;

    return 0;
}
