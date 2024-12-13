#include <iostream>
#include <vector>
#include <fstream>
#include <string>



class Uchebnik
{
public:
    
    friend std::ostream& operator<<(std::ostream& out, const Uchebnik& obj);
    

    std::string toString() const
    {
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

    
    /* int choiceIndex;
    std::cout << "Choose a book by number: ";
    std::cin >> choiceIndex;

    if (choiceIndex > 0 && choiceIndex <= static_cast<int>(uchebnici.size())) {
        std::cout << "You chose:\n" << uchebnici[choiceIndex - 1].toString();
    } else {
        std::cout << "Invalid choice.\n";
    } */
    return uchebnici;
}


    void add(int x)
    {
        std::ofstream dataFile("dataUchebnik.txt", std::ios::app);
        std::vector<Uchebnik> Uchebnici;
        std::cout << "---------------------------\n";

        for (int i = 0; i < x; i++)
        {
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

        /* for (size_t i = 0; i < Uchebnici.size(); i++)
        {
            std::cout << "Headline: " << Uchebnici[i].getHeadline() << "\n";
            std::cout << "Author: " << Uchebnici[i].getAuthor() << "\n";
            std::cout << "Poredno Izdanie: " << Uchebnici[i].getIzdanie() << "\n";
            std::cout << "ISBN: " << Uchebnici[i].getISBN() << "\n";
            std::cout << "Tiraj: " << Uchebnici[i].getTiraj() << "\n";
            std::cout << "Date: " << Uchebnici[i].getDate() << "\n";
            std::cout << "---------------------------\n";
        } */
    }
    void setHeadLine(const std::string &x)
    {
        headline = x;
    }
    void setAuthor(std::string x)
    {

        author = x;
    }
    void setIzdanie(int x)
    {

        porednoIzdanie = x;
    }
    void setISBN(int x)
    {

        numberISBN = x;
    }
    void setDate(std::string x)
    {

        date = x;
    }
    void setTiraj(int x)
    {

        tiraj = x;
    }
    void setPrice(double x)
    {
        price = x;
    }
    std::string getHeadline()
    {
        return headline;
    }
    std::string getAuthor()
    {
        return author;
    }
    int getIzdanie()
    {
        return porednoIzdanie;
    }
    int getISBN()
    {
        return numberISBN;
    }
    std::string getDate()
    {
        return date;
    }
    int getTiraj()
    {
        return tiraj;
    }
    double getPrice()
    {
        return price;
    }
    bool getApproval()
    {
        return serificate;
    }
    void setApproval(bool x)
    {
        serificate =x;
    }
    void setApprovalDate(const std::string &x)
    {
        approvalDate = x;
    }
    std::string getApprovalDate()
    {
        return approvalDate;
    }
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

std::ostream& operator<<(std::ostream& out, const Uchebnik& obj){
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

class MON
{
public:

    void setApprovalDate(const std::string &x)
    {
        approvalDate=x;
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
        std::cout << "   1.Approve!        " << "\n";
        std::cout << "   2.Deny!           " << "\n";
        std::cout << "   0.Exit!           " << "\n";
        std::cout << "=====================" << "\n";
        std::cin >> choice;
        std::string approvalDateL;
        
        if (approved == false)
        {
            switch (choice)
            {
            case 1:
                std::cout << "Approval succeeded!" << "\n";
                std::cout << "Enter approval date: ";
                std::cin.ignore();
                std::getline(std::cin,approvalDateL);
                setApprovalDate(approvalDateL);
                setApproval(true);
                break;
            case 2:
                std::cout << "Approval denied!";
                setApproval(false);
                break;
            case 0:
                std::cout << "EXITING...";
                break;
            default:
                std::cout << "Incorrect choice!!!";
                break;
            }
        }
        return 0;
    }

private:
    std::string approvalDate;
    bool udobrenie = true;
};
class razprostraniteli
{
public:

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

    

 std::string toString() const
    {
        return "Name: " + name + "\n" +
               "Address: " + address + "\n" +
               "Phone Number: " +phoneNumber + "\n"
               "------------------------\n";
    }
    void add(int x)
    {
        std::ofstream dataFile("dataRazpredeliteli.txt", std::ios::app);
        
        std::cout << "---------------------------\n";

        for (int i = 0; i < x; i++)
        {
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

            std::cin.ignore();

            dataFile << razp.toString();
            
            std::cout << "---------------------------\n";
        }

       /*  for (size_t i = 0; i < razprostranitelite.size(); i++)
        {
            std::cout << "Name: " << razprostranitelite[i].getName() << "\n";
            std::cout << "Address: " << razprostranitelite[i].getAddress() << "\n";
            std::cout << "Phone Number: " << razprostranitelite[i].getPhoneNumber() << "\n";
            std::cout << "---------------------------\n";
        } */
    }
    void setName(std::string x)
    {
        name = x;
    }
    void setAddress(std::string x)
    {

        address = x;
    }
    void setPNumber(std::string x)
    {

        phoneNumber = x;
    }
    std::string getName()
    {
        return name;
    }
    std::string getAddress()
    {
        return address;
    }
    std::string getPhoneNumber()
    {
        return phoneNumber;
    }

private:
    std::string name;
    std::string address;
    std::string phoneNumber;
};

int main()
{

    std::cout << "What do you want to do?" << "\n";
    std::cout << " =========================="<< "\n" ;
    std::cout << "|1. Create Uchebnici       |"<< "\n";
    std::cout << "|2. Create Razprostraniteli|"<< "\n";
    std::cout << "|3. Chose Razprostranitel  |"<< "\n";
    std::cout << "|4. MON APPROVAL/DENIEAL   |"<< "\n";
    std::cout << " =========================="<< "\n";
    Uchebnik k;
    razprostraniteli r;
    MON mon;
    int choice;
    std::cout << "Choice to be made:";
    std::cin >> choice;
    std::vector<Uchebnik> vsichki;
    std::ofstream updatedFile;
    std::vector<Uchebnik> uch;
    
    switch (choice)
    {
    case 1:
        int x1;
        std::cout <<"Number of Uchebnici: ";
        std::cin >> x1;
        k.add(x1);
        std::cout << k;
        break;
    case 2:
        int x2;
        std::cout << "Number of Razprostraniteli: ";
        std::cin >> x2;
        r.add(x2);
        break;
    case 3:
        r.readAndChooseRazprostranitel();
        std::cout << "Would you like to order some Uchebnici?" << "\n";
        std::cout << " ========" << "\n";
        std::cout << "| 1. Yes |" << "\n";
        std::cout << "| 2. No  |" << "\n";
        std::cout << " ========"<< "\n";
        int x3;
        std::cin >> x3;
        switch (x3)
        {
        case 1:

            std::cout << "Numbers of Uchebnici: ";
            int x31;
            std::cin >> x31;
            double totalSum;
            vsichki= k.readAndChooseUchebnik();
            int choiceUch;
        
            for (int i =0 ; i < x31; i++)
            {
                std::cout << "Uch to buy:";
                std::cin >> choiceUch;

                totalSum +=vsichki.at(choiceUch-1).getPrice();

            }
        
            std::cout << "Total sum is:" << totalSum;
        
            break;
        case 2:
        
            std::cout << "No orders made!";
        
            break;
        
        default:
        
            break;
        }
        break;
    case 4: 
        uch = k.readAndChooseUchebnik();
        vsichki = k.readAndChooseUchebnik();
        int choiceUchToApprove;
        std::cout <<"Uchebnik to approve: " << "\n";
        std::cin >> choiceUchToApprove;

        mon.apporval(vsichki.at(choiceUchToApprove-1).getApproval());
        vsichki.at(choiceUchToApprove-1).setApproval(mon.getApproval());
        vsichki.at(choiceUchToApprove-1).setApprovalDate(mon.getApprovalDate());
        
        updatedFile.open("dataUchebnik.txt", std::ios::trunc);

        for(const auto &uch : vsichki)
        {
            updatedFile << uch.toString();
        }

        break;

    default:
        std::cout <<"No such choice";
        break;
    }
}


//.Да има възможност за избор на книгоразпространител и за него да се поръчват
//различни учебници, като се изчислява общата цена на поръчката(10 точки).

/* Създайте приложение, което да поддържа информация за издадени учебници. За всеки учебник се пази следната информац
ия: заглавие, автор /творчески колектив/, поредно издание, ISBN номер, дата на излизане от печат и тираж. Учебниците могат
да бъдат одобрени от Министерството на образованието, или все още да не са получили този сертификат. Пази се също и дата на одобряване.


Да се предефинира операцията <<, която да се използва за извеждане на данните (10 точки).  Класовете да се опишат с UML клас диаграма (10 точки).


Работи се с няколко книгоразпространителя. За това се пази името, адреса и телефона за всеки от книгоразпространителите.Приложението да има възможност
за въвеждане на произволен брой различни учебници и книгоразпространители(10 точки) Класовете (най-малко 3 класа при реализацията) трябва да капсулира всичките детайли.
Използват се private инстанции на променливите за съхраняване на различните детайли. Трябва да има най-малко два конструктора, public getters/setters за private
инстанции на променливите (30 точки). Необходимо е да извършвате проверка на входните данни (10 точки). Данните да се четат и съхраняват във файл (20 точки).
 */