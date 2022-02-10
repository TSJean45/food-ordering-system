/******************************
Name : Tan Szu Jean
Id : 1201200641
Section : TC2V
Title : Food Ordering System
*****************************/
#include<iostream>
#include<iomanip>
using namespace std;

//base class for class order
class customer{
	protected:
		string name,hp;
		
	public:
		//user input to get user's name and phone number
		void setData(){
			fflush(stdin);
			cout<<"\t\tEnter your name: ";
			getline(cin,name);
			cout<<"\t\tEnter your phone number: ";
			getline(cin,hp);
			//clear screen for clarity
			system("cls");
		}
};

class welcome{
	public:
		//function displaying welcome screen
		welcome(){
			cout<<"\n\n\t\t        *************************";
			cout<<"\n\t\t      *****************************";
			cout<<"\n\t\t    *********************************";
			cout<<"\n\t\t  ************************************";
			cout<<"\n\t\t*****************************************";
		    cout<<"\n\t\t **                                   **";
		    cout<<"\n\t\t **             Jean's	              **";
		    cout<<"\n\t\t **       Food Ordering System        **";
		    cout<<"\n\t\t **                   		      **";
		    cout<<"\n********************************************************************************";
		}
};

//base class for class food and drinks
class order: public customer{
	protected:
		//declare variables
		string order_name;
		float order_price;
		int order_quantity,code;
		
	public:
		//display user's information
		void order_header(){
			cout<<"\n\t\t*****************************************";
			cout<<"\n\t\tName: "<<name;
			cout<<"\n\t\tPhone Number: "<<hp;
			cout<<"\n\t\t*****************************************";
		}
		
		/*virtual function for derived classes Food and Drinks because
		 both have display_menu with different contents */
		virtual void display_menu(){
		}
		
		//get user input to determine which food or drinks the user wants to order
		void setOrder(){
			cout<<"\n\t\t*****************************************";
			cout<<"\n\t\tWhat would you like to order?";
			cout<<"\n\t\tEnter code: ";
			cin>>code;
		}
		
		//accessor function to return code
		int getOrder(){
			return code;
		}
};

class food:public order{
	
	public:
		//display the food with codes
		void display_menu(){
			cout<<"\n\t\t*****************************************";
			cout<<"\n\t\tFood Menu";
			cout<<"\n\t\t*****************************************";
			cout<<"\n\t\t[1] Quesadillas";
			cout<<"\n\t\t[2] Crockpot Salsa Chicken";
			cout<<"\n\t\t[3] French Bread Pizza";
			cout<<"\n\t\t[4] Lemon Chicken";
			cout<<"\n\t\t[5] Chicken Fingers";
		}
		
		//mutator function to set the price for each food according to user input
		void set_price(int code){
			switch(code){
				case 1:
					order_price=10.00;
					order_name="Quesadillas";
					break;
				case 2:
					order_price=13.10;
					order_name="Crockpot Salsa Chicken";
					break;
				case 3:
					order_price=11.50;
					order_name="French Bread Pizza";
					break;
				case 4:
					order_price=16.20;
					order_name="Lemon Chicken";
					break;
				case 5:
					order_price=8.70;
					order_name="Chicken Fingers";
					break;
			}
		}
		
		//accessor function to return order_price to main function
		float get_price(){
			return order_price;
		}
		
		//display the name and price of the food that the user has choosen
		void display_food(){
			cout<<"\n\t\tYou have ordered "<<order_name;
			cout<<fixed<<setprecision(2)<<"\n\t\tPrice: RM "<<order_price;
		}
		
		//user input for food quantity
		void set_quantity(){
			cout<<"\n\t\tEnter quantity: ";
			cin>>order_quantity;
		}
		
		//accessor function to return order_quantity to main function
		int get_quantity(){
			return order_quantity;
		}
};

class drinks:public order{
	public:
		//display the drinks with codes
		void display_menu(){
			cout<<"\n\t\t*****************************************";
			cout<<"\n\t\tDrinks Menu";
			cout<<"\n\t\t*****************************************";
			cout<<"\n\t\t[6] Cocktails";
			cout<<"\n\t\t[7] Hard Soda";
			cout<<"\n\t\t[8] Barley";
			cout<<"\n\t\t[9] Lemon Tea";
			cout<<"\n\t\t[10] Milk";
		}
		
		//mutator function to set the price for each drinks according to user input
		void set_price(int code){
			switch(code){
				case 6:
					order_price=13.90;
					order_name="Cocktails";
					break;
				case 7:
					order_price=3.10;
					order_name="Hard Soda";
					break;
				case 8:
					order_price=1.50;
					order_name="Barley";
					break;
				case 9:
					order_price=3.20;
					order_name="Lemon Tea";
					break;
				case 10:
					order_price=3.00;
					order_name="Milk";
					break;
			}
		}
		
