#include <iostream>
#include "Currency.h"
#include "Krone.h"
#include "BST.h"

using namespace std;

int main() {
	Currency* arr[20] = {new Krone(57.12), new Krone(23.44), new Krone(87.43), 
		new Krone(68.99), new Krone(111.22), new Krone(44.55), new Krone(77.77), 
		new Krone(18.36), new Krone(543.21), new Krone(20.21), new Krone(345.67),
		new Krone(36.18), new Krone(48.48), new Krone(101.00), new Krone(11.00),
		new Krone(21.00), new Krone(51.00), new Krone(1.00), new Krone(251.00), 
		new Krone(151.00)};

	BST tree;
	for (int i = 0; i < 6; i++) {
		tree.insertNode(arr[i]);
	}

	tree.deleteNode(arr[0]);

	return 0;
}                                                                              