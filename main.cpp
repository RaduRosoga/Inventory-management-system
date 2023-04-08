#include <bits/stdc++.h>
//#include <algorithm>
using namespace std;
//$ is the chosen currency

float balance=10000;

class Shop{
	
	protected:
		string shop_name;
		bool Valve_affiliation;
	
	public:
		
		//setters
		void set_shop_name(string u_shop_name);
		void set_Valve_affiliation(bool u_Valve_affiliation);
	
		
		//getters
		string get_shop_name();
		bool get_Valve_affiliation();
		
		//Constructors
		Shop();
		Shop(string u_shop_name, bool u_Valve_affiliation);
		
		//Destructor
		~Shop();
};

/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Shop methods definitions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	
void Shop ::set_shop_name(string u_shop_name)
{
	shop_name=u_shop_name;
}

void Shop ::set_Valve_affiliation(bool u_Valve_affiliation)
{
	Valve_affiliation=u_Valve_affiliation;
}

string Shop :: get_shop_name()
{
	return shop_name;
}

bool Shop :: get_Valve_affiliation()
{
	return Valve_affiliation;
}

Shop :: Shop()
{
    cout<<"Implicit constructor was called. (Shop)\n";
    shop_name = "Default name";
	Valve_affiliation = false ;
}

Shop :: Shop(string u_shop_name, bool u_Valve_affiliation){
	cout<<"Constructor with parameters was called. (Shop)\n";
	shop_name=u_shop_name;
	Valve_affiliation = u_Valve_affiliation;
}

Shop :: ~Shop()
    {
        cout<<"Destructor was called. (Shop)\n";
    }
	

class Item :public Shop{
	protected:
		string item_name;
		string category;
		
	public:
		
		//setters
		void set_item_name(string item_name)
		{
			this-> item_name = item_name;
		}
		void set_category(string category)
		{	
			this-> category = category;
		}
	
		
		//getters
		string get_item_name()
		{
			return this->item_name;
		}
		string get_category()
		{
			return this->category;
		}
		
		//Constructors
		Item():Shop()
		{
            cout<<"Implicit constructor was called. (Item)\n";
            item_name = "Gun :(";
            category= "Rifle";
        }		
        
		Item(string u_shop_name, bool u_Valve_affiliation, string u_item_name, string u_category) :
			Shop(u_shop_name, u_Valve_affiliation)
		{
			cout<<"Constructor with parameters was called. (Item)\n";
			item_name=u_item_name;
			category=u_category;
		}
		//Destructor
		~Item()
		{
        cout<<"Destructor was called. (Item)\n";				
		}
};


class Skin: public Item{
	protected:
		string skin_name;
		string rarity;
		string condition;
		
		//bool stickers;
		int no_stickers;
	public:
		float price;
	public:
		
		//setters
		void set_skin_name(string skin_name)
		{
			this->skin_name = skin_name;
		}
		void set_rarity(string rarity)
		{
			this->rarity = rarity;
		}
		void set_condition(string condition)
		{
			this->condition = condition;
		}
		void set_price(float price)
		{
			this->price = price;
		}
		void set_no_stickers(int no_stickers)
		{
			this->no_stickers = no_stickers;
		}
		
		//getters
		string get_skin_name()
		{
			return this->skin_name;
		}
		string get_rarity()
		{
			return this->rarity;
		}
		string get_condition()
		{
			return this->condition;
		}
		float get_price()
		{
			return this->price;
		}
		int get_no_stickers()
		{
			return this->no_stickers;
		}
		
		//constructors
		Skin():Item()
		{
			skin_name="Default";
			rarity="Common";
			condition="Battlescared";
			price=0.00;
			no_stickers=1;
			//we consider there is a infinite quatity of this item on the market
		}
		Skin(string u_shop_name, bool u_Valve_affiliation, string u_item_name, string u_category, 
			string u_skin_name, string u_rarity, string u_condition, float u_price,  int u_no_stickers):
				Item(u_shop_name, u_Valve_affiliation, u_item_name, u_category)
			{
				skin_name=u_skin_name;
				rarity=u_rarity;
				condition=u_condition;
				price=u_price;
			//	stickers=u_stickers;
				no_stickers=u_no_stickers;		
			}
			
