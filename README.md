# 🇩🇪 GermanC

**GermanC** is a fun programming language that works exactly like C, but with German keywords.  
You write C code using German words, and this tool will translate it into regular C and compile it

---

## 🚀 Features

- Write C-like code using German keywords
- Translates the gc code into C code which can be then run normally 

---

## 🛠 Installation

### 1. Clone and Build

```bash
git clone https://github.com/SimonMter/GermanC
cd GermanC
g++ german_c.cpp -o germanc
```
2. Make it Globally Available
```bash
sudo cp germanc /usr/local/bin/
sudo chmod +x /usr/local/bin/germanc
```

📜 How to Use
🧪 Translate a .gc File
```bash
./germanc meinprogramm.gc
```

### It will:

Translate meinprogramm.gc to meinprogramm.c

Compile it using gcc


🧠 Supported Keywords
Deutsch	C Equivalent
ganzzahl	int
zeichen	char
leer	void
haupt	main
zurück	return
wenn	if
sonst	else
während	while
für	for
breche	break
fortsetzen	continue

## 🧪 Example
### 📝 beispiel.gc
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

▶️ Run It
```bash
germanc beispiel.gc
clang beispiel.c -o bsp
./bsp
```
🔧 Requirements (as of now)

    Linux

    g++ to compile the translator

    gcc to compile generated C files

📦 Optional: Package for Others

You can compile germanc once and share the binary. No C++ required on the user’s system afterwards!

https://www.instagram.com/p/DGHY4zSqkhw/?igsh=bzk3cDh4MnNxOHY5

now GermanC is real and it can hurt you :)




---

Let me know if you'd like me to:
- Add a logo or emoji header
- Make this a GitHub repo template
- Include setup scripts for easier onboarding

Want me to generate a real example `.gc` file to go along with this?
