#include "Contact.hpp"

std::string Contact::get_name() const
{
    return name;
}

std::string Contact::get_surname() const // std::string -> sstr döndürecek.  cantact::get_name()->contact sınıfından fonksiyon const-> sınıfın verilerini değiştiremez
{
    return surname;
}

std::string Contact::get_nickname() const
{
    return nickname;
}

std::string Contact::get_phone_number() const
{
    return phone_number;
}

std::string Contact::get_darkest_secret() const
{
    return darkest_secret;
}

void Contact::set_name(const std::string& name)
{
    this->name = name;
}

void Contact::set_surname(const std::string& surname)
{
    this->surname = surname;
}

void Contact::set_nickname(const std::string& nickname)
{
    this->nickname = nickname;
}

void Contact::set_phone_number(const std::string& phone_number)
{
    this->phone_number = phone_number;
}

void Contact::set_darkest_secret(const std::string& darkest_secret)
{
    this->darkest_secret = darkest_secret;
}

std::string Contact::resize_string(const std::string& str) const  // "resize_string" fonksiyonu, uzunluğu 10 karakteri aşan stringleri kısaltmak için kullanılır.
{
    std::string result = str;  // İlk olarak, parametre olarak alınan string'i "result" adında bir değişkene kopyalıyoruz.

    if (result.length() > 10)  // Eğer string'in uzunluğu 10 karakterden fazla ise
    {
        result.resize(9);  // String'in uzunluğunu 9'a indiriyoruz, böylece son karakter kesiliyor.
        result += ".";  // Kesilen sonucun sonuna "..." ekliyoruz.
    }

    return result;  // Kısaltılmış ya da olduğu gibi bırakılmış string'i geri döndürüyoruz.
}
