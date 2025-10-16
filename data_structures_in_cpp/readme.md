Video link - [here](https://youtu.be/B31LgI4Y4DQ?si=oa6n955r3aYjZmtW). 

# What is a data structure?
A data structure is a way to store and organize data in a computer, so that it can be used effectively. 

Data types are spoken about in two ways - 

1. As abstract data types (i.e. as mathematical / logical models) - 

    Eg: We can describe a List as a data structure that stores a given number of elements of any type, reads element by position and modify elements at a position. Do not have any implementation details. 

1. As a concrete implementation - 

    Eg: Most languages offer a concrete implementation of the lists described above. That is Arrays. 

# List 

## List as an abstract type

1. Static lists

    1. Static list should: 

        1. Store a given number of elements of a given data type. 

        1. Write/modify element at a position. 

        1. Read element at a position. 

    1. Static lists are implemented as arrays. These are fixed size, can write at a specific position and read elements at a specific position. 

1. Dynamic lists

    What if we wanted dynamic lists?

    1. Dynamic list should : 

        1. A list of size 0 designated as empty. 

        1. insert at any position. 

        1. Remove at any position. 

        1. Read/modify element at a position. 
    
    1. Implementation

        We can declare an array of large size to implement a dynamic array. But this comes with its problems. 

        1. Inserting at end (given array is not full) is easy - O(1). But inserting in the middle is harder. 

            Say, array has 5 element and we want to insert in pos 1. Then elements in position 1, 2, 3, 4 would have to be pushed back one position to empty the space in position 1. 

            Hence, Inserting takes O(n) with n being the array size. 

        1. Removing has the same problem as inserting. All elements following the removed element will have to be moved 1 position earlier. This means if dynamic lists are implemented as arrays removing also would have O(n).

        1. If the allocated space for the array gets over, then we cannot extend the existing array. Hence, a new array with an even larger size has to be created and the contents of the older array would have to be copied into the new array. This operation is once again costly. 

        1. Reading elements at a position is still O(1) though. This property is characteristic of arrays. 

## Linked list to implement dynamic lists

