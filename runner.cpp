#include <iostream>
#include "Currency.h"
#include "Krone.h"
#include "BST.h"
#include <fstream>
#include <sstream>

using namespace std;


int main() {
	Currency* arr[20] = {new Krone(57.12), new Krone(23.44), new Krone(87.43), 
		new Krone(68.99), new Krone(111.22), new Krone(44.55), new Krone(77.77), 
		new Krone(18.36), new Krone(543.21), new Krone(20.21), new Krone(345.67),
		new Krone(36.18), new Krone(48.48), new Krone(101.00), new Krone(11.00),
		new Krone(21.00), new Krone(51.00), new Krone(1.00), new Krone(251.00), 
		new Krone(151.00)};

	BST tree;

	for (int i = 0; i < 20; i++) {
		tree.insertNode(arr[i]);
	}

	ofstream writer;
	writer.open("output.txt");
	if (!writer.is_open()) {
		cout << "Could not create or open output.txt." << endl; 
		return 1;
	}

	string breadthFirst = "Breadth First Traversal: " + tree.printBreadthFirst();
	cout << breadthFirst << endl;
	writer << breadthFirst << endl; 

	string inOrder = "In Order Traversal: " + tree.printInOrder();
	cout << inOrder << endl; 
	writer << inOrder << endl; 

	string preOrder = "Pre Order Traversal: " + tree.printPreOrder();
	cout << preOrder << endl; 
	writer << preOrder << endl; 

	string postOrder = "Post Order Traversal: " + tree.printPostOrder();
	cout << postOrder << endl << endl; 
	writer << postOrder << endl << endl; 

	string line;
	stringstream stream;
	char operationType;
	double value;
	Currency* data;

	cout << "Please enter your input in the following format: <modification "
		<< "type> <value>, where " << endl << "modification type is either i(insert), d(delete) "
		<< "s(search) or t(traversal)." << endl << "If doing operations i, d, or s, include "
		<< "a Krone value afterwards. Type 'q' when" << endl << "you are done. " << endl << endl;
	do {
		cout << "Input: ";
		getline(cin, line);
		stream.str(line);
		stream >> operationType >> value;
		stream.clear();

		try {
			if (operationType == 't' || operationType == 'q') {
				breadthFirst = "Breadth First Traversal: " + tree.printBreadthFirst();
				cout << endl << breadthFirst << endl;
				writer << breadthFirst << endl;

				inOrder = "In Order Traversal: " + tree.printInOrder();
				cout << inOrder << endl;
				writer << inOrder << endl;

				preOrder = "Pre Order Traversal: " + tree.printPreOrder();
				cout << preOrder << endl;
				writer << preOrder << endl;

				postOrder = "Post Order Traversal: " + tree.printPostOrder();
				cout << postOrder << endl << endl;
				writer << postOrder << endl << endl;
			}
			else {
				data = new Krone(value);

				if (operationType == 'i') {
					tree.insertNode(data);
				}
				else if (operationType == 'd') {
					tree.deleteNode(data);
				}
				else if (operationType == 's') {
					if (tree.search(data)) {
						cout << "Data was found.";
						writer << "Data was found.";
					}
					else {
						cout << "Data was not found.";
						writer << "Data was not found.";
					}
					cout << endl << endl; 
					writer << endl << endl;
				}
				delete data;
			}
		}
		catch (const char* msg) {
			cout << value << " was ignored. Error: " << msg << endl << endl;
			writer << value << " was ignored. Error: " << msg << endl << endl;
		}
	} while (line != "q");

	writer.close();
	return 0;
}                                                                              