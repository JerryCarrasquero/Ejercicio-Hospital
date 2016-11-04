#include<iostream>
#include<vector>
#include<algorithm>
#include <stdlib.h>
#include <string>
using namespace std;
class Person{
private:
	int id;
	string name;
	string gender;
	string bloodtype;
public:
	void setId(int id){
		this->id=id;
	}
	int getid (){
		return this->id;
	}
	void setName(string name){
		this->name=name;
	}
	string getName(){
		return this->name;
	}
	
	void setGender(string gender){
		this->gender=gender;
	}
	string getgender(){
		return this->gender;
	}
	
	void setBloodType(string bloodtype){
		this->bloodtype=bloodtype;
	}
	string getBloodType(){
		return this->bloodtype;
	}
	Person(){}
	Person(int id,string name,string gender,string bloodtype){
		this->id=id;
		this->name=name;
		this->gender=gender;
		this->bloodtype=bloodtype;
	}
	virtual void info (){
		cout<<"\n informacion\n";
		cout<<"\n name: "<<getName();
		cout<<"\n Bloodtype: "<<getBloodType();
		cout<<"\n Gender: "<<getgender();
		cout<<"\n ID :"<<getid();
	}
};
class Illness{
private:
	string illness;
public:
		void setillness(string illness){
			this->illness=illness;
		}
		string getillness(){
			return this->illness;
		}
		void info (){
			cout<<"\n Case:"<<getillness();
		}
};
class Daywork{
private:
	string day;
	string hour;
	string shift;
public:
	void setday(string day){
		this->day=day;
	}
	string getday(){
		return this->day;
	}
	
	void sethour(string hour){
		this->hour=hour;
	}
	string gethour(){
		return this->hour;
	}
	void setshift(string hour,string day){
		this->shift=hour+" on "+day;
	}
	string getshift(){
		return this->shift;	}
		
		void info (){
			cout<<"\n shift:"<<getshift();
		}
};
	class Employee : public Person{
	private:
		int code;
		double salary;
		
	public:
		Daywork shift;
		void setcode(int code){
			this->code=code;
		}
		int getcode (){
			return this->code;
		}
		void setsalary(double salary){
			this->salary=salary;
		}
		double getsalary(){
			return this->salary;
		}
		Daywork setshift(Daywork shift){
			this->shift=shift;
		}
		Daywork getshift(){
			return this->shift;
		}
		
		void info (){
			Person::info();
			cout<<"\n Code :"<<getcode();
			cout<<"\n Salary :"<<getsalary();
			this->shift.info();
		}
		Employee(){}
		Employee(int id,string name,string bloodtype,string gender,int code ,double salary,string hour,string day){
			this->setId(id);
			this->setName(name);
			this->setGender(gender);
			this->setBloodType(bloodtype);
			this->code=code;
			this->salary=salary;
			this->shift.setshift(hour,day);
		}
		
	};//end Class2	
class Professional : public Employee{
private:
	string type;
	string specialty;
public:
	void settype(string type){
		this->type=type;
	}
	string gettype(){
		return this->type;
	}
		
