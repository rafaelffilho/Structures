#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template <typename Type>
struct Node{
    Type data;
    Node<Type> *next;
};

template <typename Type>
Node<Type> *create_node(Type data){
    Node<Type> *buffer = new Node<Type>;
    buffer->data = data;
    buffer->next = nullptr;
    return buffer;
}

template <typename Type>
struct LinkedList{
    Node<Type> *start;
};

template<typename Type>
int initialize_list(LinkedList<Type> &list){
    list.start = nullptr;
    return 1;
}

template<typename Type>
int push_back(LinkedList<Type> &list, Type data){
    Node<Type> *buffer = create_node(data);
    if(list.start == nullptr){
        list.start = buffer;
        return 1;
    }
    Node<Type> *nav = list.start;
    while(nav->next != nullptr){
        nav = nav->next;
    }
    nav->next = buffer;
    return 1;
}

template<typename Type>
int push_begin(LinkedList<Type> &list, Type data){
    Node<Type> *buffer;
    buffer = create_node(data);
    if(list.start == nullptr){
        list.start = buffer;
        return 1;
    }
    buffer->next = list.start;
    list.start = buffer;
    return 1;
}

template<typename Type>
int push_position(LinkedList<Type> &list, Type data, int position){
    Node<Type> *buffer;
    buffer = create_node(data);
    Node<Type> *nav;
    nav = list.start;
    for(int i = 0; i < position - 1; i++){
        nav = nav->next;
    }
    buffer->next = nav->next;
    nav->next = buffer;
    return 1;
}

template<typename Type>
int pop_back(LinkedList<Type> &list){
    if(list.start == nullptr)
            return 0;

    Node<Type> *nav;
    nav = list.start;
    while (nav->next->next != nullptr) {
        nav = nav->next;
    }
    delete nav->next;
    nav->next = nullptr;
    return 1;
}

template<typename Type>
int pop_begin(LinkedList<Type> &list){
    if(list.start == nullptr)
        return 0;

    Node<Type> *buf = list.start;
    list.start = list.start->next;
    delete buf;
    return 1;
}

template<typename Type>
int pop_position(LinkedList<Type> &list, int position){
    if(list.start == nullptr)
        return 0;
    if(list.start->next != nullptr && position == 0){
        list.start = list.start->next;
        return 1;
    }

    Node<Type> *nav;
    nav = list.start;
    for(int i = 0; i < position - 1; i++){
        nav = nav->next;
    }
    Node<Type> *buf = nav->next;
    nav->next = nav->next->next;
    delete buf;
    return 1;
}

#endif // LINKEDLIST_H
