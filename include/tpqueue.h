// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <stdexcept>

template<typename T>
class TPQueue {
     private:
     struct Node {
        T data;
        Node* next;
        explicit Node(const T& value) : data(value), next(nullptr) {}
     };

    Node* head = nullptr;

 public:
    ~TPQueue() {
        clear();
    }

    void push(const T& value) {
        Node* newNode = new Node(value);
        if (!head || newNode->data.prior > head->data.prior) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next && current->next->data.prior
              >= newNode->data.prior) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    T pop() {
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty!");
        }
        Node* tempNode = head;
        T returnValue = head->data;
        head = head->next;
        delete tempNode;
        return returnValue;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

 private:
    void clear() {
        while (head) {
            Node* tempNode = head;
            head = head->next;
            delete tempNode;
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
