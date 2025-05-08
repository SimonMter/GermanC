#include <iostream>
#include <fstream>
#include <unordered_map>
#include <map>
#include <sstream>
#include <regex>
#include <cstdlib>
#include <tuple>
#include <cctype>
#include "Translator.h"

const std::string GERMC_VERSION = "1.2.2";

std::unordered_map<std::string, std::string> keyword_map = {
    {"ganzzahl", "int"},
    {"bitzeichen", "char"},
    {"zurück", "return"},
    {"soferne", "if"},
    {"andernfalls", "else"},
    {"während", "while"},
    {"durchlaufe", "for"},
    {"nichtig", "void"},
    {"ursprung", "main"},
    {"unterbrech", "break"},
    {"weitergehen", "continue"},
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
    {"blockzeitlich", "auto"},
    {"fallunterscheidung", "switch"},
    {"fall", "case"},
    {"vorzeichenfrei", "unsigned"},
    {"vorzeichenbehaftet", "signed"},
    {"standardfall","default"},
    {"springezu","goto"},
    {"größewert","sizeof"},
    {"unvorhersagbar", "volatile"},
    {"ausführen","do"},
    {"gemeinspeicher", "union"},
    {"wertreihe", "enum"},
    {"typbenennung", "typedef"},
    {"schnellspeicher", "register"},
    {"einfügefunktion", "inline"}
    
};

std::unordered_map<std::string, std::string> function_map = {
    {"schreibe", "printf"},
    {"scanner", "scanf"},
    {"hole", "getchar"},
};

std::unordered_map<std::string, std::string> func_map = {
    {"ganzzahl", "int"},
    {"zeichen", "char"},
    {"leer", "void"},
};


std::vector<std::string> stilwoerter = {
    "halt",
    "tja",
    "nun",
    "eben",
    "schon",
    "irgendwie",
    "sozusagen",
    "quasi",
    "vielleicht",
    "ja",
    "also",
    "naja",
    "achso",
    "bitte",
    "ehrlichgesagt",
    "kurz",
    "jetzt",
    "schließlich",
    "tatsächlich",
    "übrigens",
    "genaugenommen",
    "eigentlich",
    "bedauerlicherweise",
    "sicherlich",
    "notfalls",
    "sowieso",
    "mal ehrlich",
    "ehm",
    "hmm"
};

std::unordered_map<std::string, int> units = {
    {"null", 0}, {"eins", 1}, {"ein", 1}, {"zwei", 2}, {"drei", 3}, {"vier", 4},
    {"fünf", 5}, {"sechs", 6}, {"sieben", 7}, {"acht", 8}, {"neun", 9}
};

std::unordered_map<std::string, int> teens = {
    {"zehn", 10}, {"elf", 11}, {"zwölf", 12}, {"dreizehn", 13}, {"vierzehn", 14},
    {"fünfzehn", 15}, {"sechzehn", 16}, {"siebzehn", 17}, {"achtzehn", 18}, {"neunzehn", 19}
};

std::unordered_map<std::string, int> tens = {
    {"zwanzig", 20}, {"dreißig", 30}, {"vierzig", 40}, {"fünfzig", 50},
    {"sechzig", 60}, {"siebzig", 70}, {"achtzig", 80}, {"neunzig", 90}
};

std::unordered_map<std::string, int> magnitudes = {
    {"hundert", 100},
    {"tausend", 1000},
    {"million", 1000000}, {"millionen", 1000000},
    {"milliarde", 1000000000}, {"milliarden", 1000000000}
};

int parseGermanNumber(std::string word);

int extractAndRemove(std::string& word, const std::unordered_map<std::string, int>& dict) {
    for (const auto& pair : dict) {
        if (word.find(pair.first) == 0) {
            word = word.substr(pair.first.length());
            return pair.second;
        }
    }
    return -1;
}

int parseBlock(std::string& word) {
    int value = 0;

    std::size_t undPos = word.find("und");
    if (undPos != std::string::npos && undPos + 3 < word.length()) {
        std::string unitPart = word.substr(0, undPos);
        std::string tenPart = word.substr(undPos + 3);
        int unitsValue = parseGermanNumber(unitPart);
        int tensValue = parseGermanNumber(tenPart);
        word = "";
        return unitsValue + tensValue;
    }

    int t = extractAndRemove(word, teens);
    if (t != -1) return t;

    t = extractAndRemove(word, tens);
    if (t != -1) return t;

    t = extractAndRemove(word, units);
    if (t != -1) return t;

    return 0;
}

