#include <iostream>
#include <conio.h>
#include <fstream>
struct books
{
	int no;
	char book_name[25];
	char author_name[25];
	int price;

};
using namespace std;
void credit_card(void);
void book_collection(void);
void course_book(void);
void comic_book(void);
void histroy_book(void);
void novels(void);
void book_purchase(books[],int quant[]);
void book_search(void);
void required_book(void);
void book_cart(void);
void book_ordered(books,int b);
void book_stock(int &number,int amount,int selected_book,books d[]);
int pay=0;
int books_ready=0;
//BOOKS AVAILABLE IN BOOK STORE
books course[10]={{1,"PAK-STUDIES","HASSAN JAVED",70},
	{2,"ISLAMIC-STUDIES","ALI ARSHAD",70},
	{3,"COMMAND-ENGLISH","ALAN WALKER",70},
	{4,"COMPUTER","YASIN SABRI",70},
	{5,"DATABASE","FARKHANDA QAMAR",70},
	{6,"C++PROGRAMMING","FARKHANDA QAMAR",70},
	{7,"DATA-STRUCTURE","CHRIS THOMAS",70},
	{8,"ELECTRONICS","NOMAN HASSAN",70},
	{9,"STATISTICS","USMAN KHAN",70},
	{10,"CHEMISTRY","HAMMAD YOUSAF",70}};

books comics[10]={
	{1,"DOCTOR-STRANGE","JON HOPKINS",70},
	{2,"SPIDERMAN","GEORGE ORWELL",70},
	{3,"GHOST-IN-SHELL","KEVIN ROY",70},
	{4,"PUNISHER","SAM FISHER",70},
	{5,"WOLVERINE","PETERSON RAND",70},
	{6,"THE-DARK-KNIGHT","KEVIN HERTZ",70},
	{7,"BLACK-PANTHER","PETERSON LOGAN",70},
	{8,"INCREDIBLE-HULK","HARRY STYLES",70},
	{9,"FANTASTIC-FOUR","JOSEPH HELLER",70},
	{10,"GHOST-RIDER","ROSE TAYLOR",70}};

	books novel[10]={{1,"THE-OLD-MAN-&-THE-SEA","JAMES JOYCE",70},
	{2,"GOODBYE-MR.CHIPS","JAMES HILTON",70},									
	{3,"ULYSSES-HUMAN-FATE","JAMES JOYCE",70},											
	{4,"BATTLE-CRY-OF-FREEDOM","ALDOUS HUXLEY",70},									
	{5,"DARKNESS-AT-NOON","ARTHUR KOESTLER",70},
	{6,"THE-DEVIL-IN-THE-CITY","MALCOLM LOWRY",70},										
	{7,"BATTLEFIELD-EARTH","AYN RAND",70},									
	{8,"MISSION-EARTH-2050","RON HUBBARD",70},										
	{9,"THE-ABRAHAM-LINCOLN","HARPER LEE",70},	
	{10,"BRAVE-NEW-WORLD-1778","SCOTT JAMES",70}};	
	
	books history[10]={{1,"HIROSHIMA-REDEMPTION","JOHN HERSEY",70},
	{2,"THE-HISTORIES-OF-WAR","HERODOTUS",70},
	{3,"THE-RISE-AND-FALL","DAVID JOY",70},
	{4,"BATTLE-OF-FREEDOM","JAMES M.CARVER",70},
	{5,"GUNS,GERMS-AND-STEEL","JARED DIAMOND",70},						
	{6,"TEAM-OF-RIVALS-ALCHEMY","DAVID ROY",70},										
	{7,"THE-GUNS-OF-AUGUST","BARBARA TUCHMAN",70},							
	{8,"THE-DIARY-OF-YOUNG-GIRL","DAVID ROY",70},							
	{9,"A-DISTANT-MIRROR","BARBARA TUCHMAN",70},
	{10,"A-SHORT-HISTORY-OF-WWII","DEE BROWN",70}};

	int a[10]={10,10,10,10,10,10,10,10,10,10};
	int b[10]={10,10,10,10,10,10,10,10,10,10};
	int c[10]={10,10,10,10,10,10,10,10,10,10};
	int d[10]={10,10,10,10,10,10,10,10,10,10};


 void menu_display(void)
{
	system("cls");
	int a;
	cout<<"						Books Store					"<<endl<<endl<<endl<<endl;
	do
	{
	cout<<"1.Display The Books Collection:"<<endl;
	cout<<"2.Search The Requied Book:"<<endl;
	cout<<"3.Display Books You Ordered:"<<endl;
	cout<<"4.Enter Your Credit Card Number To Complete The Transaction:"<<endl<<endl;
	cout<<"\"Select The Options From The Main Menu:\""<<endl;
	cout<<"Press 0 To Exit From The Menu"<<endl;
	cin>>a;
	cout<<endl;
	/*if (a<1 || a>4)
	{
		cout<<"\"You Enter Wrong Option\""<<endl<<endl;
		continue;
	}
	else
	{
		break;
	}*/
	}
	while (a<0 || a>4);
	if (a==1)
	{
		book_collection();
	}
	else if (a==2)
	{
		book_search();
	}
	else if (a==3)
	{
		book_cart();
	}
	else if(a==4)
	{
		credit_card();
	}
	else if (a==0)
	{
		exit(0);
	}
}
void book_collection(void)
{
	system("cls");
	cout<<"					Books Collection					"<<endl;
	cout<<"1.Comic Books"<<endl<<"2.Course Books"<<endl<<"3.Novels"<<endl<<"4.History Books"<<endl<<"Press 0 To Retun To The Main Menu"<<endl;
	int a;
	cout<<"Select Option:";
	cin>>a;
	if (a==1)
	{
			comic_book();
	}
	else if (a==2)
	{
			course_book();
	}
	else if (a==3)
	{
			novels();
	}
	else if (a==4)
	{
			histroy_book();
	}
	else if (a==0)
	{
			menu_display();
	}
	else 
	{
		book_collection();
	}


}
void book_purchase(books p[],int quant[])
{
	int a;
	char b;
	int quantity;
	cout<<endl<<"Enter Book No. To Purchase The Book:"<<endl<<"\"Press 0 To Return To The Menu\""<<endl;
	cin>>a;
	if (a==0)
	{
		book_collection();
	}
	else if (a>0 && a<11)
	{
		system("cls");
		a--;
		
		cout<<endl<<"Book Selected"<<endl;
		cout<<"No:"<<"		Books Name:		"<<"	Author Name:		"<<"Price:	"<<endl;
		cout<<p[a].no<<"		"<<p[a].book_name<<"			"<<p[a].author_name<<"		   "<<p[a].price<<endl;
		cout<<"Quantity:";
		cin>>quantity;
		
		book_stock(quant[a],quantity,a,p);
		cout<<"Want To Buy Another Book(Y/N)?";
		cin>>b;
		if (b=='Y')
		{
			book_collection();
		}
		else
		{
			cout<<endl<<"			Books Ordered			"<<endl;
			system("pause");
			menu_display();
	}
	}
}
void main()
{
	menu_display();
	/*struct books
	{
		char name[25];
		int price;
	};
	books b[3];
	char author[25];
	int j=0;
	for(int k=0;k<3;k++)
	{
		cout<<"enter name & price:";
		cin>>b[k].name;
		cin>>b[k].price;
	}
	cout<<"Enter Name Kuttay:";
	cin>>author;



for (int i=0;i<3;i++)
{
	j=0;
	while (j<26)
	{
		if (b[i].name[j]==author[j])
		{
			j++;
			if(b[i].name[j]=='\0')
			{
				cout<<b[i].name<<endl;
				cout<<b[i].price<<endl<<"kkkk";
			}
		}
			else 
			{
				break;
			}
	}
	}

	*/


	getch();
	
}

