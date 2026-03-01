```
////////////////////////////////////////////////////////
//                                                    //
//     _     ____  _   _  _____  _   _  _   _   ____  //
//    / \   / ___|| | | ||_   _|| | | || \ | | / ___| //
//   / _ \ | |    | |_| |  | |  | | | ||  \| || |  _  //
//  / ___ \| |___ |  _  |  | |  | |_| || |\  || |_| | //
// /_/   \_\\____||_| |_|  |_|   \___/ |_| \_| \____| //
//                                                    //
////////////////////////////////////////////////////////
```

# GermanC – Die deutsche C-Alternative

GermanC ist eine Programmiersprache, die in ihrer Funktionsweise dem klassischen C entspricht, jedoch durch die Verwendung deutschsprachiger Schlüsselwörter eine einzigartige stilistische Annäherung bietet. Mit GermanC verfassen Sie Quellcode in vertrauter deutscher Sprache, welcher sodann in regulären C-Code überführt und anschließend kompiliert wird.

---

## Besonderheiten

- Formulierung von C-artigem Quelltext mit deutschsprachigen Befehlen
- Automatische Übersetzung der `.gc`-Dateien in standardkonformen C-Code
- Nahtlose Kompilierung und Ausführung des resultierenden Programms

---

## Einrichtung

### 1. Klonen und Kompilieren
```bash
git clone https://github.com/SimonMter/GermanC
cd GermanC
g++ german_c.cpp Translator.cpp -o germanc
```
### 2. Systemweite Verfügbarkeit einrichten
```bash
./germanc globalize
```
### Anwendungshinweise
Übersetzung einer .gc-Datei
(wenn im Ordner mit germanc)
```bash
./germanc meinprogramm.gc
```
oder nach globalisierung
```bash
./germanc meinprogramm.gc
```
### Der Ablauf:

Übersetzt meinprogramm.gc in die Datei meinprogramm.c

Kompiliert das Ergebnis mittels gcc zu einer ausführbaren Datei
# Deutsche C-Schlüsselwörter

Dieses Dokument enthält eine Liste von deutschen Schlüsselwörtern, die ihren C-Sprachäquivalenten zugeordnet sind, sowie eine detaillierte Beschreibung.

## 📘 Deutsche C-Schlüsselwort-Tabelle



| **GermanC Keyword**      | **C++ Keyword**                           |
| ------------------------ | ----------------------------------------- |
| ganzzahl                 | int                                       |
| bitzeichen               | char                                      |
| zurück                   | return                                    |
| sofern                  | if                                        |
| andernfalls              | else                                      |
| während                  | while                                     |
| durchlaufe               | for                                       |
| nichtig/-e/-er/-es                  | void                                      |
| ursprung                 | main                                      |
| unterbrech               | break                                     |
| weitergehen              | continue                                  |
| fließkommazahl           | float                                     |
| doppelt                  | double                                    |
| lang                     | long                                      |
| kurz                     | short                                     |
| gleich                   | ==                                        |
| nicht\_gleich            | !=                                        |
| größer                   | >                                         |
| kleiner                  | <                                         |
| größer\_oder\_gleich     | >=                                        |
| kleiner\_oder\_gleich    | <=                                        |
| und                      | &&                                        |
| oder                     |                                           |
| nicht/-e/-er/-es                    | !                                         |
| wahr/-e/-er/-es                     | true                                      |
| falsch/-e/-er/-es                   | false                                     |
| eventuell/-e                | Erst durch Beobachtung entscheidet sich das Universum zwischen wahr und falsch|
| null                     | NULL                                      |
| konstant/-e/-er/-es                 | const                                     |
| extern/-e/-er/-es                   | extern                                    |
| statisch/-e/-er/-es                 | static                                    |
| zeichenfolge             | char\*                                    |
| beinhalte                | include                                   |
| definieren               | define                                    |
| kommentar                | //                                        |
| übrigens                 | //by the way                              |
| des weiteren             | //the further                             |
| ich muss ihnen mitteilen | //i must you tell                         |
| wohl gemerkt             | //well noticed                            |
| am rande                 | //at the edge                             |
| nebenbei                 | //next to it                              |
| kleiner hinweis          | //small hint                              |
| ach                      | //oh yes                                  |
| bloß so                  | //just so                                 |
| zur info                 | //to the info                             |
| sei gesagt               | //be said                                 |
| kurzer einwurf           | //short throw-in                          |
| nicht vergessen          | //not forget                              |
| als randnotiz            | //as edge note                            |
| by the way               | //by the way                              |
| wohlgemerkt              | //well noticed (duplicate alias-spelling) |
| kommentar\_block         | /\* \*/                                   |
| kommentar\_block\_anfang | /\*                                       |
| kommentar\_block\_ende   | \*/                                       |
| strukturen               | struct                                    |
| blockzeitlich/-e/-er/-es            | auto                                      |
| fallunterscheidung       | switch                                    |
| fall                     | case                                      |
| vorzeichenfrei/-e/-er/-es           | unsigned                                  |
| vorzeichenbehaftet/-e/-er/-es       | signed                                    |
| standardfall             | default                                   |
| springezu                | goto                                      |
| größewert                | sizeof                                    |
| unvorhersagbar/-e/-er/-es           | volatile                                  |
| ausführen                | do                                        |
| gemeinspeicher           | union                                     |
| wertreihe                | enum                                      |
| typbenennung             | typedef                                   |
| schnellspeicher          | register                                  |
| einfügefunktion          | inline                                    |
| schreibe             | printf           |
| scanner              | scanf            |
| hole                 | getchar          |
| minus                 |  -          |
| plus                  |  +          |
| mal                 |  *          |
| geteilt durch                 |  /          |
| modulo                 |  %          |

