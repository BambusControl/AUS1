#include "menu.h"

Menu::Menu() :
    opCount(MIN_OP_COUNT),
    structureType(TestStructureType::List),
    structure(TestStructure::ArrayList),
    scenario(Scenario::All),
    filename("test")
{ }

void Menu::run()
{
    do
    {
        askType();
        cout << endl;
        askTest();
        cout << endl;
        askScenario();
        cout << endl;
        askOpCount();
        cout << endl;
        askFilename();
        cout << endl;
        startTest();
        cout << endl;
    } while (askAnotherOne());
}

// - - - - - - - - - - - - 

int Menu::askForInput(int max, int min, int offset)
{
    int input;
    bool repeat = true;

    do
    {
        cout << "Vasa volba: ";
        cin >> input;

        if (input < min || input > max || cin.fail())
        {
            cout << "Napiste cislo od " << min << " po " << max << '!' << endl;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(256, '\n');
            }
        }
        else
        {
            repeat = false;
        }
    } while (repeat);

    return input + offset;
}

bool Menu::askAnotherOne()
{
    cout
        << "Chcete spustit dalsi test?" << endl
        << "\t1. Ano" << endl
        << "\t2. Nie" << endl;

    return askForInput(2) == 1;
}

// - - - - - - - - - - - - - - - - - - - - - -

void Menu::askType()
{
    cout << "Aky test chcete spustit?" << endl;

    int i = 1;
    for (string item : TestFactory::getStructureTypeNames())
    {
        cout << '\t' << i++ << ". " << item << endl;
    }

    structureType = static_cast<tests::TestStructureType>(askForInput(3, 1, -1));
}

void Menu::askTest()
{
    cout
        << "Aku strukturu chcete testovat?" << endl
        << "\t0. Vsetky" << endl;

    int i = 1;
    for (string item : TestFactory::getStructureNames(structureType))
    {
        cout << '\t' << i++ << ". " << item << endl;
    }
    
    int s = askForInput(i - 1, 0);
    if (s == 0)
    {
        structure = TestStructure::All;
    }
    else
    {
        structure = TestFactory::getStructureOfType(structureType, s - 1);
    }
}

void Menu::askOpCount()
{
    cout
        << "Zadajte pocet operacii od " << MIN_OP_COUNT 
        << " po " << INT_MAX << "." << endl;
    opCount = askForInput(INT_MAX, MIN_OP_COUNT);
}

void Menu::askScenario()
{
    bool val = structureType < TestStructureType::Matrix;

    cout
        << "Vyberte scenar:" << endl
        << "\t0. Vsetky" << endl;

    int i = 1;
    for (string item : TestFactory::getAvailableScenarioNames(structureType))
    {
        cout << '\t' << i++ << ". " << item << endl;
    }

    scenario = static_cast<Scenario>(askForInput(i - 1, 0));
}

void Menu::askFilename()
{
    cout << "Zadajte nazov vystupneho .csv suboru: ";
    string f;
    cin >> f;
    filename = f + ".csv";
}

void Menu::startTest()
{

    cout << "Starting test..." << endl;

    TestFactory factory;
    stringstream str;

    if (structure == TestStructure::All)
    {
        if (scenario == Scenario::All)
        {
            factory.runAll(structureType, str, opCount);
        }
        else
        {
            factory.runAllOneScenario(structureType, scenario, str, opCount);
        }
    }
    else
    {
        bool test = factory.getTest(structure, str, opCount).runScenario(scenario);
        if (!test)
        {
            cout << "Error when running scenario!" << endl;
        }
    }

    cout << "End of test." << endl;

    cout
        << endl << "Creating file: \'"
        << filename << '\'' << endl;

    ofstream file;
    file.open(filename, ios::out);

    if (file.is_open())
    {
        cout
            << "File has been created!" << endl
            << "Writing to file..." << endl;
        file << str.rdbuf();
        file.close();
    }
    else
    {
        cout << "ERROR: Could not create/open file!" << endl;
    }
}