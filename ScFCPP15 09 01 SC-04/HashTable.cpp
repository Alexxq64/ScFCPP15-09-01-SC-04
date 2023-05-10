#include "HashTable.h"


    pair<string, string>* table; // ������ ��� ����-��������
    int memSize; // ������ �������
    int count; // ���������� ��������� � �������

    int HashTable::hashFunc(string key) { // ���-������� ������� ���������
        const float A = 0.6180339887; // ��������� A - ������� �������
        float hashValue = 0;
        for (int i = 0; i < key.length(); i++) {
            hashValue = hashValue + key[i];
        }
        hashValue = hashValue * A; // �������� �� ��������� A
        hashValue = hashValue - floor(hashValue); // ����������� ����� �����
        return (int)floor(hashValue * memSize); // �������� �� ������ ������� � ���������� ����� �����
    }

    int HashTable::quadraticProbing(int index, int i) { // ����� ������������� ������������
        return (index + i * i) % memSize;
    }

    HashTable::HashTable(int size) { // ����������� � �������� ������� �������
        memSize = size;
        table = new pair<string, string>[memSize];
        count = 0;
    }

    void HashTable::add(string key, string value) { // ���������� �������� � �������
        if (count == memSize) { // ������� ���������
            cout << "Error: table is full" << endl;
                return;
        }
        int index = hashFunc(key);
        int i = 0;
        while (table[index].first != "" && table[index].first != key) {
            i++;
            index = quadraticProbing(index, i);
        }
        if (table[index].first == "") { // ��������� ������
            table[index] = make_pair(key, value);
            count++;
        }
        else { // ������ ������ ��������� � ��� �� ������
            table[index].second = value;
        }
    }

    string HashTable::find(string key) { // ����� �������� � �������
        int index = hashFunc(key);
        int i = 0;
        while (table[index].first != "" && table[index].first != key) {
            i++;
            index = quadraticProbing(index, i);
        }
        if (table[index].first !="") { // ������� �� ������
            return "";
        }
        else { // ������� ������
            return table[index].second;
        }
    }

    void HashTable::del(string key) { // �������� �������� �� �������
        int index = hashFunc(key);
        int i = 0;
        while (table[index].first != "" && table[index].first != key) {
            i++;
            index = quadraticProbing(index, i);
        }
        if (table[index].first != "") { // ������� ������
            table[index].first = "";
            table[index].second = "";
            count--;
        }
    }

    HashTable::~HashTable() { 
        delete[] table;
    }
