#include <iostream>
#include <vector>
#include <clocale>
#include <conio.h>

using namespace std;

class Vendedor
{
private:
    int nrVendedor;
    string nome;
    string zona;
    float valorVendas;

public:
    // setters
    void setNrVendedor(int num)
    {
        nrVendedor = num;
    }
    void setNome(string VendedorNome)
    {
        nome = VendedorNome;
    }
    void setNrVendas(string zonaVendas)
    {
        zona = zonaVendas;
    }
    void setZona(string zonaVendas)
    {
        zona = zonaVendas;
    }
    void setValorVendas(float vendas)
    {
        valorVendas = vendas;
    }
    // criar os getters
    int getNrVendedor()
    {
        return nrVendedor;
    }
    string getnome()
    {
        return nome;
    }
    string getzona()
    {
        return zona;
    }
    float getValor()
    {
        return valorVendas;
    }
    void registar()
    {
        system("cls");
        cout << "Registar Vendedor" << endl
             << "Número de vendedor: ";
        cin >> nrVendedor;
        cout << "Nome de vendedor: ";
        cin >> nome;
        cout << "Zona: ";
        cin >> zona;
        cout << "Valor de vendas: ";
        cin >> valorVendas;
    }

    void mostraLista()
    {
        cout << nrVendedor << "\t" << nome << "\t" << zona << "\t" << valorVendas;
    }
};
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int op, numEliminar, numProcurar, posicao = 0;
    string zonaProcurar;
    int totalVendas, valor;
    bool existe = false;
    // vector da class Vendedor
    vector<Vendedor> V;
    // Objeto da class Vendedor
    Vendedor pessoa;

    while (op != 6)
    {
        system("cls");
        cout << "Empresa Alfa, S.A." << endl
             << "1-Registar vendedor" << endl
             << "2-Mostrar os dados de um vendedor especifico" << endl
             << "3-Listar as vendas de uma determinada zona (o utilizador insere a zona)" << endl
             << "4-Listar todas as vendas apresentandoum total final" << endl
             << "5-Eliminar um registo (o utilizador indica o número de registo)" << endl
             << "6-Sair" << endl
             << "Digite a sua opção: ";
        cin >> op;
        switch (op)
        {
        case 1:
            pessoa.registar();
            V.push_back(pessoa);
            break;
        case 2:
            system("cls");
            cout << "Localizar aluno" << endl;
            cout << "Digite o numero do Vendedor:";
            cin >> numProcurar;
            existe = false;
            for (unsigned int i = 0; i < V.size(); i++)
            {
                if (V[i].getNrVendedor() == numProcurar)
                {
                    cout << endl
                         << "Nome:" << V[i].getnome();
                    cout << endl
                         << "Zona:" << V[i].getzona();
                    cout << endl
                         << "Vendas:" << V[i].getValor();
                    existe = true;
                    break;
                }
            }
            if (!existe)
            {
                cout << "O numero do vendedor introduzido, não consta na lista de vendedores." << endl;
            }
            cout << endl
                 << "Pressione Enter para continuar." << endl;
            getch();
            break;
        case 3:
            system("cls");
            cout << "Localizar vendas em Zona" << endl;
            cout << "Digite a zona:";
            cin >> zonaProcurar;
            existe = false;
            for (unsigned int i = 0; i < V.size(); i++)
            {
                if (V[i].getzona() == zonaProcurar)
                {
                    cout << endl
                         << "Nome:" << V[i].getnome();
                    cout << endl
                         << "Zona:" << V[i].getzona();
                    cout << endl
                         << "Vendas:" << V[i].getValor();
                    existe = true;

                    totalVendas = totalVendas + V[i].getValor();
                    break;
                }
                cout << endl
                     << "Total de vendas: " + totalVendas;
            }
            if (!existe)
            {
                cout << "O numero do vendedor introduzido, não consta na lista de vendedores." << endl;
            }
            cout << endl
                 << "Pressione Enter para continuar." << endl;
            getch();
            break;
        case 4:
            system("cls");
            cout << "Nr\tNome\tZona\tVendas" << endl;
            for (unsigned int i = 0; i < V.size(); i++)
            {
                V[i].mostraLista();
                cout << endl;
            }
            cout << "Fim da listagem" << endl
                 << "Pressione qualquer tecla para sair...";
            getch();
            break;
        case 5:
            system("cls");
            cout << "Eliminar registo" << endl
                 << "Indique numero do vendedor que pretende eliminar: ";
            cin >> numEliminar;
            existe = false;
            for (unsigned int i = 0; i < V.size(); i++)
            {
                if (V[i].getNrVendedor() == numEliminar)
                {
                    posicao = i;
                    existe = true;
                    break;
                }
            }
            if (!existe)
            {
                cout << endl
                     << "Numero de Vendedor inexistente na lista";
            }
            else
            {
                // eliminar o registo
                V.erase(V.begin() + posicao);
                cout << endl
                     << "Foi retirado o vendedor com o numero " + numEliminar;
            }
            break;
        case 6:
            cout << "Fim do programa...";
            getch();
            break;
        default:
            cout << "Opção inválida, tente novamente" << endl;
            getch();
        }
    }
}