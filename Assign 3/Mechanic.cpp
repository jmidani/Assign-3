#include <iostream>
#include <string>
#include "Person.h"
#include "Appointment.h"
#include "Mechanic.h"
using namespace std;

Mechanic::Mechanic(){
    counter=0;
    maxAppointments=50;
}
Mechanic::Mechanic(int max){
    counter=0;
    setMaxAppointments(max);
}
bool Mechanic::isAvailable(int hr, int min){
    if(counter==maxAppointments-1){
        return false;
    }
    Appointment temp;
    temp.hour=hr;
    temp.minute=min;
    for(int i=0;i<maxAppointments;i++){
        if (temp.hour==appointment[i].hour&&temp.minute==appointment[i].minute){
            return false;
        }
    }
    return true;
}
void Mechanic::setCounter(int c){
    if(c>=0&&c<50){
        counter=c;
    }
    else{
        cout<<"Maximum appointments per day is 50.\n";
    }
}
void Mechanic::setMaxAppointments(int max){
    if(max>=0&&max<50){
        maxAppointments=max;
    }
    else{
        cout<<"Maximum appointments per day is 50.\n";
    }
}
void Mechanic::setAppointment(int hr, int min){
    if(hr>=0&&hr<24){
        appointment[counter].hour=hr;
        counter++;
    }
    else{
        cout<<"Hours cannot be set to less than 0 or more than 24.\n";
    }
    if(min>=0&&min<60){
        appointment[counter].minute=min;
        counter++;
    }
    else{
        cout<<"Minutes cannot be set to less than 0 or more than 59.\n";
    }
    
    for(int i=0;i<=counter;i++){
        if (appointment[i].hour > appointment[i+1].hour) {
            Appointment temp = appointment[i+1];
            appointment[i] = appointment[i+1];
            appointment[i+1] = temp;
        }
        if (appointment[i].hour == appointment[i+1].hour) {
            if(appointment[i].minute > appointment[i+1].minute){
            Appointment temp = appointment[i+1];
            appointment[i] = appointment[i+1];
            appointment[i+1] = temp;
            }
        }
        
    }
}
int Mechanic::getCounter(){
    return counter;
}
Appointment Mechanic::getAppointments(int number){    
    return appointment[number];
}