#include <iostream>
using namespace std;

struct Patient
{
  string name;
  int ID;
  int phoneNumber;
  string address;
  float invoic;
  Patient* next;
};

Patient* head = new Patient();

   
bool CheckRecord(int patient_id)
{
    if(head == NULL)
    {
        return false;
    }
    Patient* temp=head;
    temp = head;
    while(temp!=NULL){
        if(temp->ID==patient_id)
              return true;
            temp=temp->next;
       }
        return false;
}

void CreatRecord(int ID, string name, int phoneNum, string address,double invoic)
{
    
    if(CheckRecord(ID))
    {
        cout<<"There is already a patiant with this record"<<endl;
        return;
    }
    else if(invoic<10)
    {
        cout<<"invoic less than 10 will not be added"<<endl;
        return;
    }
    
    Patient* newNode=new Patient();
    newNode->ID=ID;
    newNode->name=name;
    newNode->phoneNumber=phoneNum;
    newNode->address=address;
    newNode->invoic=invoic;
    newNode->next = NULL;
    
    if(head==NULL||head->ID>=newNode->ID){
        newNode->next=head;
        head=newNode;
       
    }else{
        Patient* temp=head;
        while(temp->next!=NULL&&temp->next->ID<newNode->ID){
            temp=temp->next;
        }
        newNode->next = temp->next;
        temp->next=newNode;
     
    }
cout<<"Patient record has been Successfully Inserted"<<endl;
}

void SearchRecord(int ID)
{
    if(head==NULL)
    {
        cout<<"<<There no pasients with such a record>>"<<endl;
        return;
    }
    else{
    Patient* temp=head;
    while(temp)
    {
        if(temp->ID==ID)
        {
        cout<<"patient ID number<<"<<temp->ID<<">>"<<endl;
        cout<<"patient name<<"<<temp->name<<">>"<<endl;
        cout<<"patient phone Number<<"<<temp->phoneNumber<<">>"<<endl;
        cout<<"patient address<<"<<temp->address<<">>"<<endl;
        cout<<"patient invoic<<"<<temp->invoic<<">>"<<endl;
        return ;
        }
        temp= temp->next;
    }


 if(temp==NULL)
    
        cout<<"<<There no pasients with such a record>>"<<endl;
    
    }
}
void deleteRecord(int ID)
{
     if(CheckRecord(ID)){
    Patient* temp=head;
    Patient* temp2 = NULL;
    while(temp!=NULL&&temp->ID!=ID){
        
        temp=temp->next;
    }
    head=temp->next;
        free(temp);
        cout<<"patient record has been deleted"<<endl;
    }else
    cout<<"No patient record was found";
}

void ShowRecord(int ID)
{
    Patient* temp= head;
    if(temp == NULL)
    {
        cout<<"<<There no pasients with such a record>>"<<endl;
        
    }
    else{
        cout<<"Patient ID\tPatient name\tPatient phone Number "
        <<"\tPatient address\tPatient invoic"<<endl;
         Patient* temp= head;
        while(temp!=NULL)
        {
           cout<<temp->ID<<"\t\t"<<temp->name<<"\t\t"
           <<temp->phoneNumber<<"\t\t"<<temp->address<<"\t\t"<<temp->invoic<<"\t\t"<<endl;
            temp=temp->next;
            
        }
    } 
}


void updateRecord(int ID){
   Patient* temp=head;
   
   
     if(CheckRecord(ID))
     {
         while (temp != NULL)
        {
            if (temp->invoic > 100)
            {
                temp->invoic = ( temp->invoic * 0.15 ) + temp->invoic;
                cout << "Invoice Updated\n";
                return;
            }
            else if (temp->invoic < 10)
            {
                
                 temp->invoic;
                 
                 
                
                
               cout << "Invoice Updated\n";
            }

            temp = temp->next;
        }
         
     }else
         cout << "There is no patients by this ID to update their invoice\n";
 }
    
 


int main()
{
    Patient* head = new Patient();
    head=NULL;
   int option;
   int ID, phoneNumber;
  double invoic;
  string name,address;
  
     while(1){
       
       cout<<"\nList";
       cout<<"\n1:Add a Record";
       cout<<"\n2:search a Record";
       cout<<"\n3:Delete a Record";
       cout<<"\n4:Update Invoice";
       cout<<"\n5:Show all Record";
       cout<<"\n6:Exit";
       cout<<"\nEnter Transaction:";
       cin>>option;
       
     
       
       switch(option)
       {
           
           case 1:
           cout<<"\nplease enter id of patient:";
           cin>>ID;
           
           cout<<"\nplease enter the name of patient:";
           cin>>name;
           
           cout<<"\nplease enter the phonenumber of patient:";
           cin>>phoneNumber;
           
           cout<<"\nplease enter the address of patient:";
           cin>>address;
           
           cout<<"\nplease enter the total invoice:";
           cin>>invoic;
           CreatRecord(ID,name,phoneNumber,address,invoic);
           break;
           cout<<"\n";
           case 2:
           cout<<"enter the id of patient:";
           cin>>ID;
           SearchRecord(ID);
               break;
               cout<<"\n";
            case 3:
                cout<< "Enter the ID of patient: ";
                cin >> ID;
                deleteRecord(ID);
                break;
                
           
            case 4:
            updateRecord(ID);
            break;
            
             case 5:
            ShowRecord(ID);
            break;
            
            
            case 6:
            exit(0);
            break;
            default:
            cout<<"You entered an invalid command....";
            break;
               
           }
            
               cout<<endl;
       }
       return 0;
   }



