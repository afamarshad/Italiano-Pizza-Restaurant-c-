#define kSaladPrice 50            //Constant salad price 50
#include<iostream>
#include<fstream>
#include<iomanip>
#include<time.h>
#include<stdlib.h>
using namespace std;

//FOOD ORDERING SYSTEM

void start_page();             //Declaration of function for showing the menu
int pizzaPage();               //Declaration of function for Pizza calculations
int beveragePage();            //Decalartion of function for Beverage calculations
int dessertPage();             //Declaration of function for Dessert calculations
void save_in_file();           //Declaration of function for saving the bill in file
void exit();

struct food       //Structure named food for storing variables
{
    int pizza_qty;
    int total_pizza_price;
    int beverage_qty;
    int total_beverage_price;
    int dessert_qty;
    int total_dessert_price;
    char salad;
    int price;
    string array[6];
    
};    //Termination of Structure

//Main function

int main()
{   cout<<"\t\t\t\tFOOD ORDERING SYSTEM";
	cout<<"\n\t\t\t!!Welcome to Italiano Restaurant!!";
    cout<<"\n\t\t\t!!The best quality food in affordable prices!!";
    cout<<"\n\t\t\t\t\tCreated By: Afsah Arshad"<<"\n";
    cout<<"\n";
    int b;
    
    while(true)
    {
    	cout<<"\n\t\t";
    for(int i=0;i<25;i++)
    {
        cout<<char(178);
    }
    cout<<"START PAGE";
    for(int i=0;i<25;i++)
    {
        cout<<char(178);
    }
    cout<<"\n";
    cout<<"\n";
      do
	{
        cout<<"\t\t\t\t\t1). Show Menu\t\t\t\t\t\t\n";
        cout<<"\t\t\t\t\t2). Place Order\t\t\t\t\t\t\n";
        cout<<"\t\t\t\t\t3). EXIT\t\t\t\t\t\t\n\n";
         cout<<"\t\t";
        for(int i=0;i<60;i++)
        {
        cout<<char(178);
         }
    cout<<"\n";
        cout<<"\t\t Please Enter the option you want to go with :";
        cin>>b;
        if(b<1 || b>4 )
        {
            cout<<"\n\n\t\t\t wrong input plz try again !! \n\n";
        }

    }while(b<1 || b>4);
    
    
    if(b==1){
    	cout<<"\n\t\t";
    for(int i=0;i<25;i++)
    {
        cout<<char(178);
    }
    cout<<"MENU PAGE";
    for(int i=0;i<25;i++)
    {
        cout<<char(178);
    }
    cout<<"\n";
        cout<<"\n";
        start_page();       //Calling of Menu function
        cout<<"\t\tPIZZA: \t\t\tBEVERAGES:\t\tDESERTS:";
		cout<<"\n\t1). Pepperoni Pizza : Rs 358\t1). Pepsi: Rs 50\t1). Chocolate Cake: Rs 2300";
		cout<<"\n\t2). Hotnspicy Chicken: Rs 358\t2). Miranda: Rs 50\t2). Black Forest Cake: Rs 1700";
        cout<<"\n\t3). Tandoori Chicken: Rs 358\t3). Dew: Rs 35\t\t3). Pineapple Cake: Rs 1750";
	    cout<<"\n\t4). Chicken Tikka: Rs 358\t4). 7up: Rs 40\t\t4). Chocolate Fudge Cake: Rs 1249";
	    cout<<"\n\t5). Superb Cheese: Rs 278\t5). Coke: Rs 50\t\t5). Red Velvet Cake: Rs 2075";
	    cout<<"\n\t6). Veggie Feast: Rs 278\t6). Sprite: Rs 50\t6). Kit Kat Chocolate Cake: Rs 1250";
	    cout<<"\n\n\t\t";
        for(int i=0;i<60;i++)
        {
        cout<<char(178);
         }
    cout<<"\n";
	
    }
    else if(b==2){
        
        save_in_file();     //Calling of the function for taking output from file
    }
    
    else{
        
        exit();
        break;
    }
    
    }
    
}
//Defining the start page function

void start_page()
{
    ifstream input;
    string a;
    input.open("ItalianoPizza.txt");       //Opening a file named ItalianoPizza
    while(!input.eof())                    //If the file not equal to zero while loop will run
    {
        getline(input,a);
        cout<<a<<endl;
    }
    input.close();                        //Closing the file
    
    
}

