#include "PhdStudent.hpp"
PhdStudent::PhdStudent(std::string name, double fines, double fees, bool fullTime){
    PhdStudent::name = name;
    PhdStudent::fullTime = fullTime;
    SetLibraryFines(fines);
    tuition_fees = fees;
}


double PhdStudent::MoneyOwed() const{
    return 0.0;
}




//phd student