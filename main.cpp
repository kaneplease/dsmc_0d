#include <iostream>
#include <fstream>
#include "particles.h"
#include "MyDSMC.h"

int main () {
    int nlast = 1000;

    particles Part;
    MyDSMC DSMC_0d(Part);

    std::ofstream ofs_init("Part_init.csv", std::ios::out | std::ios::trunc);
    for(int i = 0; i<Part.v.size(); i++){
        ofs_init << Part.v[i][0] << "," << Part.v[i][1] << "," << Part.v[i][2] << std::endl;
    }

    for(int i = 0; i<nlast; i++){
        DSMC_0d.collision(Part);
    }

    std::ofstream ofs("Part_fin.csv", std::ios::out | std::ios::trunc);
    for(int i = 0; i<Part.v.size(); i++){
        ofs << Part.v[i][0] << "," << Part.v[i][1] << "," << Part.v[i][2] << std::endl;
    }

    return 0;
}