//
// Created by 服部篤樹 on 2018/12/21.
//

#ifndef DSMC_0D_DSMC_H
#define DSMC_0D_DSMC_H


#include "particles.h"

class MyDSMC {
public:
    MyDSMC(particles& Part);
    int collision(particles& Part);

private:
    double rgas;
    double t0;
    double d;
    double vref, tref;
    double col;     //単位面積あたり衝突数
    double dx, dy;
    double area;    //面積
    double fgmax, gmax;
    double dt;
    double ns;      //単位面積あたり粒子発生数
    double akn;     //クヌーセン数

    double uniform_random();
};


#endif //DSMC_0D_DSMC_H
