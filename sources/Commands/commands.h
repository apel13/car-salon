#pragma once

#include <string>

enum CommandType {
    CAR_LIST,
    FILTER_LIST,
    FILTER,
    RESET_FILTERS,
    MY_CAR,
    BUY,
    HELP,
    EXIT,
    UNKNOWN
};

void printHelp(std::ostream &os);

CommandType parseCommand(std::string &command);


