#include <iostream>
#include <vector>
#include<string>

using namespace std;

class User
{

    public:
        string name;
};

vector<User>sign_up;

bool verify_account(string user_name)
{
    for (auto i : sign_up)
    {
        if(i.name.compare(user_name) == 0)
        {
            cout << "Nome de usuário inválido, por favor tente novamente!" << endl;
            return false;
        } 
    }
    
    return true;
}

bool signUp_newUser()
{
    string x;
    cout << "Deseja cadastrar novo usuário? ";
    getline(cin , x);

    if(x.compare("sim") == 0)
    {
         User new_user;
        do
        {
            cout << "informe o nome do usuário: ";
            getline(cin, new_user.name);

        } while (!verify_account(new_user.name));
        
        sign_up.push_back(new_user);

        return true;
    }
    
    return false;
}


int main(void)
{
    while(signUp_newUser()){cout<< "Novo usuário cadastrado com sucesso!" << endl;}

    cout<< "Finalizando cadastro de usuário!" << endl;

    return 0;
}