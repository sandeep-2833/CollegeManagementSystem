
#include <iostream>
#include<mysql.h>     //libraries are added to project
#include<mysqld_error.h>  
using namespace std;

char HOST[]="localhost";
char USER[]="root";
char PASS[]= "SillyPassword";   
int main()
{
    
    MYSQL* obj;
    
    int College_ID;
    char Name[20];
    char Birthday[11];
    float Grade;
    
    
    bool ProgramIsOpened=true;
    int answer;
    
    char * consult;
    char* sentence;
    string sentence_aux;
    
    
    if(!(obj=mysql_init(0)))
    {
       cout<<"ERROR: MySQL object could not be created."<<endl;
    }
    else
    {
        if(!mysql_real_connect(obj,HOST,USER<PASS<"college",3306,NULL,0))
        {
          cout<<"ERROR: Some database info is wrong or do not exist"<<endl;
          cout<<mysql_error(obj)<<endl;
        }
        else 
        {
             cout<<"Logged in"<<endl<<endl;
             
             while(ProgramIsOpened)
             {
                cout<<"College_ID";
                cin>>College_ID;
                cin.ignore(100,'\n');
                
                cout<<"Name: ";
                cin.getline(Name,20,'\n');
                
                cout<<"Birthday: ";
                cin.getline(Birthday,11,'\n');
                
                cout<<"Grade: ";
                cin>>Grade;
                cin.ignore(100,'\n');
                cout<<endl;
                
                
                sentence_aux="INSERT INTO student(College_ID,Name,Birthda,Grade) VALUES('%d','%s','%s','%f')";
                sentence = new char[sentence_aux.length()+1];
                strcpy(sentence,sentence_aux.c_str());
                
                consult = new char[strlen(sentence)+sizeof(int)+strlen(Name)+strlen(Birthday)+sizeof(float)];
                sprintf(consult,sentence,College_ID,Name,Birthday,Grade);
                
                if(mysql_ping(obj))
                {
                    cout<<"ERROR: Impossible to connect."<<endl;
                    cout<<mysql_eroor(obj)<<endl;
                 }
                 if(mysql_query(obj,consult))
                 {
                   cout<<"ERROR:"<<mysql_error(obj)<<endl;
                   rewind(stdin);
                   getchar();
                 }
                 else
                 {
                     cout<<"Info added correcty."<<endl;
                 }
                 mysql_store_result(obj);
                 
                 cout<<endl<<"Another?"<<endl;
                 cout<<"[1]: Yes"<<endl;
                 cout<<"[0]: No"<<endl;
                 cout<<"Answer:  ";
                 cin>>answer;
                 cin.ignore(100,'\n');
                 if(answer==0)
                 {
                   ProgramIsOpened= false;
                 }
                 cout<<endl;
                 
                                   
             } 
        }   
    }
    
    cout<<"BYE!!"<<endl;
    
  return 0;
}
