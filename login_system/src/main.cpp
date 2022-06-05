# include <iostream>
# include <fstream>
# include <string>

bool IsLoggedIn(){
    std::string username, password, un, pw;
    std::cout << "Enter username: "; std::cin >> username;
    std::cout << "Enter password: "; std::cin >> password;

    std::ifstream read("data/" + username + ".txt");
    std::getline(read, un);
    std::getline(read, pw);

    if (un == username && pw == password){
        std::cout << "matching!" << std::endl;
        return true;
    }
    else{
        std::cout << "unmatching!" << std::endl;

        return false;
    }
}


int main (){
    int choice;
    std::cout << "1: Register\n2: Login\nYour choice: ";
    std::cin >> choice;
    if (choice == 1){
        std::string username, password;
        std::cout << "select a username: "; std::cin >>username;
        std::cout << "select a password: "; std::cin >>password;

        std::ofstream file;
        file.open("data/" + username + ".txt");
        file << username << std::endl << password;
        file.close();

        main();
    }
    else if (choice == 2){
        bool status = IsLoggedIn();
        if (!status){
            std::cout << "False Login!" << std::endl;
            system("PAUSE");
            return 0;
        }
        else{
        std::cout << "Successfully logged in!" << std::endl;
        system("PAUSE");
        return 1;
    }
    
    }

}