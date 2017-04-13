#ifndef QUEUE_H
#define QUEUE_H

template <typename Type>
struct Node{
    Type data;
    Node<Type> *next;
};

template <typename Type>
struct Queue{
    Node<Type> *start;
};


template <typename Type>
Node<Type> *create_node(Type data){
	Node<Type> *newNode = new Node<Type>;
	newNode->data = data;
	newNode->next = nullptr;
	return newNode;
}

template <typename Type>
void initialize_queue(Queue<Type> &queue){
	queue.start = nullptr;
}

template <typename Type>
void queue(Queue<Type> &queue, Type data){
    Node<Type> *node = create_node(data);
    if(queue.start == nullptr){
        queue.start = node;
        return;
    }
    Node<Type> *nav = queue.start;
    while(nav->next != nullptr)
        nav = nav->next;

    nav->next = node;
    return;
}

template <typename Type>
Node<Type> dequeue(Queue<Type> &queue){
    Node<Type> temp;
    if(!(queue.start == nullptr)){
        Node<Type> *buffer = queue.start;
        temp.data = queue.start->data;
        temp.next = nullptr;
        queue.start = queue.start->next;
        delete buffer;
        return temp;
    }
}

#endif // QUEUE_H
