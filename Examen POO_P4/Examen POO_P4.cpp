//Critter
#include <iostream>

using namespace std;

class Critter
{
public:
    Critter(int hunger = 0, int boredom = 0, int poopiss = 0, bool alive = true);
    bool m_Alive;
    void Talk();
    void Eat(int food = 4);
    void Play(int fun = 4);
    void GoBathroom(int pushingForce = 4);
    void medicalCheck();

private:
    int m_Hunger;
    int m_Boredom;
    int m_Poopiss;
    void PassTime(int time = 1);
};

Critter::Critter(int hunger, int boredom, int poopiss, bool alive) :
    m_Hunger(hunger),
    m_Boredom(boredom),
    m_Poopiss(poopiss),
    m_Alive(alive)
{}


void Critter::PassTime(int time)
{
    m_Hunger += time;
    if (m_Hunger >= 10)
    {
        cout << "\nHe muerto de hambre\n";
        m_Alive = false;
    }
    m_Boredom += time;
    if (m_Boredom >= 50)
    {
        cout << "\nMe mori del aburrimiento (lo digo en serio)\n";
        m_Alive = false;
    }
    m_Poopiss += time;
    if (m_Poopiss >= 50)
    {
        cout << "\nSin comentarios...(la mascota ha muerto en circunstancias inhumanas)\n";
        m_Alive = false;
    }
    
}

void Critter::Talk()
{
    if (m_Hunger <= 5 && m_Boredom <= 5 && m_Poopiss <= 5)
    {
        cout << "\nEstoy muy feliz y no me falta nada\n";
    }
    else if (m_Hunger <= 25 && m_Boredom <= 25 && m_Poopiss <= 25)
    {
        cout << "\nAun estoy feliz, pero...\n";
    }
    else if (m_Hunger <= 45 && m_Boredom <= 45 && m_Poopiss <= 45)
    {
        cout << "\nNo estoy nada feliz...\n";
    }
    else
    {
        cout << "\nMe estoy literalmente muriendo, si hay alguien ahi que pueda oirme o si existe algun dios que todo lo vea, porfavor acaben con mi sufrimiento. Ya no me importa morir, solo quiero que acabe esta tortura\n";
    }
    //Hambre
    if (m_Hunger > 5 && m_Hunger <= 25)
    {
        cout << "- Tengo algo de hambre\n";
    }
    else if (m_Hunger > 25 && m_Hunger <= 45)
    {
        cout << "- Tengo mucha hambre\n";
    }
    else if (m_Hunger > 45)
    {
        cout << "- Me muero de hambre\n";
    }
    //Aburrimiento
    if (m_Boredom > 5 && m_Boredom <= 25)
    {
        cout << "- Estoy algo aburrido\n";
    }
    else if (m_Hunger > 25 && m_Boredom <= 45)
    {
        cout << "- Estoy muy aburrido\n";
    }
    else if (m_Boredom > 45)
    {
        cout << "- Me estoy volviendo loco del aburrimiento\n";
    }
    //Ganas de ir al baño
    if (m_Poopiss > 5 && m_Poopiss <= 25)
    {
        cout << "- Tengo ganas de ir al baño\n";
    }
    else if (m_Hunger > 25 && m_Poopiss <= 45)
    {
        cout << "- Siento que voy a reventar si no voy al baño\n";
    }
    else if (m_Poopiss > 45)
    {
        cout << "- Creo que mi colon a explotado, ya no siento mis piernas y parece que tengo una fuga en la retaguardia. Lo unico bueno es que al menos yo no tendre que limpiar todo este desastre\n";
    }
    PassTime();
}

void Critter::Eat(int food)
{
    cout << "\nBrrupp. \n";
    m_Hunger -= food;
    if (m_Hunger < 0)
    {
        m_Hunger = 0;
    }
    PassTime();
}

void Critter::Play(int fun)
{
    cout << "\nWheee!\n";
    m_Boredom -= fun;
    if (m_Boredom < 0)
    {
        m_Boredom = 0;
    }
    PassTime();
}

void Critter::GoBathroom(int pushingForce)
{
    cout << "\nPrffffttttt!\n";
    m_Poopiss -= pushingForce;
    if (m_Poopiss < 0)
    {
        m_Poopiss = 0;
    }
    PassTime();
}

void Critter::medicalCheck()
{
    cout << "\n--Analisis Medico--\n\n";
    cout << "- Hambre: " << m_Hunger << endl;
    cout << "- Aburrimiento: " << m_Boredom << endl;
    cout << "- Ganas de ir al baño: " << m_Poopiss << endl;
    PassTime();
}

int main()
{
    Critter crit;
    crit.Talk();
    int choice;
    do
    {
        cout << "\n Mascotas Virtuales\n\n";
        cout << "0 - Salir.\n";
        cout << "1 - Escucha a tu mascota.\n";
        cout << "2 - Alimentar.\n";
        cout << "3 - Jugar con tu mascota.\n";
        cout << "4 - Llevar a tu mascota al baño\n";
        cout << "5 - Hacer una revision medica a la mascota\n";
        cout << "Elige una opción: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "Vuelve pronto!.\n";
            break;
        case 1:
            crit.Talk();
            break;
        case 2:
            crit.Eat();
            break;
        case 3:
            crit.Play();
            break;
        case 4:
            crit.GoBathroom();
            break;
        case 5:
            crit.medicalCheck();
            break;
        default:
            cout << "\n Tu elección es inválida. \n";
        }
    } while (choice != 0 && crit.m_Alive);
}