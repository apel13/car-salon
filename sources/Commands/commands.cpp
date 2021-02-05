#include "commands.h"

#include <iostream>
#include <iomanip>
#include <array>

using namespace std;


struct Command {
    CommandType type;
    const char *name;
    const char *params;
    const char *description;
};

constexpr std::array<Command, 8> commands = {
        {
                {CommandType::CAR_LIST,
                        "car_list", "",
                        "show the list of cars"},
                {CommandType::FILTER_LIST,
                        "filter_list", "",
                        "show the filtered list of cars"},
                {CommandType::FILTER,
                        "filter", "[field] [op] [val]",
                        "filter the current list"},
                {CommandType::RESET_FILTERS,
                        "reset_filters", "",
                        "reset all filters"},
                {CommandType::MY_CAR,
                        "my_car", "",
                        "show which car you own"},
                {CommandType::BUY,
                        "buy", "[ID]",
                        "buy a specific car by ID"},
                {CommandType::HELP,
                        "help", "",
                        "show current help"},
                {CommandType::EXIT,
                        "exit", "",
                        "exit the program"}
        }
};

void printHelp(std::ostream &os) {
    os << "available commands:" << endl;
    for (auto &[_, cmd, params, desc] : commands) {
        os << '\t'
           << std::setw(30) << std::left << string(cmd) + " " + params
           << " - " << desc << endl;
    }
}


CommandType parseCommand(std::string &command) {
    for (auto &[type, cmd, params, _] : commands) {
        if (command == string(cmd))
            return type;
    }
    return CommandType::UNKNOWN;
}


