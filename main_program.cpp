#include <iostream>
#include "database.h"
#include "interface.h"

using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 2) {
	cout << "Usage: mydb <full_path_to_binary_file>" << endl;
	exit(1);
    }
    DataBase db(argv[1]);
    Interface iface;
    iface.run(&db);
    return 0;
}
