#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>


// Constructor (Yapıcı Fonksiyon)
PhoneBook::PhoneBook() : contact_count(0) {}  // 'contact_count' değişkeni 0 olarak başlatılır.


// Kullanıcıdan tam bir satır almak için kullanılan fonksiyon
void PhoneBook::read_getline(std::string &str)
{
    std::getline(std::cin, str);  // Kullanıcıdan bir satır alınır ve 'str' değişkenine kaydedilir.

    if (std::cin.eof()) {  // Eğer EOF (End of File) durumu meydana gelirse (kullanıcı dosya sonu vs. girerse)
        throw std::runtime_error("EOF encountered");  // Hata fırlatılır.
    }
    else if (std::cin.fail()) {  // Eğer bir okuma hatası oluşursa
        std::cin.clear();  // 'fail' bayrağını temizler.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Geriye kalan veriyi yok sayar.
        throw std::runtime_error("Invalid input");  // Geçersiz giriş hatası fırlatılır.
    }
}


// Yeni bir kişi eklemek için kullanılan fonksiyon
void PhoneBook::add_contact(Contact contact)
{
    contacts[contact_count] = contact;  // 'contact' nesnesi, 'contacts' dizisinin ilgili indeksine eklenir.
    contact_count++;  // 'contact_count' bir artırılır (yeni bir kişi ekleniyor).

    if (contact_count == 8) {  // Eğer kişi sayısı 8'e ulaşırsa (maksimum kapasite)
        contact_count = 0;  // 'contact_count' sıfırlanır, böylece diziyi tekrar baştan kullanabiliriz.
    }
}

// String'i tam sayıya dönüştürmek için kullanılan fonksiyon
int str_to_int(const std::string& str)
{
    std::stringstream ss(str);  // 'str' string'ini bir stringstream'e aktarırız.
    int num = 0;  // Sayıyı tutacak bir değişken oluşturulur.
    ss >> num;  // Stringstream üzerinden sayıya dönüşüm yapılır.

    if (ss.fail()) {  // Eğer dönüşüm başarısız olursa
        return -1;  // Geçersiz dönüşüm durumunda -1 döndürülür.
    }

    return num;  // Başarılı dönüşümde sayıyı döndürür.
}


// Kişileri aramak için kullanılan fonksiyon
void PhoneBook::search_contact()
{
    int index;  // Arama yapılacak kişinin indeksini tutacak değişken.
    std::string tmp;  // Kullanıcıdan alınacak geçici giriş değişkeni.

    std::cout << "     Index|First name| Last name|  Nickname" << std::endl;  // Başlık yazdırılır.

    // Kişiler dizisinde her kişiyi yazdırıyoruz. 'contacts' dizisi, 8 kişiye kadar yer tutar.
    for (int i = 0; i < 8; i++) {  // 8 kişi için döngü başlatılır.
        std::cout << std::setw(10) << i + 1 << "|";  // Kişinin indeks numarası yazdırılır.
        std::cout << std::setw(10) << contacts[i].resize_string(contacts[i].get_name()) << "|";  // Kişinin adı, 10 karaktere kadar gösterilir ve 10'dan fazlaysa kısaltılır.
        std::cout << std::setw(10) << contacts[i].resize_string(contacts[i].get_surname()) << "|";  // Soyadı da aynı şekilde kısaltılır.
        std::cout << std::setw(10) << contacts[i].resize_string(contacts[i].get_nickname()) << std::endl;  // Takma adı da kısaltılır.
    }

    std::cout << "Enter an index: ";  // Kullanıcıdan bir indeks girmesi istenir.
    read_getline(tmp);  // Giriş alınır.
    index = str_to_int(tmp);  // Giriş tamsayıya dönüştürülür.

    if (index < 1 || index > 8) {  // Eğer indeks geçerli değilse (1 ile 8 arasında olmalı)
        std::cout << "\033[1;31mInvalid index, please enter a valid index.\033[0m" << std::endl;  // Hata mesajı yazdırılır.
        return;  // Fonksiyon sonlandırılır.
    }

    // Geçerli bir indeks girildiyse, kişinin tüm bilgileri yazdırılır.
    std::cout << "First name:     " << contacts[index - 1].get_name() << std::endl;
    std::cout << "Last name:      " << contacts[index - 1].get_surname() << std::endl;
    std::cout << "Nickname:       " << contacts[index - 1].get_nickname() << std::endl;
    std::cout << "Phone number:   " << contacts[index - 1].get_phone_number() << std::endl;
    std::cout << "Darkest secret: " << contacts[index - 1].get_darkest_secret() << std::endl;
}
