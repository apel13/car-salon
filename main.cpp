#include <iostream>
#include <string>
#include <iomanip>

#include "salon.h"
#include "commands.h"
#include "car.h"


using namespace std;


int main() {
    Salon salon;
    Customer customer("Vadim");
//    std::system("clear");

    string line, command;

    while (cout << "enter command: " << flush && getline(cin, line)) {
        try {
//            std::system("clear");

            istringstream is(line);
            is >> command;
            CommandType cmd = parseCommand(command);

            switch (cmd) {
                case CommandType::CAR_LIST:
                    salon.showCarList();
                    break;
                case CommandType::FILTER_LIST:
                    salon.showFilteredCarList();
                    break;
                case CommandType::FILTER:
                    salon.filter(CarFilters::parseCondition(is));
                    break;
                case CommandType::RESET_FILTERS:
                    salon.resetFilters();
                    break;
                case CommandType::MY_CAR:
                    if (customer.getCar() != nullptr) {
                        cout << "your car: " << *customer.getCar() << endl;
                    } else {
                        cout << "you haven't a car" << endl;
                    }
                    break;
                case CommandType::BUY:
                    uint16_t id; is >> id;
                    if (salon.buy(customer, id))
                        cout << "ok" << endl;
                    else
                        cout << "there is no car with id = " << id << endl;
                    break;
                case CommandType::HELP:
                    printHelp(cout);
                    break;
                case CommandType::EXIT:
                    return 0;
                default:
                    cout << "unknown command" << endl;
            }
        }
        catch (std::exception &e) {
            cout << e.what() << endl;
        } catch (...) {
            cout << "something went wrong, try again";
        }
    }
    return 0;
}