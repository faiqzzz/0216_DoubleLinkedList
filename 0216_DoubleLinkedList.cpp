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

    

}