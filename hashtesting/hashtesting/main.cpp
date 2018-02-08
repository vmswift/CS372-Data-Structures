#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class HashEntry
{

private:

    string key;

    string value;

public:

    HashEntry(string key, string value)
    {

        this->key = key;

        this->value = value;

    }



    string getKey()
    {

        return key;

    }



    string getValue()
    {

        return value;

    }

};

const int TABLE_SIZE = 31;



class HashMap
{

private:

    HashEntry **table;
    int hits,used;

public:

    HashMap()
    {

        table = new HashEntry*[TABLE_SIZE];

        for (int i = 0; i < TABLE_SIZE; i++)
        {
            table[i] = NULL;
        }
        hits=0;
        used=0;
    }



    string get(string key)
    {
        int sum=0;
        for(int i=0; i<key.length(); i++)
        {
                    sum=sum+(key[i]*2);
        }
        int hash = (sum % TABLE_SIZE);

        while (table[hash] != NULL && table[hash]->getKey() != key)

            hash = (hash + 1) % TABLE_SIZE;

        if (table[hash] == NULL)

            return 0;

        else

            return table[hash]->getValue();

    }



    void put(string key, string value)
    {

        int sum=0;
        for(int i=0; i<key.length(); i++)
        {
                    sum=sum+(key[i]*2);
        }
        int hash = (sum % TABLE_SIZE);
//        cout << hash << endl;
        while (table[hash] != NULL && table[hash]->getKey() != key)
        {
            hash = (hash + 1) % TABLE_SIZE;
            hits++;
        }
        if (table[hash] != NULL)
        {
            delete table[hash];
        }
        table[hash] = new HashEntry(key, value);
        used++;

    }

    void print()
    {

        for(int i=0; i<TABLE_SIZE; i++)
        {
            if(table[i]!=NULL)
            {
                cout << table[i]->getKey() << table[i]->getValue() << endl;
            }
        }
    }

    int collisions()
    {
        return hits;
    }

    int hashSize()
    {
        return used;
    }

    ~HashMap()
    {

        for (int i = 0; i < TABLE_SIZE; i++)

            if (table[i] != NULL)

                delete table[i];

        delete[] table;

    }

};

int main()
{
    HashMap myhash;
    char test;
    int bounds=0;
    string value, key;

    ifstream infile;
    infile.open("HashNamesAndPhone.txt");


    while(infile)//count<27)
    {
        infile.get(test);
        if(test>='A'&&test<='z'&&bounds!=-999)
        {
            key=key+test;
        }
        if(test==32&&bounds!=-999)
        {
            key=key+test;
        }
        if(isdigit(test)||test=='-')
        {
            bounds=-999;
            value=value+test;
        }
        if(test=='\n')
        {
            bounds=0;
            if(key.length()&&value.length())
				//while(key[])
                myhash.put(key,value);
			cout << key.back() << endl;
            key.clear();
            value.clear();
        }

    }

    //cout << myhash.get(key) << endl;
    myhash.print();
    cout << "Number of collisions building this database: " << myhash.collisions() << endl;
    cout << "Number of used locations: " << myhash.hashSize() << endl;
    cout << "looking up Twoseeor knocksee : " << myhash.get("Twoseeor knocksee ") << endl;
    cout << "looking up Legg T.        : " << myhash.get("Legg T.        ") << endl;
    return 0;
}
