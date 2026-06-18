#include <iostream>
#include <string>
using namespace std;

string lgrade(double gp){    //gp stands for grade points   //this grading scale is according to IBA Karachi
  if(gp<1.67)  {return "F";}
  else if(gp>=1.67 && gp<2.00) return "C-";  
  else if(gp>=2.00 && gp<2.33) return "C ";
  else if(gp>=2.33 && gp<2.67) return "C+"; 
  else if(gp>=2.67 && gp<3.00) return "B-";
  else if(gp>=3.00 && gp<3.33) return "B ";
  else if(gp>=3.33 && gp<3.67) return "B+";
  else if(gp>=3.67 && gp<4.00) return "A-";
  else return "A";                       
}  

void print(string c, double gp){
    cout<<"---------------------------------"<<endl;
    cout<<"  "<<c<<"  |  Grade: "<< lgrade(gp); cout<<endl;
    cout<<endl;
}

int main() {

    string course;  int t;  //t for credit hours per course
    double gpoints;   //grade points per course
    int sumoft=0;     //total credit hours
    double sumofqp=0;  //total quality points
   



int a; //a stands for total no of semester
cout<<"Enter no of semester:"; cin>>a; cout<<endl;
double tqp;  //total quality points in each semester
int tch;    //total credit hours of each semester
double sumoftqp=0;
int sumoftch=0;

    for(int i=1; i<a; i++){
        cout<<"Enter total quality points of the semester "<<i<<": "; cin>>tqp; 
        cout<<"Enter total credit hours of the semester "<<i<<": ";   cin>>tch; 
        sumoftqp+=tqp;
        sumoftch+=tch;
    }
cout<<endl;

int n;  //no of courses
cout<<"Enter total no of courses this semester: ";  cin>>n; cout<<endl;

    for(int i=0; i<n; i++){
    cout<<"Enter course name: "; cin>>course;
    cout<<"Enter credit hours of this course: "; cin>>t; 
    cout<<"Enter obtained grade points of this course(eg; 3.5): "; cin>>gpoints;  cout<<endl;
    double qp = gpoints*t;  //qp stands for quality points
    print(course,gpoints);
    
    sumofqp+=qp;
    sumoft+=t;
}
cout<<endl;
double gpa= sumofqp/sumoft;
double cgpa= (sumoftqp+sumofqp)/(sumoftch+sumoft);

cout<<"===================================="<<endl;
cout<<"  FINAL TRANSCRIPT:-"<<endl;
cout<<"Your grade points this semester: "<<sumofqp<<endl;
cout<<"YOUR GPA THIS SEMESTER: "<<gpa<<endl;

cout<<"CGPA: "<<cgpa<<endl;

return 0;
}