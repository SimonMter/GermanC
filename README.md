# 🇩🇪 GermanC

**GermanC** is a fun programming language that works exactly like C, but with German keywords.  
You write C code using German words, and this tool will translate it into regular C, compile it, and run it.

---

## 🚀 Features

- Write C-like code using German keywords
- Automatically translates `.gc` to `.c`
- Compiles and runs the result
- You can run `.gc` files directly like scripts!

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
🧪 Translate & Run a .gc File
```bash
./germanc meinprogramm.gc
```

It will:

    Translate meinprogramm.gc to meinprogramm.c

    Compile it using gcc

    Run the output

🔁 Or Run .gc Files Directly

Add this to the top of your .gc file:
```gc
#!/usr/bin/env germanc
```
Then make it executable:
```bash
chmod +x meinprogramm.gc
```
Now you can run it like a shell script:
```bash
./meinprogramm.gc
```
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
./beispiel.gc
```
🔧 Requirements (as of now)

    Linux

    g++ to compile the translator

    gcc to compile generated C files

📦 Optional: Package for Others

You can compile germanc once and share the binary. No C++ or Java required on the user’s system!

Have fun coding in Deutsch! 🇩🇪💻


---

Let me know if you'd like me to:
- Add a logo or emoji header
- Make this a GitHub repo template
- Include setup scripts for easier onboarding

Want me to generate a real example `.gc` file to go along with this?
