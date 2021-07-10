// TulianPryanic.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include <vector>
using namespace std;
int factorial(int a);

void start_factorial() {
    while (true) {
        int a;
        std::cin >> a;

        std::cout << "Hello World!\n";
        std::cout << "factorial of ";
        std::cout << a;
        std::cout << " is ";
        std::cout << factorial(a);
        std::cout << "\n";
    }
}

int exp(int power) {
    int a = 1;
    for (int i = 0; i < power; i++) {
        a = a * 2;
        //cout << a << " И тут тоже \n";
    }
    return a;
}

void initcube(int demension, vector<int>& vect) {
    int boundary = exp(demension);
    cout << boundary << "\n";
    for (int i = 0; i < boundary;i++) {
        vect.push_back(i);
    }
    
}



int main()
{ 
    setlocale(LC_ALL,"ru");
    //start_factorial();

    vector <int> VecCube;
    int dem = 5;
    initcube(dem,VecCube);
    for (int i = 0; i < VecCube.size();i++) {
        cout << VecCube[i]<<"\n";
    }
    //cout << "Хаха у тебя ничего не выводится ";

}

int factorial(int a) {
    if (a <= 0)
        return 0;
    if (a == 1) {
        return a;
    }
    if (a>1) {
        return a * factorial(a - 1);
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
