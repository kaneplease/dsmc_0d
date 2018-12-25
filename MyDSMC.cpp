//
// Created by 服部篤樹 on 2018/12/21.
//
#include <cmath>
#include <random>
#include <iostream>

#include "MyDSMC.h"

MyDSMC::MyDSMC (particles& Part) {
    rgas = 287.0;
    dx = 1.0;
    dy = 1.0;
    area = dx*dy;
    t0 = 200.0;
    d = 0.1;
    vref = sqrt(2.0*rgas*t0);
    tref = d / vref;
    akn = 0.4;

    //Gmaxを定義する
    fgmax = 10.0;
    gmax = fgmax*sqrt(rgas*t0) / vref;

    double v0 = 0;
    double dtv = (d*fmin(dx, dy) / (v0 + sqrt(2.0*rgas*t0))) / tref;
    double dtc = 0.2*akn;

    dt = fmin(dtv, dtc);
    ns = 500000;

    col = fgmax*dt / (4.0*area * static_cast<double>(ns)*akn);

    /*初期粒子の分布を決定*/
    Part.num = static_cast<int>(ns * area);
    Part.v.resize(Part.num);
    for (int i=0; i<Part.v.size(); i++){
        Part.v[i].resize(3);
    }
    //確率密度関数
    //2*vrefまでの大きさの速度が一様に分布
    //F=1/2*x よって
    for(int i = 0; i<Part.v.size(); i++){
        Part.v[i][0] = 2 * uniform_random();
        Part.v[i][1] = 0;
        Part.v[i][2] = 0;
    }
}

int MyDSMC::collision(particles& Part)
{
    //粒子数
    double n_all = static_cast<double>(ns) * area;
    //最大衝突数の設定
    double acol = col * n_all * n_all - 1;
    int ncol = int(acol);
    if (uniform_random() < (acol - double(ncol))) {
        ncol = ncol + 1;
    }
    //std::cout << (ncol) << std::endl;

    //ncol<=0　や　lc[i][j]<=1　の場合は除く
    if ((ncol > 0) && (n_all > 1)) {
        for (int nc = 0; nc < ncol; nc++) {
            //mは粒子番号l,nを選ぶためのパラメタ
            int l = int(uniform_random() * n_all);
            int n = int(uniform_random() * n_all);

            //l=nとなったら粒子番号を再設定
            while (l == n) {
                n = int(uniform_random() * n_all);

                //printf("lc = %d, lc0 = %d", lc[i][j], lc0[i][j]);
                //printf("m = %d, n = %d\n", m, n);

            }
            //							<-- (l,n) is collision pair.

            //gm は相対速度の大きさ
            double gm = sqrt(pow((Part.v[l][0] - Part.v[n][0]), 2.0) + pow((Part.v[l][1] - Part.v[n][1]), 2.0) + pow((Part.v[l][2] - Part.v[n][2]), 2.0));
            //最大衝突法
            if (uniform_random() <= (gm / gmax)) {

                double cs = 1.0 - 2.0*uniform_random();
                double sn = sqrt(1.0 - pow(cs, 2.0));
                double bb = 2.0*M_PI*uniform_random();
                double rx = sn*cos(bb);
                double ry = sn*sin(bb);
                double rz = cs;

                double cxt = Part.v[l][0] + Part.v[n][0];
                double cyt = Part.v[l][1] + Part.v[n][1];
                double czt = Part.v[l][2] + Part.v[n][2];

                //std::cout << "l,before: " << Part.v[l] << std::endl;
                //std::cout << "n,before: " << Part.v[n] << std::endl;
                //粒子が衝突した後の速度に更新
                Part.v[l][0] = 0.5*(cxt - gm*rx);
                Part.v[l][1] = 0.5*(cyt - gm*ry);
                Part.v[l][2] = 0.5*(czt - gm*rz);
                Part.v[n][0] = 0.5*(cxt + gm*rx);
                Part.v[n][1] = 0.5*(cyt + gm*ry);
                Part.v[n][2] = 0.5*(czt + gm*rz);
                //std::cout << "l,after: " << Part.v[l] << std::endl;
                //std::cout << "n,after: " << Part.v[n] << std::endl;
            }
        }
    }
    return 0;
}

//一様分布を返す関数
//ランダム値を毎回出すためには毎回変数に代入すること
double MyDSMC::uniform_random()
{
    static std::random_device rd;
    static std::mt19937 mt(rd());
    static std::uniform_real_distribution<double> dist(0.0, 1.0);

    return dist(mt);
}