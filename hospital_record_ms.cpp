#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
typedef struct patient *patient_list;
typedef struct employee *employee_list;
typedef struct patient_bst *patient_bst_tree;
typedef struct employee_bst *employee_bst_tree;

struct patient 
{
  int ID;
  int age;
  string name;
  struct patient *next;
};

struct employee
{
  int ID;
  int age;
  string name;
  struct employee *next;
};

struct patient_bst 
{ 
	int ID;
	int age;
	string name; 
	struct patient_bst  *left, *right; 
}; 

struct employee_bst 
{ 
	int ID;
	int age;
	string name; 
	struct employee_bst  *left, *right; 
}; 

/////////////////////////////////////////////
/////PATIENT HELPER FUNCTIONS///////////////
void patient_insert(int x, int age, string name,patient_list l) 
{
  struct patient *new_patient;
  new_patient = new patient;
  new_patient->ID = x;
  new_patient->age = age;
  new_patient->name = name;
  new_patient->next = l->next;
  l->next = new_patient;
}

void patient_insert_end(int x, int age ,string name,patient_list l) 
{
  struct patient *new_patient;
  struct patient *temp_pat;
  temp_pat=l;
  while(temp_pat->next!=NULL && temp_pat!=NULL)
  {
    temp_pat=temp_pat->next;
  }
  new_patient = new patient;
  new_patient->ID = x;
  new_patient->age = age;
  new_patient->name = name;
  new_patient->next = NULL;
  temp_pat->next = new_patient;
}


//case 2
void patient_display(patient_list l) 
{
  cout << "PATIENT DETAILS :: \n";
  struct patient *p = l->next;
  while (p->next!= NULL && l!=NULL)
        {          
          cout << p->ID << "\t"<<p->name<<"\t"<<p->age<<"\n";
          p = p->next;
        }
  cout<<"NULL\n";
}

//case 5
void patient_write(patient_list l) 
{
  ofstream patient_file;
  patient_file.open("patients.txt",ios::trunc);
  struct patient *p = l->next;
  while (p->next != NULL && l!=NULL)
        { 
          patient_file << p->ID << "\t"<<p->name<<"\t"<<p->age<<"\n";
          p = p->next;
        }  
  patient_file.close();
}

void patient_read(patient_list l)
{
  fstream patient_file;
  patient_file.open("patients.txt",ios::in);
  int id;
  int age;
  string name;
  if(!patient_file){
    patient_file.close();
    patient_file.open("patients.txt",ios::out);
    patient_file.close();
    patient_file.open("patients.txt",ios::in);
  }
  while(1)
  {
    if(patient_file.eof()){break;}
    else
    {
      patient_file>>id;
      patient_file>>name;
      patient_file>>age;
      patient_insert_end(id,age,name,l);
    }
  }
  patient_file.close();
}

void patient_search(int x, patient_list l)
{

  struct patient *p = l->next;
  int flag=1;
  while(p!=NULL){
    if(p->ID==x)
    {
      cout<<"\n\nPatient ID:"<<p->ID<<"\tPatient Name:"<<p->name<<"\tPatient Age:"<<p->age<<"\n\n\n";
      flag=0;
    }
  p=p->next;
  }
  if(flag==1){cout<<"\nPatient with given ID is not found\n";}

}

void patient_modify(int x, string name, patient_list l){
//modify name only
  
struct patient *p = l->next;
int flag=1;
while(p!=NULL){
  if(p->ID==x)
  {
    p->name=name;
    flag=0;
  }
p=p->next;
}
if(flag==1){cout<<"\nPatient with given ID is not found\n";}
}

struct patient_bst *patient_bst_new_node(string name,int id,int age,patient_bst_tree bst) 
{ 
	struct patient_bst *temp;
	temp = new patient_bst;
	temp->name=name;
	temp->age=age;
	temp->ID=id;
	temp->left = temp->right = NULL;
	bst=temp; 
	return(bst);
} 

struct patient_bst *patient_bst_insert(string name,int id,int age,patient_bst_tree bst) 
{ 
	
	if (bst == NULL) {
		bst=patient_bst_new_node(name,id,age,bst); }

	else if (name<bst->name){
		bst->left=patient_bst_insert(name,id,age,bst->left);} 

