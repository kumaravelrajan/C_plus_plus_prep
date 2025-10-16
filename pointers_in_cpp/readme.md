Video Link - [Click here](https://youtu.be/zuegQmMdy8M?si=rtJyKhy0SmlCbt_r)

# Why are pointer variables strongly typed when all they do is store addresses?

![](/pointers_in_cpp/images/1_generic_ptr_type_vs_strongly_typed_ptr.png)

Because pointers are not just used to store addresses. They are also dereferenced to get the value being pointed to and modify the value. 

In the image we can see that ```int a``` made up of four bytes has the value 1025 stored in binary. The left most bit (MSB) acts as the sign bit. 

Now, pointer p points to ```int a```. If we print *p this would mean we want the value of a. Because p is integer pointer, the system knows to look for a 4 byte value to get the stored value correctly. 

If p had been a char*, then the system would have only looked at one byte. 

Even if p had been a float* ```a```'s value would not have been retrieved correctly since the way floats and ints are stored are not the same. 

This is explained [here](/pointers_in_cpp/code/2_strong_typing_pointers_and_void_pointer.cpp).