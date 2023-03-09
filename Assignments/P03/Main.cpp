
/*****************************************************************
 *
*  Author:           Aashish Panta
*  Email:            liverpool.ashish.ap@gmail.com
*  Label:            P03
*  Title:            Graphviz 
*  Course:           CMPS 2143
*  Semester:         Spring 2023
 *
 *  Description:
 *       This program implements a class that allows a singly-linked list to be
 *used similarly to a vector. The linked list can add and remove nodes with data
 *values, search existing nodes' values for a specific value, and it can be
 *sorted in ascending numerical order.  It also has print functionality to
 *display the linked list similarly to an array.
 *
 *  Usage:
 *       N/A
 *
 *  Files:
 *       main.cpp    : driver program
 *****************************************************************************/

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#define INF 1000000000 // infinity
struct Node {          // node for our linked list
  int data;
  Node *next;

  // constructor
  Node(int num) {
    data = num;
    next = nullptr;
  }
};

/**
 * Class MyVector
 *
 * Description:
 *            The class has tools to create a linked list. The values in linked
 * list can be added from another vector, from an array. The class also has
 * various methods like push and pop to add and remove items from the list as
 * needed. The final output is written onto a output file named test.out.
 *
 *
 * Public Methods:
 *                Vector()
 *                Vector(int *A, int size)
 *                Vector(string FileName)
 *                Vector(const Vector &other)
 *                void init()
 *      void      inorderPush(int x)
 *      void      sortList()
 *      void      pushFront(int x)
 *      void      pushFront(const Vector &other)
 *      void      pushRear(int x)
 *      void      pushRear(const Vector &other)
 *      bool      pushAt(int i, int x)
 *      int       popFront()
 *      int       popRear()
 *      int       popAt(int loc)
 *      int       find(int val)
 *   
 *
 *
 * Private Methods:
 *      void      _inorderPush(int x)
 *
 *
 * Usage:
 *      v1.pushFront(18);        pushes 18 in vector v1
 *      v2.inorderPush(27);      pushes 27 in ordered vector v2
 *
 *
 */
class MyVector {
private:
  Node *head; // base pointer of list
  Node *tail; // to hold the address of the end of linked list
  int size;   // holds the temporary size of the list
  static ofstream fout;
  string fileName;
  bool sorted;

  Node *_Find(int location) {
    Node *travel = head;
    int index = 0;

    while (travel && location--) {

      travel = travel->next;
    }
    return travel;
  }

  void _inorderPush(int x) {
    Node *tempPtr = new Node(x); // allocate new node
    Node *prev = head;           // get previous and next pointers
    Node *curr = head;

    while (curr->data > x) { // loop to find proper location
      prev = curr;
      curr = curr->next;
    }

    tempPtr->next = prev->next; // add new node in its proper position
    prev->next = tempPtr;

    size++; // add to size :)
  }

public:
  /**
   * Public : Vector
   *
   * Description:
   *      default constructor of the vector class
   *      creates and empty linked list
   * Params:
   *      none
   *
   * Returns:
   *      -none
   */
  MyVector() { head = tail = nullptr; }

  /**
   * Public : Vector
   *
   * Description:
   *     overloaded constructor of vector to initialize using array
   *
   * Params:
   *      int* :array of integers
   *      int :size of the array
   * Returns:
   *      -none
   */
  MyVector(int *A, int size) {
    init();

    for (int i = 0; i < size; i++) {
      pushRear(A[i]);
    }
  }

  /**
   * Public : Vector
   *
   * Description:
   *      overloaded constructor of vector to initialize using data from an
   * input file. Reads data from the input file and adds it to the list
   *
   * Params:
   *      string : name of the data file
   * Returns:
   *      none
   */
  MyVector(string FileName) {
    init();

    ifstream fin;
    int x = 0;

    fin.open(FileName);
    while (!fin.eof()) {
      fin >> x;
      pushRear(x);
    }
  }

