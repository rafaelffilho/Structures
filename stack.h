#ifndef STACK_H
#define STACK_H

template <typename Type>
struct Node{
    Type data;
    Node<Type> *prev;
};

template <typename Type>
struct Stack{
    Node<Type> *end;
};

template <typename Type>
void initialize_stack(Stack<Type> &stack){
    stack.end = nullptr;
}

template <typename Type>
Node<Type> *create_node(Type data){
    Node<Type> *temp = new Node<Type>;
    temp->data = data;
    temp->prev = nullptr;
    return temp;
}

template <typename Type>
void push(Stack<Type> &stack, Type data){
    Node<Type> *temp = create_node(data);
    if(stack.end != nullptr)
        temp->prev = stack.end;
    stack.end = temp;
}

template <typename Type>
Node<Type> pop(Stack<Type> &stack){
    Node<Type> temp;
    temp.data = stack.end->data;
    temp.prev = nullptr;
    Node<Type> *buf;
    buf = stack.end;
    stack.end = stack.end->prev;
    delete buf;
    return temp;
}

#endif // STACK_H