### Style Keywörter:
    halt

    tja

    nun

    eben

    schon

    irgendwie

    sozusagen

    quasi

    vielleicht

    ja

    also

    naja

    achso

    bitte

    ehrlichgesagt

    kurz

    jetzt

    schließlich

    tatsächlich

    genaugenommen

    eigentlich

    bedauerlicherweise

    sicherlich

    notfalls

    sowieso

    mal ehrlich

    ehm

    hmm





---


## Anwendungsbeispiel
Beispielcode (beispiel.gc):
```gc
#!/usr/bin/env germanc

ganzzahl ursprung() {
    ganzzahl x = 10;
    sofern (x > 5) {
        zurück x;
    } andernfalls {
        zurück 0;
    }
}
```

### Ausführung
```bash
germanc beispiel.gc
clang beispiel.c -o bsp
./bsp
```

oder
```bash
germanc run beispiel.gc
```


## Systemvoraussetzungen

Eine Linux-basierte Umgebung

g++ zur Übersetzung des GermanC-Interpreters

gcc zur Kompilierung des generierten C-Codes

## Optionale Weitergabe

Der GermanC-Übersetzer lässt sich einmalig kompilieren und als ausführbare Datei weitergeben. Eine lokale C++-Umgebung ist für Endnutzer dann nicht länger erforderlich.
Versionen & Update

**Aktuelle Version: 1.3**

Um sicherzustellen, dass Sie die neueste Version von GermanC haben, können Sie das Repository regelmäßig aktualisieren. Benutzen Sie dafür den folgenden Befehl:
```bash
germanc update
```
Dies wird das Repository aus GitHub klonen, den Quellcode neu kompilieren und die neueste Version systemweit installieren.
Update- und Installation
Update oder Neuinstallation
```
germanc update
```
Dies wird das Repository von GitHub herunterladen, den Code neu kompilieren und das System mit der neuesten Version von germanc versorgen.
Clone-Funktion

Um eine lokale Kopie des GermanC-Repositories zu erstellen, können Sie den folgenden Befehl verwenden:
```
germanc clone <target-directory>
```
Dies wird das Repository in das angegebene Verzeichnis klonen.
Weitere Befehle

### Verfügbare Befehle:

    translate – Nur Übersetzen (kein Kompilieren)

    build – Übersetzen und dann kompilieren

    run – Übersetzen, kompilieren und ausführen

    update – Aktualisiert GermanC von GitHub

    globalize - Globalisiert GermanC

    clone <target-directory> – Klont das Repository nach <target-directory>

    features – Zeigt die unterstützten Sprachmerkmale an

    --version – Zeigt die aktuelle Version

    --help – Zeigt diese Hilfe

---

GermanC ist nun Realität – und sie könnte Ihnen gefährlich werden.

Bei Rückfragen oder etwaigen Komplikationen zögern Sie bitte nicht, sich mitzuteilen.


---

## License

This project is licensed under the [MIT License](./LICENSE).
