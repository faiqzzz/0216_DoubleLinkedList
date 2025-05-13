#include <iostream>     
using namespace std;

// membuat struktur untuk object double linkedList
struct Node
{
    // deklarasi noMhs dan name untuk menampung data
    int noMhs;
    string name;
    // deklarasi pointer next dan pref untuk penunjukan
    Node *next;
    Node *prev;
};

// deklarasi pointer START dan pemvbverian nilai
Node *START = NULL;

// deklarasi prosedur addNode
void addNode ()
{

    // pembuatan node dan pemberian value untuk data noMhs dan name 
    Node *newNode = new Node(); // step 1 : Buat node baru
    cout << "\nEnter the roll number of the student : ";
    cin >> newNode->noMhs; // Assign value to the data field of the new node
    cout << "\nEnter the name of the student :";
    cin >> newNode->name; // Assign value to the data field of th

    //Insert the new node in the list
    // kondisi jika star == null atau noMhs node baru <= noMhs start
    if (START == NULL || newNode->noMhs <= START->noMhs)
    {
        // step 2 : insert the new node at the begining
        // kondisi jika star tidak kosong dan noMhs nide baru sama dengan noMhs
        if (START != NULL && newNode->noMhs == START ->noMhs)
        {
            cout << "\033[31mDuplicate roll numbers not allowed\033[0m" << endl;
            return;
        }
        // if the list is empty, make the new node the START
        // jika  list kosong, maka node next nya adalah START
        newNode->next = START; // step 3: make thenew node point to the first node
        // kondisi jika start tidak memiliki nilai atau tidak kosong
        if (START != NULL)
        {   
            START ->prev = newNode; // step 4: make the first node point to the 
        }
    }   


}