	else{
		bst->right=patient_bst_insert(name,id,age,bst->right); }
	
	return(bst);
 
} 
//node search
void patient_bst_search(string name,patient_bst_tree bst) 
{ 
	
	if(bst == NULL){
		cout<<"Record not found";
	}
	
	else if (name==bst->name){
		cout<<"Record contains Patient: \n";
		cout<<"ID: "<<bst->ID<<"\tName: "<<bst->name<<"\tAge: "<<bst->age<<endl;
		}	 

	else if (name<(bst->name)){
		patient_bst_search(name,bst->left); }
	
	else if(name>(bst->name)){
		patient_bst_search(name,bst->right);}
	
} 
struct patient_bst *patient_bst_read(patient_bst_tree bst)
{
	string a1;
	ifstream patient_file;
	patient_file.open("patients.txt");
	string name;
	int id;
	int age;
  while(1){
    if(patient_file.eof()){break;}
    else
    {
        patient_file>>id;
        patient_file>>name;
        patient_file>>age;
        bst=patient_bst_insert(name,id,age,bst);
        }
    }
  patient_file.close();
  return(bst);
}


//////PATIENT HELPER FUNCTIONS END//////
////////////////////////////////////////

////////////////////////////////////////
//////EMPLOYEE HELPER FUNCTIONS/////////
void employee_insert(int x, int age,string name,employee_list k) 
{
  struct employee *new_employee;
  new_employee = new employee;
  new_employee->ID = x;
  new_employee->age = age;
  new_employee->name = name;
  new_employee->next = k->next;
  k->next = new_employee;
}

void employee_insert_end(int x, int age,string name,employee_list k) 
{
  struct employee *new_employee;
  struct employee *temp_emp;
  temp_emp=k;
  while(temp_emp->next!=NULL){
    temp_emp=temp_emp->next;
  }
  new_employee = new employee;
  new_employee->ID = x;
  new_employee->name = name;
  new_employee->age = age;
  new_employee->next = NULL;
  temp_emp->next = new_employee;
}


//case 2
void employee_display(employee_list k) 
{
  cout << "EMPLOYEE DETAILS :: \n";
  struct employee *p = k->next;
  while (p->next!= NULL && k!=NULL)
        {
          
          cout << p->ID << "\t"<<p->name<<"\t"<<p->age<<"\n";
          p = p->next;
        }
  cout<<"NULL\n";
}

//case 5
void employee_write(employee_list k) 
{
  ofstream employee_file;
  employee_file.open("employees.txt",ios::trunc);
  struct employee *p = k->next;
  while (p->next != NULL && k!=NULL)
        { employee_file << p->ID << "\t"<<p->name<<"\t"<<p->age<<"\n";
          p = p->next;
        }  
  employee_file.close();
}

void employee_read(employee_list k)
{
fstream employee_file;
employee_file.open("employees.txt",ios::in);
  int id;
  int age;
  string name;
  if(!employee_file){
    employee_file.close();
    employee_file.open("employees.txt",ios::out);
    employee_file.close();
    employee_file.open("employees.txt",ios::in);
  }

  while(1){
    if(employee_file.eof()){break;}
    else{
    employee_file>>id;
    employee_file>>name;
    employee_file>>age;
    employee_insert_end(id,age,name,k);
    }
    }
  employee_file.close();
}

void employee_search(int x, employee_list k){

struct employee *p = k->next;
int flag=1;
while(p!=NULL){
  if(p->ID==x)
  {
    cout<<"\n\nEmployee ID:"<<p->ID<<"\tEmployee Name:"<<p->name<<"\tEmployee Age"<<p->age<<"\n\n\n";
    flag=0;
  }
p=p->next;
}
if(flag==1){cout<<"\nEmployee with given ID is not found\n";}

}

void employee_modify(int x, string name, employee_list k){

  
struct employee *p = k->next;
int flag=1;
while(p!=NULL){
  if(p->ID==x)
  {
    p->name=name;
    flag=0;
  }
p=p->next;
}
if(flag==1){cout<<"\nEmployee with given ID is not found\n";}

}