void comic_book(void)
{
	system("cls");
	cout<<"					\" COMIC BOOKS \"					"<<endl<<endl;
	cout<<"No:"<<"		Books Name:		"<<"Author Name:		"<<"Price:	"<<endl<<endl;
	for (int i=0;i<10;i++)
	{
		cout<<endl<<comics[i].no<<"		"<<comics[i].book_name<<"	        "<<comics[i].author_name<<"		   "<<comics[i].price<<endl;
	}

	book_purchase(comics,a);
}
void course_book(void)
{
	system("cls");
	cout<<"					\" COURSE BOOKS \"					"<<endl<<endl;
	cout<<"No:"<<"		Books Name:		"<<"	Author Name:		"<<"Price:	"<<endl<<endl;
	for (int i=0;i<10;i++)
	{
		cout<<endl<<course[i].no<<"		"<<course[i].book_name<<"			"<<course[i].author_name<<"		   "<<course[i].price<<endl;
	}

	book_purchase(course,b);

}
void histroy_book(void)
{
	system("cls");
	cout<<"					\" HISTORY BOOKS \"					"<<endl<<endl;
	cout<<"No:"<<"		Books Name:		"<<"	Author Name:		"<<"Price:	"<<endl<<endl;
	for (int i=0;i<10;i++)
	{
		cout<<endl<<history[i].no<<"		"<<history[i].book_name<<"	        "<<history[i].author_name<<"		   "<<history[i].price<<endl;
	}

	book_purchase(history,c);
}

