# Arbitrary-Precision-Calculator
Absolutely — here is a polished, professional **README.md** formatted specifically for a **C + Data Structures–based Arbitrary Precision Calculator project**:

---

# 🧮 Arbitrary Precision Calculator

*A high-accuracy calculator built using C and Data Structures.*

---

## 📌 Overview

Traditional calculators and built-in data types in C (like `int`, `long long`, `float`, and `double`) have fixed storage limits, causing overflow and precision loss during large number computations.

This **Arbitrary Precision Calculator** removes those limitations by using **dynamic memory and data structures** to store and operate on numbers of virtually unlimited size — similar to how Python handles big integers.

---

## 🚀 Key Features

| Capability                      | Description                                                                       |
| ------------------------------- | --------------------------------------------------------------------------------- |
| ➕➖✖️➗ Basic Operations          | Supports addition, subtraction, multiplication, and division with exact precision |
| 📏 Unlimited Digit Handling     | No restriction on number length — supports extremely large integers               |
| 🔁 Linked-List Based Storage    | Each digit is stored as a node for scalable computation                           |
| ⚙️ Custom Arithmetic Algorithms | Designed using efficient, low-level mathematical logic                            |
| 🎯 Error-Free Precision         | No floating-point rounding errors                                                 |

---

## 🧠 How It Works

The project internally represents numbers using:

* **Doubly Linked Lists** for storing digits
* **Stacks/Queues** for intermediate operations
* **Custom carry/borrow logic** for precision arithmetic
* **Node-based multiplication and division algorithms**

Example structure:

```c
typedef struct Node {
    int digit;
    struct Node* next;
    struct Node* prev;
} Node;
```

---

## 📂 Project Structure

```
📁 Arbitrary-Precision-Calculator
│
├── APC/
│   ├── main.c
│   ├── addition.c
│   ├── subtraction.c
│   ├── multiplication.c
│   ├── division.c
│   └── campare.c
│
├── include/
│   └── calculator.h
│
└── README.md
```

---

## ▶️ Usage Example

```
Enter first number: 355
Enter second number: 113
Operation (+, -, *, /): /

Result:
3.141592653589793238462643383279
```

---

## 🛠️ Compilation & Run

```bash
gcc src/*.c -o calculator
./calculator
```

---

## 📈 Future Enhancements

* √ Square root and power operations
* Decimal support in all operations
* File input/output support
* GUI/Terminal-based interactive mode

---

## 🤝 Contributions

Pull requests, enhancements, and issue reports are welcome.
Feel free to fork the repository and improve it!

---

## 📜 License

This project is released under the **MIT License**.