  /**
   * Public : Vector
   *
   * Description:
   *      overloaded constructor of vector to initialize using another vector.
   *
   * Params:
   *      Vector : address of the other vector to be copied.
   *
   * Returns:
   *      none
   */
  MyVector(const MyVector &other) {
    init();

    Node *temp = other.head;

    while (temp) {
      pushRear(temp->data);
      temp = temp->next;
    }
  }

  /**
   *   Initialize the data members so we don't
   *   have duplicate lines in each constructor.
   *
   */
  void init() {
    head = tail = NULL;
    fileName = "";
    size = 0;
    sorted = false;
  }

  /**
   * Public : inorderPush
   *
   * Description:
   *             The method pushes a given value in the list in correct order.
   *             The method checks if the list is sorted if not it sorts it and
   *              then inserts the value in correct place.
   * Params:
   *      int     : value to be inserted in the list
   *
   * Returns:
   *      none
   */

  void inorderPush(int x) {
    if (!sorted) {
      sortList();
    }

    if (!head) {
      pushFront(x); // call push front for empty list
    } else if (x < head->data) {
      pushFront(x); // call push front if x is less than head
    } else if (x > tail->data) {
      pushRear(x); // call push rear if x > tail
    } else {
      _inorderPush(x); // call private version of push in order
    }
  }

  /**
   * Public : sortList
   *
   * Description:
   *             The method sorts the list in proper order.
   * Params:
   *       none
   *
   * Returns:
   *      none
   */

  void sortList() {
    Node *newFront = head;
    while (newFront->next) {
      Node *smallest = newFront;
      Node *current = newFront;
      int minimum = INF;
      while (current) {
        if (current->data < minimum) {
          smallest = current;
          minimum = current->data;
        }
        current = current->next;
      }
      smallest->data = newFront->data;
      newFront->data = minimum;
      newFront = newFront->next;
    }
    sorted = true;
  }

  /**
   * Public : pushFront
   *
   * Description:
   *      Pushes a number x at the front of the list
   *
   * Params:
   *      int : number to be put in the list
   *
   * Returns:
   *      void
   */
  void pushFront(int x) {
    Node *tempPtr = new Node(x);

    // empty list make head and tail
    // point to new value
    if (!head) {
      head = tail = tempPtr;
      // otherwise adjust head pointer
    } else {
      tempPtr->next = head;
      head = tempPtr;
    }
    size++;
  }

  /**
   * Public : pushFront
   *
   * Description:
   *      this function will place a pre-existing linked list at the front of
   * another linked list. Params:
   *      - Vector :  list to be pushed at thr front of the another list
   * Returns:
   *      -void
   */
  void pushFront(const MyVector &other) {
    Node *otherPtr = other.head;         // get copy of other lists head
    int *tempData = new int[other.size]; // allocate memory to hold values

    // load other list into array
    int i = 0;
    while (otherPtr) {
      tempData[i] = otherPtr->data;
      otherPtr = otherPtr->next;
      ++i;
    }

    // process list in reverse in order to keep them
    // in their original order.
    for (int i = other.size - 1; i >= 0; i--) {
      pushFront(tempData[i]);
    }
  }

  /**
   * Public : pushRear
   *
   * Description:
   *      Pushes a number x at the back of the list
   *
   * Params:
   *      int : number to be put in the list
   *
   * Returns:
   *      void
   */
  void pushRear(int x) {
    Node *tempPtr = new Node(x);

    if (!head) {
      head = tail = tempPtr;
    } else {
      tail->next = tempPtr;
      tail = tempPtr;
    }
    size++; // add to size of list
  }

  /**
   * Public : pushRear
   *
   * Description:
   *      this function will place a pre-existing linked list at the back of
   * another linked list. Params:
   *      - Vector :  list to be pushed at thr front of the another list
   * Returns:
   *      -void
   */

  void pushRear(const MyVector &other) {
    Node *otherPtr = other.head; // get copy of other lists head

    while (otherPtr) { // traverse and add
      pushRear(otherPtr->data);
      otherPtr = otherPtr->next;
    }
  }

  /**
   * Public : pushAt
   *
   * Description:
   *            The method pushes a value at given index.
   *
   * Params:
   *      int     : index of the list
   *      int     : value to be inserted in the list
   *
   * Returns:
   *      bool    : returns true if inserted else false.
   */

