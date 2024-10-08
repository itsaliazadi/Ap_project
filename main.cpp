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

        // << operator prints the whole address.
        std::ostream& operator<<(std::ostream& os) const {
            os << "Country: " << country << ", City: " << city << ", Street: " << street;
            return os;
        }

        // >> operator asks the user for their address.
        std::istream& operator>>(std::istream& is) {
            std::cout << "Enter country: ";
            is >> country;
            std::cout << "Enter city: ";
            is >> city;
            std::cout << "Enter street: ";
            is >> street;
            return is;
        }

        // Getters and setters
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

            // Vaidating the id of the user
            if (validate(ID)){
                name = Name;
                id = ID;
                address = ad;
            }

            else{
                std::cout<<"Invalid id..."<<"\n";
            }

        }

        // Copy constructor
        Person(Person& object){
            name = object.name;
            id = object.id;
            address = object.address;
        }

        // << operator prints the person's information.
        std::ostream& operator<<(std::ostream& os) {
            os << "Name: " << name << ", ID: " << id << ", Address: " << address.getCountry() << "," << address.getCity() << "," << address.getStreet() << "\n";
            return os;
        }

        // >> operator asks the user for their address.
        std::istream& operator>>(std::istream& is) {
            std::cout << "Enter name: ";
            is >> name;
            std::cout << "Enter id: ";
            is >> id;
            return is;
        }

        // Overloading the = operator
        Person& operator=(const Person& other) {
            if (this != &other){  
                name = other.name;
                id = other.id;
                address = other.address;
            }
            return *this;
        }

        // Getters and setters
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

        // The validate function validates users' ids using regex.
        bool validate(std::string ID){

            std::regex format("^(8[4-9]|9[0-9])\\D{1,3}[0-35-9]{5}$");

            if (std::regex_match(ID, format)) {
                return true;
            } else {
                return false;
            }
        }
};



class Employee{
    public:
        std::string name;
        std::string id;
        Address address;

    private:
        int hourWork;
        int salaryPerHour;
        int workToDo;
        int workDone;

    public:
        Employee(std::string Name="", std::string ID="", Address ad = Address(), int HourWork=0, int SalaryPerHour=0, int WorkToDo=0, int WorkDone=0){
            
            // Validating the employee's id
            if (validate(ID)){
                name = Name;
                id = ID;
                address = ad;
                hourWork = HourWork;
                salaryPerHour = SalaryPerHour;
                workToDo = WorkToDo;
                workDone = WorkDone;
            }

            else{
                std::cout<<"Invalid id..."<<"\n";
            }

        }

        // Copy constructor
        Employee(Employee& object){
            name = object.name;
            id = object.id;
            address = object.address;
            hourWork = object.hourWork;
            salaryPerHour = object.salaryPerHour;
            workToDo = object.workToDo;
            workDone = object.workDone;
        }

        // Getters and setters
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

        int getHourWork(){
            return hourWork;
        }

        void setHourWork(int HourWork){
            hourWork = HourWork;
        }

        int getSalary(){
            return salaryPerHour;
        }

        void setSalryPerHour(int Salary){
            salaryPerHour = Salary;
        }

        int getWorkToDo(){
            return workToDo;
        }

        void setWorkToDo(int WorkToDo){
            workToDo = WorkToDo;
        }

        int getWorkDone(){
            return workDone;
        }

        void setWorkDone(int WorkDone){
            workDone = WorkDone;
        }

        // << operator prints the employee's information.
        std::ostream& operator<<(std::ostream& os) {
            os << "Name: " << name << ", ID: " << id << ", Address: " << address.getCountry() << "," << address.getCity() << "," << address.getStreet() << ", HourWork:" << getHourWork() << ", SalaryPerHour:" << getSalary() << ", WorkToDo:" << getWorkToDo() << ", WorkDone:" << getWorkDone() << "\n";
            return os;
        }

        // >> operator asks the user for their address.
        std::istream& operator>>(std::istream& is) {
            std::cout << "Enter name: ";
            is >> name;
            std::cout << "Enter id: ";
            is >> id;
            return is;
        }

        // Overloading the = operator
        Employee& operator=(const Employee& other) {
            if (this != &other){  
                name = other.name;
                id = other.id;
                address = other.address;
                hourWork = other.hourWork;
                salaryPerHour = other.salaryPerHour;
                workToDo = other.workToDo;
                workDone = other.workDone;
            }
            return *this;
        }

