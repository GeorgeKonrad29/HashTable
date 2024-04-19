#ifndef __List__
#define __List__
#include <iostream>
#include <functional>
//esto es una lista doblemente enlazada

template<typename T> class List{
    private:
        class Node{
            private:
            T data;
            Node* next;
            Node* prev;
            public:
            Node() : next(nullptr), prev(nullptr) {}
            Node(T data) : data(data), next(nullptr), prev(nullptr) {}
            T getData() const {return data;}
            Node* getNext() const {return next;}
            Node* getPrev() const {return prev;}
            void setNext(Node* next) {this->next = next;} 
            void setPrev(Node* prev) {this->prev = prev;}
        };
        Node* head;
        Node* tail;
        unsigned int size;
    public:
        List() : head(nullptr), tail(nullptr), size(0) {}
        ~List()
        {
            while(size>0)
            {
                pop_back();
            }
        }
        unsigned int getSize() const {return size;}
        bool empty() const {return size==0;}
        void pushBack(const T& elem)
        {
            Node* n = new Node(elem);
            if(empty())
            {
                head = n;
            }
            else
            {
                tail->setNext(n);
                n->setPrev(tail);
            }
            tail = n;
            size++;
        }
        void pushFront(const T& elem)
        {
            Node* n = new Node(elem);
            if(empty())
            {
                head = n;
                tail = n;
                size++;
            }
            else
            {
                n->setNext(head);
                head->setPrev(n);
                head = n;
                size++;
            }
        }
        void pop_back()
        {
            if(empty())
            {
                std::cout<<"no hay elementos en la lista"<<std::endl;
                return;
            }
            if(size==1)
            {
                delete head;
                head = nullptr;
                tail = nullptr;
                size--;
                return;
            }
            Node* temp = tail->getPrev();
            delete tail;
            tail = temp;
            tail->setNext(nullptr);
            size--;
        }
        void pop_front()
        {
            if(empty())
            {
                std::cout<<"no hay elementos en la lista"<<std::endl;
                return;
            }
            if(size==1)
            {
                delete head;
                head = nullptr;
                tail = nullptr;
                size--;
                return;
            }
            Node* temp = head->getNext();
            delete head;
            head = temp;
            head->setPrev(nullptr);
            size--;
        }
        void print()
        {
            if(empty())
            {
                std::cout<<"< >"<<std::endl;
                return;
            }
            Node* temp = head;
            while(temp!=nullptr)
            {
                std::cout<<"("<<temp->getData()<<")";
                temp = temp->getNext();
            }
            std::cout<<std::endl;
        }
        void visitor(std::function<void(const T&)> fun)
        {
            Node* temp = head;
            while(temp!=nullptr)
            {
                fun(temp->getData());
                temp = temp->getNext();
            }
        }


};

#endif