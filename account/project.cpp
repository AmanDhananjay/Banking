#include<iostream>
#include<conio.h>
#include<fstream>
#include<iomanip>
using namespace std;
void arr(int p,int point)
 {
    if(p== point){cout<<"\t\t\t\t[+]";}
 	else         {cout<<"\t\t\t\t[ ]";}
}
int manu()
{    
int a=0,p=0;
do 
	{
	system ("cls");
	cout<<"\n\n\t\t\t\t======================\n";
	cout<<"\t\t\t\tBANK MANAGEMENT SYSTEM";
	cout<<"\n\t\t\t\t======================\n";
	  cout<<" \t\t\t\t    manu    \n";
	  arr(0,p);cout<<" log in \n";
	  arr(1,p);cout<<" sign up  \n";
	  arr(2,p);cout<<" exit\n";
	  cout<<"\t\t\t\t press enter to select\n";
	  a= getch();
	  if (a==80 && p!=2)p++;
	  if( a==72 && p!=0)p--;
	  else { p=p;
	  };
    }while(a!= 13);
     
     return p;
}
int manu1()
{ int a=0,p=3;
do 
	{
		
	system ("cls");
		cout<<"\n\n\t\t\t\t======================\n";
	  cout<<"  \t\t\t\t  user  manu    ";
	  	cout<<"\n\t\t\t\t======================\n";
	  arr(3,p);cout<<" deposit account \n";
	  arr(4,p);cout<<" withdraw account\n";
	  arr(5,p);cout<<" balance equiry\n";
	  arr(6,p);cout<<" delete account\n";
	  arr(7,p);cout<<" modify account\n";
	  arr(8,p);cout<<" show all account \n";
	  arr(9,p);cout<<" transfer amount \n";
	  arr(10,p);cout<<" back \n";
	  cout<<"\t\t\t\t press enter to select\n";
	    a= getch();
	     if (a==80 && p!=10)p++;
	     if( a==72 && p!=3)p--;
	      else { p=p;};
	      
    } while(a!= 13);
  
  return p;
}  
    class account
{
	 int acno;
     char name[50];
     int password;
	 int deposit;
	 char type;
   public:
 void create_account()
	 {
	 system("CLS");
	 cout<<"\n\t\t\tEnter the Account No. : ";
	 cin>>acno;
	 cout<<"\n\n\t\t\tEnter the Name of the Account holder : ";
	 cin.ignore();
	 cin.getline(name,50);
	 cout<<"\n\t\t\tEnter password. : ";
	 cin>>password;
	 cout<<"\n\t\t\tEnter Type of the Account (C/S) : ";
	 cin>>type;
	 type=toupper(type);
	 cout<<"\n\t\t\tEnter The Initial amount : ";
	 cin>>deposit;
	 cout<<"\n\n\t\t\tAccount Created..";
     };
  void show_account() 
	 {
	 cout<<"\n\t\t\tAccount No. : "<<acno;
	 cout<<"\n\t\t\tAccount Holder Name : "<<name;
	 cout<<"\n\t\t\t password : "<<password;
	 cout<<"\n\t\t\tType of Account : "<<type;
	 cout<<"\n\t\t\tBalance amount : "<<deposit;
     };
 void modify()
	 {
	 cout<<"\n\t\t\tAccount No. : "<<acno;
	 cout<<"\n\t\t\tModify Account Holder Name : ";
	 cin.ignore();
	 cin.getline(name,50);
	 cout<<"\n\t\t\tModify Type of Account : ";
	 cin>>type;
	 type=toupper(type);
	 cout<<"\n\t\t\tModify Balance amount : ";
	 cin>>deposit;
     };
	 void dep(int);
	 void draw(int);
	 void report() const;
	  int retacno() const;
	 int retdeposit() const;
	 char rettype() const;
	 int retpassword() const;
};
int account::retpassword() const
{
	return password;
}


void account::dep(int x)
{
	deposit+=x;
}

void account::draw(int x)
{
	deposit-=x;
}
  void account::report() const
{  cout<<acno<<"\t "<<name<<" \t"<<password<<"\t"<<type<<"\t"<<deposit<<endl;
//	cout<<acno<<" \t\t"<<name<<"\t\t "<<type<<"\t"<<deposit<<endl;
}

int account::retacno() const
{
	return acno;
}

int account::retdeposit() const
{
	return deposit;
}