		//accessor function to return order_price to main function
		float get_price(){
			return order_price;
		}
		
		//display the name and price of the drinks that the user has choosen
		void display_drinks(){
			cout<<"\n\t\tYou have ordered "<<order_name;
			cout<<fixed<<setprecision(2)<<"\n\t\tPrice: RM "<<order_price;
		}
		
		//user input for drinks quantity
		void set_quantity(){
			cout<<"\n\t\tEnter quantity: ";
			cin>>order_quantity;
		}
		
		//accessor function to return order_quantity to main function
		int get_quantity(){
			return order_quantity;
		}
};

class bill:public order{
	private:
		float total,extra;
		int food,drinks;
		
	public:
		//initialise all variables to 0 with default constructor
		bill(){
			total=0;
			food=0;
			drinks=0;
			extra=0;
		}
		
		//mutator function to assign variables
		void set_bill(float t, int &f, int &d, float e){
			food=f;
			drinks=d;
			total=t;
			extra=e;
		}	
		
		//display the bill
		void display_bill(){
			system("cls");
			cout<<"\n\t\t*****************************************";
			cout<<"\n\t\t\t\tBill";
			cout<<"\n\t\t*****************************************";
			cout<<"\n\t\tName			: "<<name;
			cout<<"\n\t\tPhone Number		: "<<hp;
			cout<<"\n\t\tTotal Numbers of Food	: "<<food;
			cout<<"\n\t\tTotal Numbers of Drinks : "<<drinks;
			cout<<fixed<<setprecision(2)<<"\n\t\tExtra Fees 		: RM "<<extra;
			cout<<fixed<<setprecision(2)<<"\n\t\tTotal amount to be payed is RM "<<total+extra;
		}
	
};

int main(){
	//declare variables
	int menuCode, foodCount=0, drinksCount=0,num,quantity=0,status;
	char choice;
	float price,total=0,extra=0;
	

	//declare object for class welcome to call constructor by default
	welcome wel;
	
	//declare object for class food, drinks and bill
	food *f;
	f=new food;
	
	drinks *d;
	d=new drinks;
	
	bill *b;
	b=new bill;
	
	//display menu and header
	b->setData();
	b->order_header();
	f->display_menu();
	d->display_menu();
	
	//determine the array size for ord2 by asking user input
	cout<<"\n\t\t*****************************************";
	cout<<"\n\t\tHow many types of dishes would you like to order?: ";
	cin>>num;
	
	//declare dynamic array for class order
	order *ord2;
	ord2=new order[num];
	
	//for loop to loop according to the size of the array 
	for(int i=0;i<num;i++){
			//call function to get user input for the codes and return to main function
			ord2[i].setOrder();
			menuCode=ord2[i].getOrder();
			
			//determine if the order belongs to class food or drinks using condition statement
			if(menuCode>=1&&menuCode<=5){
				f->set_price(menuCode);
				f->display_food();
				f->set_quantity();
				price=(f->get_price());
				quantity=(f->get_quantity());
				//variable to determine the total amount
				total+=(price*quantity);
				//counter to determine how many food is ordered
				foodCount+=quantity;
			}
			else if(menuCode>=6&&menuCode<=10){
				d->set_price(menuCode);
				d->display_drinks();
				d->set_quantity();
				price=(d->get_price());
				quantity=(d->get_quantity());
				//variable to determine the total amount
				total+=(price*quantity);
				//counter to determine how many drinks is ordered
				drinksCount+=quantity;
			}
			else{
				cout<<"\n\t\tInvalid menu code. Please try again!";
				i--;
			}
	}
	
	//user input to determine whether the user needs delivery or not
	cout<<"\n\t\t*****************************************";
	cout<<"\n\t\tExtra Fees";
	cout<<"\n\t\t*****************************************";
	cout<<"\n\t\tDelivery = RM 4.00";
	cout<<"\n\t\tTakeaway = None ";
	cout<<"\n\t\tDelivery or Takeaway? [D- Delivery T-Takeaway]: ";
	cin>>choice;
	
	//assign extra fees according to user input
	if(choice=='D'){
		extra=4.00;
	}
	else if(choice=='T'){
		extra=0;
	}
	
	//send the total amount, food counter and drinks counter as argument to class bill
	b->set_bill(total,foodCount,drinksCount,extra);
	//call function to display the bill
	b->display_bill();
	
	//delete new objects
	delete f;
	delete d;
	delete b;
	//delete this dynamic array of objects
	delete []ord2;

	return 0;
}


