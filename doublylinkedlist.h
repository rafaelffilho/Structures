#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>

template <typename Type>
struct DNode{
    Type data;
    DNode<Type> *prev;
    DNode<Type> *next;
};

template <typename Type>
DNode<Type> *create_dnode(Type data){
    DNode<Type> *buffer = new DNode<Type>;
    buffer->data = data;
    buffer->next = nullptr;
    buffer->prev = nullptr;
    return buffer;
}

template <typename Type>
struct DoublyLinkedList{
    DNode<Type> *start;
    DNode<Type> *end;
};

template <typename Type>
void initialize_list(DoublyLinkedList<Type> &list){
    list.end = nullptr;
    list.start = nullptr;
}

template<typename Type>
int push_back(DoublyLinkedList<Type> &list, Type data){
    DNode<Type> *buffer = create_dnode(data);
    if(list.start == nullptr && list.end == nullptr){
        list.start = buffer;
        list.end = buffer;
        return 1;
    }
    list.end->next = buffer;
    buffer->prev = list.end;
    list.end = buffer;
    return 1;
}

template<typename Type>
int push_begin(DoublyLinkedList<Type> &list, Type data){
    DNode<Type> *buffer = create_dnode(data);
    if(list.start == nullptr && list.end == nullptr){
        list.start = buffer;
        list.end = buffer;
        return 1;
    }
    buffer->next = list.start;
    list.start->prev = buffer;
    list.start = buffer;
    return 1;
}

template<typename Type>
int push_position(DoublyLinkedList<Type> &list, Type data, int position){
    DNode<Type> *buffer = create_dnode(data);
    if(list.start == nullptr && list.end == nullptr){
        list.start = buffer;
        list.end = buffer;
        return 1;
    }
    if (position == 0)
        return push_begin(list, data);

    DNode<Type> *nav = list.start;
    while(position-- > 0 && nav != nullptr){
        nav = nav->next;
    }

    if(nav == nullptr){
        buffer->next = nullptr;
        buffer->prev = list.end;
        list.end->next = buffer;
        list.end = buffer;
        return 1;
    }

    buffer->prev = nav->prev;
    buffer->next = nav;
    nav->prev = buffer;
    nav->prev->prev->next = buffer;

    return 1;
}

template<typename Type>
int pop_back(DoublyLinkedList<Type> &list){
    if(list.end != nullptr){
        if(list.end != list.start){
            list.end = list.end->prev;
            list.end->next = nullptr;
        } else {
            list.end = nullptr;
            list.start = nullptr;
        }
        return 1;
    }
    return 0;
}

template<typename Type>
int pop_begin(DoublyLinkedList<Type> &list){
    if(list.start != nullptr){
        if(list.start->next != nullptr){
            list.start = list.start->next;
            list.start->prev = nullptr;
        }else{
            list.start = nullptr;
            list.end = nullptr;
        }
        return 1;
    }
    return 0;
}

template<typename Type>
int pop_position(DoublyLinkedList<Type> &list, int position){
    DNode<Type> *nav = list.start;
    while(position-- > 0 && nav != nullptr){
        nav = nav->next;
    }

    if(nav == nullptr)
        return 0;
    if(nav == list.end)
        return pop_back(list);
    if(nav == list.start)
        return pop_begin(list);
    nav->next->prev = nav->prev;
    nav->prev->next = nav->next;
    delete nav;
    return 1;
}

template<typename Type>
void print(DoublyLinkedList<Type> &list){
    DNode<Type> *nav = list.start;
    while (nav != nullptr) {
        std::cout << nav->data << std::endl;
        nav = nav->next;
    }
    std::cout << "-----------" << std::endl;
}

#endif // DOUBLYLINKEDLIST_H
