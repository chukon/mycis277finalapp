//C++ program to write and read object using read and write function.
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
 
//class student to read and write student details
class student
{
    public:
        string name;
        string birthdate;
        void getData()
        { 
          name="";
          cout<<"Enter name:"; 
          getline(cin,name);
          cout<<"Enter birthdate (MM-DD):"; 
          getline(cin,birthdate);
        }
 
};
 
int main()
{
    student s;
     
    ofstream file("aaa.txt", std::ios_base::app);
     if(!file){
        cout<<"Error creating file..";
        return 0;
    }
    cout<<"\nFile created successfully."<<endl;
 
    //write into file
    s.getData();    //read from user
    string writeline = s.name + " " + s.birthdate;
    file<<writeline<<endl;    //write into file
 
    file.close();   //close the file
    cout<<"\nFile saved and closed succesfully."<<endl;
 
    //re open file in input mode and read data
    //open file1
    ifstream file1;
    //again open file in read mode
    file1.open("aaa.txt",ios::in);
    if(!file1){
        cout<<"Error in opening file..";
        return 0;
    }else{
       cout<<"\nFile read successfully, here is the log:"<<endl;
    }
 
    //declare string to hold each line of text
    string line;
  
  //loop through myinfile while line exist
  while(getline(file1,line))
  {
      cout << line << endl;
  }
  
    //close the file
    file1.close();
     
    return 0;
}
