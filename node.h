//
// Created by Nasir Alizade on 2023-04-24.
//

#ifndef LABB3_V1_NODE_H
#define LABB3_V1_NODE_H
struct Node{
    Node(int data):data(data),left(nullptr),right(nullptr){}
    int data;
    Node* left;
    Node* right;
};
struct hash_node{
    hash_node(int data): data(data), next(nullptr){};
    int data;
    hash_node* next;
};
#endif //LABB3_V1_NODE_H
