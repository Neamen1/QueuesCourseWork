#ifndef COURSEWORK_QUEUEVECTOR_H
#define COURSEWORK_QUEUEVECTOR_H
#include <vector>

template <typename Data>
struct QueueVector{
private:
    std::vector<Data> elements;
public:
    bool empty();
    int size();
    void push(Data object);
    Data pop();
    Data top();
    void print();
};

template <typename Data>

bool QueueVector<Data>::empty() {
    return elements.empty();
}

template <typename Data>
int QueueVector<Data>::size() {
    return elements.size();
}

template<typename Data>
void QueueVector<Data>::push(Data object){
    elements.push_back(object);
}

template<typename Data>
Data QueueVector<Data>::pop(){
    if(empty()){
        std::cout<<"queue is empty, can't pop element"<<std::endl;
        return {};
    }
    else {
        Data temp = elements.front();
        elements.erase(elements.begin());
        return temp;
    }
}


template <typename Data>
Data QueueVector<Data>::top()
{
    return elements.front();
}

template <typename Data>
void QueueVector<Data>::print()
{
    if(size()==0){
        std::cout<<"Queue is empty"<<std::endl;
        return;
    }
    for(auto el:elements){
        std::cout<<el<<", ";
    }
    std::cout<<std::endl<<std::endl;
}
#endif //COURSEWORK_QUEUEVECTOR_H
