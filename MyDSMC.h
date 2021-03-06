//
// Created by 服部篤樹 on 2018/12/21.
//

#ifndef DSMC_0D_DSMC_H
#define DSMC_0D_DSMC_H


#include "particles.h"

class MyDSMC {
public:
    MyDSMC(particles& Part, double kn);
    int collision(particles& Part);
    void output_data(int nstep, particles Part);

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
    void init1(particles& Part);
    void init2(particles& Part);
    void init3(particles& Part);
    void init4(particles& Part);
};


#endif //DSMC_0D_DSMC_H
