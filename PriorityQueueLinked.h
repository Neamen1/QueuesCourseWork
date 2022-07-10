#ifndef COURSEWORK_PRIORITYQUEUELINKED_H
#define COURSEWORK_PRIORITYQUEUELINKED_H

template <typename Data>
struct Node
{
    Data data;
    Node* next = nullptr;
    Node(Data object);
};


template <typename Data>
struct PriorityQueueLinked{
private:
    Node<Data> *head = nullptr;
    int currentSize=0;
public:

    void push(Data object);
    Data top();
    Data pop();
    int size();
    bool empty();
    void print();
    ~PriorityQueueLinked();
};

template <typename Data>
Node<Data>::Node(Data object){
    data = object;
}

template<typename Data>
Data PriorityQueueLinked<Data>::top(){
    return head->data;
}

template<typename Data>
Data PriorityQueueLinked<Data>::pop(){       // Removes the element with the highest priority
    if(head == nullptr){
        return {};
    }
    Node<Data>* temp = head;
    Data tempData = temp->data;
    head = head->next;
    currentSize--;
    delete temp;
    return tempData;
}

// Function to push according to priority
template<typename Data>
void PriorityQueueLinked<Data>::push(Data object)
{
    currentSize++;
    Node<Data>* temp = new Node<Data>(object);    // Create new Node with new data

    if(head == nullptr){
        head = temp;
        return;
    }
    if (head->data < object)        //if object that we add is bigger than head (head has the biggest priority)
    {
        temp->next = head;          // Insert new Node before head
        head = temp;                //change head pointer
    }
    else
    {
        Node<Data>* iter = head;
        //Go through the list and find a position to insert new node
        while ((iter->next != nullptr) && (object < iter->next->data))
        {
            iter = iter->next;
        }

        //inserting new node between  iter and iter->next
        temp->next = iter->next;
        iter->next = temp;
    }
}

template<typename Data>
int PriorityQueueLinked<Data>::size() {
    return currentSize;
}

//Check if list is empty
template<typename Data>
bool PriorityQueueLinked<Data>::empty()
{
    return head == nullptr;
}

template <typename Data>
void PriorityQueueLinked<Data>::print()
{
    if(currentSize==0){
        std::cout<<"Queue is empty"<<std::endl;
        return;
    }
    Node<Data> *temp = head;
    while (temp!= nullptr){
        std::cout<<temp->data<<", ";
        temp=temp->next;
    }
    std::cout<<std::endl<<std::endl;
}

template <typename Data>
PriorityQueueLinked<Data>::~PriorityQueueLinked(){
    Node<Data> *temp = head;
    Node<Data> *next = head;
    while(temp!= nullptr){
        next = temp->next;
        delete temp;
        temp=next;
    }

}

#endif //COURSEWORK_PRIORITYQUEUELINKED_H
