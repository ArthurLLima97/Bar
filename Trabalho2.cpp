#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

/*
class client {
public:
    string nome;
		string cpf;
		string telefone;
		string card;
	
	client(string nome, string cpf, string telefone, string card) {
		this->nome = nome;
		this->cpf = cpf;
		this->telefone = telefone;
		this->card = card;
	}
};
*/
string a;
double valor = 0;
double atual = 0; 
double bar = 0; 

void cadastro();
void cadastrar();
void bar1();
void caixa();
void menu();
void searchFile();
void writeFile();







int main() {
  
	menu();
	
}

void cadastrar(vector<string>cliente)
{
    ofstream clientes;
    clientes.open("clientes.txt");
    for(int i = 0; i < cliente.size(); i++) {
        clientes << cliente[i] << endl;
    }

    clientes.close();
}

void menu() {
	//system("cls");
	int n;
	cout << "------Lima's & Camargo's BAR------" << endl;
	cout << endl;
	cout << "1 - Cadastro de Clientes" << endl;
	cout << "2 - Bar" << endl;
	cout << "3 - Caixa" << endl;
  cout << "4 - Sair" << endl;
	cout << endl;
	cout << "Informe a operação:" ;
	cin >> n;

	  switch (n)
	{
	case 1: cadastro();
	case 2: bar1();
	case 3: caixa();
  case 4: searchFile();
  case 0: menu();
  default: break;
	}

}

	void cadastro() {
    int n=1;
    vector<string>cliente;
    string nome;
		string cpf;
		string telefone;
		string card;

    while(n==1){
	
		cout << "------Cadastro de Clientes------" << endl;
		cout << "Informe o Nome:" << endl;
	  cin >> nome;
    cout << "Informe o CPF:" << endl;
		cin >> cpf;
		cout << "Telefone:";
		cin >> telefone;
		cout << "Informe o Card ID" << endl;
		cin >> card;

    cliente.push_back(nome);
    cliente.push_back(cpf);
    cliente.push_back(telefone);
    cliente.push_back(card);
    cliente.push_back("0");


   // client temp(nome, cpf, telefone, card);

	//	cliente.push_back(temp);

    cliente.push_back("0");

    cout << "Você deseja cadastrar mais alguem?" << endl;
    cout << "1 - SIM" << endl;
    cout << "2 - NÃO" << endl;
    cin >> n;
  
     }

     
		cadastrar(cliente);

    menu();

	}

	void bar1() {
		//system("cls");

   int b = 0;
   int c = 1;

   cout << endl;
   cout << "----------------Comidas-------------" << endl;
   cout << "1 - Batata fritas c/ Queijo..R$25.00" << endl;
   cout << "2 - Batata fritas s/ Queijo..R$20.00" << endl;
   cout << "3 - Polenta s/ Queijo........R$25.00" << endl;
   cout << "4 - Polenta c/ Queijo........R$20.00" << endl;
   cout << "5 - Hambúrguer...............R$15.00" << endl;
   cout << "----------------Drinks--------------" << endl; 
   cout << "6 - Refrigerante.............R$5.00" << endl;
   cout << "7 - Cerveja..................R$9.00" << endl;
   cout << "8 - Água.....................R$2.50" << endl;
   cout << "9 - Tropical Gin.............R$15.00" << endl;
   cout << "10 - Vodka com energetico....R$20.00" << endl;
   cout << endl;
 
   cout << "Informe o Nome?:" << endl;
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
  menu();
	}

	void caixa() {
		//system("cls");
		int a;
		cout << "Informe o ID:" << endl;
		cin >> a;
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
