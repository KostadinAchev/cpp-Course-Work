#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdexcept> 

class Uchebnik {
public:
    
    Uchebnik()
        : price(0.0),
          serificate(false),
          porednoIzdanie(0),
          numberISBN(0),
          tiraj(0) {
        std::cout << "Uchebnik created (default constructor).\n";
    }

    Uchebnik(const std::string& headline, const std::string& author, int izdanie, int isbn, const std::string& date, int tiraj, double price, bool serificate = false, const std::string& approvalDate = "")
        : headline(headline),
          author(author),
          porednoIzdanie(izdanie),
          numberISBN(isbn),
          date(date),
          tiraj(tiraj),
          price(price),
          serificate(serificate),
          approvalDate(approvalDate) {
        validate(); 
        std::cout << "Uchebnik created (parameterized constructor).\n";
    }

    ~Uchebnik() {
        std::cout << "Uchebnik destroyed.\n";
    }

    void validate() {
        if (headline.empty()) throw std::invalid_argument("Headline cannot be empty!");
        if (author.empty()) throw std::invalid_argument("Author cannot be empty!");
        if (porednoIzdanie <= 0) throw std::invalid_argument("Edition must be a positive number!");
        if (numberISBN <= 0) throw std::invalid_argument("ISBN must be a positive number!");
        if (date.empty()) throw std::invalid_argument("Date cannot be empty!");
        if (tiraj <= 0) throw std::invalid_argument("Tiraj must be a positive number!");
        if (price < 0) throw std::invalid_argument("Price cannot be negative!");
    }

    friend std::ostream& operator<<(std::ostream& out, const Uchebnik& obj);

    std::string toString() const {
        return "Headline: " + headline + "\n" +
               "Author: " + author + "\n" +
               "Poredno Izdanie: " + std::to_string(porednoIzdanie) + "\n" +
               "ISBN: " + std::to_string(numberISBN) + "\n" +
               "Date: " + date + "\n" +
               "Tiraj: " + std::to_string(tiraj) + "\n" +
               "Price: " + std::to_string(price) + "\n" +
               "Approval: " + std::to_string(serificate) + "\n" +
               "Approval Date: " + approvalDate + "\n" +
               "------------------------\n";
    }

    std::vector<Uchebnik> readAndChooseUchebnik() {
        std::ifstream dataFile("dataUchebnik.txt");

        std::vector<Uchebnik> uchebnici;
        std::string line;
        while (std::getline(dataFile, line)) {
            if (line.find("Headline: ") == 0) {
                Uchebnik uch;

                std::string headline = line.substr(10); 
                uch.setHeadLine(headline);

                std::getline(dataFile, line);
                std::string author = line.substr(8); 
                uch.setAuthor(author);

                std::getline(dataFile, line);
                int izdanie = std::stoi(line.substr(17)); 
                uch.setIzdanie(izdanie);

                std::getline(dataFile, line);
                int isbn = std::stoi(line.substr(6)); 
                uch.setISBN(isbn);

                std::getline(dataFile, line);
                std::string date = line.substr(6); 
                uch.setDate(date);

                std::getline(dataFile, line);
                int tiraj = std::stoi(line.substr(7)); 
                uch.setTiraj(tiraj);

                std::getline(dataFile, line);
                double price = std::stod(line.substr(7));
                uch.setPrice(price);

                uchebnici.push_back(uch);

                std::getline(dataFile, line);
            }
        }
        dataFile.close();

        for (size_t i = 0; i < uchebnici.size(); ++i) {
            std::cout << i + 1 << ".\n" << uchebnici[i].toString();
        }

        return uchebnici;
    }

    void add(int x) {
        std::ofstream dataFile("dataUchebnik.txt", std::ios::app);
        std::cout << "---------------------------\n";

        for (int i = 0; i < x; i++) {
            Uchebnik uch;
            std::string headlineL;
            std::string authorL;
            int izdanieL;
            int ISBNL;
            int tirajL;
            double priceL;
            std::string dateL;

            std::cin.ignore();
            
            std::cout << "Headline: ";
            std::getline(std::cin, headlineL);
            uch.setHeadLine(headlineL);

            std::cout << "Author: ";
            std::getline(std::cin, authorL);
            uch.setAuthor(authorL);

            std::cout << "Poredno Izdanie: ";
            std::cin >> izdanieL;
            uch.setIzdanie(izdanieL);

            std::cout << "ISBN: ";
            std::cin >> ISBNL;
            uch.setISBN(ISBNL);

            std::cout << "Tiraj: ";
            std::cin >> tirajL;
            uch.setTiraj(tirajL);

            std::cout << "Date: ";
            std::cin >> dateL;
            uch.setDate(dateL);

            std::cout << "Price: ";
            std::cin >> priceL;
            uch.setPrice(priceL);

            uch.getApproval();

            std::cin.ignore();

            dataFile << uch.toString();
            std::cout << "---------------------------\n";
        }
    }

    void setHeadLine(const std::string &x) { headline = x; }
    void setAuthor(std::string x) { author = x; }
    void setIzdanie(int x) { porednoIzdanie = x; }
    void setISBN(int x) { numberISBN = x; }
    void setDate(std::string x) { date = x; }
    void setTiraj(int x) { tiraj = x; }
    void setPrice(double x) { price = x; }
    void setApproval(bool x) { serificate = x; }
    void setApprovalDate(const std::string &x) { approvalDate = x; }

    std::string getHeadline() { return headline; }
    std::string getAuthor() { return author; }
    int getIzdanie() { return porednoIzdanie; }
    int getISBN() { return numberISBN; }
    std::string getDate() { return date; }
    int getTiraj() { return tiraj; }
    double getPrice() { return price; }
    bool getApproval() { return serificate; }
    std::string getApprovalDate() { return approvalDate; }

private:
    double price;
    bool serificate = false;
    std::string headline;
    std::string author;
    int porednoIzdanie;
    int numberISBN;
    std::string date;
    int tiraj;
    std::string approvalDate;
};

std::ostream& operator<<(std::ostream& out, const Uchebnik& obj) {
    out << "Headline: " << obj.headline << "\n"
        << "Author: " << obj.author << "\n"
        << "Poredno Izdanie: " << obj.porednoIzdanie << "\n"
        << "ISBN: " << obj.numberISBN << "\n"
        << "Date: " << obj.date << "\n"
        << "Tiraj: " << obj.tiraj << "\n"
        << "Price: " << obj.price << "\n"
        << "Approval: " << obj.approvalDate << "\n"
        << "Approval Date: " << obj.serificate << "\n"
        << "------------------------\n";
    return out;
}
