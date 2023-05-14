#include <iostream>
#include "List.h"
using namespace std;

enum choice { insert = 1, removel, clear, print, exitProgram = -1 };

void menu()
{
	cout << "----------------------------------------" << endl;
	cout << "enter a number 1-4 (-1 to exit): " << endl;
	cout << "\t1 - insert element to list" << endl;
	cout << "\t2 - remove element from list" << endl;
	cout << "\t3 - clear all elements from list" << endl;
	cout << "\t4 - print the list" << endl;
	cout << "----------------------------------------" << endl << endl;

}

List getList() {
    int num;
    cin >> num;
    List l;
    while (num>0)
    {
        l.insert(num);
        cin >> num;
    }
    return l;
}

List merge(List& l1, List& l2) {
	List newList = l1;
	List temp=l2;
	if (l1.isEmpty())
		return l2;
	if (l2.isEmpty())
		return l1;
	int val;
	while (!temp.isEmpty())
	{
		val = temp.firstElement();
		newList.insert(val);
		temp.removeFirst();
	}
	return newList;
}

void makeSet(List& l) {
	if (l.isEmpty())
		return;
	List temp1 = l;
	List temp2 = l;
	int val;
	temp2.removeFirst();
	while (!temp1.isEmpty() && !temp2.isEmpty()) {
		val = temp1.firstElement();
		if (temp2.firstElement() == val)
		{
			l.remove(val);
			temp1.removeFirst();
			temp2.remove(val);
		}
		else {
			temp1.removeFirst();
			temp2.removeFirst();
		}
	}
}

void reverse(List& l) {
	if (l.isEmpty())
		return;
	List temp = l;
	l.clear();
	l.insert(temp.firstElement());
	temp.removeFirst();
	int val;
	while (!temp.isEmpty())
	{
		val = temp.firstElement();
		l.add(val);
		temp.removeFirst();
	}
}

int main()
{
    #pragma region Level_1
	/*	int cho, val;
	cout << "enter the list values\n";
	List lst = getList();
	cout << "choose 0-2\n";
	cin >> cho;
	while (cho != exitProgram)
	{
		switch (cho)
		{
		case insert:cout << "enter a value to insert\n";
			cin >> val;
			try
			{
				lst.insert(val);
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
			break;
		case removel: cout << "enter a value to remove\n";
			cin >> val;
			try {
				lst.remove(val);
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
			break;
		case clear: lst.clear();
			break;
		case print: cout << lst << endl;
			break;
		default:cout << "ERROR input. enter again!\n";
		}

		menu();
		cin >> cho;
	}
	*/

#pragma endregion

	#pragma region Level_2
	List lst1, lst2, mergedList;

	cout << "enter the first list:" << endl;
	lst1 = getList();
	cout << "enter the second list:" << endl;
	lst2 = getList();

	mergedList = merge(lst1, lst2);
	cout << "the new merged list: " << mergedList << endl;

	makeSet(mergedList);
	cout << "the new merged set: " << mergedList << endl;

	reverse(mergedList);
	cout << "the new merged reverse: " << mergedList << endl;


#pragma endregion

	return 0;
}

