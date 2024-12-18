#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdexcept> 
#include <algorithm>

class razprostraniteli {
public:
    razprostraniteli()
        : name(""),
          address(""),
          phoneNumber("") {
        std::cout << "razprostraniteli created (default constructor).\n";
    }

    razprostraniteli(const std::string& name, const std::string& address, const std::string& phoneNumber)
        : name(name),
          address(address),
          phoneNumber(phoneNumber) {
        validate();
        std::cout << "razprostraniteli created (parameterized constructor).\n";
    }

    ~razprostraniteli() {
        std::cout << "razprostraniteli destroyed.\n";
    }

    void validate() {
        if (name.empty()) throw std::invalid_argument("Name cannot be empty!");
        if (address.empty()) throw std::invalid_argument("Address cannot be empty!");
        if (phoneNumber.empty()) throw std::invalid_argument("Phone number cannot be empty!");
        if (!std::all_of(phoneNumber.begin(), phoneNumber.end(), ::isdigit))
            throw std::invalid_argument("Phone number must contain only digits!");
    }

    void readAndChooseRazprostranitel() {
        std::ifstream dataFile("dataRazpredeliteli.txt");
        if (!dataFile.is_open()) {
            std::cerr << "Error: Could not open file dataRazpredeliteli.txt.\n";
            return;
        }

        std::vector<razprostraniteli> razprostranitelite;
        std::string line;
        while (std::getline(dataFile, line)) {
            if (line.find("Name: ") == 0) {
                razprostraniteli razp;

                std::string name = line.substr(6);
                razp.setName(name);

                std::getline(dataFile, line);
                std::string address = line.substr(9);
                razp.setAddress(address);

                std::getline(dataFile, line);
                std::string phoneNumber = line.substr(13);
                razp.setPNumber(phoneNumber);

                razprostranitelite.push_back(razp);

                std::getline(dataFile, line);
            }
        }
        dataFile.close();

        for (size_t i = 0; i < razprostranitelite.size(); ++i) {
            std::cout << i + 1 << ".\n" << razprostranitelite[i].toString();
        }

        int choiceIndex;
        std::cout << "Choose a distributor by number: ";
        std::cin >> choiceIndex;

        if (choiceIndex > 0 && choiceIndex <= razprostranitelite.size()) {
            std::cout << "You chose:\n" << razprostranitelite[choiceIndex - 1].toString();
        } else {
            std::cout << "Invalid choice.\n";
        }
    }

    void add(int x) {
        std::ofstream dataFile("dataRazpredeliteli.txt", std::ios::app);
        if (!dataFile.is_open()) {
            std::cerr << "Error: Could not open file dataRazpredeliteli.txt.\n";
            return;
        }

        std::cout << "---------------------------\n";

        for (int i = 0; i < x; i++) {
            razprostraniteli razp;
            std::string nameL;
            std::string addressL;
            std::string phoneNumberL;

            std::cin.ignore();
            std::cout << "Name: ";
            std::getline(std::cin, nameL);
            razp.setName(nameL);

            std::cout << "Address: ";
            std::getline(std::cin, addressL);
            razp.setAddress(addressL);

            std::cout << "Phone number: ";
            std::getline(std::cin, phoneNumberL);
            razp.setPNumber(phoneNumberL);

            try {
                razp.validate();
                dataFile << razp.toString();
                std::cout << "Distributor added successfully.\n";
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error: " << e.what() << "\n";
            }

            std::cout << "---------------------------\n";
        }
    }

    std::string toString() const {
        return "Name: " + name + "\n" +
               "Address: " + address + "\n" +
               "Phone Number: " + phoneNumber + "\n"
               "------------------------\n";
    }

    void setName(const std::string& x) { name = x; }
    void setAddress(const std::string& x) { address = x; }
    void setPNumber(const std::string& x) { phoneNumber = x; }

    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
    std::string getPhoneNumber() const { return phoneNumber; }

private:
    std::string name;
    std::string address;
    std::string phoneNumber;
};