struct employee_bst *employee_bst_new_node(string name,int emp_id,int age,employee_bst_tree bst) 
{ 
	struct employee_bst *temp;
	temp = new employee_bst;
	temp->name=name;
	temp->age=age;
	temp->ID=emp_id;
	temp->left = temp->right = NULL;
	bst=temp; 
	return(bst);
} 
 
struct employee_bst *employee_bst_insert(string name,int empid,int age,employee_bst_tree bst) 
{ 
	
	if (bst == NULL) {
		bst=employee_bst_new_node(name,empid,age,bst); }

	else if (name<bst->name){
		bst->left=employee_bst_insert(name,empid,age,bst->left);} 

	else{
		bst->right=employee_bst_insert(name,empid,age,bst->right); }
	
	return(bst);
 
} 
//node search
void employee_bst_search(string name,employee_bst_tree bst) 
{ 
	
	if(bst == NULL){
		cout<<"Record not found";
	}
	
	else if (name==bst->name){
		cout<<"Record contains employee: \n";
		cout<<"ID: "<<bst->ID<<"\tName: "<<bst->name<<"\tAge: "<<bst->age<<endl;
		}	 

	else if (name<(bst->name)){
		employee_bst_search(name,bst->left); }
	
	else if(name>(bst->name)){
		employee_bst_search(name,bst->right);}
	
} 

struct employee_bst *employee_bst_read(employee_bst_tree bst)
{
	string a1;
	ifstream employee_file;
	employee_file.open("employees.txt");
	string name;
	int emp_id;
	int age;
  while(1){
    if(employee_file.eof()){break;}
    else
    {
        employee_file>>emp_id;
        employee_file>>name;
        employee_file>>age;
        bst=employee_bst_insert(name,emp_id,age,bst);
        }
  }
  employee_file.close();
  return(bst);
}


///////EMPLOYEE HELPER FUNCTIONS END////////
////////////////////////////////////////////


////////////////////////////////////////////
/////////MAIN FUNCTION//////////////////////
////////////////////////////////////////////

