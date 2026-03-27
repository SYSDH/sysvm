<h1 align="center">SYSVM</h1>

<p align="center">
  <img src="https://img.shields.io/badge/language-C-blue?cacheSeconds=300" alt="C">
  <a href="LICENSE"><img src="https://img.shields.io/github/license/Artxzzzz/sysvm?cacheSeconds=300" alt="License"></a>
  <img src="https://img.shields.io/github/stars/Artxzzzz/sysvm?cacheSeconds=300" alt="GitHub stars">
  <a href="https://github.com/Artxzzzz/sysvm/releases/latest">
    <img src="https://img.shields.io/github/v/release/Artxzzzz/sysvm?cacheSeconds=300" alt="Latest release">
  </a>
</p>

<br>

## 📝 Description

**SYSVM** is a lightweight 32-bit Virtual Machine written in **C**. It simulates a CPU with its own instruction set, 8 general-purpose registers (named after chemical elements), and 64KB of RAM. 

It was built for those who want to understand how a processor works under the hood or for anyone tired of hardcoding bytes like a "peasant" and looking for a way to execute custom binary files with a dedicated CLI.

<br>

## 🚀 Features

* **32-bit Architecture:** Full support for 32-bit integer operations.
* **Memory Management:** 64KB of emulated RAM.
* **Stack Support:** Built-in `PUSH` and `POP` operations for advanced memory handling.
* **Chemical Registers:** 8 registers: `H`, `He`, `Li`, `Be`, `B`, `C`, `N`, `O`.
* **CLI Driven:** Load and execute `.bin` or `.hex` files directly from the terminal.
* **I/O Operations:** Read strings from `stdin` and print values/characters to `stdout`.

<br>

## 🛠️ Instruction Set (Opcodes)

| Command   | Hexadecimal | Decimal | Binary   |
| :-------- | :---------- | :------ | :------- |
| EXIT      | 0xFF        | 255     | 11111111 |
| MOV       | 0x10        | 16      | 00010000 |
| MOV_REG   | 0x11        | 17      | 00010001 |
| ADD       | 0x20        | 32      | 00100000 |
| ADD_REG   | 0x21        | 33      | 00100001 |
| SUB       | 0x22        | 34      | 00100010 |
| SUB_REG   | 0x23        | 35      | 00100011 |
| JZ        | 0x30        | 48      | 00110000 |
| JNZ       | 0x31        | 49      | 00110001 |
| JMP       | 0x32        | 50      | 00110010 |
| JMP_REG   | 0x33        | 51      | 00110011 |
| OUT       | 0x40        | 64      | 01000000 |
| OUT_REG   | 0x41        | 65      | 01000001 |
| IN        | 0x42        | 66      | 01000010 |
| PUSH      | 0x50        | 80      | 01010000 |
| PUSH_REG  | 0x51        | 81      | 01010001 |
| POP       | 0x52        | 82      | 01010010 |
| LOAD      | 0x60        | 96      | 01100000 |
| LOAD_REG  | 0x61        | 97      | 01100001 |
| STORE     | 0x62        | 98      | 01100010 |
| STORE_REG | 0x63        | 99      | 01100011 |

<br>

## ⚙️ Requirements

* **GCC** or **Clang**
* Operating System: **Windows** or **Linux**

<br>

## 💻 How to compile

```bash
# Clone the repository
git clone https://github.com/Artxzzzz/sysvm.git
cd sysvm

# Compile the project
gcc src/**/*.c -o sysvm
```

<br>

## ▶️ How to run

To run a binary file through the VM:

```bash
./sysvm <your_file.bin>

# Options
./sysvm --help      # Show help message
./sysvm --version   # Show current version
```

## ✍️ How to contribute

1. Fork the repository.
2. Create a branch: `git checkout -b feature/my-awesome-instruction`.
3. Commit your changes: `git commit -m "feat: add magic opcode"`.
4. Push to the branch: `git push origin feature/my-awesome-instruction`.
5. Open a **Pull Request**.

<br>
<br>
<br>

---
<p align="center">
  Developed by <a href="https://github.com/Artxzzzz">Artxzzzz</a>
</p>
