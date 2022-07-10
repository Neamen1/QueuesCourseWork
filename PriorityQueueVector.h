#ifndef COURSEWORK_PRIORITYQUEUEVECTOR_H
#define COURSEWORK_PRIORITYQUEUEVECTOR_H
#include <vector>

template <typename Data>
struct PriorityQueueVector{
private:
    std::vector<Data> elements;
    int currentSize=0;
    int getParent(int index);
    int getLeftChild(int index);
    int getRightChild(int index);

    void siftUp(int index);
    void siftDown(int index);
public:

    void push(Data object);
    Data top();
    Data pop();
    int size();
    bool empty();
    void print();
};


template <typename Data>
int PriorityQueueVector<Data>::getParent(int index) {

    return (index - 1)/2;
}

template <typename Data>
int PriorityQueueVector<Data>::getLeftChild(int index) {
    return 2*index + 1;
}

template <typename Data>
int PriorityQueueVector<Data>::getRightChild(int index) {
    return 2*index + 2;
}

template <typename Data>
void PriorityQueueVector<Data>::siftUp(int index) {
    if(index==0){
        return;
    }
    int parentIndex = getParent(index);

    if(!(elements[parentIndex] < elements[index])){
        return;
    }
    std::swap(elements[parentIndex], elements[index]);
    siftUp(parentIndex);
}

template <typename Data>
void PriorityQueueVector<Data>::siftDown(int index) {
    int leftChildIndex = getLeftChild(index);
    int rightChildIndex = getRightChild(index);
    int maxChildIndex;

    if(leftChildIndex > currentSize-1){     //if index don't have any child
        return;
    }
    if(rightChildIndex > currentSize-1){    //if exists only left child (after previous condition), maxChildIndex = leftChildIndex
        maxChildIndex = leftChildIndex;
    } else{
        maxChildIndex = elements[leftChildIndex] < elements[rightChildIndex] ? rightChildIndex : leftChildIndex;
    }

    if(elements[maxChildIndex] < elements[index]){
        return;
    }
    std::swap(elements[maxChildIndex], elements[index]);
    siftDown(maxChildIndex);
}

template <typename Data>
void PriorityQueueVector<Data>::push(Data object) {
    elements.push_back(object);
    currentSize++;
    siftUp(currentSize - 1);
}

template <typename Data>
Data PriorityQueueVector<Data>::pop() {
    if(currentSize==0){
        return {};
    }
    Data temp = elements[0];
    std::swap(elements[0], elements[currentSize-1]);
    currentSize--;
    elements.pop_back();
    siftDown(0);

    return temp;
}

template <typename Data>
Data PriorityQueueVector<Data>::top() {
    if(currentSize==0){
        return {};
    }
    return elements[0];
}

template <typename Data>
int PriorityQueueVector<Data>::size() {
    return currentSize;
}

template <typename Data>
bool PriorityQueueVector<Data>::empty() {
    return currentSize == 0;
}

template <typename Data>
void PriorityQueueVector<Data>::print()
{
    if(currentSize==0){
        std::cout<<"Queue is empty"<<std::endl;
        return;
    }
    std::vector<Data> tempElements = elements;
    int tempSize = currentSize;
    while(size()>0){
        std::cout << top()<<", " ;
        pop();
    }
    std::cout<<std::endl<<std::endl;
    currentSize = tempSize;
    elements = tempElements;
}

#endif //COURSEWORK_PRIORITYQUEUEVECTOR_H
