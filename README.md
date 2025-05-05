
# 🇩🇪 GermanC – Die deutsche C-Alternative

GermanC ist eine Programmiersprache, die in ihrer Funktionsweise dem klassischen C entspricht, jedoch durch die Verwendung deutschsprachiger Schlüsselwörter eine einzigartige stilistische Annäherung bietet.
Mit GermanC verfassen Sie Quellcode in vertrauter deutscher Sprache, welcher sodann in regulären C-Code überführt und anschließend kompiliert wird.


---

## 🚀 Besonderheiten

Formulierung von C-artigem Quelltext mit deutschsprachigen Befehlen

Automatische Übersetzung der .gc-Dateien in standardkonformen C-Code

Nahtlose Kompilierung und Ausführung des resultierenden Programms



---

## 🛠 Einrichtung

### 1. Klonen und Kompilieren

git clone https://github.com/SimonMter/GermanC
cd GermanC
g++ german_c.cpp -o germanc

### 2. Systemweite Verfügbarkeit einrichten

sudo cp germanc /usr/local/bin/
sudo chmod +x /usr/local/bin/germanc


---

## 📜 Anwendungshinweise

### 🧪 Übersetzung einer .gc-Datei

./germanc meinprogramm.gc

Der Ablauf:

Übersetzt meinprogramm.gc in die Datei meinprogramm.c

Kompiliert das Ergebnis mittels gcc zu einer ausführbaren Datei



---

## 🧠 Unterstützte Schlüsselwörter


---

## 🧪 Anwendungsbeispiel

📝 beispiel.gc

#!/usr/bin/env germanc

ganzzahl haupt() {
    ganzzahl x = 10;
    wenn (x > 5) {
        zurück x;
    } sonst {
        zurück 0;
    }
}

▶️ ### Ausführung

germanc beispiel.gc
clang beispiel.c -o bsp
./bsp


---

## 🔧 Systemvoraussetzungen

Eine Linux-basierte Umgebung

g++ zur Übersetzung des GermanC-Interpreters

gcc zur Kompilierung des generierten C-Codes



---

## 📦 Optionale Weitergabe

Der GermanC-Übersetzer lässt sich einmalig kompilieren und als ausführbare Datei weitergeben. Eine lokale C++-Umgebung ist für Endnutzer dann nicht länger erforderlich.

---

> https://www.instagram.com/p/DGHY4zSqkhw/?igsh=bzk3cDh4MnNxOHY5


GermanC ist nun Realität – und sie könnte Ihnen gefährlich werden.


---

Bei Rückfragen oder etwaigen Komplikationen zögern Sie bitte nicht, sich mitzuteilen.
