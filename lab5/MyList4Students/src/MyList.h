//
// Created by pawel on 06.04.2020.
//
/**
Zadanie implementacyjne:
1. Prosze w pliku include/MyList.h dokonac nastepujacej implementacji:
Proszę o zaimplementowanie szablonu klasy MyList<T>, reprezentujacej liste jednokierunkowa
z glowa i iteratorami.
Punktacja przydzielana za nastepujace metody (jak testy):
1. za konstruktor bezargumentowy i metode size() zwracajaca ilosc elementow
2. za metody push_front i pop_front, ktore odpowiednio dodaja/usuwaja element z poczatku
3. metode front() zwracajaca element na poczatku,
        oraz aby pop_front() zwracala usuniety element
4. jesli pierwszy wezel (o nazwie head), oraz kazdy nastepny wezel (head->next)
sa zaimplementowane przy pomocy unique_ptr<MyList::Node>
5. jesli w razie zawolania pop_front na pustej liscie zostal wyrzucony wyjatek std::out_of_range
6. jesli kopiowanie (konstruktor kopiujacy i operator przypisania) jest niemozliwe dla listy
7. jesli mamy zaimplementowane metody iteratora
(tutaj jeszcze nie musza w pelni dzialac, chociaz powinny zwracac co nalezy)
8. jesli napisany iterator dziala z petla for-zakresowym
9. jesli nasz iterator dziala z algorytmami standardowymi na przykladzie std::count_if
10. jesli mamy metode remove(T element), ktora usuwa wszystkie elementy z listy o danej wartosci
11. jesli lista ma operator wypisywania na strumien
        (forma wydruku dowolna, byleby byly wszystkie elementy)
**/
#ifndef MYLIST4STUDENTS_MYLIST_H
#define MYLIST4STUDENTS_MYLIST_H

#include <memory>
#include <iostream>
#include <iterator>

template <typename T>
class MyList
{
protected:
    class Node
    {
    public:
        T val;
        std::unique_ptr<Node> next;
        Node(T val){this->val = val; this->next = nullptr;}

    };
public:
    struct iterator
    {
        typedef iterator self_type;
        typedef T& reference;
        typedef T* pointer;
        typedef std::forward_iterator_tag iterator_category;
        typedef T value_type;
        typedef int difference_type;

    private:
        Node* node = nullptr;

    public:
        iterator() = default;
        reference operator*() const {return node->val;}
        bool operator==(iterator rhs) const {return node == rhs.node;}
        bool operator!=(iterator rhs) const {return node != rhs.node;}
        self_type& operator++() {node = node->next.get(); return *this;}



    private:
        iterator(Node* node){this->node = node;};
        friend class MyList;
    };


protected:
    std::size_t size_list;
    std::unique_ptr<Node> head;

public:
    typedef T value_type;

    MyList() {this->size_list = 0; this->head = nullptr;}

    MyList(const MyList&) = delete;
    MyList& operator=(const MyList&) = delete;

    int size() const { return size_list; }
    iterator begin(){return iterator(head.get());};
    iterator end() {return {};};

    T& front() { return head->val; };
    const T& front() const { return head->val; };
    void remove(const T& element);
    ~MyList()  {  while(head != nullptr){head = std::move(head->next);} };
    void push_front(const T& arg);
    T pop_front();
    template<typename T2>
    friend std::ostream& operator<<(std::ostream &out, MyList<T2>& list);
};

template <typename T>
std::ostream& operator<<(std::ostream &exit, MyList<T>& list){
    for(T& taken: list)
        exit << taken <<" ";
    return exit;
};


template<typename T>
T MyList<T>::pop_front() {
    if(head == nullptr){throw std::out_of_range("Cannot pop_front from empty list");}
    size_list--;
    std::unique_ptr poped = std::move(head);
    head = std::move(poped->next);

    return poped->val;
}

template<typename T>
void MyList<T>::push_front(const T& val) {
    std::unique_ptr pushed = std::make_unique<Node>(val);
    if(head != nullptr){
        pushed->next = std::move(head);
    }
    size_list++;
    head = std::move(pushed);
}


template<typename T>
void MyList<T>::remove(const T& value){
    Node* iter = head.get();
    Node* before_iter = nullptr;
    while( iter != nullptr){
        if(iter->val != value){
            before_iter = iter;
            iter = iter->next.get();
        }else{
            if(before_iter != nullptr) {
                before_iter->next = std::move(iter->next);
                iter = before_iter->next.get();
            }else{
                head = std::move(iter->next);
                iter = head.get();
            }
            size_list--;
        }
    }
}



#endif //MYLIST4STUDENTS_MYLIST_H