  bool pushAt(int i, int num) {
    if (i >= size) {
      return false;
    }

    Node *tempPtr = new Node(num); // allocate new node
    Node *prev = head;             // get previous and next pointers
    Node *curr = head;

    while (i > 0) { // loop to find proper location
      prev = curr;
      curr = curr->next;
      i--;
    }

    tempPtr->next = prev->next; // add new node in its proper position
    prev->next = tempPtr;

    size++; // add to size :)
    return true;
  }

  /**
   * Public : popFront
   *
   * Description:
   *            The method removes a value from the front of the list.
   *
   * Params:
   *       none
   *
   * Returns:
   *      int     : returns the removed data
   */

  int popFront() {
    if (head == nullptr) { // If the list is empty, return -1
      return -1;
    }
    int removedData = head->data;
    head = head->next;
    return removedData; // Otherwise return the popped node's data.
  }

  /**
   * Public : popRear
   *
   * Description:
   *            The method removes a value from the rear of the list.
   *
   * Params:
   *      none
   *
   * Returns:
   *      int    : returns the removed data otherwise returns -1
   */

  int popRear() {
    int hold;

    if (head) {

      Node *traverse = head;
      Node *prev = NULL;
      while (traverse->next != NULL) {
        prev = traverse;
        traverse = traverse->next;
      }

      hold = traverse->data;
      delete traverse;
      traverse = NULL;
      prev->next = NULL;
      size -= 1;

      return hold;
    }

    else {

      return -1;
    }
  }

  /**
   * Public : popAt
   *
   * Description:
   *            The method removes a value from specified location of the list.
   *
   * Params:
   *      int    : index or location of the node to be removed.
   *
   * Returns:
   *      int    : returns the removed data otherwise returns -1
   */

  int popAt(int loc) {
    int val = 0;

    if (loc == 0)
      return popFront();

    else if (head == NULL) {
      cout << "no items";
      return 0;
    }

    else {
      Node *traverse = head;
      for (int i = 0; i < (loc - 1); i++) {

        traverse = traverse->next;
      }

      if (traverse->next == NULL)
        return popRear();

      else {

        Node *temp = traverse->next;
        traverse->next = traverse->next->next;
        val = temp->data;

        delete temp;
        size -= 1;
        return val;
      }
    }
  }
  /**
   * Public : find
   *
   * Description:
   *            The method finds the location of the value entered by the user.
   *
   * Params:
   *      int    : value to be searched
   *
   * Returns:
   *      int    : returns the location of the value to be removed.
   */

  int find(int val) {
    // If list is empty, return -1
    if (head == nullptr) {
      return -1;
    }
    Node *travel = head;
    int index = 0;
    while (travel) {
      if (travel->data == val) {
        // If the value matches the current node's data, return the node index
        return index;
      } else {
        travel = travel->next;
        index++;
      }
    }
    // If value was not found in the linked list, return -1
    return -1;
  }

  /**
   * Public : overload operator <<
   *
   * Description:
   *       prints MyVector without using a print function.
   *
   *
   * Returns:
   *       os
   *
   */

  friend ostream &operator<<(ostream &os, const MyVector &rhs) {
    Node *temp = rhs.head; // temp pointer copies head

    while (temp) { // this loops until temp is NULL

      os << temp->data; // print data from Node
      if (temp->next) {
        os << "->";
      }
      temp = temp->next; // move to next Node
    }
    os << endl;
    return os;
  }
  /**
   * Public : overload operator <<
   *
   * Description:
   *       prints MyVector to output file
   *       without using a print function.
   *
   *
   * Returns:
   *       of
   *
   */

  friend ofstream &operator<<(ofstream &of, const MyVector &rhs) {
    Node *temp = rhs.head; // temp pointer copies head

    while (temp) { // this loops until temp is NULL

      of << temp->data; // print data from Node
      if (temp->next) {
        of << "->";
      }
      temp = temp->next; // move to next Node
    }
    of << endl;
    return of;
  }

