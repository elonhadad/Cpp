//
// Created by ELON HADAD on 07/01/2023.
//

#include "Lentivirus.h"

Lentivirus::Lentivirus(const string &str, const int *arr) : Virus(str, arr) {
    this->setPm(2);
}

