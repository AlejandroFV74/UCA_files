/*El aviario local ha decido contratarte junto a un fotógrafo de alto nivel, la semana
pasada una jaula sufrió un desperfecto y se cree que algunas especies podrían haber
escapado, tú junto al fotógrafo deberán identificar cuales se han dado a la fuga.
Deberá crear un programa que almacene N Aves (basadas en la lista original del
aviario), cada registro de Ave deberá contener:
- nombre
- color principal
- fecha en que ingresó al aviario
- un indicador de si ha sido o no fotografiada.
Considerar que pueden haber errores al ingresar los registros de las aves, por lo cual
se debe crear dos funciones que permitan modificar el nombre y el color de cualquier
ave previamente registrada.Adicionalmente, se solicita crear una validación para la
función que modifique el indicador de si ha sido o no fotografiada. En caso de haber
sido fotografiada y se llame a la función esta deberá mostrar un mensaje
personalizado indicando que ya fue previamente fotografiada */

#include <iostream>
#include <ctime>

using namespace std;

struct Register
{
    string name;
    string color;
    string incomeDate;
    string photographed;
    int amaunt;
} regist[4];

bool answer = false;

void modifyName(string newName, struct Register &r);
void modifyColor(string newColor, struct Register &r);

int main()
{
    int option, position, optionMod, arrayPosition;
    string newName, newColor;

    do
    {

        cout << "What would you like to do: " << endl;
        cout << "1- Register a new bird." << endl;
        cout << "2- Modifie dates of an already registered bird." << endl;
        cout << "3- See saved data birds." << endl;
        cout << "4- Exit program. " << endl;

        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Enter bird data: " << endl;

            for (int j = 0; j < 4; j++)
            {
                cout << "name: " << endl;
                cin >> regist[j].name;
                cout << "color: " << endl;
                cin >> regist[j].color;
                cout << "Income date: " << endl;
                cin >> regist[j].incomeDate;
                cout << "Already been photographed: " << endl;
                cin >> regist[j].photographed;
                cout << "Amount: " << endl;
                cin >> regist[j].amaunt;

                char moreBirds;
                cout << "Do you want to enter more birds? (y/n): " << endl;
                cin >> moreBirds;

                if (moreBirds != 'y' && moreBirds != 'Y')
                {
                    break;
                }
            }
            break;

        case 2:
            cout << "What would you like to modifie: " << endl;
            cout << "1- Name." << endl;
            cout << "2- Color." << endl;
            cin >> optionMod;
            if (optionMod == 1)
            {
                cout << "Enter the new name: " << endl;
                cin >> newName;
            }
            else
            {
                cout << "Enter the new color: " << endl;
                cin >> newColor;
            }

            cout << "From which bird you'll change the data: " << endl;
            cin >> position;

            if (optionMod == 1)
            {
                modifyName(newName, regist[position]);
            }
            else
            {
                modifyColor(newColor, regist[position]);
            }

            break;
        case 3:
            for (int i = 0; i < 4; i++)
            {
                cout << "Bird number: " << i << endl;
                cout << "Name: " << regist[i].name << endl;
                cout << "Color: " << regist[i].color << endl;
                cout << "Income date: " << regist[i].incomeDate << endl;
                cout << "Already been photographed: " << regist[i].photographed << endl;
                cout << "Amaunt registered: " << regist[i].amaunt << endl;
                cout << "------------------------------------------------------" << endl;
            }

            break;
        case 4:
            break;

        default:
            cout << "Invalid option." << endl;
            break;
        }
    } while (option != 4);

    return 0;
}

void modifyName(string newName, struct Register &r)
{
    r.name = newName;
}

void modifyColor(string newColor, struct Register &r)
{
    r.color = newColor;
}