		void increase_price(float x)
		{
			price += x;
		}
		
		void decrease_price (float x)
		{
			price -= x;
		}
		
		friend void change_stickers(Skin &skin_1, Skin &skin_2);
};
class Inventory : public Skin{
	protected :
		string owner;
	public:
		//setter
		void set_owner( string owner)
		{
			this->owner = owner;
		}
		//getter
		string get_owner()
		{
			return this->owner;
		}
		
		//Constructors
		
		Inventory(): Skin()
		{
			owner="OWNER X";
		}
		Inventory(string u_owner, string u_shop_name, bool u_Valve_affiliation, string u_item_name, string u_category, 
			string u_skin_name, string u_rarity, string u_condition, float u_price,  int u_no_stickers): Skin( u_shop_name, 
				u_Valve_affiliation, u_item_name, u_category, u_skin_name, u_rarity,  u_condition, u_price,  u_no_stickers)
		{
			owner=u_owner;
	
		}
		
		~Inventory()
		{
        cout<<"Destructor was called. (Inventory)\n";				
		}
	
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void change_stickers(Skin &skin_1, Skin &skin_2)
{
	if(skin_1.get_no_stickers() == 0)
		cout << "The Gun does not have any stickers.";
	else
	{
		skin_1.no_stickers--;
		skin_2.no_stickers++;
		cout << "One sticker was transfered from " << skin_1.get_item_name()<< " " <<skin_1.get_skin_name() << " to  "<< 
		skin_1.get_item_name()<< " "  << skin_2.get_skin_name() << "\n\n";
	}
}
//function to comnpare 2 objects by price
//source: https://stackoverflow.com/questions/12823573/c-sorting-class-array
bool operator>(Skin const & skin_1,  Skin const & skin_2)
		{
    		return skin_1.price > skin_2.price;
		}

int main()
{
/*	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~testing the functionality of Shop~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	Shop s_default;
	Shop s_parameters("Steam marketplace",true);
	
	cout << "\n~~~~Default obj~~~~ \n";
	cout << "Name: " << s_default.get_shop_name() << endl;
	cout << "Valve affiliation: " << s_default.get_Valve_affiliation() << "\n\n" ;
	
	cout << "\n~~~~Obj with paramenters~~~~ \n";
	cout << "Name: " << s_parameters.get_shop_name() << endl;
	cout << "Valve affiliation: " << s_parameters.get_Valve_affiliation() << "\n\n" ;
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~testing the functionality of Item~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	Item i_default;
	Item i_parameters("Steam marketplace",true,"AK-47","rifle");
	
	cout << "\n~~~~Default obj~~~~ \n";
	cout << "Shop name: " << i_default.get_shop_name() << endl;
	cout << "Valve affiliation: " << i_default.get_Valve_affiliation() << endl ;
	cout << "Item name: " << i_default.get_item_name() << endl;
	cout << "Category: " << i_default.get_category()<<"\n\n";
	
	cout << "\n~~~~Obj with paramenters~~~~ \n";
	cout << "Shop name: " << i_parameters.get_shop_name() << endl;
	cout << "Valve affiliation: " << i_parameters.get_Valve_affiliation() << endl ;
	cout << "Item name: " << i_parameters.get_item_name() << endl;
	cout << "Category: " << i_parameters.get_category()<<"\n\n";
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~testing the functionality of Skin~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	Skin sk_default;
	Skin sk_parameters("Steam marketplace",true,"AK-47","rifle","Vulcan","Covert(Red)","Factory New",45.50,4);
	
	cout << "\n~~~~Default obj~~~~ \n";
	cout << "Shop name: " << sk_default.get_shop_name() << endl;
	cout << "Valve affiliation: " << sk_default.get_Valve_affiliation() << endl ;
	cout << "Item name: " << sk_default.get_item_name() << endl;
	cout << "Category: " << sk_default.get_category()<< endl;
	cout << "Skin name: " << sk_default.get_skin_name() << endl;
	cout << "Rarity: " << sk_default.get_rarity() << endl;
	cout << "Condition: " << sk_default.get_condition() << endl;
	cout << "Price: " << sk_default.get_price() << endl;
	cout << "No_stickers: " << sk_default.get_no_stickers() << endl;
	
	cout << "\n~~~~Obj with paramenters~~~~ \n";
	cout << "Shop name: " << sk_parameters.get_shop_name() << endl;
	cout << "Valve affiliation: " << sk_parameters.get_Valve_affiliation() << endl ;
	cout << "Item name: " << sk_parameters.get_item_name() << endl;
	cout << "Category: " << sk_parameters.get_category()<< endl;
	cout << "Skin name: " << sk_parameters.get_skin_name() << endl;
	cout << "Rarity: " << sk_parameters.get_rarity() << endl;
	cout << "Condition: " << sk_parameters.get_condition() << endl;
	cout << "Price: " << sk_parameters.get_price() << endl;
	cout << "No_stickers: " << sk_parameters.get_no_stickers() << endl;
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~testing the functionality of Inventory~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	Inventory inv_default;
	Inventory inv_parameters("Stefan","Steam marketplace",true,"AK-47","rifle","Vulcan","Covert(Red)","Factory New",45.50,4);
	
	cout << "\n~~~~Default obj~~~~ \n";
	cout << "Owner: "  << inv_default.get_owner()<< endl;
	cout << "Shop name: " << inv_default.get_shop_name() << endl;
	cout << "Valve affiliation: " << inv_default.get_Valve_affiliation() << endl ;
	cout << "Item name: " << inv_default.get_item_name() << endl;
	cout << "Category: " << inv_default.get_category()<< endl;
	cout << "Skin name: " << inv_default.get_skin_name() << endl;
	cout << "Rarity: " << inv_default.get_rarity() << endl;
	cout << "Condition: " << inv_default.get_condition() << endl;
	cout << "Price: " << inv_default.get_price() << endl;
	cout << "No_stickers: " << inv_default.get_no_stickers() << endl;
	
	cout << "\n~~~~Obj with paramenters~~~~ \n";
	cout << "Owner: " <<   inv_parameters.get_owner()<< endl;
	cout << "Shop name: " << inv_parameters.get_shop_name() << endl;
	cout << "Valve affiliation: " << inv_parameters.get_Valve_affiliation() << endl ;
	cout << "Item name: " << inv_parameters.get_item_name() << endl;
	cout << "Category: " << inv_parameters.get_category()<< endl;
	cout << "Skin name: " << inv_parameters.get_skin_name() << endl;
	cout << "Rarity: " << inv_parameters.get_rarity() << endl;
	cout << "Condition: " << inv_parameters.get_condition() << endl;
	cout << "Price: " << inv_parameters.get_price() << endl;
	cout << "No_stickers: " << inv_parameters.get_no_stickers() << endl;
	
*/	
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Program Flow ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	int n, selection_1, selection_2,no_st, i=1,ii=1;
	string shop, item, categ, skin, rar,cond;
	char afil1;
	bool afil2;
	float pr;
	int corectness = 0; //Used to check the option input
	
	cout << "\n  ~~~~~~~~~~~~~~~ Program flow ~~~~~~~~~~~~~~\n";
	
	cout << "\nInput the maximum number of skins in the shop: ";
	cin >> n;
			
	Skin skins[n+1];
	Inventory inv[n+1];
	
	do{
		
		cout << "\n Select one of the following options: \n" << endl;
		
		cout << "1. Add new skin" << endl;
		cout << "2. View skins" << endl;
		cout << "3. Skins interactions " << endl;
		cout << "4. Instructions" << endl;
		cout << "5. Exit " << endl; 
		
		corectness=0;
		do{
			
			cout << "\nSelection: ";
			cin >> selection_1;		
			
			if(selection_1 == 1 || selection_1 == 2 || selection_1 == 3 || selection_1 == 4 || selection_1 == 5){
				corectness = 1;
			}
			
		}while(corectness == 0);
		
		if (selection_1==1)
		{
			
			//add multiple skins for different guns
			cout << "\n Shop name: ";
			cin >> shop;
			
			cout << "\n Is the shop Valve affiliated? [Y]/[N]:";
			do
			{
				cin >> afil1;
				corectness=0;
				if (afil1=='Y')
				{
					afil2=true;
					corectness=1;
				}
				else if (afil1=='N')
					{
					afil2=false;
					corectness=1;
					}
					
				if (corectness=0)
					cout<<"\nIntroduce Y or N\n";
			
			}while(corectness=0);
			
			cout << "\n Item name: ";
			cin>> item;
			
			cout << "\n Category:";
			cin>> categ;
			
			cout << "\n Skin name: " ;
			cin>>skin;
			
			cout << "\n Rarity: ";
			cin>>rar;
			 
			cout << "\n Condition: " ;
			cin>> cond;
			
			cout << "\n Price: " ;
			cin>>pr;
			
			cout << "\n No_stickers: " ;
			cin>>no_st;
			
			skins[i].set_shop_name(shop);
			skins[i].set_Valve_affiliation(afil2);
			skins[i].set_item_name(item); 
			skins[i].set_category(categ);
			skins[i].set_skin_name(skin); 
			skins[i].set_rarity(rar);
			skins[i].set_condition(cond);
			skins[i].set_price(pr);
			skins[i].set_no_stickers(no_st);
			i++;
			
			string back_menu;
				
			cout << "Press anything to go back: ";
			cin >> back_menu;
			
			
		}
		
		if(selection_1 == 2){
			
			cout << "\n  ~~~~~~~~~~~~~~~~~~~~~~~  View skin inventory  ~~~~~~~~~~~~~~~~~~~~~\n" << endl;
			
			//We consider that all the doctors are from the same shop (argument for general data)
			for(int j = 1; j < i; j++)
			{
				
				cout << "Shop name: " << skins[j].get_shop_name() << endl;
				cout << "Valve affiliation: " << skins[j].get_Valve_affiliation() << endl ;
				cout << "Item name: " << skins[j].get_item_name() << endl;
				cout << "Category: " << skins[j].get_category()<< endl;
				cout << "Skin name: " << skins[j].get_skin_name() << endl;
				cout << "Rarity: " << skins[j].get_rarity() << endl;
				cout << "Condition: " << skins[j].get_condition() << endl;
				cout << "Price: " << skins[j].get_price() << endl;
				cout << "No_stickers: " << skins[j].get_no_stickers() << endl << endl;
			}
						
			string back_menu;
			cout << "\nPress anything to go back: ";
			cin >> back_menu;
			
		}
		if (selection_1==3)
		do{
				
			cout << "\nProcedures involving the skins and invetory" << endl;
						
			cout << "1. Show skins" << endl;
			cout << "2. Increase price by x" << endl;
			cout << "3. Decrease price by x" << endl;
			cout << "4. Sort the skins" << endl;
			cout << "5. Buy an item" << endl;
			cout << "6. Show inventory" << endl;
			cout << "7. Back to pricipal menu" << endl << endl;
				
		corectness = 0;
		
		do
		{
			
			cout << "\nSelection: ";
			cin >> selection_2;		
			
			if(selection_2 == 1 || selection_2 == 2 || selection_2 == 3 || selection_2 == 4||selection_2 == 5||selection_2 == 6||selection_2 == 7){
				corectness = 1;
			}
			
		}while(corectness == 0);
				
				if(selection_2 == 1)
				{
					for (int j=1;j<i;j++)
					cout << j <<". "<< skins[j].get_item_name()<< " " <<skins[j].get_skin_name() <<"\n";	
				}
				
				if(selection_2 == 2)
				{
					int j;
					float x;
					cout << "for which skin do you want to increase the price?(select a number): ";
					cin >> j;
					if(j<=i)
					{
						cout<<"increace price by: ";
						cin>>x;
						skins[j].increase_price(x);
					}
				}
				
				if(selection_2 == 3){
					int j;
					float x;
					cout << "for which skin do you want to decrease the price?(select a number): ";
					cin >> j;
					if(j<=i)
					{
						cout<<"decreace price by: ";
						cin>>x;
						skins[j].decrease_price(x);
					}
				
				}
				if(selection_2 == 4)
				{
					// source: https://stackoverflow.com/questions/12823573/c-sorting-class-array
					cout<<"\nUnfortunately this feature isn't working at this moment, we are working on solving the issue\n";
					
					// failed attempt at sorting the object using the function bool comp
//					std::sort(std::begin(skins), std::end(skins), comp);
//						
////					for(int j = 1; j < i; j++)
////					{
//				
//							cout << "Shop name: " << skins[j].get_shop_name() << endl;
//							cout << "Valve affiliation: " << skins[j].get_Valve_affiliation() << endl ;
//							cout << "Item name: " << skins[j].get_item_name() << endl;
//							cout << "Category: " << skins[j].get_category()<< endl;
//							cout << "Skin name: " << skins[j].get_skin_name() << endl;
//							cout << "Rarity: " << skins[j].get_rarity() << endl;
//							cout << "Condition: " << skins[j].get_condition() << endl;
//							cout << "Price: " << skins[j].get_price() << endl;
//							cout << "No_stickers: " << skins[j].get_no_stickers() << endl;
//						}
				}
				if(selection_2 == 5)
				{
					
					
					int y;
					cout<<"\n What item do want to buy?(insert number): ";
					cin>> y;
					
					string z;
					cout<<"\n Enter your name: ";
					cin>> z;
					
					balance -= skins[y].get_price();
					
					inv[ii].set_owner(z);
					inv[ii].set_shop_name(skins[y].get_shop_name());
					inv[ii].set_Valve_affiliation(skins[y].get_Valve_affiliation());
					inv[ii].set_item_name(skins[y].get_item_name()); 
					inv[ii].set_category(skins[y].get_category());
					inv[ii].set_skin_name(skins[y].get_skin_name()); 
					inv[ii].set_rarity(skins[y].get_rarity());
					inv[ii].set_condition(skins[y].get_condition());
					inv[ii].set_price(skins[y].get_price());
					inv[ii].set_no_stickers(skins[y].get_no_stickers());
					
					ii++;
				}
				
			if(selection_2 == 6)	
			{
				for(int j = 1; j < ii; j++)
				{	
					cout << "owner name: " << inv[j].get_owner() << endl;
					cout << "Item name: " << inv[j].get_item_name() << endl;
					cout << "Category: " << inv[j].get_category()<< endl;
					cout << "Skin name: " << inv[j].get_skin_name() << endl;
					cout << "Rarity: " << inv[j].get_rarity() << endl;
					cout << "Condition: " << inv[j].get_condition() << endl;
					cout << "Price: " << inv[j].get_price() << endl;
					cout << "No_stickers: " << inv[j].get_no_stickers() << endl << endl;
				}
				cout<< "Remained balance: "<< balance << "$" << endl << endl; 
			}
			
		}while(selection_2 != 7);
		
		if (selection_1==4)
			cout<<"pick numbers and discover the fetures <3" << endl;
			
		
	} while (selection_1!=5);
}