	void setspecialty(string specialty){
		this->specialty=specialty;
	}
	string getspecialty(){
		return this->specialty;
	}
	void info (){
		Employee::info();
		cout<<"\n type :"<<gettype();
		cout<<"\n specialty :"<<getspecialty();
	}
	Professional(){}
	Professional(int id,string name,string bloodtype,string gender,int code ,double salary,string type,string specialty,string hour,string day){
		this->setId(id);
		this->setName(name);
		this->setGender(gender);
		this->setBloodType(bloodtype);
		this->setcode(code);
		this->setsalary(salary);
		this->type=type;
		this->specialty=specialty;
		this->shift.setshift(hour,day);
		/*this->setshift(shift);*/
	}
};//end class Professional
class Worker : public Employee{
private:
	string type;
public:
	void settype(string type){
		this->type=type;
	}
	string gettype(){
		return this->type;
	}
	void info (){
		Employee::info();
		cout<<"\n type :"<<gettype();
	}
	Worker(){}
	Worker(int id,string name,string bloodtype,string gender,int code ,double salary,string type,string hour,string day){
		this->setId(id);
		this->setName(name);
		this->setGender(gender);
		this->setBloodType(bloodtype);
		this->setcode(code);
		this->setsalary(salary);
		this->type=type;
		this->shift.setshift(hour,day);
		/*this->setshift(shift);*/
	}
};//end class Worker
class Patient : public Person{
private:
	int number;
	string date_in;
	string date_out;
	bool status;
	
public:
	Illness illness;
	void setdatein(string date_in){
		this->date_in=date_in;
	}
	string getdatein(){
		return this->date_in;
	}
	void setdateout(string date_out){
		this->date_out=date_out;
	}
	string getdateout(){
		return this->date_out;
	}
	void setnumber(int number){
		this->number=number;
	}
	int getnumber(){
		return this->number;
	}
	void setstatus(bool status){
		this->status=status;
	}
	bool getstatus(){
		return this->status;
	}
	Illness setillness(Illness illness){
		this->illness=illness;
	}
	Illness getillness(){
		return this->illness;
	}
	void info (){
		Person::info();
		cout<<"\n Age :"<<this->getnumber();
		cout<<"\n Date in :"<<this->getdatein();
		cout<<"\n Date out :"<<this->getdateout();
		if(getstatus()==false){//ask the teacher about it
		cout<<"\nStatus=dead"<< endl;
		}
		else{
		cout<<"\nStatus=alive"<< endl;
		}
		this->illness.info();
	}
	Patient(){}
	Patient(int id,string name,string bloodtype,string gender,int number ,string date_in,string date_out,bool status,string illness){
		this->setId(id);
		this->setName(name);
		this->setGender(gender);
		this->setBloodType(bloodtype);
		this->number=number;
		this->date_in=date_in;
		this->date_out=date_out;
		this->status=status;
		this->illness.setillness(illness);
		/*this->setshift(shift);*/
	}
};//end class Worker
class Hospital { 
private:
	Daywork shift;
public:
	string setday(){
		string day;
		int i;
		do {
			cout <<"Choose the days that the Employee will work"<< endl;
			cout << "\n1 - M/T1/W/T2/F/S1" << endl;
			cout << "\n2 - T1/W/T2/F/S1/S2" << endl;
			cout << "\n3 - M/T1/T2/F/S1/S2" << endl;
			cout << "\n4 - M/T1/W/F/S1/S2" << endl;
			cout << "\n5 - M/T1/W/F/S1/S2" << endl;
			cout << "\n6 - M/T1/W/T/S1/S2" << endl;
			cout << "\n7 - M/T1/W/T/F/S2" << endl;
			cin>>i;
			switch(i) {		
			case 1:
				day="M/T1/W/T2/F/S1";
				break;
			case 2:
				day="T1/W/T2/F/S1/S2";
				break;
			case 3:
				day="M/T1/T2/F/S1/S2";
				break;
			case 4:
				day="M/T1/W/F/S1/S2";
				break;
			case 5:
				day="M/T1/W/F/S1/S2";
				break;
			case 6:
				day="M/T1/W/T/S1/S2";
				break;
			case 7:
				day="M/T1/W/T/F/S2";
				break;
			}  
		}while(i<1 and i>7);
		return day;
	}
	string setturn(){
		int i;
		string turn;
		do{
			cout <<"Escoja el Turno:"<< endl;
			cout << "\n1 - Day shift" << endl;
			cout << "\n2 - Night shift" << endl;
			cin>>i;
			switch(i) {		
			case 1:
				turn=" Day shift";
				break;
			case 2:
				turn="Night shift";
				break;
			}  
		}while(i<1 and i>2);
		return turn;
	}
	string writecase(){
		
	}
	string choosegender(){
		int i;
		string gender;
		do {
			cout <<"introduce gender:"<< endl;
			cout << "\n1 - Male" << endl;
			cout << "\n2 - Female" << endl;
			cin>>i;
			switch(i) {		
			case 1:
				gender="Male";
				break;
			case 2:
				gender="Female";
				break;
			  
			default:{
				cout << "\nNo option available\n "<< endl;}
			}
		}while(i<0 || i>2);
		return gender;
	}
	string choosegblood(){
		int i;
		string bloodtype;
		do {
			cout<<"Choose Patient bloodtype";
			cout << "\n1 - Group A" << endl;
			cout << "\n2 - Group B" << endl;
			cout << "\n3 - Group AB" << endl;
			cout << "\n4 - Group O" << endl;
			cin>>i;
			switch(i) {	
			case 1:
				bloodtype="A";
				break;
			case 2:
				bloodtype="B";
				break;
			case 3:
				bloodtype="AB";
				break;
			case 4:
				bloodtype="o";
				break; 
			default:{
				cout << "\nNo option available\n "<< endl;}
			}
		}while(i<0 || i>4);
		return bloodtype;
		
	}
	
