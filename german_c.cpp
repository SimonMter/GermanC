#include <iostream>
#include <fstream>
#include <unordered_map>
#include <sstream>
#include <regex>
#include <cstdlib>

const std::string GERMC_VERSION = "1.1.0 - beta";

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
    {"fortsetzen", "continue"},
    {"fließkommazahl", "float"},
    {"doppelt", "double"},
    {"lang", "long"},
    {"kurz", "short"},
    {"gleich", "=="},
    {"nicht_gleich", "!="},
    {"größer", ">"},
    {"kleiner", "<"},
    {"größer_oder_gleich", ">="},
    {"kleiner_oder_gleich", "<="},
    {"und", "&&"},                 
    {"oder", "||"},                 
    {"nicht", "!"},
    {"wahr", "true"},
    {"falsch", "false"},
    {"null", "NULL"},
    {"konstant", "const"},
    {"extern", "extern"},
    {"statisch", "static"},
    {"zeichenfolge", "char*"},
    {"beinhalte", "include"},
    {"definieren", "define"},
    {"kommentar", "//"},
    {"kommentar_block", "/* */"},
    {"kommentar_block_anfang", "/*"},
    {"kommentar_block_ende", "*/"},
    {"strukturen", "struct"},
    {"union", "union"},
    {"enum", "enum"},
    {"typedef", "typedef"},
    {"volatile", "volatile"},
    {"register", "register"},
    {"inline", "inline"},
};

std::unordered_map<std::string, std::string> function_map = {
    {"schreibe", "printf"},
    {"scanner", "scanf"},
    {"hole", "getchar"} 
};

std::unordered_map<std::string, std::string> func_map = {
    {"ganzzahl", "int"},
    {"zeichen", "char"},
    {"leer", "void"},
};





std::string translate_function_calls(const std::string& line) {
    std::string translated = line;
    for (const auto& [german_func, c_func] : function_map) {
        std::regex pattern("\\b" + german_func + "\\b");
        translated = std::regex_replace(translated, pattern, c_func);
    }
    return translated;
}

std::string translate_function_signature(const std::string& line) {
    std::string translated = line;
    for (const auto& [german_type, c_type] : func_map) {
        std::regex pattern("\\b" + german_type + "\\b");
        translated = std::regex_replace(translated, pattern, c_type);
    }
    return translated;
}

std::string translate_arrays(const std::string& line) {
    std::regex array_pattern("\\b(ganzzahl|zeichen)\\s+([a-zA-Z_][a-zA-Z0-9_]*)\\s*\\[\\d+\\]");
    return std::regex_replace(line, array_pattern, "$1 $2[]");
}


std::string translate_line(const std::string& line){
    std::string translated = line;
    for(const auto& [german, cword] : keyword_map){
        std::regex pattern("\\b" + german + "\\b");
        translated = std::regex_replace(translated, pattern, cword);
    }

    translated = translate_function_calls(translated);
    translated = translate_function_signature(translated);
    translated = translate_arrays(translated);
    return translated;
}