        // The validate function validates users' ids using regex.
        bool validate(std::string ID){

            std::regex format("^(8[4-9]|9[0-9])\\*\\D{1,2}[0-35-9]{5}$");

            if (std::regex_match(ID, format)) {
                return true;
            } else {
                return false;
            }
        }

        double calculateSalary(){

            double ratio = (static_cast<double>(workDone)/workToDo);
            double preSalary = hourWork * salaryPerHour;
            double finalSalary = preSalary * (1 - ratio);

            return finalSalary;
            
        }

        double efficiency(){

            double eff = (static_cast<double>(workDone) / hourWork)*100;// Casting the integer to double
            return eff;

        }
};


class Point{

    private:
        int x, y;
    
    public:
        Point(int X=0, int Y=0){
            x = X;
            y = Y;
        }

        // Copy constructor
        Point(Point& object){
            x = object.x;
            y = object.y;
        }

        Point operator+(const Point& other) const {
            return Point(x + other.x, y + other.y);
        }

        Point operator-(const Point& other) const {
            return Point(x - other.x, y - other.y);
        }

        Point& operator=(const Point& other) {
            if (this != &other){  
                x = other.x;
                y = other.y;
            }
            return *this;
        }

        void operator/=(int number) {
            if (number == 0){
                std::cout<<"Invalid value!"<<"\n";
            }
            else{
                x /= number;
                y /= number;
            }
        }


        // Checking their distances from point(0,0)
        bool operator>=(const Point& other) const {
            if ((x*x + y*y) >= (other.x*other.x + other.y*other.y)){
                return true;
            }
            else{
                return false;
            }
        }

        // Getters and setters
        int getX(){
            return x;
        }

        void setX(int X){
            x = X;
        }

        int getY(){
            return y;
        }

        void setY(int Y){
            y = Y;
        }
};


class Rectangle{

    private:
        Point startPoint;
        int width;
        int height;
    
    public:
        Rectangle(int Height=0, int Width=0, Point StartPoint = Point()){
            height = Height;
            width = Width;
            startPoint = StartPoint;
        }

        // Copy constructor
        Rectangle(Rectangle& object){
            height = object.height;
            width = object.width;
            startPoint = object.startPoint;
        }

        // Getters and setters
        int getHeight(){
            return height;
        }

        void setHeight(int Height){
            height = Height;
        }

        int getWidth(){
            return width;
        }

        void setWidth(int Width){
            width = Width;
        }

        void operator+=(Rectangle& other) {
            if ((startPoint.getX() == other.startPoint.getX()) && (startPoint.getY() == other.startPoint.getY())){
                height = std::max(height, other.getHeight());
                width = std::max(width, other.getWidth());
            }
            else{
                std::cout<<"The start points are not the same!"<<"\n";
            }
        }

        void operator-=(Rectangle& other) {
            if ((startPoint.getX() == other.startPoint.getX()) && (startPoint.getY() == other.startPoint.getY())){
                height = std::min(height, other.getHeight());
                width = std::min(width, other.getWidth());
            }
            else{
                std::cout<<"The start points are not the same!"<<"\n";
            }
        }

        void operator/(Rectangle& other) {
            startPoint.setX((startPoint.getX() + other.startPoint.getX()) / 2);
            startPoint.setY((startPoint.getY() + other.startPoint.getY()) / 2);
            height = height / other.height;
            width = width / other.width;
        }

        bool collisionDetection(Rectangle rectangle){
            bool collision = !(startPoint.getX() + width < rectangle.startPoint.getX() || rectangle.startPoint.getX() + rectangle.getWidth() < startPoint.getX() || startPoint.getY() + height < rectangle.startPoint.getY() || rectangle.startPoint.getY() + rectangle.height < startPoint.getY());
            return collision;
        }

};

int main(){

    Address address("Iran", "Tehran", "Piroozi");
    Person person("Ali", "87ygh12378", address);
    Employee employee("Ali", "87*gh12378", address);
    employee.setHourWork(10);
    employee.setSalryPerHour(10);
    employee.setWorkToDo(5);
    employee.setWorkDone(3);
    std::cout<<"salary:";
    std::cout<<employee.calculateSalary()<<"\n";
    std::cout<<"efficiency:";
    std::cout<<employee.efficiency()<<"%";

    Point p1(1,2);
    Point p2(1, 2);

    Rectangle R1(1, 2, p1);
    Rectangle R2(2, 3, p2);

    R2 -= R1;

    if (R1.collisionDetection(R2)){
        std::cout<<"R1 and R2 have collided."<<"\n";
    }

    }

    