int parseGermanNumber(std::string word) {
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    int total = 0;
    int current = 0;

    for (const auto& pair : magnitudes) {
        std::size_t pos = word.find(pair.first);
        if (pos != std::string::npos) {
            std::string prefix = word.substr(0, pos);
            std::string suffix = word.substr(pos + pair.first.length());
            int multiplier = parseGermanNumber(prefix.empty() ? "eins" : prefix);
            total += multiplier * pair.second;
            word = suffix;
            return total + parseGermanNumber(word);
        }
    }

    std::size_t pos = word.find("hundert");
    if (pos != std::string::npos) {
        std::string prefix = word.substr(0, pos);
        std::string suffix = word.substr(pos + 7);
        current += (prefix.empty() ? 1 : parseGermanNumber(prefix)) * 100;
        current += parseGermanNumber(suffix);
        return total + current;
    }

    return total + parseBlock(word);
}

bool isValidGermanNumberWord(const std::string& word) {
    try {
        parseGermanNumber(word);
        return true;
    } catch (...) {
        return false;
    }
}

std::string germanNumberWordToString(const std::string& word) {
    return std::to_string(parseGermanNumber(word));
}

std::string replaceGermanNumbersInText(const std::string& input) {
    std::regex wordRegex(R"([a-zA-ZäöüÄÖÜß]+)");
    std::sregex_iterator it(input.begin(), input.end(), wordRegex);
    std::sregex_iterator end;

    std::string output;
    std::size_t lastPos = 0;

    for (; it != end; ++it) {
        std::smatch match = *it;
        std::size_t start = match.position();
        std::size_t length = match.length();
        std::string word = match.str();

        // Add non-word characters between last and this word
        output += input.substr(lastPos, start - lastPos);

        // Try to parse number word
        try {
            std::string numberStr = germanNumberWordToString(word);
            if (!numberStr.empty() && std::stoi(numberStr) > 0) {
                output += numberStr;
            } else {
                output += word;
            }
        } catch (...) {
            output += word;
        }

        lastPos = start + length;
    }

    // Add remaining non-word characters
    output += input.substr(lastPos);

    return output;
}



std::string remove_stilwoerter(const std::string& line) {
    std::string result = line;
    for (const auto& word : stilwoerter) {
        std::regex pattern("(^|\\s)" + word + "(\\s|$)");
        result = std::regex_replace(result, pattern, "");
    }
    return result;
}
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
    translated = remove_stilwoerter(translated);
    for(const auto& [german, cword] : keyword_map){
        std::regex pattern("\\b" + german + "\\b");
        translated = std::regex_replace(translated, pattern, cword);
    }

    translated = translate_function_calls(translated);
    translated = translate_function_signature(translated);
    translated = translate_arrays(translated);
    
    translated = replaceGermanNumbersInText(translated);
    translated = Translator::translate_comment(translated);
    return translated;
}


