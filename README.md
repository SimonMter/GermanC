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

| 🇩🇪 Deutsches Schlüsselwort    | 🇺🇸 C Äquivalent      | 📖 Bedeutung / Beschreibung                                           |
|------------------------------|-----------------------|-----------------------------------------------------------------------|
| `ganzzahl`                   | `int`                 | Ganzzahliger Datentyp                                                 |
| `bitzeichen`                 | `char`                | Zeichen (bitweises Symbol)                                            |
| `zurück`                     | `return`              | Rückgabe aus einer Funktion                                           |
| `soferne`                    | `if`                  | Bedingte Verzweigung                                                  |
| `andernfalls`                | `else`                | Alternative Verzweigung                                               |
| `während`                    | `while`               | Wiederholungsschleife (solange Bedingung wahr ist)                    |
| `durchlaufe`                 | `for`                 | Schleife (wiederholt sich eine festgelegte Anzahl von Malen)          |
| `nichtig`                    | `void`                | Kein Rückgabewert (leerer Rückgabewert)                               |
| `ursprung`                   | `main`                | Einstiegspunkt der Hauptfunktion                                      |
| `unterbrech`                 | `break`               | Verlassen einer Schleife                                              |
| `weitergehen`                | `continue`            | Überspringen der aktuellen Iteration und Fortsetzen der Schleife      |
| `fließkommazahl`             | `float`               | Fließkommazahl (einfache Genauigkeit)                                 |
| `doppelt`                    | `double`              | Fließkommazahl (doppelte Genauigkeit)                                 |
| `lang`                       | `long`                | Lange Ganzzahl                                                        |
| `kurz`                       | `short`               | Kurze Ganzzahl                                                        |
| `gleich`                     | `==`                  | Vergleich auf Gleichheit                                              |
| `nicht_gleich`               | `!=`                  | Vergleich auf Ungleichheit                                            |
| `größer`                     | `>`                   | Vergleich auf Größer als                                              |
| `kleiner`                    | `<`                   | Vergleich auf Kleiner als                                             |
| `größer_oder_gleich`         | `>=`                  | Vergleich auf Größer oder Gleich                                      |
| `kleiner_oder_gleich`        | `<=`                  | Vergleich auf Kleiner oder Gleich                                     |
| `und`                        | `&&`                  | Logisches Und                                                         |
| `oder`                       | `||`                  | Logisches Oder                                                        |
| `nicht`                      | `!`                   | Logisches Nicht                                                       |
| `wahr`                       | `true`                | Wahrheitswert "wahr"                                                  |
| `falsch`                     | `false`               | Wahrheitswert "falsch"                                                |
| `null`                       | `NULL`                | Null-Pointer                                                          |
| `konstant`                   | `const`               | Konstantenbezeichner (unveränderlicher Wert)                          |
| `extern`                     | `extern`              | Externe Verknüpfung, bezeichnet Variablen/Funktionen in anderen Dateien|
| `statisch`                   | `static`              | Statische Speicherung, variablen-spezifisch (lokale Lebensdauer)      |
| `zeichenfolge`               | `char*`               | Zeichenketten (Zeiger auf ein Array von Zeichen)                      |
| `beinhalte`                  | `#include`            | Präprozessor-Direktive zum Einfügen von Header-Dateien                |
| `definieren`                 | `#define`             | Präprozessor-Makrodefinition                                          |
| `kommentar`                  | `//`                  | Einzeilige Kommentar-Markierung                                       |
| `kommentar_block`            | `/* */`               | Block-Kommentar-Markierung                                            |
| `kommentar_block_anfang`     | `/*`                  | Beginn eines Block-Kommentars                                         |
| `kommentar_block_ende`       | `*/`                  | Ende eines Block-Kommentars                                           |
| `strukturen`                 | `struct`              | Strukturdefinition für benutzerdefinierte Datentypen                  |
| `blockzeitlich`              | `auto`                | Block-spezifische automatische Speicherung                            |
| `fallunterscheidung`         | `switch`              | Auswahlstruktur (Verzweigung basierend auf einem Ausdruck)            |
| `fall`                       | `case`                | Fallzweig innerhalb einer `switch`-Struktur                           |
| `vorzeichenfrei`             | `unsigned`            | Vorzeichenloser Modifikator                                           |
| `vorzeichenbehaftet`         | `signed`              | Vorzeichenbehafteter Modifikator                                      |
| `standardfall`               | `default`             | Standardfall innerhalb einer `switch`-Struktur                        |
| `springezu`                  | `goto`                | Unbedingter Sprung zu einer anderen Stelle im Programm                |
| `größewert`                  | `sizeof`              | Bestimmung der Größe eines Datentyps in Bytes                         |
| `unvorhersagbar`             | `volatile`            | Verhindert Optimierung aufgrund externer Veränderungen                |
| `ausführen`                  | `do`                  | `do...while` Schleife (wird mindestens einmal ausgeführt)             |
| `gemeinspeicher`             | `union`               | Gemeinsame Speichernutzung für verschiedene Datentypen                |
| `wertreihe`                  | `enum`                | Aufzählung von benannten Konstanten                                   |
| `typbenennung`               | `typedef`             | Definition von Typaliasen                                             |
| `schnellspeicher`            | `register`            | Hinweis auf schnelle Speicherung von Variablen                        |
| `einfügefunktion`            | `inline`              | Inline-Ersetzung einer Funktion, um den Funktionsaufruf zu vermeiden  |
| `schreibe`                   | `printf`              | Ausgabe auf der Konsole                                               |
| `scanner`                    | `scanf`               | Eingabe von Benutzerdaten über die Konsole                            |
| `hole`                       | `getchar`             | Liest ein Zeichen aus dem Eingabestrom                                |

---


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


̀̀̀---

## License

This project is licensed under the [MIT License](./LICENSE).