//Defining the pizza page function

    int pizzaPage()
{
    int total_pizza_price;
    //String used with arrays to store the flavours of pizzas
    ofstream save;
    string pizza[]={"Pepperoni Pizza",
        "Hotnspicy Chicken",
        "Tandoori Chicken",
        "Chicken Tikka",
        "Superb Cheese",
        "Veggie Feast"};
    //Integer type array used to store the prices of different pizza flavours
    int pizzaPrices[]={358,
        358,
        358,
        358,
        278,
        278};
    cout<<"\n"<<setw(16);
    for(int i=0;i<24;i++)
    {
        cout<<char(178);
    }
    cout<<"Pizza Category";
    for(int i=0;i<24;i++)
    {
        cout<<char(178);
    }
    cout<<"\n\n";
    
    //For loop used to print the flavours of pizza along with their prices    
    for (int i = 0; i < 6; i ++)
    {
        cout <<"\t"<< setw(15) << i + 1 << ") " << pizza[i] << " = Rs. " << pizzaPrices[i] << endl;
    }
    
    cout<<"\n"<<setw(17);
    for(int i=0;i<60;i++)
    {
        cout<<char(178);
    }
    int pizzaChoice;
    cout << endl;
    cout << "\t\t\t\tChoose anyone of the above: ";
    cin >> pizzaChoice;
    cout << endl;
    
    //For displaying the user the type of pizza choosen
    save.open("pizza.txt");
    save << "\t\t\t\tYou chose: " << pizza[pizzaChoice - 1] << " = Rs. " << pizzaPrices[pizzaChoice - 1] << endl << endl;
    total_pizza_price=pizzaPrices[pizzaChoice - 1];
    save.close();
    return total_pizza_price;               //Returning the total price of pizza
    
}

//Defining the function beverage page

int beveragePage()
{
    int total_beverage_price;
    //String used with arrays to store the flavours of beverages
    string beverages[]={"Pepsi",
        "Miranda",
        "Dew","7up","Coke","Sprite"};
        
    //Integer type array for storing the prices of beverage
    int beveragePrices[]={50,
        50,
        35,
        40,
        50,50};
    cout<<"\n"<<setw(16);
    for(int i=0;i<22;i++)
    {
        cout<<char(178);
    }
    cout<<"Beverage Category";
    for(int i=0;i<22;i++)
    {
        cout<<char(178);
    }
    cout<<"\n\n";
    
    //For loop for displaying the menu of beverage along with their prices
    for (int i = 0; i < 6; i ++)
    {
        cout <<"\t"<< setw(15) << i + 1 << ") " << beverages[i] << " = Rs. " << beveragePrices[i] << endl;
    }
    cout<<"\n"<<setw(15);
    for(int i=0;i<63;i++)
    {
        cout<<char(178);
    }
    int beverageChoice;
    cout << endl;
    cout << "\t\t\t\tChoose anyone of the above: ";
    cin >> beverageChoice;
    cout << endl;
    //Displays the beverage choosen by the customer
    cout << "\t\t\t\tYou chose: " << beverages[beverageChoice - 1] << " = Rs. " << beveragePrices[beverageChoice - 1];
    cout<<endl;
    total_beverage_price=beveragePrices[beverageChoice - 1];
    return total_beverage_price;//Returning the total price of beverage
}
//Defining the dessert page function

int dessertPage()
{
    int total_dessert_price;
    //String type array for storing the flavours of dessserts
    string desserts[]={"Chocolate Cake",
        "Black Forest Cake",
        "Pineapple Cake",
        "Chocolate Fudge Cake",
        "Red Velvet Cake",
        "Kit Kat Chocolate Cake"};
    //Integer type array for storing the prices of desserts
    int dessertPrices[]={2300,
        1700,
        1750,
        1249,
        2075,
        1250};
        cout<<"\n\t\t";
    for(int i=0;i<22;i++)
    {
        cout<<char(178);
    }
    cout<<"Dessert Category";
    for(int i=0;i<22;i++)
    {
        cout<<char(178);
    }
    cout<<"\n\n";
    //For loop for displayng the desserts along with their prices
    for (int i = 0; i < 6; i ++)
    {
        cout <<"\t"<< setw(15) << i + 1 << ") " << desserts[i] << " = Rs. " << dessertPrices[i] << endl;
    }
    cout<<"\n"<<setw(15);
    for(int i=0;i<63;i++)
    {
        cout<<char(178);
    }
    int dessertChoice;
    cout << endl;
    cout << "\t\t\t\tChoose anyone of the above: ";
    cin >> dessertChoice;
    cout << endl;
    //Displays the choice of dessert choosen
    cout << "\t\t\t\tYou chose: " << desserts[dessertChoice - 1] << " = Rs. " << dessertPrices[dessertChoice - 1];
    cout<<endl;
    total_dessert_price=dessertPrices[dessertChoice - 1];
    return total_dessert_price;          //Returning total price of desserts
    
}
//Defining the save in file function

