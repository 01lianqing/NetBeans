

#include <cstdio>
#include <cstdlib>
#include "beibao.h"
using namespace std;
/*
 * Simple C++ Test Suite
 */

void test1() {
    std::cout << "newsimpletest test 1" << std::endl;
    char file[] = "E:\\JAVA\\TanLanFa\\test1.txt";
    std::vector<Obj> objs;
    std::vector<int> final_list, ans_list, ans_array; //意思相同，都是保存挑选的序号
    double bag_contain = 0;
    double final_price = 0.0;
    beibao_init(file, objs, bag_contain);
    final_price = bag_pro_1(objs, final_list, bag_contain);
    cout << "The max price in bag :" << final_price << endl;
    for (vector<int>::iterator it = final_list.begin(); it != final_list.end(); it++) {
        cout << "N0." << *it<< " price " << objs[*it].price << endl;
    }
    final_price = bag_pro_2(objs, ans_list, bag_contain);
    cout << "The max price in bag :" << final_price << endl;
    for (vector<int>::iterator it = ans_list.begin(); it != ans_list.end(); it++) {
        cout << "N0." << *it << " weight: " << objs[*it].weight << endl;
    }
    final_price = bag_pro_3(objs, ans_array, bag_contain);
    cout << "The max price in bag :" << final_price << endl;
    for (vector<int>::iterator it = ans_array.begin(); it != ans_array.end(); it++) {
        cout << "N0." << *it<< " price_dencity " ;
        printf("%4.1lf\n",objs[*it].price_dencity );
    }
}

void test2() {
    std::cout << "newsimpletest test 2" << std::endl;
    std::cout << "%TEST_FAILED% time=0 testname=test2 (newsimpletest) message=error message sample" << std::endl;
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% newsimpletest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 (newsimpletest)" << std::endl;
    test1();
    std::cout << "%TEST_FINISHED% time=0 test1 (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% test2 (newsimpletest)\n" << std::endl;
    test2();
    std::cout << "%TEST_FINISHED% time=0 test2 (newsimpletest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