  /**
   * Public : overload operator []
   *
   * Description:
   *    makes MyVector to behave like an array
   *    Values in MyVector can be called using index just like an
   *     array
   *
   * Returns:
   *       int
   *
   */

  int &operator[](int location) {
    Node *temp = _Find(location);

    return temp->data;
  }

  /**
   * Public : overload operator +
   *
   * Description:
   *      adds MyVector to another vector
   *
   *
   * Returns:
   *     V : Sum of two vectors
   *
   */

  MyVector operator+(const MyVector &rhs) {
    MyVector V;
    Node *a = this->head;
    Node *b = rhs.head;
    while (a && b) {
      V.pushRear(a->data + b->data);
      a = a->next;
      b = b->next;
    }
    if (a) {
      while (a) {
        V.pushRear(a->data);
        a = a->next;
      }
    } else if (b) {
      while (b) {
        V.pushRear(b->data);
        b = b->next;
      }
    }
    return V;
  }

  /**
   * Public : overload operator -
   *
   * Description:
   *      subtracts two vectors
   *      The vector whose length is shorter is subtracted
   *       from the longer vector
   * Returns:
   *     V1 :  difference of two vectors
   *
   */

  MyVector operator-(const MyVector &rhs) {
    MyVector V1;
    Node *a = this->head;
    Node *b = rhs.head;
    while (a && b) {
      V1.pushRear(a->data - b->data);
      a = a->next;
      b = b->next;
    }
    if (a) {
      while (a) {
        V1.pushRear(a->data);
        a = a->next;
      }
    } else if (b) {
      while (b) {
        V1.pushRear(b->data);
        b = b->next;
      }
    }
    return V1;
  }

  /**
   * Public : overload operator =
   *
   * Description:
   *      assigns one vector to another
   * Returns:
   *     none
   *
   */

  void operator=(const MyVector &rhs) {
    if (rhs.head == nullptr) {
      head = tail = nullptr;
    } else {
      this->head = rhs.head;
      this->tail = rhs.tail;
    }
  }

  /**
   * Public : overload operator ==
   *
   * Description:
   *      checks the equality of two vectors
   * Returns:
   *     bool : true if they are equal false otherwise
   *
   */

  friend bool operator==(const MyVector &lhs, const MyVector &rhs) {
    Node *a = lhs.head;
    Node *b = rhs.head;
    while (a && b) {
      if (a->data != b->data) {
        return false;
      }
      a = a->next;
      b = b->next;
    }
    if ((a && !b) || (b && !a)) {
      return false;
    }
    return true;
  }
};

void printName(ostream &outputfile) {
  outputfile << "Sudhir Ray\n02/09/2023\nSpring 2143\n" << endl;
}

int main() {

  int a1[] = {1, 2, 3, 4, 5};
  int a2[] = {10, 20, 30};

  MyVector v1(a1, 5);
  MyVector v2(a2, 3);

  ofstream outputfile;
  outputfile.open("output.txt");

  printName(outputfile);
  outputfile << endl << endl;

  cout << v1[2] << endl;
  outputfile << v1[2] << endl;
  // writes out 3

  v1[4] = 9;
  // v1 now = [1,2,3,4,9]

  cout << v1 << endl;
  // writes out [1,2,3,4,9] to console.

  outputfile << v1 << endl;
  // writes out [1,2,3,4,9] to your output file.

  MyVector v3 = v1 + v2;
  cout << v3 << endl;
  outputfile << v3 << endl;
  // writes out [11,22,33,4,9] to console.

  v3 = v1 - v2;
  cout << v3 << endl;
  outputfile << v3 << endl;
  // writes out [-9,-18,-27,4,9] to console.

  v3 = v2 - v1;
  cout << v3 << endl;
  outputfile << v3 << endl;
  // writes out [9,18,27,4,9] to console.

  cout << (v2 == v1) << endl;
  outputfile << (v2 == v1) << endl;
  // writes 0 to console (false) .

  MyVector v4 = v1;
  cout << (v4 == v1) << endl;
  outputfile << (v4 == v1) << endl;
  // writes 1 to console (true) .
}
