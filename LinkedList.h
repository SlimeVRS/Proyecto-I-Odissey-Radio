#include <iostream>

template <typename T>

class NodeLL{
    T *data;
    NodeLL *nextNode;

public:
    NodeLL(T *data){
        this->data = data;
    }

    ~NodeLL(){
        delete data;
        delete nextNode;
        delete this;
    }

    T *getData(){
        return this->data;
    }

    NodeLL *getNext(){
        return this->nextNode;
    }

    void setNext(NodeLL *element){
        this->nextNode = element;
    }
};

template <typename T>

class LinkedList{
    NodeLL<T> *head;
    int size;

public:
    LinkedList(){
        this->head = nullptr;
        this->size = 0;
    }

    ~LinkedList(){
        delete head;
        delete this;
    }

    void insterElement(T *data){
        NodeLL<T> *newNode = new NodeLL<T>(data);
        NodeLL<T> *tempPtr = this->head;

        newNode->setNext(nullptr);

        if(this->head == nullptr){
            this->head = newNode;
            this->size++;
            return;
        }

        while(tempPtr->getNext() != nullptr){
            tempPtr = tempPtr->getData();
        }

        tempPtr->setNext(newNode);
        this->size++;
        return;
    }

    bool contains(T *data){
        NodeLL<T> *tempPtr = head;
        while(tempPtr != nullptr){
            if(tempPtr->getData().comapre(data) == 0){
                return true;
            }
            tempPtr = tempPtr->getNext();
        }
        return false;
    }

    NodeLL<T> *getFirst(){
        return this->head;
    }

    void remove(int index){
        NodeLL<T> *currentPtr = this->head;
        NodeLL<T> *nextPtr = currentPtr->getNext();

        int pos = 1;

        of(index == 0){
            this->head = head->getNext();
            this->size--;
            return;
        }

        while(nextPtr != nullptr){
            if(index == pos){
                currentPtr->setNext(nextPtr->getNext());
                this->size--;
                return;
            }
            pos++;
            currentPtr = currentPtr->getNext();
            nextPtr = nextPtr->getNext();
        }
    }

    void remove(T *node){
        NodeLL<T> *currentPtr = this->head;
        NodeLL<T> *nextPtr = currentPtr->getNext();

        if(node == head){
            this->head = head->getNext();
            this->size--;
            return;
        }
        while(nextPtr != nullptr){
            if(node == nextPtr){
                currentPtr->setNext(nextPtr->getNext());
                this->size--;
                return
            }

            currentPtr = currentPtr->getNext();
            nextPtr = nextPtr->getNext();
        }
    }

    int getSize(){
        return this->size;
    }
};