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
g++ german_c.cpp -o germanc
```
### 2. Systemweite Verfügbarkeit einrichten
```bash
germanc globalize
```
### Anwendungshinweise
Übersetzung einer .gc-Datei
```bash
./germanc meinprogramm.gc
```
### Der Ablauf:

Übersetzt meinprogramm.gc in die Datei meinprogramm.c

Kompiliert das Ergebnis mittels gcc zu einer ausführbaren Datei

## Unterstützte Schlüsselwörter
| Deutsch                     | C Equivalent   |
|-----------------------------|----------------|
| ganzzahl                    | int            |
| zeichen                     | char           |
| leer                        | void           |
| haupt                       | main           |
| zurück                      | return         |
| wenn                         | if             |
| sonst                        | else           |
| während                      | while          |
| für                          | for            |
| breche                       | break          |
| fortsetzen                   | continue       |
| fließkommazahl               | float          |
| doppelt                      | double         |
| lang                         | long           |
| kurz                         | short          |
| gleich                       | ==             |
| nicht_gleich                 | !=             |
| größer                       | >              |
| kleiner                      | <              |
| größer_oder_gleich           | >=             |
| kleiner_oder_gleich          | <=             |
| und                          | &&             |
| oder                         |                |
| nicht                        | !              |
| wahr                         | true           |
| falsch                       | false          |
| null                         | NULL           |
| konstant                     | const          |
| extern                       | extern         |
| statisch                     | static         |
| zeichenfolge                 | char*          |
| beinhalte                    | include        |
| definieren                   | define         |
| kommentar                    | //             |
| kommentar_block              | /* */          |
| kommentar_block_anfang       | /*             |
| kommentar_block_ende         | */             |
| strukturen                   | struct         |
| union                        | union          |
| enum                         | enum           |
| typedef                      | typedef        |
| volatile                     | volatile       |
| register                     | register       |
| inline                       | inline         |

## Anwendungsbeispiel
Beispielcode (beispiel.gc):
```gc
#!/usr/bin/env germanc

ganzzahl haupt() {
    ganzzahl x = 10;
    wenn (x > 5) {
        zurück x;
    } sonst {
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

**Aktuelle Version: 1.1.2**

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

Mehr Informationen unter: https://github.com/SimonMter/GermanC
