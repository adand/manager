#include <iostream>
using namespace std;

class Apartment {
      private:
              string id;
              string ownerName;
              double generalProportion;      
              double elevatorProportion;
      public:
             Apartment() {}
             Apartment(string, string, double, double);
             void show() {
                  cout << id << " ";
                  cout << ownerName << " ";
                  cout << generalProportion << " ";
                  cout << elevatorProportion << endl;
                  }
             double get_generalProportion () { return generalProportion; }
             double get_elevatorProportion() { return elevatorProportion; }
             string get_id() { return id; }
      };
      
Apartment::Apartment (string _id, string name, double general, double elevator) {
                     id = _id;
                     ownerName = name;
                     generalProportion = general;
                     elevatorProportion = elevator;
                     }   

class CostCategory {
      protected:
              string date;
              double cost;
      public:
             virtual void calculate(Apartment* myApartment) = 0;
      };
      
class GeneralCost : public CostCategory {
      public:
             GeneralCost(string myDate, double myCost);
             virtual void calculate(Apartment* myApartment) {
                     cout << myApartment->get_id() << " - general cost: " << cost * myApartment->get_generalProportion() / 1000 << endl;
                     }
      };
      
GeneralCost::GeneralCost(string myDate, double myCost) {
                                  date = myDate;
                                  cost = myCost;
                                  }      

class ElevatorCost : public CostCategory {
      public:
             ElevatorCost(string myDate, double myCost);
             virtual void calculate(Apartment* myApartment) {
                     cout << myApartment->get_id() << " - elevator cost: " << cost * myApartment->get_elevatorProportion() / 1000 << endl;
                     }
      };
      
ElevatorCost::ElevatorCost(string myDate, double myCost) {
                                  date = myDate;
                                  cost = myCost;
                                  }    

int main()
{
    Apartment a1 ("A1", "androulakis", 92.50, 56.50);
    Apartment a2 ("A2", "dimakis", 56.20, 62.60);
    GeneralCost gc1 ("2014-05-22", 107.50);
    ElevatorCost ec1 ("2014-05-30", 45.5);
    a1.show();
    a2.show();
    CostCategory* cc1 = &gc1;
    CostCategory* cc2 = &ec1;
    cc1->calculate(&a1);
    cc1->calculate(&a2);
    cc2->calculate(&a1);
    cc2->calculate(&a2);
    char to_stop;
    cin >> to_stop;
    return 0;
}
