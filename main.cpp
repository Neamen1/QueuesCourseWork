#include <iostream>
#include <ctime>
#include <queue>
#include <cstdlib>
#include "PriorityQueueVector.h"
#include "PriorityQueueLinked.h"
#include "QueueVector.h"
using namespace std;

int choose_data_type(){
    int choiceKey;          //змінна вибору пункту меню
    while(true){
        cout<<"         MENU - choose data type"<<endl;
        cout << "   Choose a type of data to work with:"<<endl;    //також можна використовувати власні типи даних, але вони повинні мати первантажені оператори < та ==
        cout<<"1. Integer"<<endl;
        cout<<"2. Double"<<endl;
        cout<<"3. String"<<endl;
        cin >> choiceKey;
        getchar();                   //видалення зайвого символу з буфера
        system("cls");
        if (std::cin.fail()){        //якщо попереднє зчитування потоку cin було невдалим,
            std::cin.clear();        //то очищуємо буфер
            std::cin.ignore(32767,'\n');
            std::cout << "Input is invalid. Please try again.\n";
        }
        else if(!(choiceKey>=1 && choiceKey<=4)){
            std::cout << "Input is invalid. Please try again.\n";
        }
        else{
            return choiceKey;
        }
    }

}

bool enterManually(){
    int choiceKey;          //змінна вибору пункту меню
    while(true) {
        cout << "         MENU - choose generate data or enter manually" << endl;
        cout << "1. Generate randomly" << endl;
        cout << "2. Enter manually" << endl;
        cin >> choiceKey;
        getchar();                   //видалення зайвого символу з буфера
        system("cls");
        if(choiceKey == 1) {
            return false;
        }
        else if(choiceKey == 2){
            return true;
        }
        else {
            if (std::cin.fail()) {        //якщо попереднє зчитування потоку cin було невдалим,
                std::cin.clear();        //то очищуємо буфер
                std::cin.ignore(32767, '\n');
            }
            std::cout << "Input is invalid. Please try again.\n";
        }
    }
}

void genRandString(std::string *value){
    const int len = rand()%14+6;
    static const char characters[] ="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    (*value).reserve(len);       //резервування виділення пам'яті для "len" кількості символів

    for (int i = 0; i < len; ++i) {
        (*value) += characters[rand() % (sizeof(characters) - 1)];
    }
}

void createObject(int *value){      //перевантажена функція для створення даних типів int, double, string
    if(enterManually()){
        cout<<"Enter integer number:"<<endl;
        cin>>(*value);
        system("cls");
        while (std::cin.fail()){        //якщо попереднє зчитування потоку cin було невдалим,
            std::cin.clear();           //то очищуємо буфер
            std::cin.ignore(32767,'\n');
            std::cout << "Input is invalid. Please try again.\n";
            cin>>(*value);                //повторюємо введення даних
            system("cls");
        }
    }
    else {
        *value = rand();
    }
}

void createObject(double *value){       //перевантажена функція для створення даних типів int, double, string
    if(enterManually()){
        cout<<"Enter float number:"<<endl;
        cin>>(*value);
        system("cls");
        while (std::cin.fail()){        //якщо попереднє зчитування потоку cin було невдалим,
            std::cin.clear();           //то очищуємо буфер
            std::cin.ignore(32767,'\n');
            std::cout << "Input is invalid. Please try again.\n";
            cin>>(*value);                //повторюємо введення даних
            system("cls");
        }
    }
    else {
        *value = (double)rand()/((double)RAND_MAX/(rand()%5000));
    }
}

void createObject(std::string *value){      //перевантажена функція для створення даних типів int, double, string
    if(enterManually()){
        cout<<"Enter a string:"<<endl;
        getline(std::cin, *value);
        system("cls");
        while (std::cin.fail()){        //якщо попереднє зчитування потоку cin було невдалим,
            std::cin.clear();           //то очищуємо буфер
            std::cin.ignore(32767,'\n');
            std::cout << "Input is invalid. Please try again.\n";
            getline(std::cin, *value);                //повторюємо введення даних
            system("cls");
        }
    }
    else {
        genRandString(value);   //
    }
}

template <typename T>
void QueueMenu(int StructureType){
    QueueVector<T> QV;
    PriorityQueueVector<T> PQV;
    PriorityQueueLinked<T> PQL;
    
    // push/pop menu loop
    int choiceKey;
    bool quitLoop = false;
    
    while(!quitLoop){
        cout << "         MENU - push/pop/print" << endl;
        cout << "1. Create and push value" << endl;
        cout << "2. Pop value" << endl;
        cout << "3. Print full queue" << endl;
        cout << "4. Quit" << endl;
        cin >> choiceKey;
        getchar();                   //видалення зайвого символу з буфера
        system("cls");
        if(choiceKey == 1){
            T value;
            createObject(&value);
            switch (StructureType) {
                case 1:
                    QV.push(value);
                    break;
                case 2:
                    PQV.push(value);
                    break;
                case 3:
                    PQL.push(value);
                    break;
                default:
                    break;
            }
        }
        else if(choiceKey == 2){
            switch (StructureType) {
                case 1:
                    QV.pop();
                    break;
                case 2:
                    PQV.pop();
                    break;
                case 3:
                    PQL.pop();
                    break;
                default:
                    break;
            }
        }
        else if(choiceKey == 3){
            switch (StructureType) {
                case 1:
                    QV.print();
                    break;
                case 2:
                    PQV.print();
                    break;
                case 3:
                    PQL.print();
                    break;
                default:
                    break;
            }
        }
        else if(choiceKey == 4){
            quitLoop = true;
        }
        else{
            if (std::cin.fail()) {        //якщо попереднє зчитування потоку cin було невдалим,
                std::cin.clear();         //то очищуємо буфер
                std::cin.ignore(32767, '\n');
            }
            std::cout << "Input is invalid. Please try again.\n";
        }
    }

}


int main(int argc, char* argv[])
{
    srand(time(nullptr));

    int choiceKey;
    bool quit_flag = false;

    while(!quit_flag){
        cout<<"         MENU"<<endl;
        cout<<"     Choose the data structure to work with:"<<endl;
        cout<<"1. Vector-based queue"<<endl;
        cout<<"2. Vector-based priority queue"<<endl;
        cout<<"3. Linked list-based priority queue"<<endl;
        cout<<"4. Quit"<<endl;
        cin >> choiceKey;       //змінна для вибору пункту меню
        getchar();              //видалення зайвого символу з буфера
        system("cls");
        if(choiceKey == 4){
            break;
        }
        else if(choiceKey>=1 && choiceKey<=3) {
            int dataTypeIndex = choose_data_type();
            if(dataTypeIndex == 1){             //якщо вибраний тип даних - цілі числа, то створиться вказана черга із цим типом
                QueueMenu<int>(choiceKey);
            }
            else if(dataTypeIndex == 2){        //якщо вибраний тип даних - дробові числа, то створиться вказана черга із цим типом
                QueueMenu<double>(choiceKey);
            }
            else if(dataTypeIndex == 3){        //якщо вибраний тип даних - строка, то створиться вказана черга із цим типом
                QueueMenu<std::string>(choiceKey);
            }
        }
        else {                          //в інших випадках, тобто якщо були введені невірні дані
            if (std::cin.fail())        //якщо попереднє считування потоку cin було невдалим,
            {
                std::cin.clear();       //то очищуємо буфер
                std::cin.ignore(32767,'\n');
            }
            std::cout << "Input is invalid. Please try again.\n";   //вивід повідомлення про некоректний ввід даних
        }
    }

    return 0;
}
