# Quine - Compiler Original Sin

This repository contains code examples demonstrating concepts from Ken Thompson's 1984 Turing Award lecture [Reflections on Trusting Trust](https://dl.acm.org/doi/pdf/10.1145/358198.358210). These quines illustrate the ideas behind self-propagating code. Thompson shared the concept of a self-propagating compiler backdoor that could survive indefinitely without leaving evidence in the source code.

## Contents

1. **Self-Producing Program (Quine)**: Program that outputs its own source code
2. **"Trojanized" Quine**: Self-producing program that inject purposeful modifications
3. **Obfuscated "Trojan" Quine**: Simple obfuscation to hide the injected modifications

## Code Examples

### 1. Basic Quine (`quine.c`)

```bash
gcc quine.c -o quine
./quine
```

### 2. Fortran Quine (`fort_quine.f90`)

```bash
gfortran fort_quine.f90 -o fort_quine
./fort_quine
```

### 3. Trojanized Quine (`trojan_quine.c`)

Demonstrates payload injection by replacing the word "right" with "wrong" in its output.

```bash
gcc trojan_quine.c -o trojan_quine
./trojan_quine
```

### 4. Obfuscated Trojan Quine (`obfuscated_trojan_quine.c`)

```bash
gcc obfuscated_trojan_quine.c -o obfuscated_trojan_quine
./obfuscated_trojan_quine
```

## Testing the Examples

Verify that the quines work correctly by comparing their output to their source:

```bash
# Test basic quine
./quine > output.c
diff quine.c output.c

# Test trojan quine (will show differences due to "right" -> "wrong" replacement)
./trojan_quine > trojan_output.c
diff trojan_quine.c trojan_output.c
```
