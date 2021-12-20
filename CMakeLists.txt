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
        HW_TEN/EdgeList.cpp HW_TEN/EdgeList.cpp HW_TEN/Graph.h
        FinalWork/Bag2/Bag.h FinalWork/Bag2/Bag.cpp
        FinalWork/Bag2/BagStack.h FinalWork/Bag2/BagStack.cpp
        FinalWork/Bag2/BagQueue.cpp FinalWork/Bag2/BagQueue.h
        FinalWork/Bag2/PriorityQueue.cpp FinalWork/Bag2/PriorityQueue.h FinalWork/StudentSystem/copy.cpp FinalWork/StudentSystem/StudentSystem.cpp FinalWork/StudentSystem/StudentSystem.h FinalWork/StudentSystem/test.cpp)

