/*----------------------------------------------------
TITLE:  Assignment 9
COURSE: TDT4102 - Programming
AUTHOR: Aslak J. Strand (c)

Notes:
    - Task2g: Not overloaded operator<<
	- Task5a and 5b: Not fully implemented 
		overload operator+= and operator+

Startup:
	- Compile and run program.
	- Main menu opens on startup
		- Navigate menu by input character shown.
		- ie: Input char(1) for [1] - Task 1
	- Task 1 contains sepperate menu
		- Input char(0) to return to main.
	- Task 2-5 will automaticly loop back to main
		when complete. 
----------------------------------------------------*/

#include <iostream>
#include <string.h>
#include "task1.h"
#include "task2.h"
#include "dummyTest.h"

void _task1(void);
void _task2(void);
void _task3(void);
void _task4(void);
void _task5(void);
void _cc(void);
void _mm(void);
inline void waitForEnter(void);

using namespace std;

int main() {
	char mm = 'a';
	while (true) {
		_mm();
		cin >> mm;
		switch (mm) {
			case '0': return 0;
			case 'i': _cc(); break;
			case '1': _task1(); break;
			case '2': _task2(); break;
			case '3': _task3(); break;
			case '4': _task4(); break;
			case '5': _task5(); break;
			default: cout << "Wrong input, try again." << endl; waitForEnter(); break;
		}
	}
}

void _task1(void) {
	char m1 = 'a';
	while (true) {
		for (int i = 0; i<50; i++) {cout << endl;}
		cout << "---------------------------------" << endl;
		cout << "~~~~~~~~~~~~ Task: 1 ~~~~~~~~~~~~" << endl;
		cout << "---------------------------------" << endl;
		cout << "[0] - Exit    |        " << endl;
		cout << "[a] - Task 1a | [b] - Task 1b    " << endl;
		cout << "[c] - Task 1c |     " << endl;
		cout << "---------------------------------" << endl;
		cout << "Your choice: ";
		cin >> m1;
		switch (m1) {
			case '0': return;
			case 'a': {
				int result[10];
				cout << endl << endl;
				fillInFibonacciNumbers(result, 10);
				break;
				}
			case 'b': {int arr[] = {1, 2, 3, 4, 5}; printArray(arr, 5); break;}
			case 'c': createFibonacci(); break;
		}
		waitForEnter();
	}
}
void _task2(void) {
	for (int i = 0; i<50; i++) {cout << endl;}
	cout << "---------------------------------" << endl;
	cout << "~~~~~~~~~~~~ Task: 2 ~~~~~~~~~~~~" << endl;
	cout << "---------------------------------" << endl << endl;

	Matrix *mx1 = new Matrix;
	Matrix *mx2 = new Matrix(5);
	Matrix *mx3 = new Matrix(5,10);

	cout << mx1 << endl;
	waitForEnter();
	cout << mx2 << endl;
	waitForEnter();
	cout << mx3 << endl;
	waitForEnter();
	cout << "Columns: " << mx3->getColumns() << endl;
	cout << "Rows:    " << mx3->getRows() << endl;
	mx3->set(1,1,3.14);
	cout << "Pos [1][1] = " << mx3->get(1,1) << endl;
	waitForEnter();
	cout << mx3 << endl;
	waitForEnter();

	delete mx1;
	delete mx2;
	delete mx3;
	mx1 = nullptr;
	mx2 = nullptr;
	mx3 = nullptr;
}
void _task3(void) {
	for (int i = 0; i<50; i++) {cout << endl;}
	cout << "---------------------------------" << endl;
	cout << "~~~~~~~~~~~~ Task: 3 ~~~~~~~~~~~~" << endl;
	cout << "---------------------------------" << endl << endl;

	string txt1 = "The program will print:\n";
	txt1 += "\na: 4";
	txt1 += "\nb: 4";
	txt1 += "\nc: 4";
	txt1 += "\na: 5";
	txt1 += "\nb: 5";
	txt1 += "\nc: 5";
	txt1 += "\n\nsince b is being initated with a pointer to a.num, and c = a";
	txt1 += "\ntherefore c would rewrite a, and b.num would then get the value of a.num";

	cout << txt1 << endl << endl;
	waitForEnter();
	cout << "Running dummyTest:\n";
	dummyTest();
	waitForEnter();

	// The program will crash due to the delete num statement. 
}
void _task4(void) {
	for (int i = 0; i<50; i++) {cout << endl;}
	cout << "---------------------------------" << endl;
	cout << "~~~~~~~~~~~~ Task: 4 ~~~~~~~~~~~~" << endl;
	cout << "---------------------------------" << endl << endl;

	Matrix *theMatrix = new Matrix(5,10);
	Matrix *newMatrix{theMatrix};
	theMatrix->set(2,2,1337);

	cout << "The Matrix:" << endl;
	cout << theMatrix << endl;
	waitForEnter();
	cout << "New Matrix:" << endl;
	cout << newMatrix << endl;
	waitForEnter();

	theMatrix->set(1,1,9);
}
void _task5(void) {
	for (int i = 0; i<50; i++) {cout << endl;}
	cout << "---------------------------------" << endl;
	cout << "~~~~~~~~~~~~ Task: 4 ~~~~~~~~~~~~" << endl;
	cout << "---------------------------------" << endl << endl;

	Matrix *A = new Matrix(2,2);
	Matrix *B = new Matrix(2,2);
	Matrix *C = new Matrix(2,2);

	// Init Matrix A:
	A->set(0,0,1);		A->set(0,1,2);
	A->set(1,0,3);		A->set(1,1,4);

	// Init Matrix B:
	B->set(0,0,4);		B->set(0,1,3);
	B->set(1,0,2);		B->set(1,1,1);

	// Init Matrix c:
	C->set(0,0,1);		C->set(0,1,3);
	C->set(1,0,1.5);	C->set(1,1,2);

	cout << "\nA:\n";
	cout << A << endl;
	waitForEnter();
	cout << "\nB:\n";
	cout << B << endl;
	waitForEnter();
	cout << "\nC:\n";
	cout << C << endl;
	waitForEnter();

	*A += *B;// + C;

	cout << "\nA:\n";
	cout << A << endl;
	waitForEnter();
	cout << "\nB:\n";
	cout << B << endl;
	waitForEnter();
	cout << "\nC:\n";
	cout << C << endl;
	waitForEnter();
}


// Wait for enter-key
inline void waitForEnter(void) {
    cout << endl;
    fseek(stdin,0,SEEK_END); // Clear input buffer
    do {cout << "Press Enter To Continue..";
    } while (cin.get()!='\n');
    for (int i = 0; i < 100; i++) {cout << endl;}
}
void _cc(void) {
	cout << "---------------------------------" << endl;
	cout << "    Written & Copyrighted by:" << endl;
	cout << "        Aslak J. Strand" << endl;
	cout << "---------------------------------" << endl << endl;
	waitForEnter();
}
void _mm(void) {
	for (int i = 0; i<50; i++) {cout << endl;}
	cout << "---------------------------------" << endl;
    cout << "~~~~~~~~~~~ Main Menu ~~~~~~~~~~~" << endl;
    cout << "---------------------------------" << endl;
    cout << "[0] - Exit    | [i] - Info       " << endl;
    cout << "[1] - Task 1  | [2] - Task 2     " << endl;
	cout << "[3] - Task 3  | [4] - Task 4     " << endl;
	cout << "[5] - Task 5  |      " << endl;
    cout << "---------------------------------" << endl;
    cout << "Your choice: ";
}