int main(int argc, char* argv[]) {
    if (argc == 2 && std::string(argv[1]) == "--version") {
        std::cout << "germanc Version " << GERMC_VERSION << std::endl;
        return 0;
    }
    


    if (argc == 2 && (std::string(argv[1]) == "update" || std::string(argv[1]) == "aktualisiere-die-Weisheit")) {
        std::cout << "➤ Aktualisiere von GitHub...\n";
        
        system("rm -rf GermanC");
        int clone_status = system("git clone https://github.com/SimonMter/GermanC.git");
    
        if (clone_status != 0) {
            std::cerr << "Fehler beim Klonen des Repositories.\n";
            return 1;
        }
    
        std::cout << "➤ Kompiliere german_c.cpp...\n";
        int compile_status = system("g++ GermanC/german_c.cpp GermanC/Translator.cpp -o germanc");

        if (compile_status != 0) {
            std::cerr << "Fehler beim Kompilieren von german_c.cpp.\n";
            return 1;
        }
    
        std::cout << "➤ Installiere 'germanc' systemweit...\n";
        std::string copy_cmd = "sudo cp germanc /usr/local/bin/germanc.new";
        std::string move_cmd = "sudo mv /usr/local/bin/germanc.new /usr/local/bin/germanc";
        std::string chmod_cmd = "sudo chmod +x /usr/local/bin/germanc";

        int copy_status = system(copy_cmd.c_str());
        int move_status = system(move_cmd.c_str());
        int chmod_status = system(chmod_cmd.c_str());

    
        if (copy_status == 0 && chmod_status == 0) {
            std::cout << "'germanc' wurde erfolgreich aktualisiert und global installiert.\n";
            return 0;
        } else {
            std::cerr << "Fehler beim Kopieren oder Setzen der Rechte für 'germanc'.\n";
            return 1;
        }
    }
    if (argc == 2 && (std::string(argv[1]) == "--help" || std::string(argv[1]) == "Anleitung-zur-rechten-Handhabung")) {
        std::cout << "GERMANC " << GERMC_VERSION << " – der Übersetzer der deutschen C-Weisheit\n\n"
                  << "Benutzung:\n"
                  << "  germanc <Datei.gc>                      Übersetzt und kompiliert die Datei\n"
                  << "  germanc translate <Datei.gc>           Nur übersetzen (kein Kompilieren)\n"
                  << "  germanc build <Datei.gc>               Übersetzen und dann kompilieren\n"
                  << "  germanc run <Datei.gc>                 Übersetzen, kompilieren und ausführen\n"
                  << "\n"
                  << "Verfügbare Befehle (auch auf Deutsch!):\n"
                  << "  update | aktualisiere-die-Weisheit     Lade und installiere neueste Version\n"
                  << "  globalize | verbreite-den-Übersetzer-...   Installiere systemweit\n"
                  << "     --delete                            Entfernt lokale Kopie nach Installation\n"
                  << "  features | Kunstfertigkeiten-des-Werkes Zeigt unterstützte Sprachmerkmale\n"
                  << "  --version                              Zeigt die aktuelle Version\n"
                  << "  --help | Anleitung-zur-rechten-Handhabung  Zeigt diese Hilfe\n"
                  << "\n"
                  << "Beispiel:\n"
                  << "  germanc programm.gc\n"
                  << "  germanc build mein_code.gc\n"
                  << "  germanc run test.gc\n\n"
                  << "Mehr Informationen unter: https://github.com/SimonMter/GermanC\n";
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
        outfile.close();
        std::cout << "Übersetzung abgeschlossem: " << output_filename <<"\n";

        std::string exec_name = output_filename.substr(0, output_filename.find_last_of('.'));

        std::string compile_cmd = "gcc " + output_filename + " -o " + exec_name;
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


        std::string self_path = argv[0];
        std::string copy_cmd = "sudo cp \"" + self_path + "\" /usr/local/bin/germanc";

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
            outfile.close();
            std::cout << "Übersetzung abgeschlossem: " << output_filename <<"\n";

            return 0;
        } else if (cmd == "build" || cmd == "schmiede-den-Quell-wie-ein-Runenschreiber-am-Amboss") {
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
            outfile.close();
            std::string exec_name = output_filename.substr(0, output_filename.find_last_of('.'));
            std::cout << "Übersetzung abgeschlossem: " << output_filename <<"\n";

            std::string compile_cmd = "gcc " + output_filename + " -o " + exec_name;
            std::cout << "Kompilieren mit Befehl: " << compile_cmd << std::endl;

            int compile_result = system(compile_cmd.c_str());

            std::cout << "Kompiliert.\n";

            return 0;
        } else if (cmd == "clone" || cmd == "hole-das-Werk-hernieder-aus-dem-Wolkenturme-GitHubs") {
            std::string target_dir = argv[2];
        
            std::string clone_cmd = "git clone https://github.com/SimonMter/GermanC.git " + target_dir;
        
            std::cout << "➤ Klone Repository nach '" << target_dir << "'...\n";
            int result = system(clone_cmd.c_str());
        
            if (result == 0) {
                std::cout << "Repository erfolgreich geklont.\n";
                std::cout << "Inhalt von " << target_dir << ":\n";
                std::string list_cmd = "ls " + target_dir;
                system(list_cmd.c_str());
                return 0;
            } else {
                std::cerr << "Fehler beim Klonen des Repositories.\n";
                return 1;
            }
        }
        else if (cmd == "run" || cmd == "führe-das-Artefakt-zur-Ausführung-auf-dass-der-Compiler-frohlocke") {
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
            outfile.close();
            std::string exec_name = output_filename.substr(0, output_filename.find_last_of('.'));
            std::cout << "Übersetzung abgeschlossem: " << output_filename <<"\n";

            std::string compile_cmd = "gcc " + output_filename + " -o " + exec_name;
            std::cout << "Kompilieren mit Befehl: " << compile_cmd << std::endl;

            int compile_result = system(compile_cmd.c_str());
            std::cout << "Kompiliert.\n";

            std::string run_cmd = "./" + exec_name;
            int run_result = system(run_cmd.c_str());

            std::cout << "Ausgeführt.\n";

            return 0;
        }
    }

}
