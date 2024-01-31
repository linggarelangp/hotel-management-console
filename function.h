
#include <cstdlib>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <time.h>
#include "models.h"

using namespace std;

// Create a new node
void insertData()
{
    system("cls");
    srand(time(0));

    cout << "Add The User Data\n";

    newnode = new User();
    newnode->next = NULL;
    newnode->prev = NULL;
    newnode->id = rand() % 9999;

    cout << "User ID       : " << newnode->id << "\n";
    cin.ignore();
    cout << "Input Name    : ";
    getline(cin, newnode->name);
    cout << "Input Address : ";
    getline(cin, newnode->address);
    cout << "Input Room ID : ";
    getline(cin, newnode->roomID);

    if (head == NULL)
    {
        head = tail = newnode;
    }
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }

    cout << "\nData Has Been Added\n";
    cout << "Press enter to continue...";
}

// Print the node
void print()
{

    system("cls");

    int no = 1;
    cur = head;
    cout << "=====================================================================\n";
    cout << "|No." << setw(13) << "ID" << setw(15) << "NAME" << setw(15) << "ADDR" << setw(18) << "ROOM ID"
         << "   |\n";
    cout << "=====================================================================\n";
    if (head == NULL)
        cout << "Data Empty!\n";
    while (cur != NULL)
    {

        cout << "|" << no++ << ".";
        cout << setw(15) << cur->id;
        cout << setw(14) << cur->name;
        cout << setw(15) << cur->address;
        cout << setw(16) << cur->roomID << "\t    |";
        cout << "\n";
        cur = cur->next;
    }
    cout << "\n";
}

// Delete the node
void deleteData()
{

    system("cls");

    print();

    int value;

    cout << "=====================================================================\n";
    cout << "Input Users ID will be deleted : ";
    cin >> value;

    cur = head;
    while (cur != NULL)
    {

        if (value == cur->id)
        {

            if (cur->prev == NULL)
            {

                // Hapus Depan
                if (cur->next == NULL)
                {

                    head = NULL;
                    tail = NULL;
                    delete cur;
                }
                else
                {

                    head = cur->next;
                    head->prev = NULL;
                    cur->next = NULL;
                    delete cur;
                }
            }
            else
            {

                if (cur->next == NULL)
                {

                    // Hapus Bekalang
                    tail = cur->prev;
                    tail->next = NULL;
                    cur->prev = NULL;
                    delete cur;
                }
                else
                {

                    // Hapus Tengah
                    cur->prev->next = cur->next;
                    cur->next->prev = cur->prev;
                    cur->prev = NULL;
                    cur->next = NULL;
                    delete cur;
                }
            }

            cout << "Data Has Been Deleted\n";
            break;
        }
        else
        {

            cur = cur->next;
        }
        if (cur == NULL)
            cout << "Data Not Found\n";
    }
}

// Main Menu
void mainMenu()
{

    system("cls");
    int choice;
    bool loop = true;

    while (loop == true)
    {
        cout << "=====================================================================\n";
        cout << "\t\t\t HOTEL MANAGEMENT";
        cout << "\n=====================================================================\n";
        cout << "1. Insert Data\n";
        cout << "2. Show Data\n";
        cout << "3. Delete Data\n";
        cout << "4. Exit\n";
        cout << "Choose One : ";
        cin >> choice;

        if (choice == 1)
        {

            insertData();
            cin.get();
            system("cls");
        }
        else if (choice == 2)
        {

            print();
        }
        else if (choice == 3)
        {

            if (head == NULL)
            {

                system("cls");
                cout << "\nMsg : Data Empty!\n\n";
            }
            else
            {

                deleteData();
            }
        }
        else if (choice == 4)
        {

            loop == false;
            system("cls");
            break;
        }
        else
        {
            system("cls");
            cout << "Invalid!\n";
        }
    }
}