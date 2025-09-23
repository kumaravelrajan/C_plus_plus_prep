# What is a namespace?

There might be two files having the same function name - getTicket(). When we write 

```cpp
getTicket()
getTicket()
```

the compiler is confused. To avoid this we define namespaces. The following is much clearer.

```cpp

namespaceA::getTicket()
namespaceB::getTicket()
```

