#include <iostream>
#include<fstream>
#include <iomanip>
#include <string>
using namespace std;

struct beverage
{
	string name;
	float price;
	int quantity;	
};

beverage food[5][3];
string dName;
float dPrice;
int dQuantity;
int quantity;
string pay[2];
string payMethod;
float totalPrice;
void menu(beverage food[][3]);
void display (beverage food[][3],int &choice);
void choose(int &choice);
void noRemain(beverage food[][3], int &choice);
void choosen(beverage food[][3], int *choice);
void distotalDrink (float totalPrice);
void payment(string pay[],float &dPrice);

int main()
{
	int choice;
	int sentinel = 100;

	cout.setf(ios::fixed);
	cout.precision(2);
	
	menu(food);	
	while (choice !=sentinel)
	{
	//Display Menu - title
	cout << "Press 100 to Pay\n"<< endl;	
	display (food,choice);
	choose(choice);
	noRemain(food ,choice);
	choosen(food,&choice);
	totalPrice+= dPrice;	
	};
	distotalDrink (totalPrice);
	payment(pay,dPrice);
	cout<< "FINAL"<<endl;
	display (food,choice);
	cout << "Thank you!"<<"\nHave A Great Day !" << endl;
	
	//file
	int drinks[5];
	ifstream infile;
	infile.open("input.txt");
	ofstream outfile ;
	outfile.open("output.txt");
	for (int i=0;i<5;i++)
	{
		infile >> drinks[i] ;
	}
	infile.close();
	
	
	if (dQuantity >= 10)
	{
	outfile << " Food Available ! " <<endl;
	}
	
	else 
	{
	outfile << " Please Restock The Drink ! "  << dName<<endl;
	}
	
	outfile.close();
	
}
void menu(beverage food[][3])
{
	
	food[0][0].name= "Coca Cola"; 
	food[0][1].price = 1.20; 
	food[0][2].quantity=3;
	
	food[1][0].name="Milo";
	food[1][1].price= 2.00;
	food[1][2].quantity= 30;
	
	food[2][0].name ="Iced tea";
	food[2][1].price =1.50;
	food[2][2].quantity= 30;
	
	food[3][0].name ="Mountain Dew";
	food[3][1].price =1.80;
	food[3][2].quantity= 30;
	
	food[4][0].name ="Pepsi";
	food[4][1].price =2.00;
	food[4][2].quantity= 30;	
}
void display (beverage food[][3],int &choice)// nnti nak repeat balik function akhir skli
{
	
	cout <<setw(10)<< left << "No"<< setw(20)<< left << "Drink";
	cout << setw(20) << left<< "Price"<< setw(20)<< left << "Remaining"<< endl;
	
	for (int i=0; i<5; i++ )
	cout << setw(10)<< left << i<< setw(20)<< food[i][0].name<< setw(20)<< left << food[i][1].price
		 << setw(20)<< left << food[i][2].quantity<< endl;	
}
void choose(int &choice)
{
	cout <<"\n";
	cout << "Choose your drink: \n";
	cin >> choice;
	cout << endl;	
}
void noRemain(beverage food[][3], int &choice)
{
	if (choice >=0 && choice <=4)
	{
		if (food[choice][2].quantity==0)
		{
		cout << food[choice][2].name <<" is not available"<<endl;
		cout << "Please choose another drinks"<< endl;
		cin >> choice;
		cout << endl;
		}
	}	
}
void choosen(beverage food[][3], int *choice)
{
	int sentinel;
	switch(*choice)
	{
	case 0:
		food[0][2].quantity--;// balance quantity not current quantity
		dName= food[0][0].name;
		dPrice= food[0][1].price;
		
		break;
	case 1:
		food[1][2].quantity--;
		dName=food[1][0].name;
		dPrice= food[1][1].price;
		
		break;
		
	case 2:
		food[2][2].quantity--;
		dName=food[2][0].name;
		dPrice= food[2][1].price;
	
	
		break;
	case 3:
		food[3][2].quantity--;// balance quantity not current quantity
		dName= food[3][0].name;
		dPrice= food[3][1].price;
		

		break;
	case 4:
		food[4][2].quantity--;// balance quantity not current quantity
		dName= food[4][0].name;
		dPrice= food[4][1].price;
		
		break;
	case 100: 
		sentinel= *choice;
		dPrice=0;
		break;		
	default:
		cout << "Incorrect input"<< endl;
		cout << "Please choose again"<< endl;
		cout << endl;
		break;	
	}		 
}

void distotalDrink (float totalPrice)
{
	
	cout << "Your Total Drink is :" << totalPrice << endl; 	
		
}
void payment(string pay[],float &dPrice)
{
	int num;
	int sentinel;
	if(num != sentinel)
	{ 
	cout<<" Choose a payment method using a card or an e-wallet:  "<<endl;
    cout << setw(20) << left<< "No"<< setw(20)<< left << "Payment Method"<<endl;
    cout << setw(20) << left<< "1"<< setw(20)<< left << "Card"<<endl;
    cout << setw(20) << left<< "2"<< setw(20)<< left << "E-Wallet"<< endl;
	cin>>num;
	
	for(int i=1;i<3;i++)
	 if (num==1)
	 {
	     pay[num]="Please touch your card here: ";
	   	payMethod=pay[num];

     }
	 else 
	{     
	    pay[num]="Please scan your Qr code here: ";
	    payMethod=pay[num];
	}
	cout << payMethod<< endl;
	}
}






