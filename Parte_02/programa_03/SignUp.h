#ifndef SIGN_UP_H
#define SIGN_UP_H


#include "User.h"
#include<map>
#include<algorithm>
#include<vector>
#include <algorithm>
#include <iterator>

using namespace std;

template <typename U>

class SignUp{

  public:

    using my_pair = std::pair<unsigned long, User<void>>;
    using my_map = std::map<unsigned long, User<void>>;
    using user_type = User<void>;

  public:

    //constructor
    SignUp(){};
    //destrutor
    ~SignUp()
    { /*empty*/};

    //adiciona um novo usuário
    void addUser(user_type new_user)
    {
      //verifica se o usuario já existe
      if(!verify_user(new_user)){this->users.insert({ new_user.getCpf(), new_user});}
      else{throw "Usuário informado já está cadastrado!";}

      cout<<"Usuário cadastrado com sucesso!"<< endl;
    }

    //deleta usuário
    void delUsersForCPF(unsigned long cpf_)
    {
      this->empty();//primeiro verifica se existem usuários cadastrados
      auto user_del =  users.find(cpf_); //busca usuário
      if(user_del==users.end()){throw "Usuário informado não pode ser deletado!";} //se o usuário não for encontrado lança uma exceção
      users.erase(user_del->first); //se o usuário existir deleta ele
      cout<< "usuário deletado com sucesso!"<< endl;
    }

  //busca usuário por cpf
    user_type getUserForCPF(unsigned long cpf_)
    {
        this->empty(); //primeiro checa se existem usuarios cadastrados
        auto search_user = users.find(cpf_);//faz a busca pelo usuário
        if(search_user==users.end()) {throw "cpf informado não corresponde a nem um dos usuários cadastrados";} //se o usuário não for encontrado lança uma exceção
        cout<<"o cpf informado corresponde ao usuário: "<< search_user->second.getName() << endl;
        return search_user->second;
    }
 
   
    my_map::iterator getUsersForName( string name)
    {
       this->empty(); //primeiro checa se existem usuarios cadastrados
      my_map users_list;//lista que será retornada com os usuários

      for (auto verify : users){if(verify.second.getName()==name){users_list.insert(verify);}}//verifica se os usuários com o nome existem e adiciona na lista
      
      
      if(users_list.empty()){throw "Não existe usuário com o nome informado!";}//se a lista estiver vazia lança uma execeção

      cout<<"Usuário encontrado!"<< endl;

      return users_list.begin();
    }


    my_map & getUsers()
    { 
      //verifica se existem usuário cadastrados
      this->empty();
      return this->users;
    }

 


//ordernar 
//cria um novo map
  my_map getUsersInSequence()
  {
    this->empty(); //primeiro checa se existem usuarios cadastrados
    my_map sequence;
    vector<unsigned long> credits;

    for (auto u : users)
    {
      size_t credit = u.second.getCredits();
      if(find(credits.begin(), credits.end(), credit)==credits.end()){credits.push_back(u.second.getCredits());} //passando todos os creditos para um vector
    }

    sort(credits.begin(), credits.end());
      
    int key{0};
    for (auto a: credits)
    {
      for (auto u : users)
      {
        if(a==u.second.getCredits())
        {
          key++; //atualizando a key do elemento
          my_pair user(key, u.second);
          sequence.emplace(user);
        }
      }
       
    }

    return sequence;
  }

  private:

    my_map users;

    //método que verifica se usúario informado existe ou não
    bool verify_user( user_type user)
    {
      for (auto& i : users){if(i.first==user.getCpf()){ return true;}}
      return false;
    }

    //lança uma execeção caso não tenham usuários cadastrados
    void empty(){if(users.empty()){ throw "Não existem usuários cadastrados!";}}

};


#endif

