#include <cstdlib>
#include "file_read.h"
using namespace std;

int main(int argc, char** argv) {
    char in[]="E:\\JAVA\\OneTwoThree\\1.txt";
    char out[]="E:\\JAVA\\OneTwoThree\\2.txt";
    char ans[]="E:\\JAVA\\OneTwoThree\\3.txt";
    write_once(in, out); 
    write_once(out,ans) ;
    return 0;
}


