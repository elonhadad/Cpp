//
// Created by ELON HADAD on 15/12/2022.
//

#ifndef EX_04_VIRUS_H
#define EX_04_VIRUS_H
#include <string>


using namespace std;

class Virus {

public:
    Virus();                                                        // default constructor.
    Virus(string str, const int *arr);                              // constructor for first insert.
    Virus(const Virus& v);                                          // copy constructor.
    Virus(Virus&& v) noexcept;                                      // move constructor.
    Virus& operator=(Virus &&v) noexcept;                           // move assignment operator.
    Virus& operator=(const Virus& v);                               // copy assignment operator.
    bool operator<(const Virus &a)const;                            // operator < between two grades of virus's.
    bool operator<=(const Virus &a)const;                           // operator <= between two grades of virus's.
    friend ostream& operator<<(ostream& out,const Virus &a);        // operator << for printing to standard output.
    Virus& operator*();                                             // rand 2 indexes in vec and swap (used for individual update)
    void print_vector();                                            // print the vector filed from virus.
    virtual ~Virus();                                               // destructor.

    // getters

    const string &getName() const;
    double getGrade() const;
    int getRealVer() const;
    int *getVersion() const;

    // setters

    virtual void setGrade();
    void setVersion();
    void setRealVer(int realVer);
    void setPm(int p);

private:
    string name;
    double grade;
    int pm;
    int counter;
    int real_ver;
    int* vector;
    int* version;
};

#endif //EX_04_VIRUS_H