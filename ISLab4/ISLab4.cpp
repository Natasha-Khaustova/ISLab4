// ISLab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class neuron         //класс, обозначающий наш нейрон
{
    double w = 0.3; //значение веса

public:

    double ProccesInputdata(double input)     //метод, отвечающий за вывод значения, просчитанного нейроном == вход*вес
    {
        return (input * w);
    }
    double  RestoreInputData(double output) //обратный метод вывода, для получения из выхода значение входа
    {
        return (output / w);
    }
    void Train(double input, double expected)                //метод тренировки нейрона
    {
        double actresult = input * w;                       //результат, полученный нерйоном на данный момент
        LastError = expected - actresult;                  //величина ошибки на данный момент
        double correct = (LastError / actresult) * speed; //величина треубемой корректировки на данный момент
        w += correct;                                    //изменение веса на величину корректировки
    }

    double LastError;
    double speed = 0.000001; //скорость обучения нейрона. Чем ниже - тем качественнее, но медленнее.
};

int main()
{
    setlocale(LC_ALL, "Russian");

    double USD = 1;       //"учитель", обозначающий 
    double EU = 0.95;     //настоящее значение
    neuron n;             //создание объекта "нейрон"
    int i = 0;

    while (n.LastError > n.speed || n.LastError < -n.speed) //цикл обучения
    {
        i++;
        n.Train(USD, EU);
        if (i % 100000 == 0)        //вывод информации об обучении: попытка и значение ошибки
        {
            cout << " Номер ошибки: " << i << "  Ошибка сети на данном этапе: " << n.LastError << endl;
        }
    }

    cout << endl;
    cout << " 100 долларов = " << n.ProccesInputdata(100) << " евро" << endl;       //результаты  
    cout << " 10 евро = " << n.RestoreInputData(10) << " долларов" << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
