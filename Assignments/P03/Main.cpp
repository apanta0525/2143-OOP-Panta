
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
 *       ll.hpp      : header file for linked list
 *       test.out    : output file with results
 *****************************************************************************/
#include "ll.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() { // Create a new graph
  ListGraphiz list;

  ofstream file;
  file.open("test.out", ios_base::app);
  // writing name in the file
  file << "Aashish Panta\n";
  file << "March 06, 2023\n";
  file << "Spring 2143\n";

  file << endl;

  file << "Linked List"<<endl;

  // Add nodes in linked List
  list.addNode("1");
  list.addNode("2");
  list.addNode("a");

  list.addNode("3");
  

  // Add edges in linked list
  list.addEdge(1, 2);
  list.addEdge(2, 3);
  list.addEdge(3, 4);
  list.addEdge(3, 5); // connects node with id 4 to node with id 5

  // Print the graph in Graphviz format
  list.print();
  list.printfile("test.out");

  file << endl;

  file.close();
  return 0;
}
