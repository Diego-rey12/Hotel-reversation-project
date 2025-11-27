#include <iostream>
#include <iomanip> 
#include <cstring>
using namespace std;

class Hotel {
public:
	void SetGuestinfo(char guestname[100]);
	void SetHotelinfo(int roomtype, int days);
	void Setpricecheck();


private:
	char name[100];
	int room;
	int nightstay;
};

void Hotel::SetGuestinfo(char guestname[100]) {
	strcpy_s(name, sizeof(name), guestname);
}

void Hotel::SetHotelinfo(int roomtype, int days) {
	room = roomtype;
	nightstay = days;
}
void Hotel::Setpricecheck() {
	int price;
	const char* roomname;  
	price = 0;

	switch (room) {
	case 1:
		price = 67;
		roomname = "Single Room";
		break;
	case 2:
		price = 120;
		roomname = "Double Room";
		break;
	case 3:
		price = 250;
		roomname = "Triple Room";
		break;
	case 4:
		price = 500;
		roomname = "Luxary Room";
		break;
	default:
		cout << "invalid choice" << endl;
		return;

	}
	
	int total;
	total = nightstay * price;
	cout << "-------Booking Summary--------" << endl;
	cout << "Guest Name: " << name << endl;
	cout << "nights staying " << nightstay << endl;
	cout << "Room type: " << roomname<< " and price is " << price <<endl;
	cout << "your stay is $ " << total << endl;

}



// not part of class
void checkpriceroom();
void maskcredit(char*);


int main() {
	Hotel guest;
	char guestname[100];
	int userage,reason;
	int roomtype;
	int days;
	char option;
	char cardnumb[20];
	char check;
	cout << "Hello And Welcome To Hotel Reedley " << endl;
	cout << "We Are Delighted You Chose To Stay With Us" << endl;
	cout << "Please Enter Your Name: ";
	cin.getline(guestname, 100);

	cout << "Hello " << guestname << "! " << endl;

	cout << " plese enter your age ";
	cin >> userage;


	if (userage >= 18) {
		cout << "Welcome " << guestname << "!" << endl;
	}
	else {
		cout << "Sorry " << guestname << " You must be 18 or older to check out a room alone" << endl;
		return 0;
	}
	cin.ignore();
	cout << "We offer several types of rooms we offer single, double and triple and we have  luxary room as well" << endl;
	checkpriceroom();

	cout << "Please enter 1 for single 2 for double 3 for triple and 4 for luxary room " << endl;
	cin >> roomtype;

	cout << "How Many night do you entend on staying" << endl;
	cin >> days;

	cout << " Would you like to contnue with the booking(Y/N)" << endl;
	cin >> option;
	if (option == 'n' || option == 'N') {
		cout << "thank you for visting us have a nice day" << endl;
		return 0;
	}
	else {
		cout << "thank you for contuing the booking" << endl;
	}
	cin.ignore();

	cout << "please enter credit card number to confirm booking(no - just spaces)" << endl;
	cin.getline(cardnumb, 20);

	
	guest.SetGuestinfo(guestname);
	guest.SetHotelinfo(roomtype, days);
	guest.Setpricecheck();

	maskcredit(cardnumb);

	cout << " Is information above correct" << " " << "(If yes type y or Y, if not type n or N)" << endl;
	cin >> check;

	while (check == 'N' || check == 'n') {
		cout << "where is the error 1 for type room, 2 for night of stays" << endl;
		cin >> reason;
		if (reason == 1) {
			cout << "You are currently staying in option  "<<roomtype << " please input correct information for type of room" << endl;
			checkpriceroom();
			cin >> roomtype;
			
			guest.SetHotelinfo(roomtype, days);
			checkpriceroom();
		}
		else if (reason == 2) {
			cout <<"you are currently staying for "<<days << " Input correct number of nights" << endl;
			cin >> days;
			guest.SetHotelinfo(roomtype, days);
			guest.Setpricecheck();
		}
		cout << " corrected info" << endl;
		guest.Setpricecheck();

		cout << endl << endl;
		cout << "If not type N or n " << endl;
		cout << "if yes type Y or y" << endl;
		cin >> check;
	}
	cout << "Updated info:" << endl;
	guest.Setpricecheck();

	maskcredit(cardnumb);
	cout << endl;
	cout << "CHECK-IN CONPlETE" << endl;
	cout << "Enjoy your stay " << guestname << endl;

	
	 

	return 0;
}

void checkpriceroom() {
	cout << "-------------------------------------" << endl;
	cout << "The single room is $67/night (option 1)" << endl;
	cout << "The double room is $120/night (option2)" << endl;
	cout << " The triple is $250/night (option 3)" << endl;
	cout << "The luxary is $500/night (option 4)" << endl;
	cout << "--------------------------------------" << endl;
}

void maskcredit(char* cardnumb) {
	int length = strlen(cardnumb);
	int i;
	cout << "Masked Credit Card: ";
	for ( i = 0; i < length; ++i) {
		if (i < length - 4) {
			cout << '*';  
		}
		else {
			cout << cardnumb[i];
		}
	}
	cout << endl;
}

