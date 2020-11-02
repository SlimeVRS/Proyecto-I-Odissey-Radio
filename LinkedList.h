/**
 * @author Marco Rivera Serrano
 * @date 24/10/2020
 * @file LinkedList.h
 * @brief Node class and their methods
 */

#include <iostream>

template <typename T>

class NodeLL{
    T *data;
    NodeLL *nextNode;

public:
    /**
     * @brief NodeLL Add information to the node
     * @param data Information to add
     * @return Returns the node with the information added
     */
    NodeLL(T *data){
        this->data = data;
    }
    /**
     * @brief Node destroyer
     * @return Node deleted
     */
    ~NodeLL(){
        delete data;
        delete nextNode;
        delete this;
    }
    /**
     * @brief Gives the node's information
     * @return Node information
     */
    T *getData(){
        return this->data;
    }
    /**
     * @brief Gets the next node
     * @return Next node
     */
    NodeLL *getNext(){
        return this->nextNode;
    }
    /**
     * @brief Change the next node of the current node
     * @param element Node to point
     */
    void setNext(NodeLL *element){
        this->nextNode = element;
    }
};

template <typename T>

class LinkedList{
    NodeLL<T> *head;
    int size;

public:
    /**
     * @brief Creates a new linked list with head pointing
     * at null and size 0
     * @return New empty linked list
     */
    LinkedList(){
        this->head = nullptr;
        this->size = 0;
    }
    /**
     * @brief Linked list destroyer
     */
    ~LinkedList(){
        delete head;
        delete this;
    }

    /**
     * @brief Insert new node to the linked list, if the list is empty, the node is added at the head,
     * if not, it goes at the end of the list
     * @param data New node to add
     * @return Node added in the list
     */
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
            tempPtr = tempPtr->getNext();
        }

        tempPtr->setNext(newNode);
        this->size++;
        return;
    }

    /**
     * @brief Says if the node is or not in the list
     * @return True or false
     */
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

    /**
     * @brief Returns the head of the list
     * @returns The first element
     */
    NodeLL<T> *getFirst(){
        return this->head;
    }

    /**
     * @brief Delets a node on the list
     * @param index Position of the node to delete
     * @return The list without the node
     */
    void removeI(int index){
        NodeLL<T> *currentPtr = this->head;
        NodeLL<T> *nextPtr = currentPtr->getNext();

        int pos = 1;

        if(index == 0){
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

    /**
     * @brief Deletes a node on the list
     * @param node Node to delete
     * @returns The list without the node
     */
    void removeN(T *node){
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
                return;
            }

            currentPtr = currentPtr->getNext();
            nextPtr = nextPtr->getNext();
        }
    }
    /**
     * @brief Gives the size of the list
     * @return Size of the list
     */
    int getSize(){
        return this->size;
    }

    void clear (){
        head->setNext(nullptr);
        head = nullptr;
    }
};
