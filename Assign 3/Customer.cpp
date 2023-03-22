#ifndef Appointment_hpp
#define Appointment_hpp
#ifndef Person_hpp
#define Person_hpp
#ifndef Customer_hpp
#define Customer_hpp

#include "Person.h"
#include "Appointment.h"
#include "Customer.h"
using namespace std;

Customer::Customer(){
    MechanicID="";
    appointment.hour=0;
    appointment.minute=0;
}
Customer:: Customer(string id, int hr, int min){
    MechanicID=id;
    if(hr>=0&&hr<24){
        appointment.hour=hr;
    }
    else{
        appointment.hour=0;
    }
    if(min>=0&&min<60){
        appointment.minute=min;
    }
    else{
        appointment.minute=0;
    }
}
Customer &Customer::setMechanicID(string id){
    MechanicID=id;
    return *this;
}
Customer &Customer::setAppointment(int hr, int min){
    if(hr>=0&&hr<24){
        appointment.hour=hr;
    }
    else{
        appointment.hour=0;
    }
    if(min>=0&&min<60){
        appointment.minute=min;
    }
    else{
        appointment.minute=0;
    }
    return *this;
}
string Customer::getMechanicID(){
    return MechanicID;
}
Appointment Customer::getAppointment(){
    return appointment;
}
bool Customer::operator < (Customer x){
    if (appointment.hour<x.appointment.hour){
        return true;
    }
    else if(appointment.hour==x.appointment.hour&&appointment.minute<x.appointment.minute){
        return true;
    }
    return false;
}
bool Customer::operator > (Customer x){
    if (appointment.hour>x.appointment.hour){
        return true;
    }
    else if(appointment.hour==x.appointment.hour&&appointment.minute>x.appointment.minute){
        return true;
    }
    return false;
}
bool Customer::operator == (Customer x){
    if (appointment.hour==x.appointment.hour&&appointment.minute==x.appointment.minute){
        return true;
    }
    return false;
}
#endif
#endif
#endif