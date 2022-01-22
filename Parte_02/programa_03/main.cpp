#include <iostream>
#include "SignUp.h"
#include "User.h"


using namespace std;



template<typename T>
    bool compare(T w, T b){ return w==b;}

 void test_exceptions()
 
 
 {   
     
    cout << "Tentando adicionar usuário com mesmo cpf: "<< endl;
    try
    {
        User<void> teste("michelle", 12345678911);
        User<void> teste1("joão", 12345678911);
        SignUp<void> cadastro;
        cadastro.addUser(teste);
        cadastro.addUser(teste1);
    }
    catch (const char* e) 
    {
        cout << "[ERRO]: "<< e << endl;
    }

    cout << "Tentando buscar usário com cpf inexistente: "<< endl;
    try
    {
        User<void> teste("michelle", 12345678911);
        User<void> teste1("joão", 12345672221);
        SignUp<void> cadastro;
        cadastro.addUser(teste);
        cadastro.addUser(teste1);
        cadastro.getUserForCPF(1);
    }
    catch (const char* e) 
    {
        cout << "[ERRO]: "<< e << endl;
    }

    cout << "Tentando buscar usário com nome inexistente: "<< endl;
    try
    {
        User<void> teste("michelle", 12345678911);
        User<void> teste1("joão", 12345672221);
        SignUp<void> cadastro;
        cadastro.addUser(teste);
        cadastro.addUser(teste1);
        cadastro.getUsersForName("marcos");
    }
    catch (const char* e) 
    {
        cout << "[ERRO]: "<< e << endl;
    }


    cout << "Tentando deletar usário com cpf inexistente: "<< endl;
    try
    {
        User<void> teste("michelle", 12345678911);
        User<void> teste1("joão", 12345672221);
        SignUp<void> cadastro;
        cadastro.addUser(teste);
        cadastro.addUser(teste1);
        cadastro.delUsersForCPF(1);
    }
    catch (const char* e) 
    {
        cout << "[ERRO]: "<< e << endl;
    }


    cout << "Tentando usar método de busca por cpf com zero usuários cadastrados: "<< endl;
    try
    {
        SignUp<void> cadastro;
        cadastro.getUserForCPF(12345678911);
    }
    catch (const char* e) 
    {
        cout << "[ERRO]: "<< e << endl;
    }

    cout << "Tentando usar método de busca por nome com zero usuários cadastrados: "<< endl;
    try
    {
        SignUp<void> cadastro;
        cadastro.getUsersForName("michelle");
    }
    catch (const char* e) 
    {
        cout << "[ERRO]: "<< e << endl;
    }

    cout << "Tentando usar método getUsers com zero usuários cadastrados: "<< endl;
    try
    {
        SignUp<void> cadastro;
        auto users = cadastro.getUsers();
    }
    catch (const char* e) 
    {
        cout << "[ERRO]: "<< e << endl;
    }

    cout << "Tentando usar método getUsersInSequence com zero usuários cadastrados: "<< endl;
    try
    {
        SignUp<void> cadastro;
        auto users = cadastro.getUsersInSequence();
    }
    catch (const char* e) 
    {
        cout << "[ERRO]: "<< e << endl;
    }


 }



