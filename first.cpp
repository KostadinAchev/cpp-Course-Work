#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <limits>
#include "Uchebnik.h"
#include "Mon.h"
#include "Razpredeliteli.h"


int getValidInt(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail() || value < 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a positive integer.\n";
        } else {
            return value;
        }
    }
}

int main() {
    std::cout << "What do you want to do?" << "\n";
    std::cout << " ==========================" << "\n";
    std::cout << "|1. Create Uchebnici       |" << "\n";
    std::cout << "|2. Create Razprostraniteli|" << "\n";
    std::cout << "|3. Chose Razprostranitel  |" << "\n";
    std::cout << "|4. MON APPROVAL/DENIAL    |" << "\n";
    std::cout << " ==========================" << "\n";

    Uchebnik k;
    razprostraniteli r;
    MON mon;
    std::vector<Uchebnik> vsichki;
    std::ofstream updatedFile;

    int choice = getValidInt("Choice to be made: ");

    switch (choice) {
    case 1: {
        int x1 = getValidInt("Number of Uchebnici: ");
        k.add(x1);
        std::cout << k;
        break;
    }
    case 2: {
        int x2 = getValidInt("Number of Razprostraniteli: ");
        r.add(x2);
        break;
    }
    case 3: {
        r.readAndChooseRazprostranitel();
        std::cout << "Would you like to order some Uchebnici?" << "\n";
        std::cout << " ========" << "\n";
        std::cout << "| 1. Yes |" << "\n";
        std::cout << "| 2. No  |" << "\n";
        std::cout << " ========" << "\n";

        int x3 = getValidInt("Your choice: ");
        if (x3 == 1) {
            int x31 = getValidInt("Numbers of Uchebnici: ");
            double totalSum = 0;
            vsichki = k.readAndChooseUchebnik();
            for (int i = 0; i < x31; i++) {
                int choiceUch = getValidInt("Uchebnik to buy: ");
                if (choiceUch > 0 && choiceUch <= vsichki.size()) {
                    totalSum += vsichki.at(choiceUch - 1).getPrice();
                } else {
                    std::cout << "Invalid choice. Please try again.\n";
                }
            }
            std::cout << "Total sum is: " << totalSum << "\n";
        } else if (x3 == 2) {
            std::cout << "No orders made!\n";
        } else {
            std::cout << "Invalid choice.\n";
        }
        break;
    }
    case 4: {
        vsichki = k.readAndChooseUchebnik();
        int choiceUchToApprove = getValidInt("Uchebnik to approve: ");
        if (choiceUchToApprove > 0 && choiceUchToApprove <= vsichki.size()) {
            mon.apporval(vsichki.at(choiceUchToApprove - 1).getApproval());
            vsichki.at(choiceUchToApprove - 1).setApproval(mon.getApproval());
            vsichki.at(choiceUchToApprove - 1).setApprovalDate(mon.getApprovalDate());

            updatedFile.open("dataUchebnik.txt", std::ios::trunc);
            for (const auto& uch : vsichki) {
                updatedFile << uch.toString();
            }
            updatedFile.close();
        } else {
            std::cout << "Invalid Uchebnik choice.\n";
        }
        break;
    }
    default:
        std::cout << "No such choice.\n";
        break;
    }
    return 0;
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