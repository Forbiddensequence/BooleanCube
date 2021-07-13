// TulianPryanic.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include <vector>
using namespace std;
long long int factorial(long long int a);

void start_factorial() {
    while (true) {
        long long int a;
        std::cin >> a;

        std::cout << "Hello World!\n";
        std::cout << "factorial of ";
        std::cout << a;
        std::cout << " is ";
        std::cout << factorial(a);
        std::cout << "\n";
    }
}

long long int poft(long long int power) {
    long long int a = 1;
    for (long long int i = 0; i < power; i++) {
        a = a << 1;
        //cout << a << " И тут тоже \n";
    }
    return a;
}

void initcube(long long int demension, vector<long long int>& vect) {
    long long int boundary = poft(demension);
    //cout << boundary << "\n";
    for (long long int i = 0; i < boundary;i++) {
        vect.push_back(i);
    }
    
}


bool isinvector(long long int element, vector<long long int>& vect) {
    for (long long int i = 0; i < vect.size(); i++) {
        if (vect[i] == element) {
            return true;
        }
    }
    return false;
}
/*
void factorizationofnuberinvector(long long int number,vector<long long int>& vect) {
    for (long long int i = 0;) {

    }
}
*/


long long int discretbinarylog(long long int y, long long int n) {
    return (y >> n) & 1;
}

long long int numberofpermutation(long long int k, long long int n) {
    return factorial(n) / (factorial(n - k) * factorial(k));
}

long long int weightofvector(long long int binaryvector) {
    long long int num = 0;
    while (binaryvector>0) {
        num += binaryvector&1;
        binaryvector=binaryvector >> 1;
    }
    return num;
}

void initvectormask(long long int k,long long int n, vector <long long int>& filvector) {
    for (long long int i = 0; i < poft(n);i++) {
        if (weightofvector(i) == k) {
            filvector.push_back(i);
        }
    }
}

long long int fillingones(long long int n) {
    int res=1;
    for (long long int i = 0; i < n-1; i++) {
        res = (res << 1) | 1;
    }
    return res;
}

bool isCIorderequals(long long int function, long long int k, long long int n) {
    long long int m = n - k;
    long long int boundaryofunfixedvariable =poft(m)* numberofpermutation(k,n);

    //cout << "Значение количества всех возможных граней размерности "<< m <<" в "<< n <<"-мерном кубе - "<< boundaryofunfixedvariable << "\n";

    vector <long long int> veccombination;
    initvectormask(k,n,veccombination);
    /*cout << "Значения вектора масок "<<"\n";
    for (int i = 0; i < veccombination.size();i++) {
        cout << veccombination[i] << "\n";
    }*/
    bool isKorder=true;
    for (long long int i = 0; i < veccombination.size();i++) {
        long long int currentvariant = veccombination[i];       
        for (long long int j = 0; j < poft(k);j++) {
            long long int currentmask = currentvariant;
            long long int currentpoint = 0;
            long long int almostpoint = currentmask;
            long long int dbj = j;
            for (long long int z = 0; z < n;z++) {
                if (almostpoint&1) {
                    currentpoint=((dbj & 1)<<z)|currentpoint;
                    dbj=dbj >> 1;
                }
                almostpoint = almostpoint >> 1;
            }

            //cout <<"Возможные начальные точки "<< currentpoint <<" с такой маской  "<< currentmask<< "\n";
            int sum = 0;
            for (long long int y = 0; y < poft(m); y++) {
                long long int currentinvmask = currentvariant^fillingones(n);
                long long int currentsubpoint = currentpoint;
                long long int almostsubpoint = currentinvmask;
                long long int dby = y;
                for (long long int z = 0; z < n; z++) {
                    if (almostsubpoint & 1) {
                        currentsubpoint = ((dby & 1) << z) | currentsubpoint;
                        dby = dby >> 1;
                    }
                    almostsubpoint = almostsubpoint >> 1;
                }
                //cout << "Возможные точки грани " << currentsubpoint << " с такой инвертированной маской " << currentinvmask << "\n";
                sum += (function >> currentsubpoint) & 1;
            }
            //cout << "Вес функции " << weightofvector(function) << ", вес функции в грани " << sum << "\n";
            
            if (weightofvector(function)==sum*poft(k)) {
                //cout << "Куб размерностью " <<m<<" с начальной точкой "<<currentpoint<< " прошел проверку\n";
                
            }
            else {
                //cout << "Куб размерностью " << m << " с начальной точкой " << currentpoint << " не прошел проверку\n";
                isKorder&= false;
                return isKorder;
            }

        }
    }
    //cout << "Ура функция завершилась \n";
    return isKorder;
}

long long int CI(long long int vector,int dem) {
    int orderofCI = 0;
    for (long long int j = 1; j < dem; j++) {
        bool res = isCIorderequals(vector, j, dem);
        //cout << res << "\n";
        if (res) {
            orderofCI = j;
        }
    }
    if (orderofCI) {
        return orderofCI;
    }
    else {
        return -1;
    }
}