void novels(void)
{
	system("cls");
	cout<<"					\" NOVELS \"					"<<endl<<endl;
	cout<<"No:"<<"		Books Name:		"<<"	Author Name:		"<<"Price:	"<<endl<<endl;
	for (int i=0;i<10;i++)
	{
		cout<<endl<<novel[i].no<<"		"<<novel[i].book_name<<"	        "<<novel[i].author_name<<"		   "<<novel[i].price<<endl;
	}

	book_purchase(novel,d);

}


void book_search(void)
{
	system("cls");
	int a,i=0;
	static int c=0;
	cout<<"					Books Search					"<<endl<<endl;
	cout<<"1.Search By AuthorName:(In This Format e.g HASSAN JAVED)"<<endl;
	cout<<"2.Search By Book Name:(In This Format e.g THE-NEW-WORLD)"<<endl<<endl;
	cout<<"\"Press 0 To Return To The Main Menu\""<<endl;
	cout<<"Select Option:";
	cin>>a;
	cout<<endl;
	if (a==1)
	{
		cout<<"Enter Author Name:";
		char author[30];
		cin.ignore();
		cin.getline(author,30);
	for (i=0;i<40;i++)
	{
	int j=0;
	while (course[i].author_name[j]!='\0')
	{
		if (author[j]==course[i].author_name[j])
		{
			j++;
			if(author[j]=='\0')
			{
				cout<<endl<<"Author Found:"<<endl;
				cout<<endl<<course[i].no<<"		"<<course[i].book_name<<"	        "<<course[i].author_name<<"		   "<<course[i].price<<endl;
				
				c++;
			}

		}

		
		else 
		{
			break;
		}
	}
	}
	}
	else if (a==2)
	{
		cout<<"Enter Book Name:";
		char book[30];
		cin.ignore();
		cin.getline(book,30);
	for (i=0;i<40;i++)
	{
	int j=0;
	while (course[i].book_name[j]!='\0')
	{
		if (course[i].book_name[j]==book[j])
		{
			j++;
			
			if(book[j]=='\0')
			{
				cout<<endl<<"Book Found:"<<endl;
				cout<<course[i].no<<"		"<<course[i].book_name<<"	        "<<course[i].author_name<<"		   "<<course[i].price<<endl;
				c++;
				
			}

		}
		else 
		{
			break;
		}
	}
	}
	}
	else if (a==0)
	{
		menu_display();
	}
	else
	{
		//c=
		book_search();
	}
	
		
	
	if (c==0)
	{
		cout<<endl<<"Not Found"<<endl;
		system("pause");
		//c=
			book_search();
	}
	else if (c>0)
	{
		required_book();
	}
	//return c;
	//book_purchase();
}

void required_book(void)
{

}
void book_ordered(books p,int b)
{
		books_ready++;
		cout<<endl;
		ofstream copy("F:\\pf.txt",ios::app);
		copy<<p.no<<"		"<<p.book_name<<"		"<<p.author_name<<"		"<<p.price<<"		"<<b<<endl;
		pay=pay+(p.price*b);
		copy.close();
}

void book_cart(void)
{
	system("cls");
	int i,no,price,j=0,k;
	char name[25],author1[15],author2[15];
	
	ifstream display("F:\\pf.txt");
	while (j<books_ready)
	{
		
	display>>no>>name>>author1>>author2>>price>>k;
	cout<<endl<<no<<"		"<<name<<"	        "<<author1<<" "<<author2<<"		   "<<price<<"		   "<<k<<endl;
	j++;
	}
	display.close();
	cout<<endl<<"\"Press 0 To Return To The Main Menu\"";
	cin>>i;
	if (i==0)
	{
		menu_display();
	}
	else
	{
		book_cart();
	}
}
void credit_card(void)
{
	if (pay==0)
	{
		cout<<"No Book Ordered"<<endl;
		system("pause");
	}
	else
	{

	cout<<"Book You Ordered:"<<endl;
	int i,no,price,j=0,k;
	char name[25],author1[15],author2[15];
	
	ifstream display("F:\\pf.txt");
	while (j<books_ready)
	{
		
	display>>no>>name>>author1>>author2>>price>>k;
	cout<<endl<<no<<"		"<<name<<"	        "<<author1<<" "<<author2<<"		   "<<price<<"		   "<<k<<endl;
	j++;
	}
	
	display.close();
	cout<<endl<<"Total Bill:"<<pay<<endl;

	char card_no[15];
	cout<<"Please Enter Your Credit Card Number.(In This Format e.g 123-456-789)";
	cin.ignore();
	cout<<endl;
	cin.getline(card_no,15);
	cout<<endl<<"\"Bill Paid\""<<endl<<"THANKS FOR SHOPPING"<<endl;
	system("pause");
	}
	menu_display();
}
void book_stock(int &number,int amount,int selected_book,books d[])
{
	number=number-amount;
	if (number<0)
	{
		cout<<"Out Of Stock"<<endl;
	}
	else
	{
		book_ordered(d[selected_book],amount);
	}
}
	