char account::rettype() const
{
	return type;
}

  
  
  
void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);
	ac.create_account();
	outFile.write((char*) &ac, sizeof(account));
	//outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
	outFile.close();
}

void display_sp(int n)
{
	account ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\t\t\tBALANCE DETAILS\n";
    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			flag=true;
		}
	}
    inFile.close();
	if(flag==false)
		cout<<"\n\n\t\t\tAccount number does not exist";
}



void modify_account(int n)
{
	bool found=false;
	account ac;
	fstream File;
    File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			ac.show_account();
			cout<<"\n\n\t\t\tEnter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*static_cast<int>(sizeof(account));
			File.seekp(pos,ios::cur); //fncallat1353
		    File.write(reinterpret_cast<char *> (&ac), sizeof(account));
		    cout<<"\n\n\t\t\tRecord Updated";
		    found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n\t\t\tRecord Not Found ";
}



void delete_account(int n)
{
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
		}
	}
    inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	cout<<"\n\nRecord Deleted ..";
}


void display_all()
{
	system("CLS");
	account ac;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"\t\t====================================================\n";
	cout<<"\t\tA/c no.          NAME         Type   Balance\n";
	cout<<"\t\t====================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
	  cout<<"\t\t";
		ac.report();
	}
	inFile.close();
}


void deposit_withdraw(int n, int option,int amt)
{

	bool found=false;
	account ac;
	fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
		
			if(option==1)
			{
		
		;
				ac.dep(amt);
			}
		    if(option==2)
			{
			
		
				int bal=ac.retdeposit()-amt;
				if(bal<0)
					cout<<"Insufficience balance";
				else
					ac.draw(amt);
		      }
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			ac.show_account();
			cout<<"\n\n\t\t\tRecord Updated";
			found=true;
	    }
    }
    File.close();
	if(found==false)
		cout<<"\n\n\t\t\tRecord Not Found ";
}
int password(int n)
{ int p;
 
	account ac;
	cout<<"enter password";
	cin>>p;
	bool flag=false;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	   {
		 cout<<"File could not be open !! Press any Key...";
		 return n;
	   }
	
    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()==n && ac.retpassword()==p)
		{
			
			flag=true;
			return n ;
		}
	}
    inFile.close();
    if(flag==false)return 0;
	  	
		
}
 int singup()
    { int num;
     cout<<" enter your account no ::";
     cin>>num;
      num = password(num);
   
     return num;
    }


int main()
{    int p,num,num1,amt=0;
     char a,c;
   
  	 cout<<"\n\n\t\t\t\t======================\n";
 	 cout<<"\t\t\t\tBANK MANAGEMENT SYSTEM";
	 cout<<"\n\t\t\t\t======================\n";
   b:
     p= manu();
    
    a:
     switch(p)
		
		{
		case 0: num=singup();
		    if(num==0) 
		    { 
			cout<<" \n\n\t\t\tenter any botten to cotinue  \n";
		     cin>>a;
		     goto b;
		   }
	c:
		  p=manu1();
		 goto a;
			
			break;
		case 1: 
			write_account();
			break;
		case 2: exit(0);
		
			break;
		case 3: 
			cout<<"\n\n\t\t\t The account No. : "<<num; 
			cout<<"\n\n\t\t\t enter The amount : ";
			cin>>amt;
			deposit_withdraw(num, 2,amt);
			
			
			break;
		case 4:
			cout<<"\n\n\t\t\t The account No. : "<<num; 
			cout<<"\n\n\t\t\t enter The amount : ";
			cin>>amt;
			deposit_withdraw(num, 1,amt);
			break;
		case 5:
				display_sp(num);
			break;
		case 6 : 
		       delete_account(num);
		    break;
		 case 7:
		 	   modify_account(num);
			break;
		 case 8: 
		     display_all();
			break;
		case 9:
			display_all();
		     cout<<"\n\n\t\t\t The account No. in which u sent money: ";
		     cin>>num1;
			 cout<<"\n\n\t\t\t enter The amount : ";
		  	 cin>>amt;
		     deposit_withdraw(num, 2,amt);
		    
			 deposit_withdraw(num1, 1,amt);
		     
			break;	
		 case 10: 
		     goto b;
	       break;
		  
		}
	
	
		 	p=0;
		cout<<" \n\n\t\t\tpress Y or N botten to cotinue or exit \n";
		cin>>a;
		if(a=='y'||a=='Y')	
		 {goto c;
		 }
		 
	
	
	

	
}












