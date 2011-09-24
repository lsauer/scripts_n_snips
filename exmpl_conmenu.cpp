#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned int uint;

class list;

class list
{
	private:
		int data;
		list *next;

	public:
		list(){
			next = new list;
		}

		~list(){
		}

		void addrset(){
		}
};

struct birthday
{
	int day;
	int month;
	int year;
	
private:
	static int z = 10;
};


void cha(int &x,int &y){
	int tmp = x;
	x = y;
	y = tmp;
}

void main(int argc, char* argv[]){
	//birthday bdate = {10,12,13};

	int x=15,y=6;
	cha(x,y);
	cout << x;
	
	int key;
	
	//list obj;

	do{	
		cout << "\
	M E N U:\n\
	1.)Show\n\
	2.)New\n\
	3.)Delete\n\
	4.)Sort\n\
	5.)Search\n\
	0.)Exit\n";
	
		cin >> key;
		switch(key){
			case 0:
				cout << "Leaving Menu now\n";
				break;

			case 1:
				break;

			case 2:

				break;

			case 3:
				break;
			
			case 4:
				break;
			
			case 5:
				break;

			default:
				cout << "Wrong option, choose another!\n";
				break;
		}
	}while(key);
}
