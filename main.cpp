#include <iostream>


class Address{

    std::string country;
    std::string city;
    std::string street;

    public:
        Address(std::string Country="", std::string City="", std::string Street=""){
            country = Country;
            City = city;
            street = Street;
        }

        std::ostream& operator<<(std::ostream& os) const {
            os << "Country: " << country << ", City: " << city << ", Street: " << street;
            return os;
        }

        std::istream& operator>>(std::istream& is) {
            std::cout << "Enter country: ";
            is >> country;
            std::cout << "Enter city: ";
            is >> city;
            std::cout << "Enter street: ";
            is >> street;
            return is;
        }

        void getCountry(){
            std::cout<<country<<"\n";
        }

        void setCountry(std::string Country){
            country = Country;
        }

        void getCity(){
            std::cout<<city<<"\n";
        }

        void setCity(std::string City){
            city = City;
        }

        void getStreet(){
            std::cout<<street<<"\n";
        }

        void setStreet(std::string Street){
            street = Street;
        }


};


class Person{

    std::string name;
    std::string id;
    Address address;

    public:
        Person(std::string Name="", std::string ID="", Address ad = Address()){
            name = Name;
            id = ID;
            address = ad;
        }

        Person(Person& object){
            name = object.name;
            id = object.id;
            address = object.address;
        }

        void getName(){
            std::cout<<name<<"\n";
        }

        void getId(){
            std::cout<<id<<"\n";
        }

        void getAddress(){
            address<<std::cout;
        }
};


















int main(){
    Address address("Iran", "Tehran", "Piroozi");
    // address<<std::cout;
    // Address newAddress;
    // std::cout << "Enter a new address:" << std::endl;
    // newAddress >> std::cin;
    // std::cout << "New address: ";
    // newAddress << std::cout;
    // std::cout << std::endl;

    Person person("Ali", "123", address);
    person.getAddress();

    }

    