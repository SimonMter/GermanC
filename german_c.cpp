#include <iostream>
#include <fstream>
#include <unordered_map>
#include <sstream>
#include <regex>
#include <cstdlib>

const std::string GERMC_VERSION = "1.0.0"; // Change as needed

std::unordered_map<std::string, std::string> keyword_map = {
    {"ganzzahl", "int"},
    {"zeichen", "char"},
    {"zurück", "return"},
    {"wenn", "if"},
    {"sonst", "else"},
    {"während", "while"},
    {"für", "for"},
    {"leer", "void"},
    {"haupt", "main"},
    {"breche", "break"},
    {"fortsetzen", "continue"}
};

std::string tranlate_line(const std::string& line){
    std::string translated = line;
    for(const auto& [german, cword] : keyword_map){
        std::regex pattern("\\b" + german + "\\b");
        translated = std::regex_replace(translated, pattern, cword);
    }
    return translated;
}

int main(int argc, char* argv[]) {
    if (argc == 2 && std::string(argv[1]) == "--version") {
        std::cout << "germanc Version " << GERMC_VERSION << std::endl;
        return 0;
    }

    if (std::string(argv[1]) == "--help") {
        std::cout << "Benutzung: germanc <Datei.gc>\n"
                  << "Optionen:\n"
                  << "  --version      Zeigt die aktuelle Version\n"
                  << "  --help         Zeigt diese Hilfe\n";
        return 0;
    }
    

    if (argc != 2) {
        std::cerr << "Benutzung: germanc <Datei.gc>\n";
        std::cerr << "Oder: germanc --version\n";
        return 1;
    }

    std::ifstream infile(argv[1]);
    if(!infile){
        std::cerr << "Fehler: Datei konnte nicht geöffnet werden. \n";
        return 1;
    }

    std::string input_filename = argv[1];
    std::string output_filename = input_filename;
    size_t pos = output_filename.find(".gc");
    if(pos != std::string::npos){
        output_filename.replace(pos, 3, ".c");
    }else{
        output_filename += ".c";
    }

    std::ofstream outfile(output_filename);
    if(!outfile){
        std::cerr << "Fehler beim Schreiben der Ausgabedatei.\n";
        return 1;
    }

    std::string line;
    bool is_shebang = true;
    outfile << "#include <stdio.h>\n";
    while(std::getline(infile, line)){

        if (is_shebang && line.find("#!") == 0) {
            is_shebang = false;
            continue;
        }
        outfile << tranlate_line(line) << "\n";
    }
    std::cout << "Übersetzung abgeschlossem: " << output_filename <<"\n";

    std::string compile_cmd = "gcc " + output_filename + " -o out_program";
    std::cout << "Kompilieren mit Befehl: " << compile_cmd << std::endl;

    int compile_result = system(compile_cmd.c_str());

    if(compile_result != 0){
        std::cerr << "Fehler beim Kompelieren.\n";
        return 1;
    }

    int run_result = system("./out_program");
    if(run_result != 0){
        std::cerr << "Fehler beim Ausführen des Programms.\n";
    }
    
    std::remove("out_program");

    return 0;
}