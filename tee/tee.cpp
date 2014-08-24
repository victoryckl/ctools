/*
* Read from standard input and write to standard 
* output and files (like linux)
* lituo 2008-9-11
*/
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const char* readLine(istream &is) {
    static char buf[1024];
    is.getline(buf, 1024);
    return buf;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        MessageBox(NULL, "About: tee is a tool(like linux) to redirect standard input\n" 
            "       to standard output and to all files in command line.\n\n"
            "Usage: command | tee filename1 filename2...\n\n", "ABOUT", MB_OK);
        return 0;
    }

    int ndx;
    ofstream *file = new ofstream[argc-1];

    try {
        for (ndx = 0; ndx < argc - 1; ndx++)
            file[ndx].open(argv[ndx + 1]);

        do {
            string line = readLine(cin);
            cout << line << endl;
            for (ndx = 0; ndx < argc - 1; ndx++)
                file[ndx] << line << endl;
        } while (!cin.eof());

        for (ndx = 0; ndx < argc - 1; ndx++) {
            file[ndx].flush();
            file[ndx].close();
        }

    } catch (...) {
        cout << "tee error" << endl;
    }

    delete [] file;
    return 0;
}