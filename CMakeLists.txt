cmake_minimum_required(VERSION 3.20)
project(HomeWork)

set(CMAKE_CXX_STANDARD 23)

add_executable(HomeWork
        HW_One/SeqList.cpp HW_One/SeqList.h
        HW_Two/LinkedList.h HW_Two/LinkedList.cpp
        HW_Three/CircularLinkedList.h HW_Three/CircularLinkedList.cpp
        HW_Three/DoubleLinkedList.h HW_Three/DoubleLinkedList.cpp
        HW_Three/StaticLinkedList.cpp HW_Three/StaticLinkedList.h
        HW_Four/SeqStack.cpp HW_Four/SeqStack.h HW_Four/LinkedStack.cpp HW_Four/LinkedStack.h
        HW_Six/String.cpp HW_Six/String.h
        HW_TEN/EdgeList.cpp HW_TEN/EdgeList.cpp HW_TEN/Graph.h)

