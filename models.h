#include <iostream>

struct User
{
    int id;
    std::string name;
    std::string address;
    std::string roomID;
    User *next;
    User *prev;
};

User *head, *tail, *newnode, *cur;