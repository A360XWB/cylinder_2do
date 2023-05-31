#include <iostream>
#include <fstream>

int main(){
    std::ofstream ofs;
    
    std::cout << "Please enter the cell number for the specific zone: \n";
    int N, incr;
    std::cin >> N;
    std::cout << "Please input the increment of the cell number if needed (0 for no increment): \n";
    std:: cin >> incr;

    ofs.open("cellZones");
    if (!ofs.is_open()){
	std::cerr << "Failed to open file.\n";
	return 1;
    }

    // logo and settings
    ofs << "/*--------------------------------*- C++ -*----------------------------------*\\\n";
    ofs << "| =========                 |                                                 |\n";
    ofs << "| \\\\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox           |\n";
    ofs << "|  \\\\    /   O peration     | Version:  2206                                  |\n";
    ofs << "|   \\\\  /    A nd           | Website:  www.openfoam.com                      |\n";
    ofs << "|    \\\\/     M anipulation  |                                                 |\n";
    ofs << "\\*---------------------------------------------------------------------------*/\n";
    ofs << "FoamFile\n" << "{\n" << "    version     2.0;\n" << "    format      ascii;\n";
    ofs << "    arch        \"LSB;label=32;scalar=64\";\n";
    ofs << "    class       regIOobject;\n";
    ofs << "    location    \"constant/polyMesh\";\n";
    ofs << "    object      cellZones;\n";
    ofs << "    meta\n    {\n        names        1 ( rotor );\n    }\n\n}\n";
    ofs << "// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //\n\n";
    ofs << "1\n(rotor\n{\n    type        cellZone;\n    cellLabels  List<label>\n";
    ofs << N;
    ofs << "\n(\n";
    
    // main loop
    for (auto i = 0; i < N; i++){
        ofs << "           " << i + incr << "\n";           
    }
   
    ofs << ")\n;\n}\n)\n\n";
    ofs << "// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //\n";

    ofs.close();
    return 0;

}

