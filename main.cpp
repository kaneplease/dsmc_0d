#include <iostream>
#include <fstream>
#include "particles.h"
#include "MyDSMC.h"

int main () {
    //nlast=50 で完全に収束
    int nlast = 100;

    //  各knに応じた
    for(int kn = 4; kn < 5; kn ++){
        double kn_d = static_cast<double>(kn)/10.0;
        particles Part;
        MyDSMC DSMC_0d(Part, kn_d);

        //    std::ofstream ofs_init("Part_init.csv", std::ios::out | std::ios::trunc);
        //    for(int i = 0; i<Part.v.size(); i++){
        //        ofs_init << Part.v[i][0] << "," << Part.v[i][1] << "," << Part.v[i][2] << std::endl;
        //    }

        for(int i = 0; i<nlast; i++){
            DSMC_0d.output_data(i, Part);
            DSMC_0d.collision(Part);
            std::cout << "iter_num: " << i << std::endl;
        }
        DSMC_0d.output_data(nlast, Part);

        //    std::ofstream ofs("Part_fin.csv", std::ios::out | std::ios::trunc);
        //    for(int i = 0; i<Part.v.size(); i++){
        //        ofs << Part.v[i][0] << "," << Part.v[i][1] << "," << Part.v[i][2] << std::endl;
        //    }
    }




    return 0;
}
