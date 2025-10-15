#include <iostream>
#include <string>
#include <cstdlib>

std::string getFileExtension(const std::string& filename) {

    size_t pos = filename.rfind('.');

    if (pos != std::string::npos) {

        return filename.substr(pos + 1);

    }

    return "";

}

int main(int argc, char* argv[]) {

    if (argc < 4 || std::string(argv[2]) != "as") {

        std::cout << "\n--------------------------- pile ----------------------------\n\nUsage: pile <source_file> as <output_name> (Optional: with <args>)\n\n";
        std::cout << "\nSupported file types:\n-------------------------------------------------------------\nC:       | .c\nC++:     | .cpp\nFORTRAN: | .f, .for, .ftn, .f77, .f90, .f95, .f03, .f08, .f18\nRust:    | .rs\nAssembly:| .asm\n-------------------------------------------------------------\n\nNeed help? https://github.com/HudsonGageTaylor/pile\n\n";

        return 1;

    }

    // VARIABLES //
    std::string outputName, extraArgs = "", gppCommand, gccCommand, rustcCommand, gfortranCommand, asmCommand, linkCommand;
    std::string filename = argv[1];
    std::string extension = getFileExtension(filename);
    outputName = argv[3];

    // Parse extra args after "with"
    if (argc > 5 && std::string(argv[4]) == "with") {
        for (int i = 5; i < argc; ++i) {
            extraArgs += std::string(argv[i]) + " ";
        }
    }
    ///////////////

    if (extension == "cpp") {

        gppCommand = "g++ " + filename + " -o " + outputName + ".exe " + extraArgs + "-static -nostdlib";

        system(gppCommand.c_str());

    }

    else if (extension == "c") {

        gccCommand = "gcc " + filename + " -o " + outputName + ".exe " + extraArgs + "-static -static-libgcc";

        system(gccCommand.c_str());

    }

    else if (extension == "rs") {

        rustcCommand = "rustc " + filename + " -o " + outputName + ".exe " + extraArgs;

        system(rustcCommand.c_str());

    }

    else if (extension == "f" || extension == "for" || extension == "ftn" || extension == "f77" || extension == "f90" || extension == "f95" || extension == "f03" || extension == "f08" || extension == "f18") {

        gfortranCommand = "gfortran " + filename + " -o " + outputName + ".exe " + extraArgs + "-static -static-libgfortran -static-libgcc";

        system(gfortranCommand.c_str());

    }

    else if (extension == "asm") {

        asmCommand = "as " + filename + " -o " + outputName + ".o " + extraArgs;
        linkCommand = "gcc " + outputName + ".o -o " + outputName + ".exe -static";

        system(asmCommand.c_str());
        system(linkCommand.c_str());

    }

    else {

        std::cout << "\n\n--------------------------- pile ----------------------------";
        std::cout << "\n\nUnknown file type!";
        std::cout << "\nSupported file types:\n-------------------------------------------------------------\nC:       | .c\nC++:     | .cpp\nFORTRAN: | .f, .for, .ftn, .f77, .f90, .f95, .f03, .f08, .f18\nRust:    | .rs\nAssembly:| .asm\n-------------------------------------------------------------\n\nNeed help? https://github.com/HudsonGageTaylor/pile";
        return 0;
    }

    return 0;

}
