
#include <iostream>
#include <string>
#include "record.h"
#include "llist.h"
#include "address_book.h"

void run_program() {
    llist records(get_file_name()); /* Lets user create their own .txt file for database purposes*/
    std::string input_name = "";
    std::string input_address = "";
    std::string input_phone = "";
    std::string dummy = "";
    int input_year = 0;
    int menu_selection = 0;

    display_commands();
    do { // do while menu_selection != 7
        menu_selection = get_menu_selection();
        switch (menu_selection) {
            case 1: // case 1 - add record
                std::cout << "--------------------\n";
                std::cout << "Add a new Record\n";
                input_name = get_name();
                input_address = get_address();
                input_year = get_birth_year();
                input_phone = get_phone_number();
                records.add_record(input_name, input_address, input_year, input_phone);
                break; // end case 1
            case 2: // case 2 - print specific record by name
                std::cout << "--------------------\n";
                std::cout << "Print Record(s) with the same name\n";
                input_name = get_name();
                records.print_record(input_name);
                break; // end case 2
            case 3: // case 3 - modify specific record by name
                std::cout << "--------------------\n";
                std::cout << "Modify Record(s) with the same name\n";
                input_name = get_name();
                input_address = get_address();
                std::getline(std::cin, dummy);
                //std::cin.getline(dummy, 4);
                input_phone = get_phone_number();
                records.modify_record(input_name, input_address, input_phone);
                break;
            case 4: // case 4 - print all records
                std::cout << "--------------------\n";
                std::cout << "Printing Records...\n";
                records.print_all_records();
                break;
            case 5: // case 5 - delete specific record by name
                std::cout << "--------------------\n";
                std::cout << "Delete Record(s) with the same name\n";
                input_name = get_name();
                records.delete_record(input_name);
                break;
            case 6: // case 6 - recursively reverse order of linked list
                std::cout << "--------------------\n";
                std::cout << "Reversing the order of all the Records...\n";
                records.reverse_llist();
                break;
            default: // repeats the loop until an input is given
                std::cout << "No input recorded, retry again";
                break;
        }
        if (menu_selection != 7) {
            display_commands();
        }
    } while (menu_selection != 7); // end while
}

void debug_function(int function_call, std::string name, std::string address, std::string phone_number, int year) {
    std::cout << "********************\n";
    if (function_call == 1) {
        std::cout << "llist::addRecord( " << name << ", " << address << ", " << year << ", " << phone_number << " );\n";
    } else if (function_call == 2) {
        std::cout << "llist::printRecord( " << name << " )n";
    } else if(function_call == 3) {
        std::cout << "llist::modifyRecord( " << name << ", " << address << ", " << phone_number << " );\n";
    } else if (function_call == 4) {
        std::cout << "llist::printAll( );\n";
    } else if (function_call == 5) {
        std::cout << "llist::deleteRecord( " << name << " )n";
    } else if (function_call == 6) {
        std::cout << "llist::reverse( );\n";
    }
    std::cout << "********************\n";
}

void display_commands() {
    std::cout << "Usage:\n";
    std::cout << "\t1: Add a new record into the database.\n";
    std::cout << "\t2: Print information about a record using the name as the key. \n";
    std::cout << "\t3: Modify a record in the database using the name as the key. \n";
    std::cout << "\t4: Print all information in the database.\n";
    std::cout << "\t5: Delete an existing record from the database.\n";
	std::cout << "\t6: Reverse the order of all existing records from the database.\n";
    std::cout << "\t7: Quit the program.\n";
    std::cout << "What would you like to do?\n";
}

int get_menu_selection() {
    int selection = 0;

    std::cin >> selection;
    while (std::cin.fail() || selection < 1 || selection > 7) { // while input is not valid
        if (std::cin.fail()) {
            std::cout << "Your input was not an integer. Please enter an integer: ";
        } else if ( selection < 1 || selection > 7) {
            std::cout << "Not a valid choice.\n";
            display_commands();
        } // end if std::cin.fail()
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> selection;
    } // end while std::cin.fail() || selection < 1 || selection > 7
    std::cin.clear(); // clear input buffer
    return selection; // get_menu_selection return - end of function
}

std::string get_name() {
    std::string name = "";

    std::cin.clear();
    std::cin.ignore(256, '\n');
    std::cout << "Please enter the person's NAME: ";
    std::getline(std::cin, name);
    //std::cin.clear();
    return name;
}

std::string get_address() {
    // get_address
    std::string address = "";

    std::cout << "Please enter the person's ADDRESS (Enter '$' when you're finished):\n";
    std::getline(std::cin, address, '$');
    //std::cin.clear();
    return address;
}

int get_birth_year() {
    // get_birth_year variables
    int birth_year = 0;

    std::cout << "Please enter the person's BIRTH YEAR: ";
    std::cin >> birth_year;
    while (std::cin.fail()) { // while input is invalid
        std::cout << "Not an integer, please enter an integer: ";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> birth_year;
    } // end while std::cin.fail()
    std::cin.clear();
    std::cin.ignore(256, '\n');
    return birth_year;
}

std::string get_phone_number() {
    // get_phone_number variables
    std::string phone_number = "";

    std::cout << "Please enter the contact's TELEPHONE NUMBER: ";
    std::getline(std::cin, phone_number);
    std::cin.clear();
    return phone_number;
}

std::string get_file_name() {

    std::string file_name = "";
    int count;

    std::cout << "Please enter your FILE NAME ('.txt' file extension will be added): ";
    std::getline(std::cin, file_name);
    file_name += ".txt";
    return file_name;
}
