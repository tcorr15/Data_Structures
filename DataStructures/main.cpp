/*
 * main.cpp
 *
 *  Created on: 2 Sept 2021
 *      Author: thoma
 */

#include <iostream>
#include "LinkedList.h"
#include "Stack.h"


/*
Function to test the Linked List functionality. if it passes all the work 
*/
bool testLinkedList() {
    try {
        LinkedList<int>* list1 = new LinkedList<int>;
        LinkedList<int>* list2 = new LinkedList<int>;
        LinkedList<int>* list3 = new LinkedList<int>;
        for (int i = 0; i < 10; i++) {
            list1->appendNode(i);
            list2->prependNode(i);
        }
        list1->printSequence();         // 0 1 2 3 4 5 6 7 8 9
        list1->deleteNodeAt(5);
        list1->printSequence();         // 0 1 2 3 4 6 7 8 9
        list1->deleteNodeAt(11);        // Index 11 exceeds current list length of 9.
        list1->printSequence();         // 0 1 2 3 4 6 7 8 9

        list2->printSequence();         // 9 8 7 6 5 4 3 2 1 0
        list2->deleteNodeAt(0);
        list2->printSequence();         // 8 7 6 5 4 3 2 1 0
        list2->deleteNodeAt(8);
        list2->printSequence();         // 8 7 6 5 4 3 2 1
        list2->appendNode(20);
        list2->printSequence();         // 8 7 6 5 4 3 2 1 20
        list2->deleteNodeAt(0);
        list2->deleteNodeAt(0);
        list2->deleteNodeAt(0);
        list2->deleteNodeAt(0);
        list2->printSequence();         // 4 3 2 1 20
        list2->deleteNodeAt(4);
        list2->printSequence();         // 4 3 2 1
        list2->appendNode(12);
        list2->printSequence();         // 4 3 2 1 12
        list2->deleteNodeAt(0);
        list2->deleteNodeAt(0);
        list2->deleteNodeAt(0);
        list2->deleteNodeAt(0);
        list2->deleteNodeAt(0);
        list2->printSequence();         // List is empty.

        list3->appendNode(10);
        list3->prependNode(8);
        list3->prependNode(8);
        list3->appendNode(10);
        list3->appendNode(5);
        list3->appendNode(8);
        list3->appendNode(10);
        list3->appendNode(10);
        list3->prependNode(5);
        list3->prependNode(5);
        list3->printSequence();         // 5 5 8 8 10 10 5 8 10 10
        list3->deleteNodesByValue(5);   // Deleted 3 nodes with value 5.
        list3->printSequence();         // 8 8 10 10 8 10 10
        list3->deleteNodesByValue(7);   // Value 7 not found in list.
        list3->deleteNodesByValue(8);   // Deleted 3 nodes with value 8.
        list3->deleteNodesByValue(10);  // Deleted 4 nodes with value 10.
        list3->deleteNodesByValue(12);  // List is empty.
        list3->printSequence();         // List is empty.

        //delete list1;
        //delete list2;
        //delete list3;

        return true;
    }
    catch(int e) {
        return false;
   }
}


bool testStack() {
    try {
        Stack s{ 2 };
        int a = 5;
        int b = 7;
        s.push(&a);
        s.push(&b);
        int* y = s.pop();
        std::cout << *y << std::endl;
        y = s.pop();
        std::cout << *y << std::endl;
        /*delete y, a, b;*/
        return true;
    }
    catch(int e){
        return false;
    }

}


int main() {
    
    if (testLinkedList()) {
        std::cout << "Linked List OK" << std::endl;
    }
    else {
        std::cout << "Linked List FAIL" << std::endl;
    }

    if (testStack()) {
        std::cout << "Stack OK" << std::endl;
    }
    else {
        std::cout << "Stack FAIL" << std::endl;
    }


    return 0;
}
