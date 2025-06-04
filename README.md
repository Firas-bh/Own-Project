# Own Projects

University projects as well as excerpts from the current student job.

The following projects are:

* [ISS – Deep Learning in Communication Technology Project](#ISS---Deep-Learning-in-Communication-Technology-Project)
* [Student Job at STRABAG](#Student-Job-at-STRABAG)
* [Computer Science Internship 1](#Computer-Science-Internship-1)

---

## ISS – Deep Learning in Communication Technology Project

* Development of an encoder-decoder model
* Compression and decompression of images from the MNIST dataset using neural networks
* Data transmission utilizing QPSK modulation

---

## **📡 Image Transmission with Autoencoder & PSK Modulation**

This project simulates robust image transmission over noisy channels by combining deep learning (autoencoder) with classical signal processing (PSK). The implementation was divided into three phases:

**🔄 Project Phases**

### Phase 1: Familiarization & Fundamentals

* Literature review on PSK modulation and AWGN channels
* Setting up a Python environment using Anaconda (incl. TensorFlow, NumPy, komm)
* Development of a baseline implementation without machine learning

### Phase 2: Classical Signal Processing

**[Python Script from Phase 2](/ISS%20–%20Deep%20Learning%20in%20communication%20technology%20project/main.py)**

* Manual feature extraction:

  * Direct conversion of image pixels into bitstreams

* PSK Modulation (QPSK):

  * Phase encoding of raw data

* Limitations:

  * No adaptation to image content
  * Susceptibility to noise

### Phase 3: Autoencoder Approach (Deep Learning)

**[Python Script from Phase 3](/ISS%20–%20Deep%20Learning%20in%20communication%20technology%20project/with_train.py)**

* Encoder:

  * Compresses images into a 64-D latent space

* PSK Transmission:

  * Modulates only the compressed representation

* Decoder:

  * Reconstructs images from noisy data

* Advantages:
  ✅ Reduced bandwidth usage
  ✅ Noise tolerance through feature learning
  ✅ End-to-end trainability

### Phase 4: Conclusion

**[Presentation Slides from Phase 4](/ISS%20–%20Deep%20Learning%20in%20communication%20technology%20project/Presentation/Final_KI-ISS%20.pptx)**

* Presentation of results
* Comparison of both approaches (bit error rate, reconstruction quality)

---

## 🛠 Technologies

Python 3.9 | TensorFlow/Keras | NumPy | komm | Matplotlib

---

## Student Job at STRABAG

Finance Calculation Tool (PowerApps)
Note: This is an anonymized code demo. All company-specific data and logic have been removed or abstracted.

---

### 🔒 Data Privacy Notice

Due to internal compliance policies, this repository contains only:

* Generic code snippets
* Anonymized function descriptions
* No real business logic or data structures

---

### 📌 Functions

* Calculation of corporate income/trade tax
* Dynamic interest calculation (§233a)
* Due date logic

---

### ⚙️ Technical Details

| Component        | Description                                                   |
| ---------------- | ------------------------------------------------------------- |
| **Language**     | Power Fx                                                      |
| **Data Sources** | SharePoint Lists                                              |
| **Key Logic**    | [see here](/Werkstudent_bei_STRABAG/AuszugAusEinemProject.fx) |

---

## Computer Science Internship 1

[see here](/PT-1_Informatik)

---

### C++ Programming Internship - Algorithms and Data Structures

**📚 Internship Goals**
This internship introduces fundamental programming concepts in C++ with a focus on:

* Implementing language-independent solutions in C++
* Analyzing algorithm quality (accuracy, efficiency)
* Utilizing modern C++ techniques like templates and operator overloading
* Comparing alternative solutions

---

**🛠 Experiment Overview**

| Experiment | Topic                           | Focus Areas                                                      |
| ---------- | ------------------------------- | ---------------------------------------------------------------- |
| 1          | Eclipse Environment             | First C++ program, setting up the development environment        |
| 2          | Data Structures and Operations  | Basic data types, arrays, structs, basic operations              |
| 3          | Control Structures              | Branching, loops, function calls                                 |
| 4          | Introduction to Classes         | OOP basics, encapsulation, methods                               |
| 5          | Dynamic Data Structures         | Pointers, linked lists, memory management, Doxygen documentation |
| 6          | Standard Template Library (STL) | Containers (vector, map), algorithms, iterators                  |
| 7          | Object-Oriented Techniques      | Polymorphism, operator overloading, friend classes               |
| 8          | Inheritance and Abstract Types  | Abstract classes, interfaces, multiple inheritance               |

---

**🛠 Technical Stack**

| Component                   | Technology/Options |
| --------------------------- | ------------------ |
| **Programming Language**    | C++17/20           |
| **Development Environment** | Eclipse CDT        |
| **Build System**            | CMake/Make         |
| **Documentation**           | Doxygen            |
