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
        // memberi nilai prev = null dan start = node baru
        newNode->prev = NULL; // step 5: make the new node point to NULL
        START = newNode;      // step 6: make the new node the first node
    }   
    // kondisi jika semua kondisi if tidak terpenuhi
    else
    {


        // insert the new node in the middle or at the end
        // set nilai current = start dan nilai previous = NULL
        Node *current = START; //step 1.a: start frome the first node
        Node *previous = NULL; //step1.b: previous node is NULL initially

        // Looping selama current != null dan noMhs dari current lebih kecil dari
        while (current != NULL && current->noMhs < newNode->noMhs)
        {                           // step 1.c: treaverse the list to find the
            previous = current;     // step 1.d: move the previous to the current
            current = current->next; // step 1.e : move the current to the next             
        }
    
    // set nilai next node baru = current dan prev node baru == previous
    newNode->next = current;    // step 4: Make the next field of the new node
    newNode->prev = previous;   // step 5: Make the previous field of the new node    
    
    
    }



}