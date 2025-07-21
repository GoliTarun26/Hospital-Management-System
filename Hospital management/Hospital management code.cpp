#include<bits/stdc++.h>
using namespace std;

class HMSException : public runtime_error {
public:
    HMSException(const string& message) : runtime_error(message) {} 
};

class Person {
protected:
    string name;
    int age;
public:
    Person(const string& n, int a){
    	name=n;
    	age=a;
	}
    virtual void display() const = 0; 
};

class Patient : public Person {
private:
    string healthIssue, previousSurgery, gender, treatmentType;
public:
    Patient(const string& n, int a, const string& h, const string& p, const string& g, const string& t)
        : Person(n, a), healthIssue(h), previousSurgery(p), gender(g), treatmentType(t) {}

    void display() const override {
        cout << "Patient Name: " << name << "\nAge: " << age << "\nGender: " << gender
             << "\nHealth Issue: " << healthIssue << "\nPrevious Surgery: " << previousSurgery
             << "\nTreatment Type: " << treatmentType << "\n" << endl;
    }
};

class Doctor : public Person {
private:
    string specialization;
    int experience;
public:
    Doctor(const string& n, int a, const string& s, int e)
        : Person(n, a), specialization(s), experience(e) {}

    void display() const override {
        cout << "Doctor Name: " << name << "\nAge: " << age 
             << "\nSpecialization: " << specialization 
             << "\nExperience: " << experience << " years\n" << endl;
    }
};

class Billing {
private:
    double consultationFee, treatmentCost, medicationCost;
public:
    Billing(double cFee, double tCost = 0.0, double mCost = 0.0){
		consultationFee=cFee;
		treatmentCost=tCost;
		medicationCost=mCost;
		}

    double calculateTotal(double taxRate) const {
        return (consultationFee + treatmentCost + medicationCost) + (1 + taxRate);
    }

    void displayBill() const {
        cout << "Consultation Fee: Rs" << fixed << setprecision(2) 
             << consultationFee << "\nTreatment Cost: Rs" 
             << treatmentCost << "\nMedication Cost: Rs" 
             << medicationCost << endl;
    }
};

class Appointment {
private:
    Patient patient;
    Doctor doctor;
    Billing billing;
    string date, time;
public:
    Appointment(const Patient& p, const Doctor& d, const Billing& b, const string& dt, const string& tm)
        : patient(p), doctor(d), billing(b), date(dt), time(tm) {}

    void display() const {
        cout << "Appointment Details:\n";
        patient.display();
        doctor.display();
        cout << "Date: " << date << "\nTime: " << time << "\n" << endl;
        
        cout << "--- Billing Information ---" << endl;
        billing.displayBill();
        cout << endl;
    }
};

int main() {
    try {
        while (true) { 
            string patientName, healthIssue, previousSurgery, gender, treatmentType;
            int patientAge;

            cout << "\n--- Enter Patient Details ---\n";
            cout << "Enter Patient Name: ";
            getline(cin, patientName);

            cout << "Enter Patient Age: ";
            string ageInput;
            getline(cin, ageInput);
            patientAge = stoi(ageInput);

            cout << "Enter Patient Gender: ";
            getline(cin, gender);

            cout << "Enter Health Issue: ";
            getline(cin, healthIssue);

            cout << "Enter Previous Surgery (or 'None'): ";
            getline(cin, previousSurgery);

            cout << "Enter Treatment Type (Checkup/Operation): ";
            getline(cin, treatmentType);

            Patient patient(patientName, patientAge, healthIssue, previousSurgery, gender, treatmentType);

            string doctorName, specialization; 
            int doctorAge, experience;

            while (true) {
                cout << "\n--- Enter Doctor Details ---\n";
                cout << "Enter Doctor Name: ";
                getline(cin, doctorName);

                cout << "Enter Doctor Age: ";
                getline(cin, ageInput);
                doctorAge = stoi(ageInput);

                cout << "Enter Doctor Specialization: ";
                getline(cin, specialization);

                cout << "Enter Doctor Experience (in years): ";
                getline(cin, ageInput);
                experience = stoi(ageInput);

                
                if (experience > doctorAge) {
                    cout << "Error: Doctor's experience cannot be more than doctors age." << endl;
                    continue;
                }

                break;
            }

            Doctor doctor(doctorName, doctorAge, specialization, experience);

            string date, time;

            cout << "\n--- Enter Appointment Details ---\n";
            cout << "Enter Appointment Date (DD-MM-YYYY): ";
            getline(cin, date);

            cout << "Enter Appointment Time (e.g., 11:00 AM): ";
            getline(cin, time);

            double consultationFee, treatmentCost, medicationCost, taxRate;

            cout << "\n--- Enter Billing Details ---\n";
            cout << "Enter Consultation Fee: Rs";
            string feeInput;
            getline(cin, feeInput);
            consultationFee = stod(feeInput);

            cout << "Enter Treatment Cost (default is 0 if not applicable): Rs";
            getline(cin, feeInput);
            treatmentCost = stod(feeInput);

            cout << "Enter Medication Cost (default is 0 if not applicable): Rs";
            getline(cin, feeInput);
            medicationCost = stod(feeInput);

            cout << "Enter Tax Rate (e.g., 0.05 for 5%): ";
            getline(cin, feeInput);
            taxRate = stod(feeInput);

            Billing bill(consultationFee, treatmentCost, medicationCost);
            
            Appointment appointment(patient, doctor, bill, date, time);
            appointment.display();

            double totalAmount = bill.calculateTotal(taxRate);
            cout << "Total Amount (including tax): Rs" 
                 << fixed 
                 << setprecision(2) 
                 << totalAmount 
                 << endl;
                 
            cout << "Type 'exit' to quit or 'continue' to proceed with another appointment: ";
            string e;
            cin >> e;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (e == "Exit" || e == "exit") {
                break;
            }
        }

    } catch (const HMSException& e) {
        cerr << e.what() << "\n";
    } catch (const exception& e) { 
        cerr << e.what() << "\n"; 
    }

    return 0;
}