void save_in_file()
{
    
    food item;
    //For storing the bill in file
    ofstream outf;
    outf.open("Bill.txt",fstream::out);
    outf<<endl<<"\t\t\t\t\tBILL\t\t\t\t"<<endl;
    outf.close();
    
    cout<<"\t\t\t\tEnter 0 if you don't want pizza"<<endl;
    cout<<" \t\t\t\tEnter the quantity of pizza: ";
    cin>>item.pizza_qty;
    item.total_pizza_price = 0;
    outf.open("Bill.txt",fstream::app|fstream::out);
    for (int i = 0; i < item.pizza_qty; i ++)
    {
        item.total_pizza_price += pizzaPage();
    }
    outf<<"\t\t\t\tTotal pizza price: "<<item.total_pizza_price<<endl;
    outf.close();
    cout<<"\t\t\t\tEnter 0 if you don't want beverage"<<endl;
    cout<<"\t\t\t\tEnter the quantity of beverage: ";
    cin>>item.beverage_qty;
    item.total_beverage_price = 0;
    outf.open("Bill.txt",fstream::app|fstream::out);
    for (int i = 0; i < item.beverage_qty; i ++)
    {
        item.total_beverage_price += beveragePage();
    }
    outf<<"\t\t\t\tTotal beverage price: "<<item.total_beverage_price<<endl;
    outf.close();
    
    cout<<"\t\t\t\tEnter 0 if you don't want dessert\n"<<endl;
    cout<<"\t\t\t\tEnter the quantity of desserts: ";
    cin>>item.dessert_qty;
    item.total_dessert_price=0;
     outf.open("Bill.txt",fstream::app|fstream::out);
    for(int i = 0; i < item.dessert_qty; i ++)
    {
        item.total_dessert_price+=dessertPage();
    }
    outf<<"\t\t\t\tTotal dessert price: "<<item.total_dessert_price<<endl;
    outf.close();
    
    
    cout<<"\n\t\t\t\tDo you want the salad(y/n)(price="<<kSaladPrice<<")=";
    cin>>item.salad;
    outf.open("Bill.txt",fstream::app|fstream::out);
     //If the choice of salad will be equal to y then Rs. 50 will be added to the total price
    if(item.salad=='y')
    {
        item.price=item.total_pizza_price+kSaladPrice+item.total_beverage_price+item.total_dessert_price;
        outf<<"\t\t\t\tSalad Price = Rs. "<<kSaladPrice<<endl;
    }
    //If the choice of salad will be n then Rs. 50 will not be added to the total price
    else
    {
        item.price=item.total_pizza_price+item.total_beverage_price+item.total_dessert_price;
    }
    outf<<"\t\t\t\tTotal Price = Rs. "<<item.price;
    
    outf.close();
    
    cout<<"\t\tThanks for ordering, your bill will be displayed in the file!!"<<endl;
    
    char bill;
    cout<<"\t\tIf you want to display the bill here press(y)";
    cin>>bill;
    if(bill=='y')
    {
    cout<<"\n"<<setw(16);
    for(int i=0;i<30;i++)
    {
        cout<<char(178);
    }
    for(int i=0;i<30;i++)
    {
        cout<<char(178);
    }
    ifstream input;
    string a;
    
    input.open("bill.txt");        //Opening a file named ItalianoPizza
    while(!input.eof())            //If the file not equal to zero while loop will run
    {
        getline(input,a);
        cout<<a<<endl;
    }
    input.close();                 //Closing the file         
    }
    else
	{
		//For printing the message on the console screen that the bill has been saved to file
        cout<<"Displayed in file"<<endl;
    }

    
}
//Exit function is defined

void exit()
{
	cout<<"\n"<<setw(15);
    for(int i=0;i<63;i++)
    {
        cout<<char(175);
    }
	
    cout<<"\n\t\t\t\t\tThankyou !!\n";
    cout<<"\t\t\tDo come again to enjoy delicious food!!";
    cout<<"\n"<<setw(15);
    for(int i=0;i<63;i++)
    {
        cout<<char(175);
    }

}


