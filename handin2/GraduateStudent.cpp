#include "GraduateStudent.hpp"

GraduateStudent::GraduateStudent(){
    name = "";
    GraduateStudent::fullTime = false;
    SetLibraryFines(0.0);
    tuition_fees = 0.0;
}

GraduateStudent::GraduateStudent(std::string name, double fines, double fees, bool fullTime){
    GraduateStudent::name = name;
    GraduateStudent::fullTime = fullTime;
    SetLibraryFines(fines);
    tuition_fees = fees;
}

double GraduateStudent::MoneyOwed() const{
    return GetLibraryFines();
}

//gradstudent