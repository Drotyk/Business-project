#ifndef RND_UTILS_H
#define RND_UTILS_H

#include <random>
using namespace std;

int rnd(int a, int b) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dist(a, b);
    return dist(gen);
}

double rndDouble(double a, double b) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_real_distribution<> dist(a, b);
    return dist(gen);
}
#endif