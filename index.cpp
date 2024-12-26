#include<iostream>
#include<vector>
using namespace std;
class School{
    private:
    int studentId;
    string studentName;

    public:

    School(int id, string name){
        this->studentId = id;
        this->studentName = name;
    }

    void seeAllStudent(){
        cout<<"\n-----------xxxxxxx-------------";
        cout<<"\nId : "<<this->studentId;
        cout<<"\nName : "<<this->studentName;
        cout<<"\n-----------xxxxxxx-------------";
    }

    int getId(){
        return this->studentId;
    }

};
int main(){
    vector<School> student;
    int choice;
    do{
        cout<<"\n1 for Add student detail...";
        cout<<"\n2 for remove student...";
        cout<<"\n3 for see All Student...";
        cout<<"\n4 for search student...";
        cout<<"\n5 for Exit...";
        cout<<"\nEnter your choice : ";
        cin>>choice;


        switch(choice){
            case 1:{

                int id; string name;
                cout<<"Enter Id : ";
                cin>>id;
                cin.ignore();
                cout<<"Enter Name : ";
                getline(cin,name);

                student.push_back(School(id, name));
                break;
            }
            case 2:{
                int id;
                bool isFound = false;
                cout<<"Enter Id : ";
                cin>>id;

                for(auto i = student.begin(); i < student.end();i++){
                    if(i->getId() == id){
                        student.erase(i);
                        isFound = true;
                        // break;
                    }
                }

                (isFound == true) ? cout<<"Student Id removed succefully !"<<endl : cout<<"Student Not Found !"<<endl;
                break;
            }
            case 3:{
                for(auto i = student.begin(); i != student.end();i++){
                    i->seeAllStudent();
                    cout<<endl;
                }

                break;
            }
            case 4:{
                    int id;
                    bool isFound = false;
                    cout<<"Enter Id : ";
                    cin>>id;
                    for(auto i = student.begin(); i != student.end();i++){
                        if(i->getId() == id){
                            i->seeAllStudent();
                            isFound = true;
                        }
                }
                 (isFound == true)?cout<<"":cout<<"Student Not Found !";
                break;
            }
            case 5:{
                cout<<"Thank You !";
                break;
            }
            default:
            cout<<"Invalid Choice..."<<endl;
        }
    }while(choice != 5);
return 0;
}