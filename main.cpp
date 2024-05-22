#include <iostream>
#include <regex>


class Address{

    std::string country;
    std::string city;
    std::string street;

    public:
        Address(std::string Country="", std::string City="", std::string Street=""){
            country = Country;
            city = City;
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

        std::string getCountry(){
            return country;
        }

        void setCountry(std::string Country){
            country = Country;
        }

        std::string getCity(){
            return city;
        }

        void setCity(std::string City){
            city = City;
        }

        std::string getStreet(){
            return street;
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

            if (validate(ID)){
                name = Name;
                id = ID;
                address = ad;
            }

            else{
                std::cout<<"Invalid id..."<<"\n";
            }

        }

        Person(Person& object){
            name = object.name;
            id = object.id;
            address = object.address;
        }

        std::ostream& operator<<(std::ostream& os) {
            os << "Name: " << name << ", ID: " << id << ", Address: " << address.getCountry() << "," << address.getCity() << "," << address.getStreet() << "\n";
            return os;
        }

        std::istream& operator>>(std::istream& is) {
            std::cout << "Enter name: ";
            is >> name;
            std::cout << "Enter id: ";
            is >> id;
            return is;
        }

        std::string getName(){
            return name;
        }

        void setName(std::string Name){
            name = Name;
        }

        std::string getId(){
            return id;
        }

        void setId(std::string ID){
            id = ID;
        }

        void getAddress(){
            address<<std::cout;
        }

        void setAddress(Address ad){
            address = ad;
        }

        bool validate(std::string ID){

            std::regex format("^(8[4-9]|9[0-9])[^\\d]{1,3}[4-6]{5}$");

            if (std::regex_match(ID, format)) {
                return true;
            } else {
                return false;
            }
        }




};


















int main(){
    Address address("Iran", "Tehran", "Piroozi");
    Person person("Ali", "87XYZ98772", address);
    }

    