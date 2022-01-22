#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>


template < typename T>
class User
{

public:

    using value_type = unsigned long;

public:


    User(std::string name_, value_type cpf_)
    {
        this->setName(name_);
        this->cpf = cpf_;
    }
    ~User(){/*empty*/}

    //getter methods
    std::string getName(){return this->name;};
    value_type getCpf(){return this->cpf;};
    value_type getCredits(){return this->credits;};

    //setter methods
    void setName(std::string name_)
    {
        if(name_.compare("")!=0){this->name = name_ ;}
        else{throw "Nome inválido!";}
    }

    // extra methods

    bool addCredits(value_type credits_)
    {
        if(credits_>0)
        {
            this->credits+=credits_;
            return true;
        }
        return false;
    }

    bool removeCredits( value_type credits_)
    {
        if(credits_<=this->credits)
        {
            this->credits-=credits_;
            return true;
        }
        return false;
    }


    //posfix
    User operator++(int) 
    {
        User user_aux = *this;
        this->addCredits(1);
        return user_aux;
    }
    //prefix
    User operator++() //????
    {
       this->addCredits(1);
       return*this;
    }

     User operator--() //prefix
    {
       
        this->removeCredits(1);
       
        return *this;
    }

     User operator--(int)  //posfix
    {
        User user_aux = *this;
       this->removeCredits(1);
       return user_aux;
       
    }



    private:
    std::string name; 
    value_type cpf;
    value_type credits = 10;
};


#endif 