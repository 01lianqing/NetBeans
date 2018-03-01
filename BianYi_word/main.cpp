#include <cstdlib>
#include"word.h"
using namespace std;

int main(int argc, char** argv) {
    char in[]="E:\\JAVA\\BianYi_word\\raw_test.txt";
    char out[]="E:\\JAVA\\BianYi_word\\pre_test.txt";
    char ans[]="E:\\JAVA\\BianYi_word\\ans_test.txt";
    word_init(in, out);
    process_word(out,ans);
    return 0;
}

