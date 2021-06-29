#include <bits/stdc++.h>
using namespace std;


class Hospital{
	struct patient_admit{
		long int aadhar_no;
		string P_name;
		int P_age;
		int P_contact;
		string date_of_admission;
		int bed_no;
		float temp;
		int bp;
		int spo2;
		string oxygen_required;		
	};
	
	public:
		string h_name;
		int total_beds;
		int total_oxygen_cylinder;
			
		vector<patient_admit> data;  
		vector<patient_admit> visit;
		     
		int avl_bed;
		int avl_oxy;
		Hospital(void);                 //default constructor
		void print_h_data();   
		void new_admission();
		void new_visiting_info();
		void existing();
		void patients_record();
		void bed_availability();
		void visiting_patient_record();
};

Hospital :: Hospital(void){            
	h_name="Sanjeevni";
	total_beds=35;
	total_oxygen_cylinder=20;
	avl_bed = total_beds;
	avl_oxy =  total_oxygen_cylinder;
}

void Hospital :: print_h_data(){
	cout<<"COVID HOSPITAL DATA->"<<endl;
	cout<<"Hospital name: "<<h_name<<endl;
	cout<<"Total beds in hospital: "<<total_beds<<endl;
	cout<<"Total oxygen cylinders available: "<<total_oxygen_cylinder<<endl;
}


void Hospital :: new_admission(){
	patient_admit p;
	cout<<"Enter details for admission of new patient->\n";
	cout<<"Enter aadhar_no: ";
	cin>>p.aadhar_no;
	cout<<endl
	<<"Enter the name of the patient: ";
	cin>>p.P_name;
	cout<<endl
	<<"Enter age of the patient: ";
	cin>>p.P_age;
	cout<<endl
	<<"Enter contact number of the patient: ";
	cin>>p.P_contact;
	cout<<"\nEnter details for patients report:\n";
	cout<<"Enter temperature: ";
	cin>>p.temp;
	cout<<"\nEnter blood pressure: ";
	cin>>p.bp;
	cout<<"\nEnter spo2 level: ";
	cin>>p.spo2;
	cout<<"\nEnter bed number: ";
	cin>>p.bed_no;
	cout<<"\nEnter date of admission: ";
	cin>>p.date_of_admission;
	data.push_back(p);	
	avl_bed = avl_bed-1;
	cout<<"\nEnter yes/no for oxygen requirement?:"<<endl;
	cin>>p.oxygen_required;
	if(p.oxygen_required=="yes"){
		avl_oxy =  avl_oxy-1;
	}
}

void Hospital :: new_visiting_info(){
	patient_admit q;
	cout<<"Enter details for new patient visiting: "<<endl;
	cout<<"Enter aadhar number: ";
	cin>>q.aadhar_no;
	cout<<"\nEnter name: ";
	cin>>q.P_name;
	cout<<"\nEnter contact number: ";
	cin>>q.P_contact;
	
	visit.push_back(q);
}

void Hospital :: existing(){
	cout<<"Enter aadhar number to search for existance: ";
	long int aadhar;
	cin>>aadhar;
	patient_admit e;
	int i=0;
	for(i=0; i<data.size(); i++){
	
	    if(data[i].aadhar_no==aadhar){
	    	cout<<"Existing \n";
	    	break;
		}
			
	}
	if(i==data.size()){
		cout<<"Not existing\n";
	}
	
}

void Hospital :: patients_record(){
	int i;
	if(data.size()>0){
		for(i=0; i<data.size(); i++){
		cout<<"Aadhar number: "<<data[i].aadhar_no<<endl;
		cout<<"Name of the patient: "<<data[i].P_name<<endl;
		cout<<"Age of patient: "<<data[i].P_age<<endl;
		cout<<"Contact number of the patient:"<<data[i].P_contact<<endl;
		cout<<"Bed number of patient: "<<data[i].bed_no<<endl;
		cout<<"\nReports of the patient:"<<endl;
		cout<<"Temperature: "<<data[i].temp<<endl;
		cout<<"Blood Pressure: "<<data[i].bp<<endl;
		cout<<"SpO2: "<<data[i].spo2<<endl;
		cout<<"\n\n";
	}
	}
	
}

void Hospital :: visiting_patient_record(){
	int i;
	for(i=0; i<visit.size(); i++){
		cout<<"Aadhar number: "<<data[i].aadhar_no<<endl;
		cout<<"Name of the patient: "<<visit[i].P_name<<endl;
		cout<<"Contact number of the patient:"<<visit[i].P_contact<<endl<<endl;
	}
}

void Hospital :: bed_availability(){
	if(total_beds-avl_bed>0){
		cout<<"Beds are available"<<endl;
	}
	else{
		cout<<"Bed not available"<<endl;
	}
}

int main(){
	Hospital h;
	h.print_h_data();
	int choice;
	int t;
    cout<<endl;
    cout<<"Test cases: ";
    cin>>t;
	for(int i=0; i<t; i++){
	cout<<endl
	<<"Enter 1 to show all currently admitted patients\n"
	<<"Enter 2 to check for bed availability \n"
	<<"Enter 3 for admitting new patient \n"
	<<"Enter 4 to search for already admitted(existing) patient's data \n"
	<<"Enter 5 for visiting patients details\n"
	<<"Enter 6 to enter details of new visiting patients\n"
	<<"Enter 7 to exit\n"
	<<endl
	
	<<"Enter your choice and press return: "<<endl;
	cin>>choice;
			
		switch(choice){
		case 1:
			h.patients_record();
			break;
		case 2:
			h.bed_availability();
			break;
		case 3:
			h.new_admission();
			break;
		case 4:
			h.existing();
				break;  
		case 5:
			h.visiting_patient_record();
			break;
		case 6:
			h.new_visiting_info();	
			break;
		default:
			cout<<"Invalid entry";				
	}
}
}
