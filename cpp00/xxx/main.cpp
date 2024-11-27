#include "PhoneBook.hpp"

void read_getline(string &str)
{
    getline(cin, str);

    if (cin.eof()) {
        // Kullanıcı girdi akışını sonlandırdıysa hata fırlatılır
        throw runtime_error("EOF encountered");
    } else if (cin.fail()) {
        // Geçersiz girdi durumunda hata fırlatılır
        cin.clear(); // Hata bayrağı temizlenir
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Geçersiz girdi temizlenir
        throw runtime_error("Invalid input");
    }
}

int main()
{
	PhoneBook				phone_book;
	string					input;

	while (true)
	{
		cout << "\033[1;36mEnter a command (ADD, SEARCH, EXIT): \033[0m";
		read_getline(input);

		if (input == "EXIT")
		{
			cout << "exit";
			break;
		}
		else if (input == "ADD")
		{
			cout << "isim gir";
			add.contact();
		}


	}


}