long long int showCIinrange(int basedem) {
    long long int ctr=0;
    for (int i = 0; i < poft(poft(basedem));i++) {
        /*if (i == poft(poft(basedem))>>1) {
            i=i;
        }*/
        int orderofCI = CI(i,basedem);
        if (orderofCI>0) {
            ctr++;
            cout << hex << "Корреляционная имунность функции " << i << " равна - " << orderofCI << "\n";
        }
    }
    cout << dec << "Итоговое количество подходящих функций  равно - " << ctr << "\n";
    return 0;
}

void pat1(long long int n, long long int beginpoint ) {
    vector <long long int> vecbeginedge;
    vector <long long int> possiblevecinedge;
    vecbeginedge.push_back(beginpoint);
    vector <long long int> direction;
    vecbeginedge.push_back(fillingones(n - 1)^beginpoint);
    for (int i = 0; i < poft(n-1); i++) {
        if (weightofvector(i)!=n-2) {
            continue;
        }
        if (!isinvector(i,direction)) {
            direction.push_back(i^ fillingones(n - 1)^ fillingones(n));
        }
    }
    long long int functionnumber = poft(vecbeginedge[0])+poft(vecbeginedge[1]);
    long long int ctr = 0;
    for (long long int i = 0; i < direction.size(); i++) {
        long long int f = functionnumber + poft(vecbeginedge[0] ^ direction[i]) + poft(vecbeginedge[1] ^ direction[i]);
        if (true||CI(f, n)>0) {
            cout << hex << f << " - Функция по паттерну 1\n";
            cout << dec << CI(f, n) << "- Корреляционная иммунность функции " << hex << f << " по паттерну 1 \n";
            
            ctr++;
        }
    }
    cout << dec <<ctr<< "- Количество функций по данному паттерну 1 с такой начальной точкой "<<beginpoint<<"\n";
    cout << endl;

}

long long int degreeof(long long int vector, long long int dem) {
    long long int f = dem;
    long long int degr = 0;
    long long int newf = 0;
    for (long long int i = 0; i < exp(dem); i++){
        if (f & 1) {
            degr = weightofvector(i);
        }
        for (long long int j = 0;j<exp(dem) - i-1;j++) {
            newf|=(((vector >> j & 1) ^ (vector >> (j + 1) & 1))<<j);
        }
        f = newf;
        newf = 0;
    }
    return degr;
}

long long int scalarmult(long long int v1, long long int v2) {
    long long int res = 0;
    while ((v1>0)&&(v2>0)) {
        res+=v1&1&
    }
}

long long int AI(long long int vector, long long int dem) {
    long long int base = fillingones(poft(dem))^vector;
    long long int AIdegree = 0;
    
    for (long long int i = 0; i < poft(weightofvector(base));i++) {
        long long int currentsubpoint = 0;
        long long int almostsubpoint = base;
        long long int dby = i;
        for (long long int z = 0; z < poft(dem); z++) {
            if (almostsubpoint & 1) {
                currentsubpoint = ((dby & 1) << z) | currentsubpoint;
                dby = dby >> 1;
            }
            almostsubpoint = almostsubpoint >> 1;
        }


    }
    
    return 0;
}

int main()
{ 
    setlocale(LC_ALL,"ru");
    //start_factorial();

    vector <long long int> veccube;
    vector <long long int>::iterator it;
    vector <long long int> vecfunction;
    long long int dem = 4;
    //cout << sizeof(dem)<<"\n";
    initcube(dem,veccube);
    /*
    cout << "Значения вектора куба " << "\n";
    for ( it = veccube.begin(); it != veccube.end();++it) {
        cout << *it<<" Вес - "<< weightofvector(*it)<<"\n";
    }
    */
    long long int funcnumber = poft(8) + poft(15);// +poft(19) + poft(28);
    //cout <<hex<< poft(64)-poft(0)<< "\n";
    cout <<dec<< funcnumber<< " Вес - " << weightofvector(funcnumber) << "\n";
    for (it = vecfunction.begin(); it != vecfunction.end(); ++it) {
        cout << *it << "\n";
    }
    
    
    int orderofCI = 0;
    for (long long int i  = 1; i < dem;i++) {
        bool res = isCIorderequals( funcnumber, i, dem);
        //cout << res << "\n";
        if (res) {
            orderofCI = i;
        }
    }

    cout << hex <<"Корреляционная имунность функции "<< funcnumber << " равна - " << orderofCI << "\n";
    
    for (int i = 0; i < poft(6); i++) {
        pat1(6,i);
    }
    showCIinrange(dem);
    //cout << "Хаха у тебя ничего не выводится ";
    return 0;
}

//Рассчитывает факториал до 20 включительно
long long int factorial(long long int a) {
    if (a < 0)
        return 0;
    if (a == 1||a==0) {
        return 1;
    }
    if (a>1) {
        return a * factorial(a - 1);
    }
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
