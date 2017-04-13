#ifndef STATICLIST_H
#define STATICLIST_H

template <typename TYPE>
struct StaticE {
    TYPE data;
};

template <typename TYPE, int MAX>
struct StaticList {
    StaticE <TYPE> elements[MAX];
    int quantity;
};

template <typename TYPE, int MAX>
void initialize_list(StaticList <TYPE, MAX> &list) {
    list.quantity = 0;
}

template <typename TYPE, int MAX>
bool push_back(StaticList <TYPE, MAX> &list, TYPE data) {
    if (list.quantity >= MAX) {
        return false;
    } else {
        StaticE <TYPE> element;
        element.data = data;
        list.elements[list.quantity] = element;
        list.quantity += 1;
        return true;
    }
}

template <typename TYPE, int MAX>
void push_begin(StaticList <TYPE, MAX> &list, TYPE data) {
    StaticE <TYPE> element;
    element.data = data;
    if (list.quantity < MAX) {
        for (int i = list.quantity; i > 0; i--) {
            list.elements[i] = list.elements[i-1];
        }
        list.elements[0] = element;
        list.quantity += 1;
    }
}

template <typename TYPE, int MAX>
void push_position(StaticList <TYPE, MAX> &list, TYPE data, int position) {
    StaticE <TYPE> element;
    element.data = data;
    if (list.quantity < MAX) {
        for (int i = list.quantity; i > position-1; i--) {
            list.elements[i] = list.elements[i-1];
        }
        list.elements[position-1] = element;
        list.quantity += 1;
    }
}

template <typename TYPE, int MAX>
void pop_back(StaticList <TYPE, MAX> &list) {
    if (list.quantity > 0) {
        list.quantity -= 1;
    }
}

template <typename TYPE, int MAX>
void pop_begin(StaticList <TYPE, MAX> &list) {
    if (list.quantity > 0) {
        for (int i = 0; i < list.quantity - 1; i++) {
            list.elements[i] = list.elements[i+1];
        }
        list.quantity -= 1;
    }
}

template <typename TYPE, int MAX>
void pop_position(StaticList <TYPE, MAX> &list, int position) {
    if (list.quantity < MAX) {
        for (int i = position - 1; i < list.quantity - 1; i++) {
            list.elements[i] = list.elements[i+1];
        }
        list.quantity -= 1;
    }
}


#endif // STATICLIST_H
