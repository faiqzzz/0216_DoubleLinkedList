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
    
        // kondisi jika current tidak sama dengan null
        if (current != NULL)
        {
            current->prev = newNode; // step 6: Make the previous field of the
        }

        // kondisi jika previous tidak sama dengan NULL
        if (previous != NULL)
        {
            previous->next = newNode; // step 7: Make the next field of the previous
        }
        // kondisi jika if previous sama dengan null
        else
        {
            // if previous is still NULL, it means is now the first node
            START = newNode;    
        }
    }
}

// pembuatan function search untuk mencari data
bool search(int rollNo, Node **previous, Node **current)
{
    *previous = NULL;
    *current = START;
    while (*current != NULL && (*current)->noMhs != rollNo)
    {
        *previous = *current;
        *current = (*current)->next;
    }
    return (*current != NULL);
}

// pembuatan prosedur delete untuk menghapus data
void deleteNode()
{
    Node *previous, *current;
    int rollNo;

    cout << "\nEnter the roll number of the student whose record is to be deleted :";
    cin >> rollNo; // step 3: get the roll number to be deleted

    if (START == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    current = START; // step 1: start from the first node
    previous = NULL;

    // locate the node to be deleted
    while (current != NULL && current->noMhs != rollNo)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
    {
        cout << "\033[31mThe record with roll number " << rollNo << " not found\033[0m" << endl;
        return;
    }

    // node to be deleted in the first node
    if (current = START) 
    {
        START = START->next; //step 2: update the START pointer
        if (START != NULL)
        {
            START ->prev = NULL;
        }
    }
    else
    { // node to be deleted is not the first node
        previous-> next = current->next;
        if (current->next != NULL)
        {  // if there's a successor, update its prev pointer
              current->next->prev = previous;  
        }
    }

    //relase the memory of the nodemarked as current
    delete current;
    cout << "\x1b[32mRecord with roll number " << rollNo << "deleted\x1b[0m" << endl;
}

// method untuk mengecek apakah list kosong
bool listEmpty() 
{
    return (START == NULL);
}

//prosedur traverse untuk menampilkan data secara urut
void traverse()
{
    if (listEmpty())
        cout << "\nList is empty" << endl;
    else 
    {
        cout << "\nRecords in ascending order of roll number are:" << endl;
        Node *currentNode = START; // step 1
        while (currentNode != NULL) // step 2
        {
            cout << currentNode->noMhs << " " << currentNode->name << endl;
            currentNode = currentNode->prev;
        }
    }

}

// prosedur untuk menampilkan data secara urutan terbalik
void revtraverse()
{
    if (listEmpty())
        cout << "\nList is empty" << endl;
    else
    {
        cout << "\nRecords in descending order of roll numbers are: " << endl;
        Node *currentNode = START;
        while (currentNode->next != NULL)
            currentNode = currentNode->next;
        
        while (currentNode != NULL)
        {
            cout << currentNode->noMhs << " " << currentNode->name << endl;
            currentNode = currentNode->prev;
        }
    }
}

    // prosedur untuk mencari data dan menampilkan data yang di cari jika ada
    void searchData()
    {
    if (listEmpty() == true)
    {
        cout << "\nList is empty" << endl;
    }
    Node *prev, *curr;
    prev = curr = NULL;
    cout << "\nEnter the roll number of the student whose record you want to search :";
    int num;
    cin >> num;
    if (search(num, &prev, &curr) == false)
        cout << "\nRecord not found " << endl;
    else
    {
        cout << "\nRecords found" << endl;
        cout << "\nRoll number : " << curr->noMhs<< endl;
        cout << "\nName : " << curr->name << endl;
    }
}

int main()
{

    // perulangan selama bernilai benar untuk program utama double linkedList
    while (true)
     {

        try
        {
            cout << "\nMenu" << endl;
            cout << "1. Add a record to the list" << endl;
            cout << "2. Delete a record from the list " << endl;
            cout << "3. View all records in the ascending order of roll numbers" << endl;
            cout << "4. View all records in the descending order of roll numbers" << endl;
            cout << "5. Search for a record in the list" << endl;
            cout << "6. Exit" << endl;
            cout << "\nEnter your choice (1-6) :";
            char ch;
            cin >> ch;
        
            switch(ch)
            {
                case '1':
                    addNode();
                    break;
                case '2':
                    deleteNode();
                    break;
                case '3':
                    traverse();
                    break;
                case '4':
                    revtraverse();
                    break;
                case '5':
                    searchData();
                    break;
                case '6':
                    return 0;
                default:
                    cout << "\nInvalid option" << endl;
                    break;
            }
         }
         catch (exception &e)
         {
            cout << "Check for the values entered. " << endl;
         }
    }
}

