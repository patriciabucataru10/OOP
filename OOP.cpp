

#include <iostream>
using std::string;

//Abstraction
class AbstractEmployee
{
    virtual void AskForPromotion()=0;
};
class Employee:AbstractEmployee
{
protected:
//Incapsulare
    string Name;
    string Company;
    int Age;

public:
//Getters and setters
//Pentru nume
    void setName(string name)
    {
        Name = name;
    }
    string getName()
    {
        return Name;
    }
//Pentru varsta
    void setAge(int age)
    {
        //Conditie pentru setter
        if (age>=18 && age<100)
            Age = age;
    }
    int getAge()
    {
        return Age;
    }
//Pentru companie
    void setComp(string companie)
    {
        Company = companie;
    }
   string getComp ()
    {
        return Company;
    }

//Constructorul clasei
    Employee(string name, string company, int age)
    {
        Name = name;
        Company = company;
        Age = age;
}
//Metoda ce afiseaza atributele obiectului respectiv
    void IntroduceYourself()
    {
        std::cout << "Name - " << Name << std::endl;
        std::cout << "Company - " << Company << std::endl;
        std::cout << "Age - " << Age << std::endl;
    }
    void AskForPromotion()
    {
        if (Age > 30)
            std::cout << "Promovat.";
        else
            std::cout << "Nu va fi promovat.";
    }
    void Work()
    {
        std::cout << Name << "cverifica e-mailuri zi si noapte" << std::endl;

    }
};
//Inheritance/Mostenire
class Developer:public Employee
{
public:
    string FavProgrammingLang;
    Developer(string name, string company, int age, string favprogramminglang) :Employee(name,company,age)
    {
      
        FavProgrammingLang = favprogramminglang;
    }

    void FixBug()
    {
        std::cout << getName() << " fixed bug using " << FavProgrammingLang << std::endl;

    }
//Polymorphism
    void Work()
    {
        std::cout << Name << " scrie cod zi si noapte" << std::endl;

    }
};
int main()
{
    string numea;
    Employee employee1 = Employee("Patricia", "Nu este angajat/a", 21);
    Employee employee2 = Employee("Jon", "Amazon", 32);

   
    employee2.IntroduceYourself();

    std::cout << "Numele primului angajat este " << employee1.getName()<<std::endl;
    employee1.setAge(13);
    employee1.IntroduceYourself();
    Developer d=Developer ("Alex","Nu este angajat/a",22,"C++");
    d.FixBug();
    d.Work();
    employee1.Work();
}