int main()
{  
    
    {
     /*!-------------TESTE CLASSE USUÁRIO---------------------------!*/

        User<void> teste("michelle", 12345678911);
        User<void> teste1("joão", 76894561236);
        User<void> teste2("annie", 93217658316);
       
       

        cout << "\t\t\tTestando getName "<< endl;
        compare<string>(teste.getName(), "michelle")? std::cout<< "SUCESS \n": cout<< "ERRO \n" ;
        compare<string>(teste1.getName(), "joão")? std::cout<< "SUCESS \n": cout<< "ERRO \n" ;
        compare<string>(teste2.getName(), "annie")? std::cout<< "SUCESS \n": cout<< "ERRO \n" ;


        cout << "\t\t\tTestando getCpf "<< endl;
        compare<unsigned long>(teste.getCpf(), 12345678911)? std::cout<< "SUCESS \n": cout<< "ERRO \n" ;
        compare<unsigned long>(teste1.getCpf(), 76894561236)? std::cout<< "SUCESS \n": cout<< "ERRO \n" ;
        compare<unsigned long>(teste2.getCpf(), 93217658316)? std::cout<< "SUCESS \n": cout<< "ERRO \n" ;


        cout << "\t\t\tTestando getCredits "<< endl;
        compare<unsigned long>(teste.getCredits(), 10)? std::cout<< "SUCESS \n": cout<< "ERRO \n" ;
        compare<unsigned long>(teste1.getCredits(), 10)? std::cout<< "SUCESS \n": cout<< "ERRO \n" ;
        compare<unsigned long>(teste2.getCredits(), 10)? std::cout<< "SUCESS \n": cout<< "ERRO \n" ;

        cout << "\t\t\tTestando operador de incremento ++( prefix) "<< endl;
        ++teste;
        ++teste1;
        ++teste2;
        compare<unsigned long>(teste.getCredits(), 11)? std::cout<< "SUCESS \n": cout<< "ERRO \n" ;
        compare<unsigned long>(teste1.getCredits(), 11)? std::cout<< "SUCESS \n": cout<< "ERRO \n" ;
        compare<unsigned long>(teste2.getCredits(), 11)? std::cout<< "SUCESS \n": cout<< "ERRO \n" ;
       
       
        cout << "\t\t\tTestando operador de incremento ++ (posfix) "<< endl;
        teste++;
        teste1++;
        teste2++;
        compare<unsigned long>(teste.getCredits(), 12)? std::cout<< "SUCESS \n": cout<< "ERRO \n" ;
        compare<unsigned long>(teste1.getCredits(), 12)? std::cout<< "SUCESS \n": cout<< "ERRO \n" ;
        compare<unsigned long>(teste2.getCredits(), 12)? std::cout<< "SUCESS \n": cout<< "ERRO \n" ;


         cout << "\t\t\tTestando operador de decremento --( prefix) "<< endl;
        --teste;
        --teste1;
        --teste2;
        compare<unsigned long>(teste.getCredits(), 11)? std::cout<< "SUCESS \n": cout<< "ERRO \n" ;
        compare<unsigned long>(teste1.getCredits(), 11)? std::cout<< "SUCESS \n": cout<< "ERRO \n" ;
        compare<unsigned long>(teste2.getCredits(), 11)? std::cout<< "SUCESS \n": cout<< "ERRO \n" ;
       
       
        cout << "\t\t\tTestando operador de decremento  -- (posfix) "<< endl;
        teste--;
        teste1--;
        teste2--;
        compare<unsigned long>(teste.getCredits(), 10)? std::cout<< "SUCESS \n": cout<< "ERRO \n" ;
        compare<unsigned long>(teste1.getCredits(), 10)? std::cout<< "SUCESS \n": cout<< "ERRO \n" ;
        compare<unsigned long>(teste2.getCredits(), 10)? std::cout<< "SUCESS \n": cout<< "ERRO \n" ;

        cout << "\t\t\tTestando addCredits "<< endl;
        teste.addCredits(10);
        teste1.addCredits(20);
        teste2.addCredits(30);
        compare<unsigned long>(teste.getCredits(), 20)? std::cout<< "SUCESS \n": cout<< "ERRO \n" ;
        compare<unsigned long>(teste1.getCredits(), 30)? std::cout<< "SUCESS \n": cout<< "ERRO \n" ;
        compare<unsigned long>(teste2.getCredits(), 40)? std::cout<< "SUCESS \n": cout<< "ERRO \n" ;

        cout << "\t\t\tTestando removeCredits "<< endl;
        teste.removeCredits(10);
        teste1.removeCredits(20);
        teste2.removeCredits(30);
        compare<unsigned long>(teste.getCredits(), 10)? std::cout<< "SUCESS \n": cout<< "ERRO \n" ;
        compare<unsigned long>(teste1.getCredits(), 10)? std::cout<< "SUCESS \n": cout<< "ERRO \n" ;
        compare<unsigned long>(teste2.getCredits(), 10)? std::cout<< "SUCESS \n": cout<< "ERRO \n" ;

        cout << "\t\t\tTestando setName "<< endl;
        teste.setName("clara");
        teste1.setName("lucas");
        teste2.setName("ronny");
        compare<string>(teste.getName(), "clara")? std::cout<< "SUCESS \n": cout<< "ERRO \n" ;
        compare<string>(teste1.getName(), "lucas")? std::cout<< "SUCESS \n": cout<< "ERRO \n" ;
        compare<string>(teste2.getName(), "ronny")? std::cout<< "SUCESS \n": cout<< "ERRO \n" ;
        


    }

    {
        /*!-------------TESTE CLASSE CADASTRO---------------------------!*/
        User<void> teste("joão", 12345678911);
        User<void> teste1("maria", 76894561236);
        User<void> teste2("annie", 93217658316);
        teste.addCredits(10);
        teste1.addCredits(20);
        teste2.addCredits(30);

        SignUp<void> cadastro;

        cout << "\t\t\tTestando addUser "<< endl;

        cadastro.addUser(teste);
        cadastro.addUser(teste1);
        cadastro.addUser(teste2);

        cout << "\t\t\tTestando getUserForCpf "<< endl;
        User<void> u1 =cadastro.getUserForCPF(12345678911);
        User<void> u2 =  cadastro.getUserForCPF(76894561236);
        User<void> u3= cadastro.getUserForCPF(93217658316);

        cout << "\t\t\tTestando getUserName "<< endl;
        auto u4 = cadastro.getUsersForName("joão");
        auto u5 = cadastro.getUsersForName("maria");
        auto u6 = cadastro.getUsersForName("annie");

        cout << "\t\t\tTestando getUsers "<< endl;

        map<unsigned long, User<void>> users = cadastro.getUsers();

        cout << "Todos os usuários cadastrados: ";

        for (auto &&i : users)
        {
            cout << "["<<i.second.getName()<< "] ";
        }

        cout << endl; cout << "Testando dgetUsersInSequence "<< endl;

        map<unsigned long, User<void>> users1 = cadastro.getUsersInSequence();

        for (auto i : users1)
        {
            cout<< "Nome do usuário: [" << i.second.getName() << "]  | seu crédito: " << i.second.getCredits() << endl;
        }
        

        cout << "\t\t\tTestando delUssersForCpf "<< endl;
         
        cadastro.delUsersForCPF(12345678911);
        cadastro.delUsersForCPF(76894561236);
        cadastro.delUsersForCPF(93217658316);



    }


    {   

         /*!-------------TESTE EXCEÇÕES---------------------------!*/

        cout << "----Tentando criar um usuário com nome inválido----"<< endl;
        try
        {
            User<void> teste("", 12345678911);
        }
        catch (const char* e) 
        {
            cout << "[ERRO]: "<< e << endl;
        }
     
        cout << "----Tentando adicionar usuário com mesmo cpf----"<< endl;
        try
        {
            User<void> teste("michelle", 12345678911);
            User<void> teste1("joão", 12345678911);
            SignUp<void> cadastro;
            cadastro.addUser(teste);
            cadastro.addUser(teste1);
        }
        catch (const char* e) 
        {
            cout << "[ERRO]: "<< e << endl;
        }

        cout << "----Tentando buscar usário com cpf inexistente----"<< endl;
        try
        {
            User<void> teste("michelle", 12345678911);
            User<void> teste1("joão", 12345672221);
            SignUp<void> cadastro;
            cadastro.addUser(teste);
            cadastro.addUser(teste1);
            cadastro.getUserForCPF(1);
        }
        catch (const char* e) 
        {
            cout << "[ERRO]: "<< e << endl;
        }

        cout << "----Tentando buscar usário com nome inexistente----"<< endl;
        try
        {
            User<void> teste("michelle", 12345678911);
            User<void> teste1("joão", 12345672221);
            SignUp<void> cadastro;
            cadastro.addUser(teste);
            cadastro.addUser(teste1);
            cadastro.getUsersForName("marcos");
        }
        catch (const char* e) 
        {
            cout << "[ERRO]: "<< e << endl;
        }


        cout << "----Tentando deletar usário com cpf inexistente----"<< endl;
        try
        {
            User<void> teste("michelle", 12345678911);
            User<void> teste1("joão", 12345672221);
            SignUp<void> cadastro;
            cadastro.addUser(teste);
            cadastro.addUser(teste1);
            cadastro.delUsersForCPF(1);
        }
        catch (const char* e) 
        {
            cout << "[ERRO]: "<< e << endl;
        }


        cout << "----Tentando usar método de busca por cpf com zero usuários cadastrados----"<< endl;
        try
        {
            SignUp<void> cadastro;
            cadastro.getUserForCPF(12345678911);
        }
        catch (const char* e) 
        {
            cout << "[ERRO]: "<< e << endl;
        }

        cout << "----Tentando usar método de busca por nome com zero usuários cadastrados----"<< endl;
        try
        {
            SignUp<void> cadastro;
            cadastro.getUsersForName("michelle");
        }
        catch (const char* e) 
        {
            cout << "[ERRO]: "<< e << endl;
        }

        cout << "----Tentando usar método getUsers com zero usuários cadastrados---- "<< endl;
        try
        {
            SignUp<void> cadastro;
            auto users = cadastro.getUsers();
        }
        catch (const char* e) 
        {
            cout << "[ERRO]: "<< e << endl;
        }

        cout << "----Tentando usar método getUsersInSequence com zero usuários cadastrados----"<< endl;
        try
        {
            SignUp<void> cadastro;
            auto users = cadastro.getUsersInSequence();
        }
        catch (const char* e) 
        {
            cout << "[ERRO]: "<< e << endl;
        }


    }


   



    return 0;
}