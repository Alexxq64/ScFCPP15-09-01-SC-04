#include "HashTable.h"


    pair<string, string>* table; // массив пар ключ-значение
    int memSize; // размер таблицы
    int count; // количество элементов в таблице

    int HashTable::hashFunc(string key) { // хеш-функция методом умножения
        const float A = 0.6180339887; // константа A - золотое сечение
        float hashValue = 0;
        for (int i = 0; i < key.length(); i++) {
            hashValue = hashValue + key[i];
        }
        hashValue = hashValue * A; // умножаем на константу A
        hashValue = hashValue - floor(hashValue); // отбрасываем целую часть
        return (int)floor(hashValue * memSize); // умножаем на размер таблицы и возвращаем целое число
    }

    int HashTable::quadraticProbing(int index, int i) { // метод квадратичного пробирования
        return (index + i * i) % memSize;
    }

    HashTable::HashTable(int size) { // конструктор с заданием размера таблицы
        memSize = size;
        table = new pair<string, string>[memSize];
        count = 0;
    }

    void HashTable::add(string key, string value) { // добавление элемента в таблицу
        if (count == memSize) { // таблица заполнена
            cout << "Error: table is full" << endl;
                return;
        }
        int index = hashFunc(key);
        int i = 0;
        while (table[index].first != "" && table[index].first != key) {
            i++;
            index = quadraticProbing(index, i);
        }
        if (table[index].first == "") { // свободная ячейка
            table[index] = make_pair(key, value);
            count++;
        }
        else { // ячейка занята элементом с тем же ключом
            table[index].second = value;
        }
    }

    string HashTable::find(string key) { // поиск элемента в таблице
        int index = hashFunc(key);
        int i = 0;
        while (table[index].first != "" && table[index].first != key) {
            i++;
            index = quadraticProbing(index, i);
        }
        if (table[index].first !="") { // элемент не найден
            return "";
        }
        else { // элемент найден
            return table[index].second;
        }
    }

    void HashTable::del(string key) { // удаление элемента из таблицы
        int index = hashFunc(key);
        int i = 0;
        while (table[index].first != "" && table[index].first != key) {
            i++;
            index = quadraticProbing(index, i);
        }
        if (table[index].first != "") { // элемент найден
            table[index].first = "";
            table[index].second = "";
            count--;
        }
    }

    HashTable::~HashTable() { 
        delete[] table;
    }
