# qp-calc
A simple QP (Quick Postfix) calculator with features like simple arithmetic, stack operations and more.

<img width="599" height="478" alt="Screenshot 2026-02-20 at 17 41 22" src="https://github.com/user-attachments/assets/f6c314fb-1b65-471e-a4ec-b78bd6828f17" />

## How to build and run
Prebuilt executables for Windows, macOS and Linux can be found on the Releases page!

### Windows
1. Install MinGW-w64 or MSYS2 and add g++ to your PATH.
2. Open Command Prompt and navigate to the repository folder.
3. Compile:
```bash
g++ -std=c++11 *.cpp -o qp-calc.exe
```
4. Run:
```bash
qp-calc.exe
```

### macOS/Linux
1. Open Terminal and navigate to the repository folder.
2. Compile:
```bash
g++ -std=c++11 *.cpp -o qp-calc
```
3. Run:
```bash
./qp-calc
```
