#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "cliente.h"

using namespace std;



string a;
double valor = 0;
double atual = 0; 
double bar = 0; 



void menu() {
  
  vector<cad>cliente;

	while(1){
  int n;
	cout << "------Lima's & Camargo's BAR------" << endl;
	cout << endl;
	cout << "1 - Cadastro de Clientes" << endl;
	cout << "2 - Bar" << endl;
  cout << "3 - Sair" << endl;
	cout << endl;
	cout << "Informe a operação:" ;
	cin >> n;

	     switch (n)
    	{
	    case 1: cadastro(cliente);
      break;
	    case 2: bar1();
      break;
      case 3: exit(0);
      }
	}

}



	void cadastro( vector<cad>cliente ) {
    int m=1;

    string nome;
		string cpf;
		string telefone;
		string card;

    while(m==1){
	
		cout << "\n------Cadastro de Clientes------\n" << endl;
		cout << "Informe o Nome:";
	  cin >> nome;
    cout << "Informe o CPF:";
		cin >> cpf;
		cout << "Telefone:";
		cin >> telefone;
		cout << "Informe o Card ID";
		cin >> card;

    
    cad c(nome, cpf, telefone, card);
	  
    cliente.push_back(c);


    cout << "Você deseja cadastrar mais alguem?" << endl;
    cout << "1 - SIM" << endl;
    cout << "2 - NÃO" << endl;
    cin >> m;
  
     }



    cadastrar(cliente);

	}



void cadastrar(vector<cad> cliente)
{
    ofstream clientes;
    clientes.open("clientes.txt");
    for(int i = 0; i < cliente.size(); i++) {
        clientes << cliente[i] << endl;
    }

    clientes.close();
}




	void bar1() {
		

   int b = 0;
   int c = 1;

  cardapio();

   cout << "Informe o Nome?:";
	 cin >> a;

   while (c == 1){ 

  cout << "O que você Deseja? (0 para sair)" << endl;
	cin >> b;

	 switch (b)
	{
	case 1: 
  valor = valor + 25;
  break;
	case 2: 
  valor = valor + 20;
  break;
	case 3: valor = valor + 25;
  break;
  case 4: valor = valor + 20;
  break;
  case 5: valor = valor + 15;
  break;
  case 6: valor = valor + 5;
  break;
  case 7: valor = valor + 9;
  break;
  case 8: valor = valor + 2.5;
  break;
  case 9: valor = valor + 15;
  break;
  case 10: valor = valor + 20;
  break;
  default: c=0;
	}
  
  }

  cout << "Valor = " << valor << endl;

  searchFile();

}



void cardapio(){

ifstream menu;
string temp;
cout << endl;
menu.open("Comidas&Drinks.txt");

  for(int i=0; i < 12; i++)
  {
  getline(menu, temp);
  cout << temp << endl;
  }

menu.close();
}



	

void searchFile()
{
	fstream dataIn;

	dataIn.open("clientes.txt");

	string temp;
	string line;

 	bar = valor;

	if (dataIn.is_open())  // Registra o valor que está na comanda
	{
		while (getline(dataIn, temp))
		{
			line.append(temp);

			if (line.find(a) != string::npos)
			{
        for(int i=0; i < 3; i++)
        {
        getline(dataIn, temp);
        }
         dataIn >> atual;
         cout << "Total da Comanda: R$" << atual << endl;
  
				break;
			}
		}
		dataIn.close();
	}
  
  writeFile();
}

void writeFile()
{
  fstream dataOut;

  string temp2;
	string line2;

  bar = valor;

  dataOut.open("clientes.txt");

if (dataOut.is_open())  // Grava o valor lido
	{
		while (getline(dataOut, temp2))
		{
			line2.append(temp2);

			if (line2.find(a) != string::npos)
			{
      for(int i=0; i < 3; i++)
        {
        getline(dataOut, temp2);
        }
        dataOut << atual + bar << endl; 
        cout << "Valor atual da Comanda: R$" << atual + bar << endl;
				break;
			}
		}
		dataOut.close();
	}
  cout << endl;
  cout << endl;
}




int main() { 
  
	menu(); 
	
	return 0;
}

