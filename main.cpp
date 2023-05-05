#include <iostream>
#include <string>
#include "SelfBalanceBST.h"

using namespace std;

int main (void) {
    bool run = true;
    char input;

    SelfBalanceBST* tree = new SelfBalanceBST(10);
    while(run) {
        cout << "Please enter: \n1: insert into the list\n2: display the list\n3: quit \n";

        while(!(cin >> input) || cin.peek() != '\n' || (input != '1' && input != '2' && input !='3')) {
            cin.clear();
		    cin.ignore(3000, '\n');
            cout << "Please enter: \n1: insert into the list\n2: display the list\n3:quit ";
        }

        string temp;
        switch(input) {
            case '1':
                cout << "Please enter number" << endl;
                
                cin >> temp;
                tree = tree->insert(stoi(temp));
                break;

            case '2':
                tree->display();
                break;

            case '3':
                run = false;
                break;
        }

    }
}