	void Hospitalmenu(){
	int i,x;
	vector<Patient*> v;
	vector<Employee*> e;
	v.push_back(new Patient(0,"J-pop girl","A","Female",19,"5/10/2002","7/10/2002",false,"rabies?"));
	v.push_back(new Patient(1,"Grethe Bruvold","O","Female",17,"29/10/2016","Undetermined",true,"Depression"));
	v.push_back(new Patient(2,"Carlos Suarez","B","Male",18,"25/10/2016","Undetermined",true,"Attemp of suicide afther failing math II for a second time"));
	e.push_back(new Worker(2,"Luigi Rojas","O","male",18,23000,"Janitor","Night Shift","never"));
	e.push_back(new Worker(1,"Hugo Archuleta","A","male",41,23000,"Janitor","Night Shift","Maybe?"));
	e.push_back(new Professional(0,"Dr. Fu Manchu","B","male",156,100000,"Doctor","Evil Genius","Night Shift","all days and on his lab"));
	do {
		system("cls");
		cout << "\n=======================================================================" << endl;
		cout << "\nHospital Saint Carlos of the Montes's Holy grace and the mercifull soul" << endl;
		cout << "\n=======================================================================" << endl;
		cout << "\nHospital menu"<< endl;
		cout << "\n1 - Log in a new pacient" << endl;
		cout << "\n2 - Introduce a new Employee on the system" << endl;
		cout << "\n3 - Look for a pacient" << endl;
		cout << "\n4 - Look for an Employee" << endl;
		cout << "\n5 - Update Patient status" << endl;
		cout << "\n0 - Exit" << endl;
		cout << "\nPick one:"<< endl;
		cin >> i;
		switch(i) {		
		case 1:do{
			system("cls");
			string /*fname,*/name, /*lastname,*/gender,bloodtype,date_out;
			int age, id,i,c,d,b;
			bool status;
			cin.ignore();
			cout << "\nPlease introduce the Patient name\n" << endl;
			getline(cin,name);
			cout << "introduce the patient ID: \n"<< endl;
			cin >> id;	
			cout << "introduce Patient Age: \n"<< endl;
			cin >> age;	
			cin.ignore();
			gender=choosegender();
			bloodtype=choosegblood();
			do {
				cout<<"\nStatus of the Patient upon entry"<< endl;
				cout<<"\n1-Alive"<< endl;
				cout<<"\n2-Decesased\n"<< endl;
				cin>>d;
				switch(d) {	
				case 1:
					status=true;
					date_out="not determine";
					break;
				case 2:
					status=false;
					date_out="Taken to the morgue";
					break;
				default:
					cout<<"\nSorry Mr.Schrödinger,there is nothing we can do about your cat"<< endl;
					break;
				}
			}while(d<0 || d>2);
			string test/*[30]*/;
			cin.ignore();
			cout<<"\nEnter pacient Illness:  \n";
		/*	fgets(test,30,stdin);*/
			getline(cin,test);
//			fflush(stdin);
			int number=v.size();
			string date_in="31/10/2016";
			Patient *p=new Patient(id,name,bloodtype,gender,number,date_in,date_out,status,test);
			p->info();
			v.push_back(p);
			cout << "\nIntroduce another Patient? "<< endl;
			cout << "1-yes "<< endl;
			cout << "2-no \n"<< endl;
			cin >> x;
		}while(x!=2);
		break;
		case 2:do{
			system("cls");
			string name,gender,bloodtype,type,specialty;
			int age, id,i,c,d,salary;
			cin.ignore();
			cout << "\nPlease introduce the Employee name\n" << endl;
			getline(cin,name);
			cout << "introduce the Employee ID:\n "<< endl;
			cin >> id;	
			cout << "introduce Employee Age:\n "<< endl;
			cin >> age;
			cin.ignore();
				if (age<18){
					cout << "The venezuelan code of law prohibites the use children on a companie's work force\n "<< endl;
				}
				else{
			gender=choosegender();
			bloodtype=choosegblood();
			string day=setday();
			string hour=setturn();
			
			int code=e.size();
			do {
				cout << "\nChoose the Employee type "<< endl;
				cout << "1-Professional "<< endl;
				cout << "2-Worker\n "<< endl;
				cin>>d;
				if(d==1) {
					int b;
					do {
						cout << "\nChoose the Employee type "<< endl;
						cout << "1-Doctor "<< endl;
						cout << "2-Nurse\n "<< endl;
						cin>> b;
						if(b==1) {
							type = "doctor";
							cout << "\nWritte doctor's speciality "<< endl;
							cin>> specialty;
							cout << "\nWritte doctor's Salary "<< endl;
							cin>> salary;								
						}
						else if(b==2) {
							type= "nurse";
							cout << "\nWritte Nurses's speciality "<< endl;
							cin>> specialty;
							cout << "\nWritte Nurses's Salary "<< endl;
							cin>> salary;							
						}
						else {
							cout << "\nPlease try again "<< endl;
						}
					}while(b<0 || b>2);
					Professional *g=new Professional(id, name, bloodtype, gender, code , salary, type, specialty,hour,day);
					g->info();
					e.push_back(g);
				}
				else if(d==2){
					int b;
					do {
					cout << "\nChoose the Employee type "<< endl;
					cout << "1-Administrative job "<< endl;
					cout << "2-Janitor\n "<< endl;
					cin>> b;
					if(b==2) {
						type = "Janitor";
						cout << "\nWritte janitor's Salary "<< endl;
						cin>> salary;								
					}
					else if(b==1) {
						type= "Administrative job";
						cout << "\nWritte Administrator's Salary "<< endl;
						cin>> salary;							
					}
					else {
						cout << "\nPlease try again "<< endl;
					}
					}while(b<0 || b>2);
					Worker *h=new Worker (id, name, bloodtype, gender, code , salary, type,hour,day);
					h->info();
					e.push_back(h);
				}
			}while(c<0 and 2>c);
				}
			cout << "\nIntroduce another Employee?"<< endl;
			cout << "1-yes "<< endl;
			cout << "2-no\n"<< endl;
			cin >> x;
		}while(x!=2);
		break;
		case 3:
			int g;
			do{	
				int id;
				g=0;
				system("cls");
				cin.ignore();
				cout<<"\nIntroduce the ID for the Patient you wish to search for\n";
				cin>>id;
				for (int i=0;i<v.size();i++){
					if(id==v[i]->getid()){
						v[i]->info();
						g=+1;
						break;
					}
				}
				if (g==0){
					cout<<"\nNo Patient by that ID found\n";
				}
				cout << "\nIntroduce another Patient?\n "<< endl;
				cout << "1-yes "<< endl;
				cout << "2-no "<< endl;
				cin >> x;
			}while(x!=2);
			break;
		case 4:
			do{int id;
			g=0;
			system("cls");
			cin.ignore();
			cout<<"\nIntroduce the ID for the Employee you wish to search for\n";
			cin>>id;
			for (int i=0;i<e.size();i++){
				if(id==e[i]->getid()){
					e[i]->info();
					g=+1;
					break;
				}
			}
			if (g==0){
				cout<<"\nNo Employee by that ID found\n";
			}
			cout << "\nIntroduce another Patient?\n "<< endl;
			cout << "1-yes "<< endl;
			cout << "2-no "<< endl;
			cin >> x;
		}while(x!=2);
			
			break;
		
		case 5:do{
			int id,m;
			g=0;
			system("cls");
			cout<<"\nIntroduce the ID for the Patient you wish to Update\n";
			cin>>id;
			for (int i=0;i<v.size();i++){
				if(id==v[i]->getid()){
					v[i]->info();
					g=+1;
					do {
						cout<<"\nChoose Patient value to update";
						cout << "\n1 - Case" << endl;
						cout << "\n2 - Exit Date(set pacient exit day to today)" << endl;
						cout << "\n3 - set status" << endl;
						cin>>m;
						switch(m) {	
						case 1:{
							cin.ignore();
							string ncase;
							cout<<"Type the pacients symtomps ";
							getline(cin,ncase);
							v[i]->illness.setillness(ncase);
							break;}
						case 2:{
								cin.ignore();
							cout<<"Updating pacient exit to today ";
							system("pause");
							v[i]->setdateout("31/10/2016");
							
							break;	}							
						case 3:{
							int d;
							do {
								cin.ignore();
								bool status;
								string date_out;
								cout<<"\nStatus of the Patient upon entry"<< endl;
								cout<<"\n1-Alive"<< endl;
								cout<<"\n2-Decesased\n"<< endl;
								cin>>d;
								switch(d) {	
								case 1:{
									v[i]->setstatus(true);
									v[i]->setdateout("not determine");
									break;}
								case 2:{
									v[i]->setstatus(false);
									v[i]->setdateout("Taken to the morgue");
									break;}
								default:{
									cout<<"\nSorry Mr.Schrödinger,there is nothing we can do about your cat"<< endl;
									break;}
								}
							}while(d<0 || d>2);
							break;
							default:{
							cout << "\nNo option available\n "<< endl;}
							}//end case
						}
					}while(m<0 || m>3);
					v[i]->info();
				}
			}
			if (g==0){
				cout<<"\nNo Patient by that ID found\n";
			}
			cout << "\nIntroduce another Patient?\n "<< endl;
			cout << "1-yes "<< endl;
			cout << "2-no "<< endl;
			cin >> x;
		}while(x!=2);
			break;
		case 0:
			cout << "\nHave a nice day \n"<< endl;
			break;
		default:
			cout << "\nNo option available\n "<< endl;
			system("pause");
			break;
		} 
	}while(i!=0);}	
};
int main (int argc, char *argv[]) {
	Hospital newhospital = Hospital();
	newhospital.Hospitalmenu();
	return 0;
}