int main () 
{

  int x, pos, ch, i;

  //patient init
  patient_list l;
  l = new patient;
  l->next = NULL;

  //employee init
  employee_list k;
  k = new employee;
  k->next = NULL;
  cout << "HOSPITAL RECORD MANAGEMENT SYSTEM \n\n";
    do
    {
        cout<<"1. HOSPITAL PATIENT UI\t";
        cout<<"2. HOSPITAL EMPLOYEE UI\t";
        cout<<"3. EXIT\t";
        cout<<"\nEnter choice: ";
        cin >> ch;
      switch (ch)
     	{
        case 1://PATIENT UI
        {
	        //read and generate from file before proceeding
          l = new patient;
          l->next = NULL;
          patient_read(l);

          patient_bst_tree bst;
	        bst=NULL;
	        bst=patient_bst_read(bst);

          cout <<"\nWELCOME TO THE PATIENT RECORDS CENTRE\n";
          //input and retrieve patient details
          int patient_choice=0;

          do
          {
            cout<<"\n1. New Patient"<<"\t";
            cout<<"2. All Patients "<<"\t";
            cout<<"3. Search Patient by ID"<<"\t";
            cout<<"4. Modify Patient"<<"\t";
            cout<<"5. Search Patient by Name"<<"\t";
            cout<<"6. BACK";
            patient_choice=0;
            cout<<"\n\nEnter Choice :";
            cin>>patient_choice;            
            switch(patient_choice)
            {
              case 1:
              { 
                //Update Linked List from File
                l = new patient;
                l->next = NULL;
                patient_read(l);

                //entry for new patient
                int id;
                int age;
                id=(l->next->ID)+1;
                string name;
                cout<<"New - Patient Name : ";
                cin>>name;
                cout<<"New - Patient Age : ";
                cin>>age;
                patient_insert(id,age,name,l);
                cout<<"Your ID : "<<id;
                patient_write(l);
              }break;

              case 2:
              {
                //display
                patient_display(l);
              }break;

              case 3:
              { //search using patient ID
                
                //update list
                l = new patient;
                l->next = NULL;
                patient_read(l);

                //search
                cout<<"Search - Patient ID : ";
                int x;
                cin>>x;
                patient_search(x,l);

              }break;

              case 4:
              { //modify patient record
                //update list
                l = new patient;
                l->next = NULL;
                patient_read(l);

                //modify
                int x;
                cout<<"Modify - Patient ID : ";
                cin>>x;
                cout<<"New Name : ";
                string name;
                cin>>name;
                patient_modify(x,name,l);
                patient_write(l);
              }break;

              case 5:
              { //search by patient name
                //generate binary tree
                patient_bst_tree bst;
	              bst=NULL;
	              bst=patient_bst_read(bst);

                //search
                string name;
                cout<<"Enter Patient Name to search records : ";
                cin>>name;
                patient_bst_search(name,bst);
              }break;


              case 6:
              {/*saving and main menu*/ 
                //cout<<"Writing list to file"<<endl;
                patient_write(l);
              }break;

              default:
              {
                cout<<"Wrong choice.....Please try again\n\n\n"<<endl;
              }break;

            }//patient switch ends

          }while(patient_choice!=6);	        
          
        }break;//PATIENT UI ends

      case 2://EMPLOYEE UI
        {
	        //p = l;
          //*******************************//
          //clear console with c++ if required
          //read from file before proceeding
          k = new employee;
          k->next = NULL;
          employee_read(k);  

          employee_bst_tree emp_bst;
	        emp_bst=NULL;
	        emp_bst=employee_bst_read(emp_bst);

          //
	        cout <<"\nWELCOME TO THE EMPLOYEE RECORDS CENTRE\n";
          //input and retrieve employee details
          int employee_choice=0;

          do
          {
            cout<<"\n1. New Employee \t";
            cout<<"2. All Employees \t";
            cout<<"3. Search Employee using ID\t";
            cout<<"4. Modify Employee \t";
            cout<<"5. Search Employee using Name\t";
            cout<<"6. BACK \t";
            employee_choice=0;
            cout<<"\nEnter Choice : ";
            cin>>employee_choice;            
            switch(employee_choice)
            {
              case 1:
              {
                //regenerate the linked list
                k = new employee;
                k->next = NULL;
                employee_read(k); 

                //entry for new employee
                int id;
                int age;
                id=(k->next->ID)+1;
                string name;
                cout<<"Enter new employee name : ";//<<endl;
                cin>>name;
                cout<<"Enter new employee age : ";
                cin>>age;
                cout<<"Your ID : "<<id<<endl;
                employee_insert(id,age,name,k);
                employee_write(k);
              }break;

              case 2:
              {
                //display
                employee_display(k);
              }break;

              case 3:
              { //search using employee ID

                k = new employee;
                k->next = NULL;
                employee_read(k);                 

                cout<<"Enter ID of employee to search:";
                int x;
                cin>>x;
                employee_search(x,k);

              }break;

              case 4:
              {
                //update list
                l = new patient;
                l->next = NULL;
                patient_read(l);

                //modify
                int x;
                cout<<"Enter employee ID of details to be modified:";
                cin>>x;
                cout<<"Enter new name:";
                string name;
                cin>>name;
                employee_modify(x,name,k);
                employee_write(k);
              }break;

              case 5:
              { //search employee by name
                employee_bst_tree emp_bst;
	              emp_bst=NULL;
	              emp_bst=employee_bst_read(emp_bst);

                //search
                string name;
                cout<<"Enter Employee Name to search records : ";
                cin>>name;
                employee_bst_search(name,emp_bst);                
                break;
              }

              case 6:
              {/*saving and main menu*/ 
                cout<<"Writing list to file"<<endl;
                employee_write(k);
              }break;

              default:
              {
                cout<<"Wrong choice.....Please try again\n\n\n"<<endl;
              }break;

            }//employee switch ends

          }while(employee_choice!=6);
	        
          
        }break;//EMPLOYEE UI ends

        case 3:{}break;
        default:{
          cout<<"Not an Option : Retry\n";
        } break;      
      }//main switch ends	      
    }while (ch!=3);
}

/*
NOTES:
-> assumption that name is only 1 word
-> [Fixed] Bug: program unexpected shutdown wont save the records
-> [Fixed] Bug: infinite loop if no entry in txt file, but clicked search option
-> [Check] Bug: employee id starts at 32768 no matter what
-> [Fixed] Bug: Code won't run when corresponding files not available
-> [Fixed] Name cannot exceed 20 characters (limit 20 can be changed)
*/