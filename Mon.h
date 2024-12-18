#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <limits>

class MON
{
public:
    void setApprovalDate(const std::string &x)
    {
        approvalDate = x;
    }
    std::string getApprovalDate()
    {
        return approvalDate;
    }
    void setApproval(bool x)
    {
        udobrenie = x;
    }
    bool getApproval()
    {
        return udobrenie;
    }
    bool apporval(bool approved)
    {
        int choice;
        std::cout << "Choice to be made: " << "\n";
        std::cout << "=====================" << "\n";
        std::cout << "   1. Approve!        " << "\n";
        std::cout << "   2. Deny!           " << "\n";
        std::cout << "   0. Exit!           " << "\n";
        std::cout << "=====================" << "\n";

        while (true)
        {
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            if (std::cin.fail() || choice < 0 || choice > 2)
            {
                std::cin.clear(); 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                std::cout << "Invalid input. Please enter a valid choice (0-2).\n";
            }
            else
            {
                break;
            }
        }

        if (!approved)
        {
            switch (choice)
            {
            case 1: 
                std::cout << "Approval succeeded!" << "\n";
                std::cout << "Enter approval date (YYYY-MM-DD): ";
                std::cin.ignore(); 
                std::getline(std::cin, approvalDate);
                setApprovalDate(approvalDate);
                setApproval(true);
                break;
            case 2: 
                std::cout << "Approval denied!\n";
                setApproval(false);
                break;
            case 0: 
                std::cout << "Exiting...\n";
                break;
            default:
                break;
            }
        }
        else
        {
            std::cout << "Already approved!\n";
        }
        return udobrenie;
    }

private:
    std::string approvalDate;
    bool udobrenie = true;
};