int main(int argc, char* argv[]) {
    if (argc == 2 && std::string(argv[1]) == "--version") {
        std::cout << "germanc Version " << GERMC_VERSION << std::endl;
        return 0;
    }

    if (std::string(argv[1]) == "--help" || std::string(argv[1]) == "Anleitung-zur-rechten-Handhabung") {
        std::cout << "Benutzung: germanc <Datei.gc>\n"
                  << "Optionen:\n"
                  << "  --version      Zeigt die aktuelle Version\n"
                  << "  --help         Zeigt die Anleitung zur rechten Handhabung\n";
        return 0;
    }
    

    if (argc > 3) {
        std::cerr << "Benutzung: germanc <Datei.gc>\n";
        std::cerr << "Oder: germanc --version\n";
        return 1;
    }
    if (argc == 2 &&
        !(std::string(argv[1]) == "features" || std::string(argv[1]) == "Kunstfertigkeiten-des-Werkes") &&
        !(std::string(argv[1]) == "globalize" || std::string(argv[1]) == "verbreite-den-Übersetzer-weit-und-breit-im-Reich-der-Binärmagie")) {

        std::ifstream infile(argv[1]);
        if(!infile){
            std::cerr << "Fehler: Datei konnte nicht geöffnet werden. \n";
            std::cout << argv[1];
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
            outfile << translate_line(line) << "\n";
        }
        std::cout << "Übersetzung abgeschlossem: " << output_filename <<"\n";

        std::string compile_cmd = "gcc " + output_filename + " -o out_program";
        std::cout << "Kompilieren mit Befehl: " << compile_cmd << std::endl;

        int compile_result = system(compile_cmd.c_str());

        std::cout << "Kompeliert.\n";

        return 0;
    }
    if (argc == 2 &&
        (std::string(argv[1]) == "features" || std::string(argv[1]) == "Kunstfertigkeiten-des-Werkes")) {
        std::cout << "GERMC Features:\n"
                  << "- Übersetzt Deutsch-ähnliche C-Syntax in echtes C\n"
                  << "- Unterstützt if/else, loops, datentypen, Funktionen, etc.\n"
                  << "- Kompiliert direkt nach der Übersetzung mit gcc\n"
                  << "- Unterstützt shebang-Erkennung\n"
                  << "- Optionale Funktionsnamenübersetzung\n";
        return 0;
    }if ((argc == 2 && (std::string(argv[1]) == "globalize" || std::string(argv[1]) == "verbreite-den-Übersetzer-weit-und-breit-im-Reich-der-Binärmagie")) ||
    (argc == 3 && (std::string(argv[1]) == "globalize" || std::string(argv[1]) == "verbreite-den-Übersetzer-weit-und-breit-im-Reich-der-Binärmagie") &&
     std::string(argv[2]) == "--delete")) {


        std::string copy_cmd = "sudo cp germanc /usr/local/bin/";
        std::string chmod_cmd = "sudo chmod +x /usr/local/bin/germanc";
        std::string delete_cmd = "rm -f germanc";

        std::cout << "➤ Kopiere 'germanc' nach /usr/local/bin ...\n";
        int copy_status = system(copy_cmd.c_str());
        
        int chmod_status = system(chmod_cmd.c_str());

        if (copy_status == 0 && chmod_status == 0) {
            std::cout << "'germanc' ist nun systemweit verfügbar.\n";

            if (argc == 3 && std::string(argv[2]) == "--delete") {
                std::cout << "➤ Lokale Datei wird gelöscht ...\n";
                int del_status = system(delete_cmd.c_str());
                if (del_status == 0) {
                    std::cout << "Lokale Datei erfolgreich entfernt.\n";
                } else {
                    std::cerr << "Fehler beim Löschen der lokalen Datei.\n";
                }
            }

            return 0;
        } else {
            std::cerr << "Fehler beim Kopieren oder Setzen der Rechte.\n";
            return 1;
        }
    }


    if(argc == 3){
        std::string cmd = std::string(argv[1]);
        if (cmd == "translate" || cmd == "übersetze-mit-heiligem-Ernst") {
            std::ifstream infile(argv[2]);
            if(!infile){
                std::cerr << "Fehler: Datei konnte nicht geöffnet werden. \n";
                return 1;
            }
            std::string input_filename = argv[2];
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
                outfile << translate_line(line) << "\n";
            }
            std::cout << "Übersetzung abgeschlossem: " << output_filename <<"\n";

            std::string compile_cmd = "gcc " + output_filename + " -o out_program";
            std::cout << "Kompilieren mit Befehl: " << compile_cmd << std::endl;

            int compile_result = system(compile_cmd.c_str());

            std::cout << "Kompiliert.\n";

            return 0;
        } else if (cmd == "build" || cmd == "schmiede-den-Quell-wie-ein-Runenschreiber-am-Amboss") {

        } else if (cmd == "clone" || cmd == "hole-das-Werk-hernieder-aus-dem-Wolkenturme-GitHubs") {

        } else if (cmd == "run" || cmd == "führe-das-Artefakt-zur-Ausführung-auf-dass-der-Compiler-frohlocke") {

        }
        
        
    }

}
