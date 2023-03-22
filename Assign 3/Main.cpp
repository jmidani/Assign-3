#include <iostream>
#include <string>
#include <fstream>
#include "Queue.h"
#include "Customer.h"
#include "Mechanic.h"
#include "Appointment.h"
using namespace std;

void mechanic_info(Mechanic*,string,int); //Fills array of mechanics, reads from file

int main(){
    int mechanics_available=10;
    Mechanic *mechanics= new Mechanic[mechanics_available];
    string myfile="mechanics.txt";
    mechanic_info(mechanics,myfile,mechanics_available);
    delete [] mechanics;
    return 0;
}

void mechanic_info(Mechanic *person, string filename, int size){
    ifstream file;
    file.open(filename);
    int count=0;
    while(!file.eof()){
        Mechanic x;
        string name,id;
        int age,appointments;
        file>>name>>age>>id>>appointments;
        x.setName(name).setAge(age).setID(id);
        x.setCounter(appointments);
        appointments=appointments*2;
        while(appointments!=0){
            int hr,min;
            file>>hr;
            file>>min;
            x.setAppointment(hr,min);
            appointments=appointments-2;
        }
        *(person+count)=x;
        (person+count)->printInfo();
        count++;
    };
    file.close();
}