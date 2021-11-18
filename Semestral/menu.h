#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "structures/list/list.h"
#include "structures/list/array_list.h"
#include "structures/list/linked_list.h"
#include "structures/priority_queue/priority_queue.h"
#include "structures/priority_queue/priority_queue_linked_list.h"
#include "structures/priority_queue/priority_queue_list.h"
#include "structures/priority_queue/heap.h"
#include "structures/matrix/matrix.h"
#include "structures/matrix/coherent_matrix.h"
#include "structures/matrix/incoherent_matrix.h"
#include "tests/list/test_list.h"
#include "tests/priority_queue/test_priority_queue.h"
#include "tests/testFactory.h"

using namespace tests;

class Menu
{

public:

    Menu();

    /// <summary>
    /// Spusti menu system
    /// </summary>
    void run();

private:

    const int MIN_OP_COUNT = 1;
    int opCount;
    TestStructureType structureType;
    TestStructure structure;
    Scenario scenario;
    string filename;

    // <summary>
    /// Opyta sa a priradi typ testu zvoleny pouzivatelom
    /// </summary>
    void askTest();

    /// <summary>
    /// Opyta sa a priradi typ testu konkretneho ADT zvoleneho pouzivatelom
    /// </summary>
    void askType();

    /// <summary>
    /// Opyta sa a priradi pocet operacii na vykonanie v jednom teste
    /// </summary>
    void askOpCount();

    /// <summary>
    /// Opyta sa a priradi testovaci scenar
    /// </summary>
    void askScenario();

    /// <summary>
    /// Opyta sa a priradi nazov vystupneho .csv suboru
    /// </summary>
    void askFilename();

    /// <summary>
    /// Spusti test
    /// </summary>
    void startTest();

    /// <summary>
    /// Opyta sa na a ziska input z console streamu.
    /// Pokial pouzivatel nezada cele cislo v rozsahu [min, max] opyta sa znova.
    /// Offset sa na konci pripocita k navratovej hodnote.
    /// </summary>
    /// <param name="min">Najnizsia mozna volba</param>
    /// <param name="max">Najvyssia mozna volba</param>
    /// <param name="max">Pripocitane cislo</param>
    /// <returns>Zvolene cislo + offset</returns>
    int askForInput(int max, int min = 1, int offset = 0);

    bool askAnotherOne();

};