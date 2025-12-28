#include <bits/stdc++.h>
using namespace std;

class Student{
    private:
        string name;
        string roll;
        vector<int>marks;

    public:
        Student(string n, string r, vector<int>m){
            name = n;
            roll = r;
            marks = m;
        }
        
         void display(){
            cout<<"Name: "<<name<<endl;
            cout<<"Roll No.: "<<roll<<endl;
            cout<<"Marks:   ";
            for(int x : marks){
                cout<<x<<" ";
            }
            cout<<endl;
        }
        float avgMarks(){
            int sum = 0;
            for(int x : marks){
                sum += x;
            }
            return (float)sum / marks.size();
        }
        void printFile(){
            ofstream fout("data.txt", ios::app);
            fout<<"                   Record                 "<<endl<<endl;
        }
        void save(){
            ofstream fout("data.txt",ios::app);
            
            

            fout<<"Name: "<<name<<endl;
            fout<<"Roll No.: "<<roll<<endl<<endl;
            fout<<"Marks:  "<<endl;
            fout<<"Computer(Theory):  ";
            fout<<marks[0];
            fout<<endl;
            fout<<"Physics:  ";
            fout<<marks[1];
            fout<<endl;
            fout<<"Mathematics:  ";
            fout<<marks[2];
            fout<<endl;
            fout<<"Electronics and Communication:  ";
            fout<<marks[3];
            fout<<endl;
            fout<<"Humanities:  ";
            fout<<marks[4];
            fout<<endl;
            
            fout<<endl;

            int sum = 0;
            for(int x : marks){
                sum += x;
            }
            float avg = ((float)sum / marks.size());
            fout<<"Average Marks of this student is:  "<<avg<<endl<<endl;
            
            if(avg>25){
                fout<<"Status: PASSED"<<endl<<endl<<endl;
            }
            else{
                fout<<"Status: FAILED"<<endl<<endl<<endl;
            }

            fout.close();
        }

       
};
    

int main() {
    
    int n;
    cout<<"Please state the number of students to be added to the list:  ";
    cin>>n;
    vector<Student>students;

    for(int i=1; i<=n; i++){
        string name,roll;
        cout<<"Enter the details for student "<<i<<endl<<endl;

        cout<<"ENTER NAME: ";
        cin.ignore();
        getline(cin,name);
        
        cout<<"ENTER THE ROLL NO.: ";
        cin>>roll;
        cout<<endl;
        vector<int>marks(5);
        cout<<"ENTER MARKS FOR THE FOLLOWING SUBJECTS MENTIONED: "<<endl;
        cout<<"Computer(Theory):  ";
        cin>>marks[0];
        cout<<endl;
        cout<<"Physics:  ";
        cin>>marks[1];
        cout<<endl;
        cout<<"Mathematics:  ";
        cin>>marks[2];
        cout<<endl;
        cout<<"Electronics and Communication:  ";
        cin>>marks[3];
        cout<<endl;
        cout<<"Humanities:  ";
        cin>>marks[4];
        cout<<endl<<endl;

        students.push_back(Student(name,roll,marks));
    }

    for(Student &s : students){
        s.printFile();
        break;
    }
    int idx=1;
    for(Student &s : students){
        ofstream fout("data.txt", ios::app);
        fout<<"Student "<<idx<<": "<<endl<<endl;
        s.save();
        cout<<endl;
        idx++;
    }
    
    return 0;
}