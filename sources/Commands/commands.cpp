#include "commands.h"

#include <iostream>
#include <iomanip>
#include <array>

using namespace std;

void printHelp() {
    static array<Command, 8> command_desc = {
            {
                    {"сar_list ", "show the list of cars"},
                    {"filter_list", "show the _filtered list of cars"},
                    {"filter [field] [op] [val]", "filter the current list"},
                    {"reset_filters", "reset all filters"},
                    {"my_car", "show which car you own"},
                    {"buy [ID]", "buy a specific car by ID"},
                    {"help", "show current help"},
                    {"exit", "exit the program"}
            }};

    cout << "available commands:" << endl;
    for (auto &[cmd, desc] : command_desc) {
        cout << '\t' << std::setw(26) << std::left
             << cmd << " - " << desc << endl;
    }
}

CommandType parseCommand(std::string &command) {
    if (command == "car_list") {
        return CommandType::CAR_LIST;
    } else if (command == "filter_list") {
        return CommandType::FILTER_LIST;
    } else if (command == "filter") {
        return CommandType::FILTER;
    } else if (command == "reset_filters") {
        return CommandType::CAR_LIST;
    } else if (command == "my_car") {
        return CommandType::MY_CAR;
    } else if (command == "buy") {
        return CommandType::BUY;
    } else if (command == "help") {
        return CommandType::HELP;
    } else if (command == "exit") {
        return CommandType::EXIT;
    }
    return CommandType::UNKNOWN;
}


