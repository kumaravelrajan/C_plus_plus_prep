#include <iostream>
#include <string>
#include <memory>

using namespace std;

struct B;

struct A{
    std::shared_ptr<B> ptrB; /* strong reference to B. This ptrB points to a dynamically created object of class B. The reference count of the memory block that contains the class B object goes up by 1. */

    A(){
        cout << "Object A created\n";
    }

    ~A(){
        cout << "Object A destroyed.\n";
    }
};

struct B{
    std::shared_ptr<A> ptrA; /* Strong reference to A. ptrA points to a dynamically created object of class A. The reference count of the mem block having this class A object goes up by 1. */

    B(){
        cout << "Object B created.\n";
    }

    ~B(){
        cout << "Object B destroyed.\n";
    }
};

int main(){
    /* 
    
    Unique ptrs and shared ptrs when pointing to a mem block increase the reference count for the memory block they point to. They "own" the memory block. But specially in the case of shared pointers this might lead to the case of circular references where the reference count of two memory blocks does not get to 0 ever resulting in the shared pointers themselves going out of scope BUT the reference counts of the two mem blocks being pointed to never reaches 0. Hence, this results in memory leaks. Therefore, to solve this problem we have weak pointers.  

    */

    shared_ptr<A> objectA = make_shared<A>(); /* New class A object created in heap. */
    shared_ptr<B> objectB = make_shared<B>(); /* New class B object created in heap. */

    objectA->ptrB = objectB; 

    objectB->ptrA = objectA;

    return 0;
}